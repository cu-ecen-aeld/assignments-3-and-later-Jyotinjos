#!/bin/bash
#author is Jyotin

writefile="$1"
writestr="$2"

if [ "$#" -ne 2 ]; then
   echo "Usage: $0 <writefile> <writestr>"
   exit 1
elif [ -z "$writefile" ]; then
   echo "Error: writefile is empty"
   exit 1
elif [ -z "$writestr" ]; then 
   echo "Error: writestr is missing"
   exit 1
fi

echo "${writestr}"
echo "${writefile}"


echo "${writestr}" > "${writefile}"

if [ ! -f "$1" ]; then
   echo "Error: Could not create file"
   exit 1
fi

if [ "$?" -ne 0 ];then
   echo "Unable to create or write to ${writefile}"
   exit 1
else
   echo "File '${writefile}' created successfully"
   exit 0
fi
