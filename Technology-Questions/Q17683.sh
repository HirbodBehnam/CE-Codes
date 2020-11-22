src="$1"
dst="$2"
if [ ! -d "$dst" ]; then
	mkdir "$dst"
fi
# Search for images
for f in $(find "$src" -iregex '.*\.\(jpg\|png\|jpeg\)$'); do
	year_modified=$(date -r "$f" '+%Y')
	mkdir "$dst/$year_modified"
	mkdir "$dst/$year_modified/photos"
	width_of_image=$(convert "$f" -format '%w' info:)
	if [[ "$width_of_image" -gt 1024 ]]; then
		name=$(basename "$f")
		convert "$f" -resize 1024 "$dst/$year_modified/photos/$name"
	else
		cp "$f" "$dst/$year_modified/photos/"
	fi
done
# Search for videos
for f in $(find "$src" -iregex '.*\.\(mp4\|avi\|3gp\|mpeg\|mkv\|wmv\|mov\)$'); do
	year_modified=$(date -r "$f" '+%Y')
	mkdir "$dst/$year_modified"
	mkdir "$dst/$year_modified/videos"
	cp "$f" "$dst/$year_modified/videos/"
done
