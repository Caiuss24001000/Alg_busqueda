#!/bin/bash
buscando=(322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 1295390003, 450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839354, 2109248666, 2147470852, 0)
numeros=(1000000 2000000 3000000 4000000 5000000 6000000 7000000 8000000 9000000 10000000)

clear
rm -r resultado/*.txt

gcc bLinFib/busqueda.c bLinFib/algoritmos_b.c bLinFib/general.c -lpthread -o bFibo

for (( j=0; j<${#numeros[@]}; j++ )) # ${#numeros[@]}
do
    echo "Iterando con n = " ${numeros[$j]} >>resultado/fibonacci.txt
    for (( i=0; i<${#buscando[@]}; i++ )) # ${#buscando[@]}
    do
        
        ./bFibo ${numeros[$j]} ${buscando[$i]} 8 >>resultado/fibonacci.txt
        echo >> resultado/fibonacci.txt
    done
done

#for (( j=0; j<${#numeros[@]}; j++ )) # ${#numeros[@]}
#do
#    echo "Iterando con n = " ${numeros[$j]} >>resultado/fibonacci.txt
#    for (( i=0; i<3; i++ )) # ${#buscando[@]}
#    do
        
#        ./bLineal ${numeros[$j]} ${buscando[$i]} 8 >>resultado/fibonacci.txt
#        echo >> resultado/fibonacci.txt
#    done
#done

#for (( j=0; j<${#numeros[@]}; j++ )) # ${#numeros[@]}
#do
#    echo "Iterando con n = " ${numeros[$j]} >>resultado/exponencial.txt
#    for (( i=0; i<3; i++ )) # ${#buscando[@]}
#    do
#        
#        ./bLineal ${numeros[$j]} ${buscando[$i]} 8 >>resultado/exponencial.txt
#        echo >> resultado/exponencial.txt
#    done
#done

#gcc ABB/TestArBin.c ABB/general.c -o bABB

#for (( j=6; j<${#numeros[@]}; j++ )) # ${#numeros[@]}
#do
#    echo "Iterando con n = " ${numeros[$j]} >>resultado/ABB.txt
#    for (( i=0; i<${#buscando[@]}; i++ )) # ${#buscando[@]}
#    do
        
#        ./bABB ${numeros[$j]} ${buscando[$i]} 8 >>resultado/ABB.txt
#        echo >> resultado/ABB.txt
#    done
#done

#gcc bBin/testBusquedaBinaria.c bBin/busquedaBinaria.c -o bBinaria

#for (( j=0; j<${#numeros[@]}; j++ )) # ${#numeros[@]}
#do
#    echo "Iterando con n = " ${numeros[$j]} #>>resultado/binaria.txt
#    for (( i=0; i<3; i++ )) # ${#buscando[@]}
#    do
        
#        ./bBinaria ${numeros[$j]} ${buscando[$i]} 8 #>>resultado/binaria.txt
#        echo #>> binaria.txt
#    done
#done

