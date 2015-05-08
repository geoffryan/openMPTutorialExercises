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
printf "pi_para1\n"
./pi_para1

unset OMP_NUM_THREADS
