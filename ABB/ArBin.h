typedef struct ArBNodo{
	struct ArBNodo* izq;
	Elem raiz;
	struct ArBNodo* der;
}*ArBin; //Definimos la estructa como ArBin y señalamos los nodos de enlace 

ArBin vacio(){return NULL;}  // Generamos un Arreglo vacio

ArBin consa(Elem r, ArBin iz, ArBin de){ //Ingresa nuestro dato Elem como raiz entre los arreglos izquierdos y derechos
	ArBin t = (ArBin)malloc(sizeof(struct ArBNodo));
	t->raiz = r;
	t->izq = iz;
	t->der = de;
	return t;
}

int esvacio(ArBin a){return a == vacio();} //Devolvemos el resultado Booleano de si es vacio

Elem raiz(ArBin a){return a->raiz;}  //Se obtiene el elemento raiz del arreglo

ArBin izquierdo(ArBin a){return a->izq;}  //Devuelve el elemento que se encuentra a la izquierda de la raiz

ArBin derecho(ArBin a){return a->der;}  //Devuelve el elemento que se encuentra a la derecha de la raiz

void InOrd(ArBin a){  //Imprime en orden los datos del arreglo 
	if(!esvacio(a)){
		InOrd(izquierdo(a));
		ImpElem(raiz(a));
		InOrd(derecho(a));
	}
}
