/*
 * ArbolBusquedaBinaria.cpp
 *
 */

#ifdef ARBOLBUSQUEDABINARIA_H_

#include<iostream>

template <typename TipoDato>
ArbolBusquedaBinaria<TipoDato>::ArbolBusquedaBinaria(){
	raiz = NULL;
}

template <typename TipoDato>
bool ArbolBusquedaBinaria<TipoDato>::buscar(TipoDato dato){
	return buscarNodo(raiz, dato) != NULL;
}
/*
 * Porque toca pasar por referencia el objeto en la lista.
 */

template <typename TipoDato>
typename ArbolBusquedaBinaria<TipoDato>::NodoABB * ArbolBusquedaBinaria<TipoDato>::buscarNodo(ArbolBusquedaBinaria<TipoDato>::NodoABB*nodo, TipoDato dato) {
		if (nodo == NULL) return NULL;
		if (dato == nodo->dato) return nodo;
		if (dato < nodo->dato) {
			return buscarNodo(nodo->izq, dato);
		} else {
			return buscarNodo(nodo->der, dato);
	}
}


template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::insertar(TipoDato dato){
	insertarNodo(raiz, dato);
}

template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::insertarNodo(ArbolBusquedaBinaria<TipoDato>::NodoABB * & nodo, TipoDato dato){
	if (nodo == NULL) {
		nodo = new NodoABB;
		nodo->dato = dato;
		nodo->izq = nodo->der = NULL;
	} else {
		if (dato != nodo->dato) {
			if (dato < nodo->dato) {
				insertarNodo(nodo->izq, dato);
			} else {
				insertarNodo(nodo->der, dato);
			}
		}
	}

}





template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::imprimir(){
	imprimirArbol(raiz);
}

template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::imprimirArbol(ArbolBusquedaBinaria<TipoDato>::NodoABB *nodo){
	if (nodo != NULL) {
		imprimirArbol(nodo->izq);
		std::cout << nodo->dato << std::endl;
		imprimirArbol(nodo->der);
	}
}

#endif
