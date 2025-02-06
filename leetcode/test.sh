#!/bin/bash


for(( strat=1; strat<= 2000; strat+=100)); do
    end=$(( strat + 99 ))
    dir_name="${strat}-${end}"
    cp ./my_include.h "${dir_name}" 
    #for i in $(seq $strat $end); do
    #    if [ -f "$i.cpp" ]; then
    #        echo "Moving success"
    #        mv "$i.cpp" "${dir_name}"
    #    else
    #        echo "$i.cpp does not exist"
    #    fi
    #done
done

