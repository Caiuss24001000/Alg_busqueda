#include <stdio.h>
#include <stdlib.h>
#include "busquedaBinaria.h"

int main(int argc, char const *argv[])
{
    int tamArreglo, numBuscado, numHilos;

    /*
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    pthread_t *thread;
    struct parametros parame;
    */

    if(argc != 4){
        printf("Indique el tam del arreglo, el dato a buscar y los hilos que usara - \tEjemplo:[user@equipo]$ %s 10000000 12010 4\n\n", argv[0]);
        exit(-1);
    }
    tamArreglo = atoi(argv[1]);
    numBuscado = atoi(argv[2]);
    numHilos = atoi(argv[3]);

    creandoArreglo(tamArreglo, numBuscado);
    return 0;
}
