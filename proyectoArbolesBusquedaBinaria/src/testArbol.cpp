/*
 * testArbol.cpp
 */

#include"ArbolBusquedaBinaria.h"
#include<iostream>
using namespace std;

int main(){
	ArbolBusquedaBinaria<int> arbol;
	arbol.insertar(7);
	arbol.insertar(3);
	arbol.insertar(1);
	arbol.insertar(5);
	arbol.insertar(9);

	arbol.imprimir();
	return 0;
}


