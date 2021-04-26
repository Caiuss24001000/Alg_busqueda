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

int bfibonacci(int arr[], int tam_arreglo, int dato){
    int fibNum1 = 0; 
    int fibNum2 = 1; 
    int fibNum3 = fibNum1 + fibNum2; 
 
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

// RETORNA EL MINIMO DE DOS NUMEROS
int min(int x, int y){
    return (x <= y) ? x : y;
}

/*
void* proceso(void* argumentos){

    struct parametros* datos_p = (struct parametros*)argumentos;
    struct parametros* aux2 = (struct parametros*)argumentos;
    int inicio,fin,i;
    int id = datos_p -> id;
    int tam_arreglo = datos_p -> tam_arreglo;
    int buscando = datos_p -> buscando;
    int num_hilos = datos_p -> num_hilos;
    int *arreglo = datos_p -> arreglo;
    int *aux;

    //Revisar la parte de los datos a procesar  
    inicio = (id * tam_arreglo)/num_hilos;
    if(id==num_hilos-1)  
        fin=tam_arreglo-1;
    else
        fin=(id+1)*tam_arreglo;

    tam_arreglo = fin - inicio + 1;
    aux = (int *)malloc(sizeof(int)*tam_arreglo);

    printf("\nHola desde procesar\tSoy el thread %d\tInicio %d\tTermino %d",id,inicio,fin);

    for(i=0;i<=fin;i++)     
        //printf("\nProcesando dato %d",i);
        aux[i] = arreglo[inicio+i];
    
    //printf("\nBye desde procesar\tSoy el thread %d\tHe terminado",num_hilos);

    aux2->encontrado = bfibonacci(aux, tam_arreglo, buscando);
    argumentos = (void *)aux2;
}



void crear_hilos(int num_hilos, pthread_t hilos[], struct parametros parame[], int funcion){
    pthread_t *aux=hilos;

    switch(funcion){
        case 5:
            for (int i = 1; i < num_hilos && parame->encontrado == -1; ++i){
                if (pthread_create (&aux[i], NULL, proceso, (void *)&parame[i]) != 0 ){
                    perror("El thread no  pudo crearse");
                    exit(-1);
                }
            }
            break;
        default:
            perror("La función no existe");
            exit(-1);
    }
}

void ejecutar_hilos(int num_hilos, pthread_t hilos[], int funcion){
    
    switch(funcion){
        case 5:
            for (int i=1; i<num_hilos; i++){
                pthread_join (hilos[i], NULL);
            }
            break;
        default:
            perror("La función no existe");
            exit(-1);
    }
}*/

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