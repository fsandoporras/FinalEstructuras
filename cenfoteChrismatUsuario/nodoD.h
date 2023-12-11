#pragma once
#include <iostream>
#include <stdlib.h>

class nodoD
{
private:
	int dato;
	nodoD* sgte;
	nodoD* ante;
public:
	nodoD();//constructor 
	nodoD(int);// constructor sobrecargado
	~nodoD(); //destructor
	

	//gets y sets:

	int getDato();
	nodoD* getSgte();
	nodoD* getAnte();
	
	void setDato(int);
	void setSgte(nodoD *);
	void setAnte(nodoD *);

};



