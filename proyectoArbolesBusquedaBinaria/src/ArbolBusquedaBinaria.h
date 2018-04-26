/*
 * ArbolBusquedaBinaria.h
 *
 *  Created on: 20/04/2018
 *      Author: juanferna.perez
 */

#ifndef ARBOLBUSQUEDABINARIA_H_
#define ARBOLBUSQUEDABINARIA_H_

template <typename TipoDato>
class ArbolBusquedaBinaria {
public:
	/*
	* Tipo: Nodo de �rbol de B�squeda Binaria
	* ----------
	* Estructura para almacenar cada nodo del �rbol.
	*/

	struct NodoABB {
		TipoDato dato;
		NodoABB *izq;
		NodoABB *der;
		NodoABB *padre;
	};

	//Constructores
	ArbolBusquedaBinaria();

	ArbolBusquedaBinaria(TipoDato datoIni);

	~ArbolBusquedaBinaria();

	void eliminarDato(NodoABB *nodo);

	//M�todos p�blicos
	bool buscar(TipoDato dato);

	NodoABB* buscarNodo(NodoABB* nodo, TipoDato dato);


	TipoDato minimo();

	TipoDato maximo();

	TipoDato predecesor(TipoDato dato);

	TipoDato sucesor(TipoDato dato );

	TipoDato minimoRe(NodoABB * nodo);
	TipoDato maximoRe(NodoABB * nodo);
	TipoDato predecesorRe(NodoABB * nodo,TipoDato dato);

	void insertar(TipoDato dato);

	void insertarNodo(NodoABB * & nodo, TipoDato dato);

	void eliminar(TipoDato dato);

	void imprimir();

	void imprimirArbol(NodoABB * nodo);

	void imprimirPre(NodoABB * nodo);

	void imprimirPreOrden();

	void imprimirPostOrden();

	void imprimirPost(NodoABB * nodo);


private:
	/* Atributos */
	NodoABB *raiz; 	/* Apuntador al nodo ra�z del �rbol */
};



#endif /* ARBOLBUSQUEDABINARIA_H_ */

#include "ArbolBusquedaBinaria.cpp"
