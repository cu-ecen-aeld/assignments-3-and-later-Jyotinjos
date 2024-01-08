#!/bin/bash
#author is Jyotin

filesdir=$1
searchstr=$2
argscount=$#

if [ -d $filesdir ]
then
   grep_result=$(grep -ri "$searchstr" "$filesdir") 
   echo "${grep_result}"
   #filecount=$(echo "$grep_result" | cut -d':'-f1 | sort -u | wc -l)
   #echo "Number of files are ${filecount}"
   # and the number of matching lines are ${grep_result}"
else
   if [ $argscount -ne 2 ]; then
      echo "Number of argunments is wrong"
      exit 1
   elif [ ! -d "$filesdir"]; then
      echo "'${filesdir}' does not represent a directory on the filesystem"
      exit 1
   fi
fi
   	
   
   
