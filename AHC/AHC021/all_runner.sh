#!/bin/bash

# Loop from 0 to 99
for i in $(seq -f "%04g" 0 99)
do
    # Run the C++ program with the input file and direct the output to the output file
    ./main < in/${i}.txt > out/out${i}.txt
done
