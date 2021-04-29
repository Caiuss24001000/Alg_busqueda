#include <stdio.h>
#include <stdlib.h>
#include "busquedaBinaria.h"
#include <sys/resource.h>
#include <sys/time.h>

int main(int argc, char const *argv[])
{
    int tamArreglo, numHilos, *arreglo;
    long int numBuscado;

    /*printf("Ingrese el tamanio de su arreglo: ");
    scanf("%d", &tamArreglo);
    printf("Ingrese el numero a buscar");
    scanf("%d", &numBuscado);
    */
    if (argc != 4) 
        {
            printf("Indique el tam del arreglo, el dato a buscar y los hilos que usara - \tEjemplo: [user@equipo]$ %s 10000000 12010 4\n\n",argv[0]);
            exit(-1);
        }

        tamArreglo = atoi(argv[1]);
        numBuscado = atoi(argv[2]);
        numHilos = atoi(argv[3]);
    
    creandoArreglo(tamArreglo, numBuscado);
    return 0;
}