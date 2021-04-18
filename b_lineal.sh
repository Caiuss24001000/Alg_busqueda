#!/bin/bash
buscar=(322486 14700764 3128036 6337399 61396 10393545 2147445644 1295390003 450057883 187645041 1980098116 152503 5000 1493283650 214826 1843349527 1360839354 2109248666 2147470852 10000000)

numeros=(1000000 2000000 3000000 4000000 5000000 6000000 7000000 8000000 9000000 10000000)

clear

gcc busqueda.c algoritmos_b.c general.c -o bLineal

for (( j=0; j<${#numeros[@]}; j++ ))
do
    for (( i=0; i<2; i++ ))
    do
        echo "iterando con n = " ${numeros[$j]}
        ./bLineal ${numeros[$j]} ${buscar[$i]} 8 
        echo 
    done
done

