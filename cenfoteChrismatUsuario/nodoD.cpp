#include "nodoD.h"

nodoD::nodoD()
{
	this->dato = 0;
	this->sgte = NULL;
	this->ante = NULL;
}

nodoD::nodoD(int x)
{
	setDato(x);
	setSgte(NULL);
	setAnte(NULL);
}

nodoD::~nodoD()
{
}

int nodoD::getDato()
{
	return this->dato;
}

nodoD* nodoD::getSgte()
{
	return this->sgte;
}

nodoD* nodoD::getAnte()
{
	return  this->ante;
}

void nodoD::setDato(int dato)
{
	this->dato = dato;
}

void nodoD::setSgte(nodoD* ptr)
{
	this->sgte = ptr;
}

void nodoD::setAnte(nodoD* ptr)
{
	this->ante = ptr;
}

