#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class nodoS {
private:
    int codigo;
    string nombre;
    float precio;
    int cantidadDisponible;
    string categoria; // Nueva adici�n: atributo para la categor�a
    nodoS* sgte;

public:
    nodoS(int cod, string nom, float prec, int cant, string cat);

    // Getters y setters para los atributos
    int getCodigo();
    void setCodigo(int cod);

    string getNombre();
    void setNombre(string nom);

    float getPrecio();
    void setPrecio(float prec);

    int getCantidadDisponible();
    void setCantidadDisponible(int cant);

    string getCategoria(); // Getter para la categor�a
    void setCategoria(string cat); // Setter para la categor�a

    nodoS* getSgte();
    void setSgte(nodoS* siguiente);
};

