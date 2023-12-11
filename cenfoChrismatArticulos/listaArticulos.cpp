#include "listaArticulos.h"
#include "nodoS.h";

// Constructor
listaArticulos::listaArticulos() {
    primerArticulos = nullptr;
    cantidadArticulos = 0;
}

// Destructor
listaArticulos::~listaArticulos() {
    nodoS* temp = primerArticulos;
    while (temp != nullptr) {
        nodoS* siguiente = temp->getSgte(); // Guarda el siguiente nodo antes de eliminar el actual
        delete temp; // Elimina el nodo actual
        temp = siguiente; // Avanza al siguiente nodo
    }
    primerArticulos = nullptr; // Aseg�rate de marcar la lista como vac�a
    cantidadArticulos = 0; // Reinicia la cantidad de art�culos a cero
}

// M�todos para la gesti�n de art�culos
void listaArticulos::registrarArticulo(int codigo, string nombre, float precio, int cantidad, string categoria) {
    nodoS* nuevoArticulo = new nodoS(codigo, nombre, precio, cantidad, categoria); // Crear el nuevo nodo con los datos

    if (primerArticulos == nullptr) { // Si la lista est� vac�a, el nuevo art�culo es el primer art�culo
        primerArticulos = nuevoArticulo;
    }
    else {
        nodoS* temp = primerArticulos;
        while (temp->getSgte() != nullptr) { // Encontrar el �ltimo art�culo en la lista
            temp = temp->getSgte();
        }
        temp->setSgte(nuevoArticulo); // Agregar el nuevo art�culo al final de la lista
    }

    cantidadArticulos++; // Aumentar la cantidad total de art�culos
}

bool listaArticulos::removerArticulo(int codigo) {
    if (primerArticulos == nullptr) { // Si la lista est� vac�a, no hay nada que remover
        return false;
    }

    nodoS* temp = primerArticulos;
    nodoS* anterior = nullptr;

    while (temp != nullptr && temp->getCodigo() != codigo) {
        anterior = temp;
        temp = temp->getSgte();
    }

    if (temp == nullptr) { // Si el art�culo no se encontr� en la lista
        return false;
    }

    if (anterior == nullptr) { // Si el art�culo a eliminar es el primer art�culo en la lista
        primerArticulos = temp->getSgte();
    }
    else {
        anterior->setSgte(temp->getSgte());
    }

    delete temp; // Liberar memoria del nodo a eliminar
    cantidadArticulos--; // Reducir la cantidad de art�culos
    return true;
}

bool listaArticulos::modificarArticulo(int codigo, string nombre, float precio, int cantidad) {
    nodoS* temp = primerArticulos;

    while (temp != nullptr && temp->getCodigo() != codigo) {
        temp = temp->getSgte();
    }

    if (temp == nullptr) { // Si el art�culo no se encuentra en la lista
        return false;
    }

    // Modificar los atributos del art�culo con el c�digo dado
    temp->setNombre(nombre);
    temp->setPrecio(precio);
    temp->setCantidadDisponible(cantidad);

    return true;
}

bool listaArticulos::comprarArticulo(int codigo, int cantidad) {
    nodoS* temp = primerArticulos;

    while (temp != nullptr && temp->getCodigo() != codigo) {
        temp = temp->getSgte();
    }

    if (temp == nullptr) { // Si el art�culo no se encuentra en la lista
        return false;
    }

    int cantidadDisponible = temp->getCantidadDisponible();
    if (cantidad > cantidadDisponible) { // Verifica si hay suficiente stock para la compra
        return false;
    }

    // Actualiza la cantidad disponible despu�s de la compra
    temp->setCantidadDisponible(cantidadDisponible - cantidad);
    return true;
}

void listaArticulos::ingresarInventario(int codigo, int cantidad) {
    nodoS* temp = primerArticulos;

    while (temp != nullptr && temp->getCodigo() != codigo) {
        temp = temp->getSgte();
    }

    if (temp != nullptr) { // Si el art�culo se encuentra en la lista
        int cantidadActual = temp->getCantidadDisponible();
        temp->setCantidadDisponible(cantidadActual + cantidad); // Aumenta la cantidad disponible
    }
}

