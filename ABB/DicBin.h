#include "ArBin.h" //LLamamos nuestro archivo con funciones ArBin.h
#include <string.h>
#include <time.h>
#include <sys/time.h>
typedef ArBin DicBin; //Definimos el tipo de dato DicBin como un ArBin

DicBin InsOrd(Elem e, DicBin a){//Creamos nuestra función InsOrd que recibe un Elem y un DicBin y regresamos un DicBin
	if(esvacio(a)) 
		return consa(e, vacio(), vacio()); //nos aseguramos que si es vacio el arreglo ingresaremos el nuevo dato y lo regresaremos 
	else{ 
		if(esmenor(e, raiz(a)))
			return consa(raiz(a), InsOrd(e, izquierdo(a)), derecho(a)); //Si no es vacio nos aseguraremos si es menor agregamos el nuevo a la izquierda y acomodamos el resto
		else{
            if(esmayor(e, raiz(a)))
            return consa(raiz(a), izquierdo(a), InsOrd(e, derecho(a))); //Si no es vacio y es mayor lo agregamos en la derecha y regresamos el arreglo
		}
	}
}

DicBin Orden(DicBin a,int e){
    int x,b,m;
    b=e;
	char nom[]="10millones.txt",r[15];
	FILE *archivo;
	archivo=fopen(nom,"r");
	printf("\ninicia la secuencia:  \n\n");
	clock_t t= clock();
		for(x=0;x<e;x++){
			fgets(r,15,archivo);
			if(feof(archivo))
				break;
			a=InsOrd(atoi(r),a);
		}
//	t=clock()-t;
//	double timeR_taken=((double)t)/CLOCKS_PER_SEC;
//	printf("\nValor de CPU:  %f",timeR_taken);	
	fclose(archivo);	
	return a;    
}
