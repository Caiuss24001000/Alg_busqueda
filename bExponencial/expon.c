#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#include "general.h"

#define MAX 10000000

int contador = 0, result=-1;

typedef struct arg_struct{
	int id;
	int nhilos;
	int *arr;
	int n;
	int x;
}parametros;

int binarySearch(int arr[], int, int, int);

double min(double a, double b) {
    return a<b ? a : b;
} 

// Returns position of first occurrence of
// x in array
void* exponentialSearch(void* arguments){
	
	struct arg_struct *args = arguments;
    // If x is present at firt location itself
    if (args->arr[0] == args->x){		// *
        result = 0;
		return 0;
	}
 
    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < args->n && args->arr[i] <= args->x){					// **
		contador++;
        i = i*2;
	}
    //  Call binary search for the found range.
    result = binarySearch(args->arr, i/2, min(i, args->n-1), args->x);			// ^*
}
 
// A recursive binary search function. It returns
// location of x in  given array arr[l..r] is
// present, otherwise -1
int binarySearch(int arr[], int l, int r, int x){
	int mid = (l+r)/2;								// *
	while(l<r){										// *
		if(x == arr[mid]){							// *
			return mid;
		}
		else{
			if(x < arr[mid]){						// *
				r = mid-1;							// *
			}
			else{
				l = mid+1;
			}
		}
		mid = (l+r)/2;								// *
	}
	if(x == arr[mid]){								// *
		return mid;
	}
	else{
		return -1;
	}
}
/*
El mejor caso posible es que el numero a encontrar se encuentre a la mitad
de la longitud del arreglo:



El peor caso posible es que el numero a encontrar no se encuentre en el 
arreglo.
*/

int main(int argc, char const *argv[]){
	FILE *fp = fopen("10millonesOrdenados.txt", "r");
	int *arr, n, nhilos, x;
	pthread_t *thread;
	parametros *pa;
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
	if(fp == NULL){
		printf("Error al leer el archivo\n");
		exit (0);
	}
	else {
		printf("Archivo leido con exito.\n\n");
		if(argc != 4){
			printf("Indique el tamaño del arreglo, el dato a buscar y los hilos que usara - \tEjemplo: [user@equipo]$ %s 10000000 12010 4\n\n", argv[0]);
			exit(-1);
		}
		n = atoi(argv[1]);
		x = atoi(argv[2]);
		nhilos = atoi(argv[3]);
		arr = (int *)malloc(sizeof(int) * n);
		thread = malloc(sizeof(pthread_t) * nhilos);
		pa = (parametros *)malloc(sizeof(parametros) * nhilos);
		printf("Leyendo datos...\n\n");
		for(int i=0; i<n; i++){
			fscanf(fp, "%d", &arr[i]);
			//printf("\rProgreso: arr[%d]", arr[i]);
			//fflush(stdout);
		}

        //Medicion de inicio del algoritmo
        uswtime(&utime0, &stime0, &wtime0);
        
		for (int i = 0; i < nhilos; ++i){
            pa[i].id = i;
            pa[i].nhilos = nhilos;
            pa[i].arr = arr;
            pa[i].n = n;
            pa[i].x = x;
            if (pthread_create (&thread[i], NULL, exponentialSearch, (void *)&pa[i]) != 0 ){
                perror("El thread no  pudo crearse");
                exit(-1);
            }
        }
		for (int i=0; i<nhilos; i++){
            pthread_join (thread[i], NULL);
        }

        /*
		pa->id = 0;
		pa->nhilos = nhilos;
		pa->arr = arr;
		pa->n = n;
		pa->x = x;*/

		exponentialSearch(pa);
        (result == -1)
            ? printf("\n\t\tEl elemento no esta en el arreglo\n")
            : printf("\n\t\tEl elemento esta en la posicion %d\n", result);

        //Medicion de fin del algoritmo
        uswtime(&utime1, &stime1, &wtime1);

        double t_real = wtime1 - wtime0;
        printf("\n");
        printf("real (Tiempo total)  %.10e s\n", t_real);
        printf("\n");
	}
	fclose(fp);
	free(thread);
	free(arr);
	return 0;
}