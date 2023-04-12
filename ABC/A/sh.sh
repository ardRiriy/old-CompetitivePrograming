#!/bin/bash

# Iterate through the numbers from 001 to 300
for i in $(seq -w 1 300); do
    # Check if the file does not exist
    if [ ! -f "./$i.cc" ]; then
        # Create the file
        touch "./$i.cc"
    fi
done
