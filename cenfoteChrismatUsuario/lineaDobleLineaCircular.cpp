#include "listaDobleLinealCircular.h";
#include "nodoD.h";


nodoD* listaDobleLinealCircular::dirAnterior(int x)
{
    nodoD* aux = dirNodo(x);
    if (aux == NULL)
        return NULL;
    else
        return aux->getAnte();

}



void listaDobleLinealCircular::agregarInicio(int x)
{
    nodoD* nuevo = new nodoD(x);//Paso 1. crear el nodo
    if (!esVacia()) {
        nuevo->setSgte(getCab());//Paso 2. Enlazar el nuevo nodo a lista
        getCab()->setAnte(nuevo);
    }
    //Paso 3 Reacomodar la lista con el nuevo nodo
    setCab(nuevo);
    setLargo(getLargo() + 1);
}

bool listaDobleLinealCircular::agregarAntesDe(int x, int ref)
{
    if (!esVacia())
        if (ref == getCab()->getDato()) {
            agregarInicio(x);
            return true;
        }
        else {
            nodoD* aux = dirNodo(ref);
            if (aux != NULL) { // que la ref existe en la lista
                nodoD* nuevo = new nodoD(x); //Paso 1: Crear el nodo
                nuevo->setSgte(aux); //Paso 2: Enlazar el nuevo nodo a la lista
                nuevo->setAnte(aux->getAnte());

                //Paso 3: Reacomodar la lista
                aux->getAnte()->setSgte(nuevo);
                aux->setAnte(nuevo);

                largo++;
                return true;
            }
        }
    return false;
}

listaDobleLinealCircular::listaDobleLinealCircular()
{
    this->cab = NULL;
    this->largo = 0;
}

listaDobleLinealCircular::~listaDobleLinealCircular()
{
}

nodoD* listaDobleLinealCircular::getCab()
{
    return this->cab;
}

int listaDobleLinealCircular::getLargo()
{
    return this->largo;
}

void listaDobleLinealCircular::setCab(nodoD* ptr)
{
    this->cab = ptr;
    cab->setSgte(cab);
    cab->setAnte(cab);
}

void listaDobleLinealCircular::setLargo(int n)
{
    this->largo = n;
}

bool listaDobleLinealCircular::esVacia()
{
    return this->getLargo() == 0;
}

nodoD* listaDobleLinealCircular::dirNodo(int pdato)
{
    if (esVacia()) {
        return nullptr; // La lista est� vac�a, no se puede encontrar el nodo.
    }
    else {
        nodoD* aux = getCab();
        do {
            if (aux->getDato() == pdato) {
                return aux; // Se encontr� el nodo con el valor deseado.
            }
            aux = aux->getSgte();
        } while (aux != getCab()); // Hasta que d� una vuelta entera
    }

    return nullptr; // No se encontr� el valor en la lista.
}

nodoD* listaDobleLinealCircular::dirUltimo()
{
    nodoD* last = getCab();

    while (last != NULL && last->getSgte() != NULL)
    {
        last = last->getSgte();
    }
    return last;
}

void listaDobleLinealCircular::eliminarTodos()
{
    bool eliminada = false;
    nodoD* aux = getCab();//paso1
    while (aux != NULL) {
        setCab(getCab()->getSgte());//paso2
        delete aux;
        aux = getCab();
    }
    setLargo(0);
}

void listaDobleLinealCircular::desplegar()
{
    nodoD* aux = getCab(); //aux toma el valor de la cabeza
    if (aux == NULL) {
        cout << "LA LISTA ESTA VACIA .." << endl;
    }
    else {
        cout << "ELEMENTOS EN LA LISTA:" << endl;
        while (aux != getCab()->getAnte()) {

            cout << aux->getDato() << endl;
            aux = aux->getSgte();
        }

        cout << getCab()->getAnte()->getDato() << endl;
        cout << "Vuelve a comenzar en: " << getCab()->getAnte()->getDato() << "=>" << getCab()->getDato() << endl;
    }
}

void listaDobleLinealCircular::agregarFinal(int x)
{
    nodoD* nuevo = new nodoD(x); // Paso 1: Crear el nuevo nodo

    if (esVacia()) {  // Si la lista est� vac�a, el nuevo nodo se convierte en la cabeza
        setCab(nuevo);
    }
    else {
        nodoD* ultimo = getCab()->getAnte(); // Si la lista no est� vac�a, buscamos el �ltimo nodo
        nuevo->setAnte(ultimo); // Enlazamos el nuevo nodo al final
        ultimo->setSgte(nuevo);

        ultimo->setSgte(nuevo);
        getCab()->setAnte(nuevo);
    }
    setLargo(getLargo() + 1); // Incrementar la longitud de la lista
}

bool listaDobleLinealCircular::agregarDespuesDe(int pdato, int ref) {
    nodoD* nuevo = new nodoD(pdato);

    // Buscamos el nodo de referencia
    nodoD* aux = dirNodo(ref);

    if (aux == nullptr) {
        // Si el nodo de referencia no se encuentra, no se puede agregar despu�s de �l
        delete nuevo;
        return false;
    }

    // Conectamos el nuevo nodo al siguiente nodo y al nodo de referencia
    nuevo->setSgte(aux->getSgte());
    nuevo->setAnte(aux);
    nuevo->setSgte(aux->getSgte());
    nuevo->setAnte(aux);

    if (aux->getSgte() != nullptr) {
        aux->getSgte()->setAnte(nuevo);
    }

    aux->setSgte(nuevo);
    setLargo(getLargo() + 1);

    return true;
}

bool listaDobleLinealCircular::agregarOrdenadoAscendente(int pnum)
{
    nodoD* nuevo = new nodoD(pnum);

    // Si la lista esta vacia o el nodo debe ser agregado al inicio
    if (esVacia() || pnum < getCab()->getDato()) {
        nuevo->setSgte(getCab()); // Enlace el nuevo nodo con la cabeza actual
        getCab()->setAnte(nuevo);  // Actualice el puntero anterior de la cabeza anterior para apuntar al nuevo nodo
        setCab(nuevo); // Actualice la cabeza para que apunte al nuevo nodo
        setLargo(getLargo() + 1); // Incrementa la longitud de la lista
        return true; // Devuelve true para indicar que la inserci�n fue exitosa
    }

    // Encuentra la posicion adecuada para el nuevo nodo
    nodoD* actual = getCab();
    while (actual->getSgte() != nullptr && actual->getSgte()->getDato() < pnum) {
        actual = actual->getSgte();
    }

    //Enlaza al nuevo nodo en la posici�n adecuada
    nuevo->setSgte(actual->getSgte());
    if (actual->getSgte() != nullptr) {
        actual->getSgte()->setAnte(nuevo);
    }
    nuevo->setAnte(actual);
    actual->setSgte(nuevo);
    setLargo(getLargo() + 1);
    return true; // Devuelve true para indicar que la inserci�n fue exitosa
}
