# Create the list if it does not exists
if [ ! -d "tasks.txt" ]; then
	touch tasks.txt
fi
# Get the args
case $1 in
add)
	shift
	if [[ "$#" -gt 0 ]]; then
		task="$@"
		lowered_task=$(echo "$task" | tr '[A-Z]' '[a-z]')
		priority="L"
		if [[ "$lowered_task" == *" (important)" ]]; then
			priority="M"
		elif [[ "$lowered_task" == *" (very important)" ]]; then
			priority="H"
		fi
		echo "$priority $task" >>tasks.txt
		total_tasks=$(wc -l tasks.txt | awk '{ print $1 }')
		echo "Added task $total_tasks with priority $priority"
	else
		echo >&2 "[Error] This command needs an argument"
		exit 1
	fi
	;;
list)
	counter=1
	EMPTY_TASK=true
	while IFS= read -r line; do
		EMPTY_TASK=false
		l_array=($line)
		priority="*    "
		if [[ "${l_array[0]}" == "M" ]]; then
			priority="***  "
		elif [[ "${l_array[0]}" == "H" ]]; then
			priority="*****"
		fi
		echo "$counter $priority ${l_array[@]:1}"
		counter=$((counter + 1))
	done <"tasks.txt"
	if [[ "$EMPTY_TASK" == "true" ]]; then
		echo "No tasks found..."
	fi
	;;
"done")
	if [[ "$#" -eq 2 ]]; then
		# read line
		line=$(sed -n "$2p" tasks.txt)
		l_array=($line)
		echo "Completed task $2: ${l_array[@]:1}"
		# delete the line
		sed -i "$2d" tasks.txt
	else
		echo >&2 "[Error] This command needs an argument"
		exit 1
	fi
	;;
*)
	echo >&2 "[Error] Invalid command"
	exit 1
	;;
esac
