#!/bin/bash

n=( 1000000 2000000 3000000 4000000 5000000 6000000 7000000 8000000 9000000 10000000 )

numeros=( 322486 14700764 3128036 6337399 6139 10393545 2147445644 1295390003 450057883 187645041 1980098116 152503 5000 1493283650 214826 1843349527 1360839354 2109248666 2147470852 0 )

echo "Busqueda Exponencial: " >> Resultados.txt

for i in ${n[*]} 
do
    for j in ${numeros[*]}
    do
        echo "Se busca: $j   En: $i" >> Resultados.txt
        ./expo "$i" "$j" >> Resultados.txt
    done

done
