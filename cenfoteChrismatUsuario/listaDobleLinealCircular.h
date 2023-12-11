#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "nodoD.h"


class listaDobleLinealCircular
{
private:
	nodoD* cab;
	int largo;


public:
	listaDobleLinealCircular();
	~listaDobleLinealCircular();

	nodoD* getCab(); //igual a lista simple ILS
	int getLargo(); //ILS

	void setCab(nodoD*);// igual a lista simple
	void setLargo(int);// igual a lista simple

	//Utilitarios
	bool esVacia(); //Igual a lista Simple
	nodoD* dirNodo(int); //ILS
	nodoD* dirUltimo();//ILS
	nodoD* dirAnterior(int);

	void agregarInicio(int);
	void agregarFinal(int);
	bool agregarAntesDe(int, int);
	bool agregarDespuesDe(int, int);
	bool agregarOrdenadoAscendente(int pnum);

	bool agregarAscendente(int);
	bool agregarDescendente(int);

	bool eliminar(int);
	void eliminarTodos(); //igual a lista simple
	void desplegar(); //ILS

	nodoD* dirPosicion(int i); //Dirección del nodo que se encuentra en la posicion i de la lista
	int datoPosicion(int i); //Devuelve el dato en la posición i
	bool agregarPosIndice(int x, int i); // Agregar x en la posicion i de la ista
	bool eliminarPosIndice(int i); //Eliminar el nodo de la posicion i
};


