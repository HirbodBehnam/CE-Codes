src="$1"
dst="$2"
mkdir -p "$dst"
# Get all files
for filename in "$src"/*; do
	while read -r line; do
		episode_str=$(echo "$line" | grep -o -E ' [Ss][0-9]+[Ee][0-9]+ ')
		if [ -n "$episode_str" ]; then # check if anything exists at first
			# Get the chapter and episode
			episode_str=$(echo "$episode_str" | grep -o -E '[0-9]+' | sed 's/^0*//')
			readarray -t ary <<<"$episode_str"
			# Create the chapter folder
			mkdir -p "$dst/${ary[0]}"
			echo "$line" >>"$dst/${ary[0]}/${ary[1]}.tmp" # write the whole line to file; For now...
		fi
	done <"$filename"
done
# Now sort all data in each files
for filename in "$dst"/*/*.tmp; do
	# Note that in theses arrays, same index means same title
	NAME=()       # name of torrent
	SIZE=()       # the size in megabytes
	SEED_LEACH=() # 2 * seed + leach
	while read -r line; do
		IFS=$'\t' read -r -a torrent <<<"$line" # split with tab character
		NAME+=("${torrent[0]}")
		SEED_LEACH+=($((torrent[3] * 2 + torrent[4]))) # 2 * seed + leach
		IFS=' ' read -r -a s <<<"${torrent[2],,}"      # split with space character
		if [[ "${s[1]}" == "mb" ]]; then
			SIZE+=("${s[0]}")
		else
			SIZE+=("$(echo "${s[0]}" | awk '{print $1 * 1000}')")
		fi
	done <"$filename"
	# Sort them (reverse bubble sort)
	ARRAY_SIZE=${#NAME[@]}
	for ((i = 0; i < ARRAY_SIZE; i++)); do
		for ((j = 0; j < ARRAY_SIZE - i - 1; j++)); do
			if [[ "${SEED_LEACH[j]}" -lt "${SEED_LEACH[$((j + 1))]}" ]]; then # check leaches. Larger values first
				# Sort name
				temp=${NAME[j]}
				NAME[$j]=${NAME[$((j + 1))]}
				NAME[$((j + 1))]=$temp
				# Sort leaches
				temp=${SEED_LEACH[j]}
				SEED_LEACH[$j]=${SEED_LEACH[$((j + 1))]}
				SEED_LEACH[$((j + 1))]=$temp
				# Sort size
				temp=${SIZE[j]}
				SIZE[$j]=${SIZE[$((j + 1))]}
				SIZE[$((j + 1))]=$temp
			elif [[ "${SEED_LEACH[j]}" -eq "${SEED_LEACH[$((j + 1))]}" ]]; then # if they are equal we should check other stuff
				if [[ "${SIZE[j]}" -gt "${SIZE[$((j + 1))]}" ]]; then # check sizes. Smaller values first
					# Sort name
					temp=${NAME[j]}
					NAME[$j]=${NAME[$((j + 1))]}
					NAME[$((j + 1))]=$temp
					# Sort leaches
					temp=${SEED_LEACH[j]}
					SEED_LEACH[$j]=${SEED_LEACH[$((j + 1))]}
					SEED_LEACH[$((j + 1))]=$temp
					# Sort size
					temp=${SIZE[j]}
					SIZE[$j]=${SIZE[$((j + 1))]}
					SIZE[$((j + 1))]=$temp
				elif [[ "${SIZE[j]}" -eq "${SIZE[$((j + 1))]}" ]]; then
					if [[ "${NAME[j]}" > "${NAME[$((j + 1))]}" ]]; then # compare strings. smaller values first
						# Sort name
						temp=${NAME[j]}
						NAME[$j]=${NAME[$((j + 1))]}
						NAME[$((j + 1))]=$temp
						# Sort leaches
						temp=${SEED_LEACH[j]}
						SEED_LEACH[$j]=${SEED_LEACH[$((j + 1))]}
						SEED_LEACH[$((j + 1))]=$temp
						# Sort size
						temp=${SIZE[j]}
						SIZE[$j]=${SIZE[$((j + 1))]}
						SIZE[$((j + 1))]=$temp
					fi
				fi
			fi
		done
	done
	# Overwrite final file
	rm "$filename"
	printf "%s\n" "${NAME[@]}" >"${filename::-4}"
done
