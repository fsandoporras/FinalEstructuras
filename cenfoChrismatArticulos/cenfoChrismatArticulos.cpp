#include <stdlib.h>
using namespace std;
#include <iostream>

#include "listaArticulos.h"
//#include "listaUsuarios.h"
//#include "listaCategorias.h"

void menuPrincipal() {
    int opcion = -1;
   // listaUsuarios* usuarios = new listaUsuarios(); 
   // listaCategorias* categorias = new listaCategorias();
    listaArticulos*  articulos = new listaArticulos(); 

    while (opcion != 0) {
        cout << "---- Menu Principal ----" << endl;
        cout << "(1) Gestionar Usuarios" << endl;
        cout << "(2) Gestionar Categorias" << endl;
        cout << "(3) Gestionar Articulos" << endl;
        cout << "(0) Salir" << endl;
        cout << "------------------------" << endl;
        cout << "Ingrese la opción deseada: ";
        cin >> opcion;
        cout << "------------------------" << endl;

        switch (opcion) {
        case 1:
           // menuUsuarios(usuarios);
            break;
        case 2:
           // menuCategorias(categorias);
            break;
        case 3:
            menuArticulos(articulos);
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
        }
    }

    //delete usuarios;
    //delete categorias;
    delete articulos;
}

void menuUsuarios(/*listaUsuarios* usuarios*/) {
    
    int opcion = -1;

    while (opcion != 0) {
        cout << "---- Menu de usuarios ----" << endl;
        cout << "(1) Registrar usuario" << endl;
        cout << "(2) Remover usuario" << endl;
        cout << "(3) Modificar usuario" << endl;
        cout << "(4) Consultar usuario" << endl;
        cout << "(5) Listar usuarios" << endl;
        cout << "(0) Volver al menu principal" << endl;
        cout << "------------------------------" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;
        cout << "------------------------------" << endl;

        int cedula, telefono;
        string nombre, apellido, correo;

        switch (opcion) {
        case 1:
            cout << "Ingrese la cedula del usuario: ";
            cin >> cedula;
            cout << "Ingrese el nombre del usuario: ";
            cin >> nombre;
            cout << "Ingrese el apellido del usuario: ";
            cin >> apellido;
            cout << "Ingrese el correo electronico del usuario: ";
            cin >> correo;
            cout << "Ingrese el numero de telefono del usuario: ";
            cin >> telefono;
            usuarios->registrarUsuario(cedula, nombre, apellido, correo, telefono);
            break;
        case 2:
            cout << "Ingrese la cedula del usuario a remover: ";
            cin >> cedula;
            usuarios->removerUsuario(cedula);
            break;
        case 3:
            cout << "Ingrese la cedula del usuario a modificar: ";
            cin >> cedula;
            cout << "Ingrese el nuevo nombre del usuario: ";
            cin >> nombre;
            cout << "Ingrese el nuevo apellido del usuario: ";
            cin >> apellido;
            cout << "Ingrese el nuevo correo electronico del usuario: ";
            cin >> correo;
            cout << "Ingrese el nuevo numero de telefono del usuario: ";
            cin >> telefono;
            usuarios->modificarUsuario(cedula, nombre, apellido, correo, telefono);
            break;
        case 4:
            cout << "Ingrese la cedula del usuario a consultar: ";
            cin >> cedula;
            usuarios->consultarUsuario(cedula);
            break;
        case 5:
            usuarios->listarUsuarios();
            break;
        case 0:
            cout << "Volviendo al Menú Principal..." << endl;
            menuPrincipal();
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
        }
    }
}

void menuCategorias(/*listaCategorias* categorias*/) {
    int opcion = -1;

    while (opcion != 0) {
        cout << "---- Menu de Categorías ----" << endl;
        cout << "(1) Registrar Categoría" << endl;
        cout << "(2) Remover Categoría" << endl;
        cout << "(3) Modificar Categoría" << endl;
        cout << "(4) Consultar Categoría" << endl;
        cout << "(5) Listar Categorías" << endl;
        cout << "(0) Volver al Menú Principal" << endl;
        cout << "------------------------" << endl;
        cout << "Ingrese la opción deseada: ";
        cin >> opcion;
        cout << "------------------------" << endl;

        string nombre;

        switch (opcion) {
        case 1:
            cout << "Ingrese el nombre de la categoría: ";
            cin >> nombre;
            categorias->registrarCategoria(nombre);
            break;
        case 2:
            cout << "Ingrese el nombre de la categoría a remover: ";
            cin >> nombre;
            categorias->removerCategoria(nombre);
            break;
        case 3:
            cout << "Ingrese el nombre de la categoría a modificar: ";
            cin >> nombre;
            cout << "Ingrese el nuevo nombre de la categoría: ";
            cin >> nombre;
            categorias->modificarCategoria(nombre);
            break;
        case 4:
            cout << "Ingrese el nombre de la categoría a consultar: ";
            cin >> nombre;
            categorias->consultarCategoria(nombre);
            break;
        case 5:
            cout << "---- Lista de Categorías ----" << endl;
            categorias->listarCategorias();
            cout << "--------------------------" << endl;
            break;
        case 0:
            cout << "Volviendo al Menú Principal..." << endl;
            menuPrincipal();
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
        }
    }
}

void menuArticulos(listaArticulos* articulos) {

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
        cout << "(0) Volver al menu principal" << endl;
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
            articulos->registrarArticulo(codigo, nombre, precio, cantidad, categoria);
            break;
        case 2:
            cout << "Ingrese el codigo del articulo a remover: ";
            cin >> codigo;
            articulos->removerArticulo(codigo);
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
            articulos->modificarArticulo(codigo, nombre, precio, cantidad);
            break;
        case 4:
            cout << "Ingrese el codigo del articulo a comprar: ";
            cin >> codigo;
            cout << "Ingrese la cantidad a comprar: ";
            cin >> cantidad;
            articulos->comprarArticulo(codigo, cantidad);
            break;
        case 5:
            cout << "Ingrese el codigo del articulo a ingresar al inventario: ";
            cin >> codigo;
            cout << "Ingrese la cantidad a ingresar al inventario: ";
            cin >> cantidad;
            articulos->ingresarInventario(codigo, cantidad);
            break;
        case 6:
            articulos->mostrarListaArticulos();
            break;
        case 7:
            cout << "Ingrese la categoria a mostrar: ";
            cin >> categoria;
            articulos->mostrarArticulosCategoria(categoria);
            break;
        case 8:
            cout << "Ingrese el límite de cantidad para mostrar los articulos: ";
            cin >> limite;
            articulos->mostrarArticulosLimiteCantidad(limite);
            break;
        case 9:
            cout << "Ingrese el porcentaje de cambio de precio: ";
            cin >> porcentaje;
            articulos->cambiarPrecioArticulos(porcentaje);
            break;
        case 10:
            cout << "Ingrese el nombre del articulo a buscar: ";
            cin >> nombre;
            articulos->mostrarArticulosPorNombre(nombre);
            break;
        case 0:
            cout << "Volviendo al Menú Principal..." << endl;
            menuPrincipal();
            break;
        default:
            cout << "opcion no válida." << endl;
            break;
        }
    }
}

int main()
{
    menuPrincipal();

    return 0;

}

