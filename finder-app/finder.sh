#!/bin/sh
# Author: Jyotin

filesdir="$1"
searchstr="$2"
argscount="$#"

if [ ! -d "$filesdir" ]; then
   echo "'$filesdir' does not represent a directory on the filesystem"
   exit 1
fi

if [ -z "$searchstr" ]; then
   echo "Search string must be given as the second argument"
   exit 1
fi

grep_result=$(grep -ri "$searchstr" "$filesdir")
matching_count=$(echo "$grep_result" | wc -l)
filecount=$(find -L "$filesdir" -type f | wc -l)

echo The number of files are $filecount and the number of matching lines are $matching_count

exit 0
