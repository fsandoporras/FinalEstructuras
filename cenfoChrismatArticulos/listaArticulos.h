#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "nodoS.h"

class listaArticulos {
private:
    nodoS* primerArticulos; // Apunta al primer nodo de la lista
    int cantidadArticulos; // Cantidad total de artículos en la lista

public:
    listaArticulos();
    ~listaArticulos();

    // Métodos para la gestión de artículos
    void registrarArticulo(int codigo, string nombre, float precio, int cantidad, string categoria);
    bool removerArticulo(int codigo);
    bool modificarArticulo(int codigo, string nombre, float precio, int cantidad);
    bool comprarArticulo(int codigo, int cantidad);
    void ingresarInventario(int codigo, int cantidad);

    // Métodos para consultas
    void mostrarListaArticulos();
    void mostrarArticulosCategoria(string categoria);
    void mostrarArticulosLimiteCantidad(int limite);
    void cambiarPrecioArticulos(float porcentaje);
    void mostrarArticulosPorNombre(string nombre);
};

