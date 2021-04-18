#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "algoritmos_b.h"
#include "general.h"

int main(int argc, char const *argv[]){

    int *arreglo, buscar_dato, dato_encontrado, tam_arreglo, num_hilos;

    FILE *fp = fopen("numeros10millones.txt", "r");
    if(fp == NULL){
        printf("No se encuentra el archivo\n");
        exit(0);
    }else {
        printf("Archivo encontrado\n");

        if (argc != 4) 
        {
            printf("Indique el tam del arreglo, el dato a buscar y los hilos que usara - \tEjemplo: [user@equipo]$ %s 10000000 12010 4\n\n",argv[0]);
            exit(-1);
        }

        tam_arreglo = atoi(argv[1]);
        buscar_dato = atoi(argv[2]);
        num_hilos = atoi(argv[3]);

        arreglo = (int *)malloc(sizeof(int)*tam_arreglo);
        
        car_dat(arreglo, tam_arreglo , fp);

        dato_encontrado = blineal(arreglo, tam_arreglo, buscar_dato);

        (dato_encontrado == -1)
            ? printf("\t\tEl elemento no esta en el arreglo\n")
            : printf("\t\tEl elemento esta en la posición %d\n", dato_encontrado);
    }

    fclose(fp);
    free(arreglo);

    return 0;
}