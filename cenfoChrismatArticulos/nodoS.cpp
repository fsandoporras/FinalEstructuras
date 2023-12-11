#include "nodoS.h"

// Constructor
nodoS::nodoS(int cod, string nom, float prec, int cant, string cat) {
    codigo = cod;
    nombre = nom;
    precio = prec;
    cantidadDisponible = cant;
    categoria = cat;
    sgte = nullptr;
}

// Getters y setters
int nodoS::getCodigo() {
    return codigo;
}

void nodoS::setCodigo(int cod) {
    codigo = cod;
}

string nodoS::getNombre() {
    return nombre;
}

void nodoS::setNombre(string nom) {
    nombre = nom;
}

float nodoS::getPrecio() {
    return precio;
}

void nodoS::setPrecio(float prec) {
    precio = prec;
}

int nodoS::getCantidadDisponible() {
    return cantidadDisponible;
}

void nodoS::setCantidadDisponible(int cant) {
    cantidadDisponible = cant;
}

string nodoS::getCategoria() {
    return categoria;
}

void nodoS::setCategoria(string cat) {
    categoria = cat;
}

nodoS* nodoS::getSgte() {
    return sgte;
}

void nodoS::setSgte(nodoS* siguiente) {
    sgte = siguiente;
}