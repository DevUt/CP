#! /bin/bash

COMPILE_FLAG_DIR="/home/devut/Projects/CP/boilers/"
COMPILE_FLAG_FILE="compile_flags.txt"

dest_folder=$1
folder_struct=$2

dest_folder=`realpath $1`
final_folder="${dest_folder}/${folder_struct}"
mkdir -p ${final_folder}
if [ $? -ne 0 ] ; then
   echo "Failure creating Directory!"
fi



cp "${COMPILE_FLAG_DIR}/${COMPILE_FLAG_FILE}" "${final_folder}/compile_flags.txt" 
