//Compilación de la libreria: "gcc -c general.c " (Generación del código objeto)

/*LIBRERIAS INCLUIDAS*/
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "general.h"

void car_dat(int a[], int n, FILE *fp){

    for(int i=0; i<n; i++){
        fscanf(fp, "%d", &a[i]);
        fflush(stdout);
    }
}

void llenar_arr(int a[], int tam){
    srand(time(0));
    for (int i = 0; i < tam; ++i)
    {
        a[i] = 1+rand()%TAM_MAX_NUM+1;  //Genera datos entre 1 y 10000001
        printf("Dato agregado al arreglo: %d\n", a[i]);
    }
    return;
}

void cal_timepos(double wtime0, double utime0, double stime0, double wtime1, double utime1, double stime1){

    double t_real = wtime1 - wtime0;
    double t_user = utime1 - utime0;
    double t_sys = stime1 - stime0;
    double t_cpu_wall = 100.0 * (t_user + t_sys)/t_real;
    if (t_real > 1.0 || t_user > 1.0 || t_sys > 1.0)
    {
        //Cálculo del tiempo de ejecución del programa
        printf("\n");
        printf("real (Tiempo total)  %.10f s\n", t_real);
        //printf("user (Tiempo de procesamiento en CPU) %.10f s\n", t_user);
        //printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", t_sys);
        //printf("CPU/Wall   %.10f %% \n", t_cpu_wall);
        printf("\n");
    }else{
        //Mostrar los tiempos en formato exponecial
        printf("\n");
        printf("real (Tiempo total)  %.10e s\n", t_real);
        //printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  t_user);
        //printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", t_sys);
        //printf("CPU/Wall   %.10f %% \n",t_cpu_wall);
        printf("\n");
    }
}

//uswtime (Definición)
//*****************************************************************
//Descripción: Función que almacena en las variables referenciadas 
//el tiempo de CPU, de E/S y Total actual del proceso actual.
//
//Recibe: Variables de tipo doble para almacenar los tiempos actuales
//Devuelve: 
//*****************************************************************#include <stdio.h>
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

/*En Unix, se dispone de temporizadores ejecutables (en concreto time) que nos proporcionan medidas de los tiempos
de ejecución de programas. Estos temporizadores nos proporcionan tres medidas de tiempo:

    * real:  Tiempo real que se ha tardado desde que se lanzó el programa a ejecutarse hasta que el programa finalizó y proporcionó los resultados.
    * user: Tiempo que la CPU se ha dedicado exclusivamente a la computación del programa.
    * sys:  Tiempo que la CPU se ha dedicado a dar servicio al sistema operativo por necesidades del programa (por ejemplo para llamadas al sistema para efectuar I/O).

El tiempo real también suele recibir el nombre de elapsed time o wall time. Algunos temporizadores también proporcionan el porcentaje de tiempo que la CPU se ha dedicado al programa. Este porcentaje viene dado por la relación entre el tiempo de CPU (user + sys)
y el tiempo real, y da una idea de lo cargado que se hallaba el sistema en el momento de la ejecución del programa.

El grave inconveniente de los temporizadores ejecutables es que no son capaces de proporcionar medidas de tiempo de ejecución de segmentos de código. Para ello, hemos de invocar en nuestros propios programas  a un conjunto de temporizadores disponibles en la mayor parte de las librerías de C de Unix, que serán los que nos proporcionen medidas sobre los tiempos de ejecución de trozos discretos de código.

En nuestras prácticas vamos a emplear una función que actúe de temporizador y que nos proporcione los tiempos de CPU (user, sys)
y el tiempo real. En concreto, vamos a emplear el procedimiento uswtime listado a continuación. 

Este procedimiento en realidad invoca a dos funciones de Unix: getrusage y gettimeofday. La primera de ellas nos proporciona el tiempo de CPU, tanto de usuario como de sistema, mientras que la segunda nos proporciona el tiempo real (wall time). Estas dos funciones son las que disponen de mayor resolución de todos los temporizadores disponibles en Unix.
 
Modo de Empleo:
 
La función uswtime se puede emplear para medir los tiempos de ejecución de determinados segmentos de código en nuestros programas. De forma esquemática, el empleo de esta función constaría de los siguientes pasos:

    1.- Invocar a uswtime para fijar el instante a partir del cual se va a medir el tiempo.

            uswtime(&utime0, &stime0, &wtime0);

    2.- Ejecutar el código cuyo tiempo de ejecución se desea medir.
    3.- Invocar a uswtime para establecer el instante en el cual finaliza la medición
        del tiempo de ejecución.

            uswtime(&utime1, &stime1, &wtime1);

    4.- Calcular los tiempos de ejecución como la diferencia entre la primera y segunda
        invocación a uswtime:

            real:   wtime1 - wtime0
            user:   utime1 - utime0
            sys :   stime1 - stime0

            El porcentaje de tiempo dedicado a la ejecución de ese segmento de código
            vendría dado por la relación CPU/Wall:

    CPU/Wall = (user + sys) / real x 100 %*/
