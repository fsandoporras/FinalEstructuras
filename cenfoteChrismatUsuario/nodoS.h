#pragma once
#include <iostream>
#include <stdlib.h>

class nodoS
{ 
private:
	int dato;
	nodoS* sgte;
	nodoS* ante;

public:
	nodoS();
	nodoS(int);
	~nodoS();

	int getDato();
	nodoS* getSgte();
	nodoS* getAnte();

	void setDato(int);
	void setSgte(nodoS *);
	void setAnte(nodoS *);
};

