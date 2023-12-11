#include "nodoS.h"

nodoS::nodoS()
{
	this->dato = 0;
	this->sgte = NULL;
	this->ante = NULL;
}

nodoS::nodoS(int x)
{
	setDato(x);
	setSgte(NULL);
	setAnte(NULL);
}

nodoS::~nodoS()
{
}

int nodoS::getDato()
{
	return this->dato;
}

nodoS* nodoS::getSgte()
{
	return this->sgte;
}

nodoS* nodoS::getAnte()
{
	return this->ante;
}

void nodoS::setDato(int dato)
{
	this->dato = dato;
}

void nodoS::setSgte(nodoS* ptr)
{
	this->sgte = ptr;
}

void nodoS::setAnte(nodoS* ptr)
{
	this->ante = ptr;
}
