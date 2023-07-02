#!/bin/bash

for filename in 'a' 'b' 'c' 'd' 'e' 'f'
do
    if [ -e "current/${filename}.cpp" ]; then
        echo "File ${filename}.cpp exists, deleting..."
        rm "current/${filename}.cpp"
    fi
    cp template.cpp "current/${filename}.cpp"
done
