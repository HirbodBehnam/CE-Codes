pid="$1"
path="$2"
# Get files that the target process is working on them
WORKING_FILES=()
for d in "$2/$1/"fd/*; do
	working_file=$(readlink "$d")
	working_file_base=$(basename "$working_file")
	extension="${working_file_base##*.}"
	if [[ "$extension" == "txt" ]]; then
		WORKING_FILES+=("$working_file")
	fi
done
# Check child process and working files
WORKING_FILES_STR=" ${WORKING_FILES[@]} "
CHILDREN=()
WORKING_PID=()
for d in "$2/"*; do
	child_pid=$(basename "$d")
	if [[ "$child_pid" == "$pid" ]]; then
		continue
	fi
	# At first check if the process is the child or pid
	parent_pid=$(awk '/^PPid:/{print $2}' "$d/status")
	if [[ "$pid" == "$parent_pid" ]]; then
		CHILDREN+=("$child_pid")
	fi
	# now check working files
	if [[ "${#WORKING_FILES[@]}" != "0" ]]; then
		for dd in "$d/"fd/*; do
			working_file=$(readlink "$dd")
			if [[ "$WORKING_FILES_STR" =~ " ${working_file} " ]]; then
				WORKING_PID+=("$child_pid")
				break
			fi
		done
	fi
done
# Get user id and parernt user ID
user_id=$(awk '/^Uid:/{print $2}' "$2/$1/status")
parent_pid=$(awk '/^PPid:/{print $2}' "$2/$1/status")
# Print output
echo "$user_id"
if [[ "${#CHILDREN[@]}" == "0" ]]; then
	echo "not-found"
else
	echo "${CHILDREN[*]}"
fi
echo "$parent_pid"
if [[ "${#WORKING_PID[@]}" == "0" ]]; then
	echo "not-found"
else
	echo "${WORKING_PID[*]}"
fi