// M�todos para consultas
void listaArticulos::mostrarListaArticulos() {
    nodoS* temp = primerArticulos;

    cout << "Lista de Articulos:" << endl;
    while (temp != nullptr) {
        // Muestra los detalles del art�culo
        cout << "Codigo: " << temp->getCodigo() << ", Nombre: " << temp->getNombre()
            << ", Precio: " << temp->getPrecio() << ", Cantidad Disponible: " << temp->getCantidadDisponible() << ", Categoria: " << temp->getCategoria() << endl;

        temp = temp->getSgte();
    }
}

void listaArticulos::mostrarArticulosCategoria(string categoria) {
    nodoS* temp = primerArticulos;
    bool encontrado = false;

    cout << "Articulos en la categoria " << categoria << ":" << endl;

    while (temp != nullptr) {
        // Aqu� asumimos que cada art�culo tiene una categor�a asociada para comparar con la categor�a proporcionada como argumento
        if (temp->getCategoria() == categoria) {
            cout << "C�digo: " << temp->getCodigo() << ", Nombre: " << temp->getNombre()
                << ", Precio: " << temp->getPrecio() << ", Cantidad Disponible: " << temp->getCantidadDisponible() << endl;

            encontrado = true;
        }
        temp = temp->getSgte();
    }

    if (!encontrado) {
        cout << "No se encontraron art�culos en la categoria " << categoria << endl;
    }
}

void listaArticulos::mostrarArticulosLimiteCantidad(int limite) {
    nodoS* temp = primerArticulos;
    bool encontrado = false;

    cout << "Articulos con cantidad disponible menor o igual a " << limite << ":" << endl;

    while (temp != nullptr) {
        // Muestra los detalles de los art�culos cuya cantidad disponible es menor o igual al l�mite
        if (temp->getCantidadDisponible() <= limite) {
            cout << "C�digo: " << temp->getCodigo() << ", Nombre: " << temp->getNombre()
                << ", Precio: " << temp->getPrecio() << ", Cantidad Disponible: " << temp->getCantidadDisponible() << endl;

            encontrado = true;
        }
        temp = temp->getSgte();
    }

    if (!encontrado) {
        cout << "No se encontraron art�culos con cantidad disponible menor o igual a " << limite << endl;
    }
}

void listaArticulos::cambiarPrecioArticulos(float porcentaje) {
    nodoS* temp = primerArticulos;

    cout << "Aplicando cambio de precio en un " << porcentaje << "% a todos los art�culos:" << endl;

    while (temp != nullptr) {
        // Calcula el nuevo precio aumentando o disminuyendo el porcentaje del precio actual
        float precioActual = temp->getPrecio();
        float nuevoPrecio = precioActual * (1 + (porcentaje / 100));

        // Asigna el nuevo precio al art�culo
        temp->setPrecio(nuevoPrecio);

        // Muestra los detalles del art�culo con el nuevo precio
        cout << "C�digo: " << temp->getCodigo() << ", Nombre: " << temp->getNombre()
            << ", Nuevo Precio: " << temp->getPrecio() << endl;

        temp = temp->getSgte();
    }
}

void listaArticulos::mostrarArticulosPorNombre(string nombre) {
    nodoS* temp = primerArticulos;
    bool encontrado = false;

    cout << "Articulos con nombre que coincide con '" << nombre << "':" << endl;

    while (temp != nullptr) {
        // Muestra los detalles de los art�culos cuyo nombre coincide con el proporcionado
        if (temp->getNombre() == nombre) {
            cout << "C�digo: " << temp->getCodigo() << ", Nombre: " << temp->getNombre()
                << ", Precio: " << temp->getPrecio() << ", Cantidad Disponible: " << temp->getCantidadDisponible() << endl;

            encontrado = true;
        }
        temp = temp->getSgte();
    }

    if (!encontrado) {
        cout << "No se encontraron art�culos con nombre que coincide con '" << nombre << "'" << endl;
    }
}
