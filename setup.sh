#! /bin/bash

usage() { echo "$0 dest_folder dest_sturcture"; exit ; }

while getopts ":h" arg; do
   case $arg in
      h)
         usage
         ;;
   esac
done

if [[ $# -ne 2 ]] ; then
    echo 'Unexpectable number of arguments'
    exit 1
fi

COMPILE_FLAG_DIR="/home/devut/Projects/CP/boilers/"
COMPILE_FLAG_FILE="compile_flags.txt"

dest_folder=$1
folder_struct=$2

dest_folder=`realpath $1`

final_folder="${dest_folder}/${folder_struct}"
mkdir -p ${final_folder}
if [ $? -ne 0 ] ; then
   echo "Failure creating Directory!"
   exit
fi



cp "${COMPILE_FLAG_DIR}/${COMPILE_FLAG_FILE}" "${final_folder}/compile_flags.txt" 
