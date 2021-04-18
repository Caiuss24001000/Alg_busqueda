#include <stdio.h>
#include "algoritmos_b.h"

/*  OPERACIONES BASICAS
    Comparaciones con los elementos del arreglo
    
    ANALISIS DE CASOS
    MEJOR CASO {
        Comparaciones cuando el dato esta en la primera posición 
        Operaciones basicas: 1
    }
    PEOR CASO {
        Comparaciones cuando el dato esta en la ultima posición o no esta
        Operaciones basicas: 1(n)
    }
    CASO MEDIO{
        Considerando una probabilidad igual para todos los casos tendriamos
        1*P(1) + 2*P(2) + 3*P(3) + ... + n*P(n) + n*P(n+1)
        Nuestra probabilidad general seria 1/(n+1)
        La sumatoria seria de i = 1 hasta n mas una n extra(caso cuando no esta)
        La sumatoria podria expresarse como n(n+1)/2
    }
*/

int blineal(int arreglo[], int tam_arreglo, int dato){
    int i;

    for (i = 0; i < tam_arreglo; ++i)   //Solo entrara n veces
        if(arreglo[i] == dato)          //Operacion basica
            return i;
    return -1;
}

/*  OPERACIONES BASICAS
    Comparaciones con los elementos del arreglo
    Asignaciones a mayor1 y mayor2
    Asignacion al indice i
    Asignacion a la función 
    Producto de los mayores 
    Incremento al indice
    Comparación entre el indice i y la longuitud del arreglo n

    ANALISIS DE CASOS
    PEOR CASO 
    MEJOR CASO
    CASO MEDIO{
        
    }
*/