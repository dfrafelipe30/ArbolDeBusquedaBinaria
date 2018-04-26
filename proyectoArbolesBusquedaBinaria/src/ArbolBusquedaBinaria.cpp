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
template <typename TipoDato>
ArbolBusquedaBinaria<TipoDato> :: ~ArbolBusquedaBinaria()
{
	eliminarDato(raiz);
}
template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::eliminarDato(ArbolBusquedaBinaria <TipoDato>::NodoABB *nodo)
{
	if(nodo != NULL)
	{
		eliminarDato(nodo -> izq);
		eliminarDato(nodo -> der);
		delete nodo;
	}
}

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
		nodo->izq = nodo->der =   NULL;
		nodo->padre = raiz;
	} else {
		if (dato != nodo->dato) {
			if (dato < nodo->dato) {
				raiz = nodo;
				insertarNodo(nodo->izq, dato);
			} else { 
				raiz = nodo;
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
template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::imprimirPreOrden(){
	imprimirPre(raiz);
}
template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::imprimirPre(ArbolBusquedaBinaria<TipoDato>::NodoABB *nodo){
	if (nodo != NULL) {
		std::cout << nodo->dato << std::endl;
		imprimirArbol(nodo->izq);
		imprimirArbol(nodo->der);
	}
}
template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::imprimirPostOrden(){
	imprimirPost(raiz);
}
template <typename TipoDato>
void ArbolBusquedaBinaria<TipoDato>::imprimirPost(ArbolBusquedaBinaria<TipoDato>::NodoABB *nodo){
	if (nodo != NULL) {
		imprimirArbol(nodo->izq);
		imprimirArbol(nodo->der);
		std::cout << nodo->dato << std::endl;
	}
}
template <typename TipoDato>
TipoDato ArbolBusquedaBinaria <TipoDato>::minimo()
{
	minimoRec(raiz);
}
template <typename TipoDato>
TipoDato ArbolBusquedaBinaria <TipoDato>::minimoRe(ArbolBusquedaBinaria<TipoDato>::NodoABB *nodo)
{
	if(nodo -> izq  == NULL and nodo != NULL)
	{
		return  nodo -> dato;
	}
	else{
		minimoRe(nodo -> izq);
	}
}
template <typename TipoDato>
TipoDato ArbolBusquedaBinaria <TipoDato>::maximo()
{
	maximoRe(raiz);
}
template <typename TipoDato>
TipoDato ArbolBusquedaBinaria <TipoDato>::maximoRe(ArbolBusquedaBinaria<TipoDato>::NodoABB *nodo)
{
	if(nodo-> der  == NULL and nodo != NULL)
	{
		return nodo -> dato;
	}
	else{
		maximoRe(nodo -> der);
	}
}
template <typename TipoDato>
TipoDato ArbolBusquedaBinaria <TipoDato>::predecesor(TipoDato dato)
{
	NodoABB * nuevaRaiz = buscarNodo(raiz,dato);
	return predecesorRe(nuevaRaiz,dato);
}
template <typename TipoDato>
TipoDato ArbolBusquedaBinaria <TipoDato>::predecesorRe(ArbolBusquedaBinaria<TipoDato>::NodoABB *nodo,TipoDato dato)
{
	if(nodo -> dato == minimoRe(raiz))
		return nodo -> dato;
	else if(nodo ->izq == NULL)
	{
		return nodo-> padre;
	}
	if(nodo -> izq != NULL )
	{
		maximoRe(nodo -> izq);
	}


}
#endif

