#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "nodoS.h"

class listaSimple
{
private:
	nodoS* cab;// PUNTERO al primer nodo de la lista
	int largo;//cantidad de elementos que tiene la lista

public:
	listaSimple(); // constructor de la lista
	~listaSimple();// destructor

	nodoS *getCab();
	int getLargo();

	void setCab(nodoS *);
	void setLargo(int);

	// UTILITARIOS

	nodoS* dirNodo(int);
	nodoS* dirAnterior(int);
	nodoS* dirULtimo();

	bool esVacia();

	void desplegar();
	void agregarInicio(int);
	bool agregarAntesDe(int, int);
	void agregarFinal(int);
	bool agregarDespuesDe(int, int);
	bool agregarAscendente(int);
	bool agregarOrdenadoDescendiente(int);
	
	int cantpares();

	//comentamos estos ultimos dos metodos por si se usan despues

    bool elimnar(int);

	void eliminarTodo();
	void eliminarTodo(int dato); 

};

