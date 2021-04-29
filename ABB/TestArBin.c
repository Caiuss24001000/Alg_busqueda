#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "DicBin.h"
#include "general.h"

int Buscar(ArBin a, int buscado)
{
    if(esvacio(a))
        return 0;
    else if(raiz(a)==buscado)
    {
        return 1;
    }
    else if(raiz(a)<buscado)
    {
        return Buscar(derecho(a),buscado);
    }
    else if(raiz(a)>buscado)
        return Buscar(izquierdo(a),buscado);
}


int main(int argc, char const *argv[]){
    double utime1,stime1,wtime1,utime0,stime0,wtime0,t_real;
    int i,b,num,s,si=0,no=0,f,a[]={322486,14700764,3128036,6337399,61396,10393545,2147445644,1295390003,450057883,187645041,1980098116,152503,5000,1493283650,214826,1843349527,1360839354,2109248666,2147470852,0},r=0;
//  printf("ingrese el numero de prueba:  ");
if (argc != 4) 
        {
            printf("Indique el tam del arreglo, el dato a buscar y los hilos que usara - \tEjemplo: [user@equipo]$ %s 10000000 12010 4\n\n",argv[0]);
            exit(-1);
        }

        b = atoi(argv[1]);
        num = atoi(argv[2]);
        s = atoi(argv[3]); 
//  clock_t t= clock(); 
    ArBin h = vacio();//Declaramos e inicializamos nuestro Arbol vacio
    h=Orden(h,b);
//  printf("lleno\n");
//  for(r;r<20;r++){
//  num=a[r];
    uswtime(&utime0, &stime0, &wtime0); // Inicio 
    f=Buscar(h,num);
    uswtime(&utime1, &stime1, &wtime1); // Fin
    if(f==1)
        si=1;   
//  t=clock()-t;
//  double timeR_taken=((double)t)/CLOCKS_PER_SEC;
    t_real = wtime1 - wtime0;
    printf("\n");
    printf("real (Tiempo total)  %.10e s\n", t_real);
    printf("\n");
    printf("Numero:%d    %d",num,si);
    //printf("\nvalor de tiempo real:  %f\n",timeR_taken);  
//  InOrd(h);
    return 0;
}