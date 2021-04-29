#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "busquedaBinaria.h"

void uswtime(double *usertime, double *systime, double *walltime)
{
	double mega = 1.0e-6;
	struct rusage buffer;
	struct timeval tp;
	struct timezone tzp;
	getrusage(RUSAGE_SELF, &buffer);
	gettimeofday(&tp, &tzp);
	*usertime = (double) buffer.ru_utime.tv_sec +1.0e-6 * buffer.ru_utime.tv_usec;
	*systime  = (double) buffer.ru_stime.tv_sec +1.0e-6 * buffer.ru_stime.tv_usec;
	*walltime = (double) tp.tv_sec + 1.0e-6 * tp.tv_usec; 
}

void creandoArreglo(int n, int nBuscado){
    int *a;

	a = (int *) malloc(n*sizeof(int));     //Definicion del puntero dinamico

    llenandoArreglo(a, n);
    printf("\nEl tamanio de su arreglos es: %d y el numero a buscar es %d", n, nBuscado);
    busquedaBinaria(a, n, nBuscado);
}

void llenandoArreglo(int *a, int n){
    char nom[]="10millones.txt",r[15];
	FILE *archivo;
	archivo=fopen(nom,"r");
	printf("\ninicia la secuencia:  \n");
    for(int x=0;x<n;x++){
        fgets(r,15,archivo);
        if(feof(archivo))
            break;
        a[x]=(int) strtol(r, NULL,10);
    }
	fclose(archivo);
    printf("Llenado del arreglo: Finalizado");
}

void busquedaBinaria(int *a, int n, int nBuscado){
    /*double real, user, sys;
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
    uswtime(&utime0, &stime0, &wtime0);
    */
    int mitad = n/2;                    //Asignacion   
    int contador = 0;                   //Asignacion   
    int posicion;                       //Asignacion
    char bandera = 'F';                 //Asignacion
    int new_tam = n;

    printf("\nEntrando a la busqueda binaria. . .");

    for (int i = n; i == 1 ; i/2){      // n/2 Comparaciones
        if(a[mitad] == nBuscado){
            bandera = 'V';
            posicion = mitad;
            break;
        }else if(a[mitad++] == nBuscado){
            bandera = 'V';
            posicion = mitad + 1;
            break;
        }else if(a[mitad--] == nBuscado){
            bandera = 'V';
            posicion = mitad -1;
            break;
        }

        
            if(nBuscado > a[mitad])
                mitad += (mitad/2);
            else if(nBuscado < a[mitad])
                    mitad = (mitad/2);
        
        //contador ++;
    }
    //free(a);

    if(bandera == 'V')
        printf("\nLa posicion del arreglo en la que se encontro el termino buscado fue: %d\n", posicion);
        else
           printf("\nElemento no encontrado :c");
    
    
    /*uswtime(&utime1, &stime1, &wtime1);

	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************
    */
	//Terminar programa normalmente	
	exit (0);	
}
