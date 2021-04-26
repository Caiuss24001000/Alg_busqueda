#include<stdlib.h>
#include<stdio.h>
#include <math.h>
#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

int Global_iter=0;

void get_Array(int n, int *array)
{
	int aux;
	FILE *archivo;
	archivo = fopen("numeros10millones.txt","r");
	for(int i=0;i<n;i++)
	{
		fscanf(archivo,"%d",&aux);
		//printf("%i\n",aux);
		array[i]=aux;
	}
	fclose(archivo);
}

void printArray(int n, int *array)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\n",array[i]);
	}
}

void Burbuja(int n, int *array)
{
	int aux,i,j;
	for(i=0;i<=(n-2);i++)
	{
		for(j=0;j<=((n-2)-i);j++)
		{
			if(array[j]>array[j+1])
			{
				aux=array[j];
				array[j]=array[j+1];
				array[j+1]=aux;
			}
		}
	}
}

void BurbujaOpt(int n, int *array)
{
	int cambios=1;//1=SI,0=NO
	int i=0;
	int aux,j;
	while(i<=n-2 && cambios!=0)
	{
		cambios=0;
		for(j=0;j<=((n-2)-i);j++)
		{
			if(array[j]<array[j+1])
			{
				aux=array[j];
				array[j]=array[j+1];
				array[j+1]=aux;
				cambios=1;
			}
		}
		i++;
	}
}

void Insercion(int n, int*array)
{
	int temp;
	int j,i;
	for(i=0;i<(n-1);i++)
	{
		j=i;
		temp=array[i];
		while(j>0 && temp<array[j-1])
		{
			array[j]=array[j-1];
			j--;
		}
		array[j]=temp;
	}
}

void Seleccion(int n, int *array)
{
	int temp,p,k,i;
	for(k=0;k<=(n-2);k++)
	{
		p=k;
		for(i=(k+1);i<(n-1);i++)
		{
			if(array[i]<array[p])
			{
				p=i;
			}
		}
		temp=array[p];
		array[p]=array[k];
		array[k]=temp;
	}
}

void Shell(int n, int *array)
{
	int k=n/2;
	int b,i,temp;
	while(k>=1)
	{
		b=1;
		while(b!=0)
		{
			b=0;
			for(i=k;i<=(n-1);i++)
			{
				if(array[i-k]>array[i])
				{
					temp=array[i];
					array[i]=array[i-k];
					array[i-k]=temp;
					b++;
				}
			}
		}
		k=k/2;
	}
}

struct nodo{
    int nro;
    struct nodo *izq, *der;
}tnodo;

typedef struct nodo *ABB;
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
   para mayor facilidad de creacion de variables */

void insertar(ABB *arbol, int x)
{
    if(*arbol==NULL)
    {
       	*arbol = malloc(sizeof(tnodo));
        (*arbol)->nro = x;
        (*arbol)->izq = NULL;
        (*arbol)->der = NULL;
    }
    else if(x <= (*arbol)->nro)
        insertar(&(*arbol)->izq, x);
    else if(x > (*arbol)->nro)
        insertar(&(*arbol)->der, x);
}

void enOrden(ABB arbol, int *array, int iter)
{
	//printf("%i\n",iter);
    if(arbol!=NULL)
    {
        enOrden(arbol->izq,array,iter);
        //printf("HERE:%d\n",arbol->nro);
        array[Global_iter]=arbol->nro;
        Global_iter++;
        enOrden(arbol->der,array,iter);

    }
}

void verArbol(ABB arbol, int n)
{
    if(arbol==NULL)
        return;
    verArbol(arbol->der, n+1);

    for(int i=0; i<n; i++)
     	printf("   ");

    printf("%i\n",arbol->nro );

    verArbol(arbol->izq, n+1);
}

void ArbolBinarioOrdena(int n, int *array)
{
	ABB arbol;
	arbol = NULL;
	for(int i=0;i<=(n-1);i++)
	{
		insertar(&arbol,array[i]);
		
	}
	verArbol( arbol, 0);
	enOrden(arbol,array,0);
}

/*struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}*/


//Algoritmos de busqueda
int BusquedaLineal(int nTam, int *array, int nBusq)
{
	for(int i=0;i<nTam;i++)
	{
		if(array[i]==nBusq)
		{
			return i;//Devolvemos el indice si encontramos el elemento 
		}
	}
	return -1;//El numero a buscar no esta en el arreglo
}

/*ABB BusquedaABB(ABB raiz, int nBusq)
{
	if(raiz==NULL || raiz->nro==nBusq)
	{
		return raiz;
	}
	if(raiz->nro < nBusq)
	{
		return BusquedaABB(raiz->der, nBusq);
	}
	return BusquedaABB(raiz->izq, nBusq);
}*/

int BusquedaABB(ABB raiz, int nBusq)
{
	while(raiz!=NULL)
	{
		if(raiz->nro==nBusq)
		{
			return raiz->nro;
		}
		if(raiz->nro < nBusq)
		{
			raiz = raiz->der;
		}
		else
			raiz = raiz->izq;
	}
	return -1;
}

int ArbolBinarioBusqueda(int n, int *array, int nBusq)
{
	//Bibliografia: https://users.dcc.uchile.cl/~lmateu/CC10A/Apuntes/arboles/index.html
	ABB arbol;
	arbol = NULL;
	for(int i=0;i<=(n-1);i++)
	{
		insertar(&arbol,array[i]);
		
	}
	//verArbol( arbol, 0);
	//enOrden(arbol,array,0);
	/*ABB recorrido;
	recorrido = NULL;
	recorrido = BusquedaABB(arbol, nBusq);*/
	//printf("ABB\n");
	//verArbol(recorrido, 0);
	int resultado = BusquedaABB(arbol,nBusq);
	return resultado;
}

