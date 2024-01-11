#!/bin/bash
#author is Jyotin

filesdir=$1
searchstr=$2
argscount=$#

if [ -d $filesdir ];then
   grep_result=$(grep -ri "$searchstr" "$filesdir") 
   filecount=$(find "${filesdir}" -type f | wc -l)
   mactching_count=$("${grep_Result}" | wc -l)
   echo "Number of files are ${filecount} and the number of matching lines are ${grep_result}"
   exit 0
else
   if [ -z ${searchstr} ]; then
      echo "Search string must be given as second argument"
      exit 1
   elif [ ! -d "$filesdir" ]; then
      echo "'${filesdir}' does not represent a directory on the filesystem"
      exit 1
   fi
fi
   	
   
   
