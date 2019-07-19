#!/bin/bash

find ./  ! -name "*.cpp" ! -name "*.sh"  ! -name "*.pdf" ! -name "*.txt" -type f  -exec rm {} \;
for file in ./*
do
        if test -f $file
        then
            echo "file:  $file"
        elif test -d $file
        then
            find $file  ! -name "*.cpp"  ! -name "*.pdf" ! -name "*.txt" -type f -exec rm {} \;
        fi
done
