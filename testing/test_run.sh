#!/bin/bash

genrator_file=""
your_file=""
brute_file=""
checker_file=""

genrator_bool=false
your_bool=false
brute_bool=false
checker_bool=false
only_checker_bool=false

usage() { 
	echo -e "$0 -g generator -y your_code -b brute_code -c checker[optional] -x \n";
        echo -e "-x Only checker, no brute force\n";
        echo -e "\t When writing checker stdin gives input_file and\n";
        echo -e "\t argv gives the file name of answer output\n"
	exit ; 
}


only_checker(){
   {
      set -e
      g++ "${genrator_file}" -O0 -g -o gen.out --std=c++2a
      g++ "${your_file}" -O0 -g -o your.out --std=c++2a
      g++ "${checker_file}" -O0 -g -o checker.out --std=c++2a
   }


   echo "Compiling Finished";
   for((i=1; ;++i)); do
      $(pwd)/gen.out > input_file
      $(pwd)/your.out < input_file > your_answer
      $(pwd)/checker.out your_answer < input_file  > checker_log

      if [ $? -ne 0 ]; then
         echo "Failed test $i";
         exit
      else
         echo "Passed test: " $i
      fi

   done
}

without_checker() {
   {
      set -e
      g++ "${genrator_file}" -O0 -g -o gen.out --std=c++2a
      g++ "${brute_file}" -O0 -g -o brute.out --std=c++2a
      g++ "${your_file}" -O0 -g -o your.out --std=c++2a
   }

   echo "Compiling finished";
   for((i = 1; ; ++i)); do
      $(pwd)/gen.out > input_file
      $(pwd)/brute.out < input_file > brute_answer
      $(pwd)/your.out < input_file > your_answer
      diff -Z your_answer brute_answer  > /dev/null || break
      echo "Passed test: " $i
   done
   echo "WA on the following test:"
   cat input_file
   echo "Your answer is:"
   cat your_answer
   echo "brute answer is:"
   cat brute_answer
}


with_checker() {
   {
      set -e
      g++ "${genrator_file}" -O0 -g -o gen.out --std=c++2a
      g++ "${brute_file}" -O0 -g -o brute.out --std=c++2a
      g++ "${your_file}" -O0 -g -o your.out --std=c++2a
      g++ "${checker_file}" -O0 -g -o checker.out --std=c++2a
   }


   for((i=1; ;++i)); do
      $(pwd)/gen.out > input_file
      $(pwd)/brute.out < input_file > brute_answer
      $(pwd)/your.out < input_file > your_answer
      $(pwd)/checker.out brute_answer your_answer > checker_log

      echo "Compiling finished";
      if [ $? -ne 0 ]; then
         echo "Failed test $i";
         echo < checker_log
         exit
      else
         echo "Passed test: " $i
      fi

   done
}

while getopts ":hg:y:b:c:x" arg; do
   case $arg in
      h)
         usage
         ;;
      g)
         genrator_file=`realpath ${OPTARG}`
         genrator_bool=true
         ;;
      y)
         your_file=`realpath ${OPTARG}`
         your_bool=true
         ;;
      b)
         brute_file=`realpath ${OPTARG}`
         brute_bool=true
         ;;
      c)
         checker_file=`realpath ${OPTARG}`
         checker_bool=true
         ;;
      x)
         only_checker_bool=true
         ;;
      :)
         echo "${OPTARG} requires an argument!"
         exit 1
         ;;
      ?)
         echo "Invalid option ${OPTARG}"
         exit 1
         ;;
   esac
done

if [ "$genrator_bool" = false ] ; then
   echo "Generator not set!"
   exit
fi

if [ "$your_bool" = false ] ; then
   echo "your_bool is not set!"
   exit
fi

if [ "$only_checker_bool" = true ] ; then
   only_checker
   exit
fi

if [ "$brute_bool" = false ] ; then
   echo "brute_bool is not set!"
   exit
fi

if [ "$checker_bool" = false ] ; then
   without_checker
else
   with_checker
fi

