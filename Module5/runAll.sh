#!/bin/bash

unset OMP_NUM_THREADS

if [ "$#" -eq "1" ]
then
    export OMP_NUM_THREADS=$1
    printf "Using $OMP_NUM_THREADS threads\n"
else
    printf "Using default threads\n"
fi

printf "pi_serial\n"
./pi_serial
printf "pi_para1 - My first\n"
./pi_para1
printf "pi_para2 - Dumb solution, 'false sharing'\n"
./pi_para2
printf "pi_para3 - Synchronize safely\n"
./pi_para3
printf "pi_para4 - Work-Sharing for-loop\n"
./pi_para4
printf "pi_para5 - Parallel for & Reduction\n"
./pi_para5

unset OMP_NUM_THREADS