int BusquedaBinaria(int n, int *array, int nBusq)
{
	//Bibliografía https://runestone.academy/runestone/static/pythoned/SortSearch/LaBusquedaBinaria.html
	int encontrado = -1;
	int i=0;
	int puntoMedio;
	while(i<n && encontrado==-1)
	{
		puntoMedio = (i+n)/2;
		if(array[puntoMedio]==nBusq)
		{
			encontrado = puntoMedio;
		}
		else
		{
			if(nBusq < array[puntoMedio])
			{
				n=puntoMedio;
			}
			else
			{
				i=puntoMedio;
			}
		}
	}
	return encontrado;
}

int BusquedaBinaria4Exponencial(int iGet, int *array, int n, int nBusq)
{
	//Bibliografía https://runestone.academy/runestone/static/pythoned/SortSearch/LaBusquedaBinaria.html
	int encontrado = -1;
	int i=iGet;
	int puntoMedio;
	while(i<n && encontrado==-1)
	{
		puntoMedio = (i+n)/2;
		if(array[puntoMedio]==nBusq)
		{
			encontrado = puntoMedio;
		}
		else
		{
			if(nBusq < array[puntoMedio])
			{
				n=puntoMedio;
			}
			else
			{
				i=puntoMedio;
			}
		}
	}
	return encontrado;
}

int BusquedaExponencial(int n, int *array, int nBusq)
{
	if(array[0]==nBusq)
	{
		return 0;
	}
	int i=1;
	while(i<n && array[i]<=nBusq)
	{
		i=i*2;
	}
	return BusquedaBinaria4Exponencial(i/2,array,min(i,n-1),nBusq);
}


int BusquedaFibonacci(int n, int *array, int nBusq)
{
    /* Initialize fibonacci numbers */
    int fibMMm2 = 0; // (m-2)'th Fibonacci No.
    int fibMMm1 = 1; // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci
 
    /* fibM is going to store the smallest Fibonacci
       Number greater than or equal to n */
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
 
    // Marks the eliminated range from front
    int offset = -1;
 
    /* while there are elements to be inspected. Note that
       we compare arr[fibMm2] with x. When fibM becomes 1,
       fibMm2 becomes 0 */
    while (fibM > 1) {
        // Check if fibMm2 is a valid location
        int i = min(offset + fibMMm2, n - 1);
 
        /* If x is greater than the value at index fibMm2,
           cut the subarray array from offset to i */
        if (array[i] < nBusq) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
 
        /* If x is greater than the value at index fibMm2,
           cut the subarray after i+1  */
        else if (array[i] > nBusq) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
 
        /* element found. return index */
        else
            return i;
    }
 
    /* comparing the last element with x */
    if (fibMMm1 && array[offset + 1] == nBusq)
        return offset + 1;
 
    /*element not found. return -1 */
    return -1;
}

void main()
{
	int n=20;
	int array[n];
	int indice = 0;
	printf("Obtenemos el array del archivo para las pruebas!!!\n");
	get_Array(n,array);
	//Burbuja(n,array);
	printArray(n,array);
	

	printf("\n\nBusqueda Lineal\n");
	indice = BusquedaLineal(n,array,187130533);
	printf("Elemento encontrado en el indice: %d\n",indice);
	indice = BusquedaLineal(n,array,24);
	printf("Elemento NO encontrado: %d\n",indice);

	printf("\n\nArbol Binario de Busqueda\n");
	int ArbolBinario = ArbolBinarioBusqueda(n,array,187130533);
	printf("Elemento encontrado:%d\n",ArbolBinario);
	//verArbol(ArbolBinario,0);
	ArbolBinario = ArbolBinarioBusqueda(n,array,24);
	printf("Elemento NO encontrado:%d\n",ArbolBinario);

	printf("\n\nOrdenamos el array como se requiere en los siguientes algoritmos!!!\n");
	Burbuja(n,array);
	printArray(n,array);

	printf("\n\nBusqueda Binaria\n");
	int BusquedaBin = BusquedaBinaria(n,array,187130533);
	printf("Elemento encontrado:%d\n",BusquedaBin);
	BusquedaBin = BusquedaBinaria(n,array,24);
	printf("Elemento NO encontrado:%d\n",BusquedaBin);

	printf("\n\nBusqueda Exponencial\n");
	int BusquedaExp = BusquedaExponencial(n,array,187130533);
	printf("Elemento encontrado:%d\n",BusquedaExp);
	BusquedaExp = BusquedaExponencial(n,array,24);
	printf("Elemento NO encontrado:%d\n",BusquedaExp);

	printf("\n\nBusqueda de Fibonacci\n");
	int BusquedaFib = BusquedaFibonacci(n,array,187130533);
	printf("Elemento encontrado:%d\n",BusquedaFib);
	BusquedaFib = BusquedaFibonacci(n,array,24);
	printf("Elemento NO encontrado:%d\n",BusquedaFib);
	//verArbol(ArbolBinario,0);	
	/*get_Array(n,array);
	BurbujaOpt(n,array);
	printArray(n,array);
	get_Array(n,array);
	Insercion(n,array);
	printArray(n,array);
	get_Array(n,array);
	Seleccion(n,array);
	printArray(n,array);
	get_Array(n,array);
	Shell(n,array);
	printArray(n,array);
	get_Array(n,array);
	ArbolBinarioOrdena(n,array);
	printArray(n,array);*/
	//int trunk = 5/3;
	//printf("%i\n", trunk);
}