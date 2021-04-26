#include <stdio.h>
#include <stdlib.h>
#include "busquedaBinaria.h"

void creandoArreglo(int n, int nBuscado){
    int *a;

	a = (int *) calloc(n, sizeof(int));     //Definicion del puntero dinamico

    llenandoArreglo(a, n);
    printf("\nEl tamanio de su arreglos es: %d y el numero a buscar es %d", n, nBuscado);
    busquedaBinaria(a, n, nBuscado);
}

void llenandoArreglo(int a[], int n){
	FILE *archivo;
	archivo=fopen("10millones.txt","r");
	printf("\ninicia la secuencia:  \n");
    
    for(int i=0; i<n; i++){
        fscanf(archivo, "%d", &a[i]);
        fflush(stdout);
    }
    /*for(int x=0;x<n;x++){
        fgets(r,15,archivo);
        if(feof(archivo))
            break;
        a[x]=(int) strtol(r, NULL,10);
    }*/
	fclose(archivo);
    printf("Llenado del arreglo: Finalizado");
}

void busquedaBinaria(int a[], int n, int nBuscado){
    int mitad = n/2;                    //Asignacion   
    int contador = 0;                   //Asignacion   
    int posicion;                       //Asignacion
    char bandera = 'F';                 //Asignacion

    printf("\nEntrando a la busqueda binaria. . .");

    while(bandera == 'F' && contador < (n/2)){      // n/2 Comparaciones
        if(a[mitad] == nBuscado){
            bandera = 'V';
            posicion = mitad;
            break;
        }else if(a[mitad++] == nBuscado){
            bandera = 'V';
            posicion = mitad + 1;
        }else if(a[mitad--] == nBuscado){
            bandera = 'V';
            posicion = mitad - 1;
        }

        if(bandera == 'F'){
            if(nBuscado > a[mitad])
                mitad += (mitad/2);
                else if(nBuscado < a[mitad])
                    mitad = (mitad/2);
        }
        contador ++;
    }
    free(a);

    if(bandera == 'V')
        printf("\nLa posicion del arreglo en la que se encontro el termino buscado fue: %d\n", posicion);
        else
            printf("\nElemento no encontrado :c");
}
