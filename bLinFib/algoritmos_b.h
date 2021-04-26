#include <stdio.h>
#include <pthread.h>

#ifndef LINEAL_H
#define LINEAL_H

#define TAM_MAX_ARR 10000000            //Tamaño maximo de nuestros datos
#define TAM_MAX_ARR_BUSQUEDA 20

/*DECLARACION DE FUNCIONES*/
int blineal(int [], int, int);      //Funcion de busqueda lineal
int bfibonacci(int [], int, int);   //Funcion de busqueda fibonacci

//void crear_hilos(int, pthread_t [], struct parametros [], int);
//void ejecutar_hilos(int, pthread_t [], int);

int min(int x, int y);              //Funcion que regresa el minimo

#endif