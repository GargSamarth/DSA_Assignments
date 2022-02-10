#! /bin/bash 
 
    a=$1
    b=$2
    c=$3

    if [ ( expr $a + $b ) -le $c -o ( expr $a + $c ) -le $b -o ( expr $b + $c ) -le $a ] 
    then
        echo "NO" 
    else
        echo "YES"
    fi 

