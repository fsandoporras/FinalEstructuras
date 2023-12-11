// cenfoChrismatArticulos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "listaArticulos.h"

listaArticulos articulos;

void menuArticulos() {
    
    int opcion = -1;

    while (opcion != 0) {
        cout << "---- Menu de articulos ----" << endl;
        cout << "(1) Registrar articulo" << endl;
        cout << "(2) Remover articulo" << endl;
        cout << "(3) Modificar articulo" << endl;
        cout << "(4) Comprar articulo" << endl;
        cout << "(5) Ingresar Inventario" << endl;
        cout << "(6) Mostrar Lista de articulos" << endl;
        cout << "(7) Mostrar articulos por categoria" << endl;
        cout << "(8) Mostrar articulos con Cantidad Límite" << endl;
        cout << "(9) Cambiar Precio de articulos" << endl;
        cout << "(10) Mostrar articulos por Nombre" << endl;
        cout << "(0) Salir" << endl;
        cout << "------------------------------" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;
        cout << "------------------------------" << endl;

        int codigo, cantidad, limite;
        string nombre, categoria;
        float precio, porcentaje;

        switch (opcion) {
        case 1:
            cout << "Ingrese el codigo del articulo: ";
            cin >> codigo;
            cout << "Ingrese el nombre del articulo: ";
            cin >> nombre;
            cout << "Ingrese el precio del articulo: ";
            cin >> precio;
            cout << "Ingrese la cantidad del articulo: ";
            cin >> cantidad;
            cout << "Ingrese la categoria del articulo: ";
            cin >> categoria;
            articulos.registrarArticulo(codigo, nombre, precio, cantidad, categoria);
            break;
        case 2:
            cout << "Ingrese el codigo del articulo a remover: ";
            cin >> codigo;
            articulos.removerArticulo(codigo);
            break;
        case 3:
            cout << "Ingrese el codigo del articulo a modificar: ";
            cin >> codigo;
            cout << "Ingrese el nuevo nombre del articulo: ";
            cin >> nombre;
            cout << "Ingrese el nuevo precio del articulo: ";
            cin >> precio;
            cout << "Ingrese la nueva cantidad del articulo: ";
            cin >> cantidad;
            articulos.modificarArticulo(codigo, nombre, precio, cantidad);
            break;
        case 4:
            cout << "Ingrese el codigo del articulo a comprar: ";
            cin >> codigo;
            cout << "Ingrese la cantidad a comprar: ";
            cin >> cantidad;
            articulos.comprarArticulo(codigo, cantidad);
            break;
        case 5:
            cout << "Ingrese el codigo del articulo a ingresar al inventario: ";
            cin >> codigo;
            cout << "Ingrese la cantidad a ingresar al inventario: ";
            cin >> cantidad;
            articulos.ingresarInventario(codigo, cantidad);
            break;
        case 6:
            articulos.mostrarListaArticulos();
            break;
        case 7:
            cout << "Ingrese la categoria a mostrar: ";
            cin >> categoria;
            articulos.mostrarArticulosCategoria(categoria);
            break;
        case 8:
            cout << "Ingrese el límite de cantidad para mostrar los articulos: ";
            cin >> limite;
            articulos.mostrarArticulosLimiteCantidad(limite);
            break;
        case 9:
            cout << "Ingrese el porcentaje de cambio de precio: ";
            cin >> porcentaje;
            articulos.cambiarPrecioArticulos(porcentaje);
            break;
        case 10:
            cout << "Ingrese el nombre del articulo a buscar: ";
            cin >> nombre;
            articulos.mostrarArticulosPorNombre(nombre);
            break;
        case 0:
            cout << "Saliendo del programa...";
            break;
        default:
            cout << "opcion no válida." << endl;
            break;
        }
    }
}

int main()
{
    
    articulos.registrarArticulo(123456789, "Arbol de Navidad", 35.99, 50, "Decoracion");
    articulos.registrarArticulo(234567890, "Adornos de Luces LED", 12.49, 100, "Decoracion");
    articulos.registrarArticulo(345678901, "Papa Noel de Peluche", 19.99, 30, "Juguetes");
    articulos.registrarArticulo(456789012, "Gorro de Santa Claus", 7.99, 80, "Ropa");
    articulos.registrarArticulo(567890123, "Bastón de Caramelo Gigante", 3.49, 120, "Dulces");
    menuArticulos();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
