#include <stdio.h>
#include <stdlib.h>
//#include <pthread.h>
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

    Titulo: Algoritmo de busqeuda lineal 
    Descripción: Es un algoritmo de busqueda no recursivo 
    Fecha: 28 de abril del 2021
    Versión: 1.0
    Autor: Rodriguez Ramirez Sergio 
    ¿Que hace?
        Busca un elemento dentro de un arreglo 
    ¿Como lo hace?
        Va iterando sobre los elementos del arreglo hasta encontrar 
        el dato a buscar, si es que esta dentro del arreglo
    ¿Que recibe?
        Recibe un arreglo de enteros, el tamaño(int) del arreglo y el dato(int) a buscar
    ¿Que devuelve?
        Devuelve la posición(int) del arerglo si la encontro y -1 si no encontro el dato
    ¿Causa de errores?
        Si enviara un arreglo de menor tamaño no podria recorrer todo el arreglo
*/
int blineal(int arreglo[], int tam_arreglo, int dato){
    int i;

    for (i = 0; i < tam_arreglo; ++i)   //Solo entrara n veces
        if(arreglo[i] == dato)          //Operacion basica
            return i;
    return -1;
}

/****************************************************************************************
*****************************************************************************************
    Titulo: Algoritmo de busqeuda fibonacci 
    Descripción: Es un algoritmo de busqueda que va iterando con los numeros de fibonacci
    Fecha: 28 de abril del 2021
    Versión: 1.1
    Autor: Rodriguez Ramirez Sergio 
    ¿Que hace?
        Busca un elemento dentro de un arreglo 
    ¿Como lo hace?
        Va iterando sobre los elementos del arreglo hasta encontrar 
        el dato a buscar, si es que esta dentro del arreglo
    ¿Que recibe?
        Recibe un arreglo de enteros, el tamaño del arreglo(int)y el dato(int) a buscar
    ¿Que devuelve?
        Devuelve la posición(int) del arerglo si la encontro y -1 si no encontro el dato
    ¿Causa de errores?
        Si el dato no se encuentra manda -1

*****************************************************************************************
*****************************************************************************************

    OPERACIONES BASICAS
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
*****************************************************************************************
****************************************************************************************/

int bfibonacci(int arr[], int tam_arreglo, int dato){
    int fibNum1 = 0;                    //Numero de fibonacci n-2
    int fibNum2 = 1;                    //Numero de fibonacci n-1
    int fibNum3 = fibNum1 + fibNum2;    //Numero de fibonacci n
 
    while (fibNum3 < tam_arreglo) {
        fibNum1 = fibNum2;
        fibNum2 = fibNum3;
        fibNum3 = fibNum2 + fibNum1;
    }
 
    int offset = -1;
 
    while (fibNum3 > 1) {
        int i = min(offset + fibNum1, tam_arreglo - 1);
 
        if (arr[i] < dato) {
            fibNum3 = fibNum2;
            fibNum2 = fibNum1;
            fibNum1 = fibNum3 - fibNum2;
            offset = i;
        }
 
        else if (arr[i] > dato) {
            fibNum3 = fibNum1;
            fibNum2 = fibNum2 - fibNum1;
            fibNum1 = fibNum3 - fibNum2;
        }
 
        else
            return i;
    }
 
    if (fibNum2 && arr[offset + 1] == dato)
        return (void*)(offset + 1);
 
    return -1;
}

/****************************************************************************************
*****************************************************************************************
    Titulo: Algoritmo para el minimo de dos numeros 
    Descripción: Es un algoritmo que devuelve el minimo de dos numeros
    Fecha: 28 de abril del 2021
    Versión: 1.0
    Autor: Rodriguez Ramirez Sergio 
    ¿Que hace?
        Compara cual es el menor de dos numeros 
    ¿Como lo hace?
        Hace una comparación para saber cual de los dos numeros es menor
    ¿Que recibe?
        Recibe dos numeros enteros
    ¿Que devuelve?
        Devuelve un numero entero
    ¿Causa de errores?
        Si se compararan dos numeros iguales regresaria el primer numero

*****************************************************************************************
****************************************************************************************/
int min(int x, int y){
    return (x <= y) ? x : y;
}

/****************************************************************************************
*****************************************************************************************
    OPERACIONES BASICAS
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
*****************************************************************************************
****************************************************************************************/