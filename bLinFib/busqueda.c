#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <pthread.h>
#include "algoritmos_b.h"
#include "general.h"

typedef struct datoF{
    int id;
    int num_hilos;
    int *arreglo;
    int tam_arreglo;
    int buscando;
    int encontrado;
}parametros;

pthread_mutex_t llave;

void* proceso(void* argumentos){

    parametros *p = (parametros *)argumentos;
    
    int inicio, fin, new_tam, i;
    int *aux;

    inicio = (p->id * p->tam_arreglo)/p->num_hilos;
    if(p->id == p->num_hilos - 1)
        fin = p->tam_arreglo - 1;
    else
        fin = ((p->id + 1) * p->tam_arreglo)/p->num_hilos-1;

    printf("\nHola desde procesar\tSoy el thread %d\tInicio %d\tTermino %d", p->id, inicio, fin);

    new_tam = fin - inicio + 1;
    aux = (int *)malloc(sizeof(int) * new_tam);

    for(i=0;i<=new_tam;i++)
        aux[i] = p->arreglo[inicio+i];

    p->encontrado = bfibonacci(aux, new_tam, p->buscando);
}

int main(int argc, char const *argv[]){

    int *arreglo, tam_arreglo, num_hilos, buscando, dato_encontrado = -1;
    double utime0, stime0, wtime0, utime1, stime1, wtime1;

    pthread_t *thread;
    parametros *pa, pa1, pa2;

    FILE *fp = fopen("10millonesOrdenados.txt", "r");
    if(fp == NULL){
        printf("No se encuentra el archivo\n");
        exit(0);
    }else {
        //printf("Archivo encontrado\n");

        if (argc != 4) 
        {
            printf("Indique el tam del arreglo, el dato a buscar y los hilos que usara - \tEjemplo: [user@equipo]$ %s 10000000 12010 4\n\n",argv[0]);
            exit(-1);
        }

        tam_arreglo = atoi(argv[1]);
        buscando = atoi(argv[2]);
        num_hilos = atoi(argv[3]);

        arreglo = (int *)malloc(sizeof(int) * tam_arreglo);
        thread = malloc(sizeof(pthread_t) * num_hilos);
        pa = (parametros *)malloc(sizeof(parametros) * num_hilos);

        car_dat(arreglo, tam_arreglo , fp);

        pa1.id = 0;
        pa1.num_hilos = num_hilos;
        pa1.arreglo = arreglo;
        pa1.tam_arreglo = tam_arreglo;
        pa1.buscando = buscando;
        pa1.encontrado = -1;
        
        for (int i = 0; i < num_hilos; ++i){
            pa[i].id = i;
            pa[i].num_hilos = num_hilos;
            pa[i].arreglo = arreglo;
            pa[i].tam_arreglo = tam_arreglo;
            pa[i].buscando = buscando;
            pa[i].encontrado = -1;
            if (pthread_create (&thread[i], NULL, proceso, (void *)&pa[i]) != 0 ){
                perror("El thread no  pudo crearse");
                exit(-1);
            }
        }

        for (int i=0; i<num_hilos; i++){
            pthread_join (thread[i], NULL);
        }

        
        for (int i = 0; i < num_hilos; ++i)
        {
            (pa[i].encontrado == -1)
                ? printf("\n\t\tEl elemento no esta en el arreglo\n")
                : printf("\n\t\tEl elemento esta en la posición %d\n", pa[i].encontrado);
        }

        /*
        pthread_create (&thread[0], NULL, proceso, (void *)&pa1);
        pthread_create (&thread[1], NULL, proceso, (void *)&pa2);
        pthread_join (thread[0], NULL);
        pthread_join (thread[1], NULL);
        (pa1.encontrado == -1)
                ? printf("\n\t\tEl elemento no esta en el arreglo\n")
                : printf("\n\t\tEl elemento esta en la posición %d\n", pa1.encontrado);
        (pa2.encontrado == -1)
                ? printf("\n\t\tEl elemento no esta en el arreglo\n")
                : printf("\n\t\tEl elemento esta en la posición %d\n", pa2.encontrado);
        */
/*
        //Medicion de inicio del algoritmo
        uswtime(&utime0, &stime0, &wtime0);
        
        dato_encontrado = bfibonacci(arreglo, tam_arreglo, buscando);
        (dato_encontrado == -1)
            ? printf("\t\tEl elemento no esta en el arreglo\n")
            : printf("\t\tEl elemento esta en la posición %d\n", dato_encontrado);
        //Medicion de fin del algoritmo
        uswtime(&utime1, &stime1, &wtime1);
        double t_real = wtime1 - wtime0;
        printf("\n");
        printf("real (Tiempo total)  %.10e s\n", t_real);
        printf("\n");
        */
    }

    fclose(fp);
    free(thread);
    free(arreglo);

    return 0;
}