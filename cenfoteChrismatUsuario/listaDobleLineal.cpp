#include "listaDobleLineal.h";
#include "nodoD.h";


nodoD* listaDobleLineal::dirAnterior(int x)
{
    nodoD* aux = dirNodo(x);
    if (aux == NULL)
        return NULL;
    else
        return aux->getAnte();
   
}



void listaDobleLineal::agregarInicio(int x)
{
    nodoD* nuevo = new nodoD(x);//Paso 1. crear el nodo
    if (!esVacia()) {
        nuevo->setSgte(getCab());//Paso 2. Enlazar el nuevo nodo a lista
        getCab()->setAnte(nuevo);
    }
    //Paso 3 Reacomodar la lista con el nuevo nodo
    setCab(nuevo);
    setLargo(getLargo()+1);
}

bool listaDobleLineal::agregarAntesDe(int x, int ref)
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

listaDobleLineal::listaDobleLineal()
{
    this->cab = NULL;
    this->largo = 0;
}

listaDobleLineal::~listaDobleLineal()
{
}

nodoD* listaDobleLineal::getCab()
{
    return this->cab;
}

int listaDobleLineal::getLargo()
{
    return this->largo;
}

void listaDobleLineal::setCab(nodoD* ptr)
{
    this->cab = ptr;
}

void listaDobleLineal::setLargo(int n)
{
    this->largo = n;
}

bool listaDobleLineal::esVacia()
{
    return this->getLargo() == 0;
}

nodoD* listaDobleLineal::dirNodo(int pnum)
{
    // Devolver la direccion donde se ubica pnum

    nodoD* aux = getCab();
    while ((aux != NULL) && (aux->getDato() != pnum)) {
        aux = aux->getSgte();
    }

    return aux;
}

nodoD* listaDobleLineal::dirUltimo()
{
    nodoD* last = getCab();

    while (last != NULL && last->getSgte() != NULL)
    {
        last = last->getSgte();
    }
    return last;
}

void listaDobleLineal::eliminarTodos()
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

void listaDobleLineal::desplegar()
{
    nodoD* aux = getCab(); //aux toma el valor de la cabeza
    if (aux == NULL) {
        cout << "LA LISTA ESTA VACIA .." << endl;
    }
    else {
        cout << "ELEMENTOS EN LA LISTA:" << endl;
        while (aux != NULL) {
        cout << aux->getDato() << endl;
        aux = aux->getSgte();
        }
    }
}

void listaDobleLineal::agregarFinal(int x)
{
    nodoD* nuevo = new nodoD(x); // Paso 1: Crear el nuevo nodo

    if (esVacia()) {  // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
        setCab(nuevo);
    }
    else {
        nodoD* ultimo = dirUltimo(); // Si la lista no está vacía, buscamos el último nodo
        nuevo->setAnte(ultimo); // Enlazamos el nuevo nodo al final
        ultimo->setSgte(nuevo);
    }
    setLargo(getLargo() + 1); // Incrementar la longitud de la lista
}

bool listaDobleLineal::agregarDespuesDe(int pdato, int ref) {
    nodoD* nuevo = new nodoD(pdato);

    // Buscamos el nodo de referencia
    nodoD* aux = dirNodo(ref);

    if (aux == nullptr) {
        // Si el nodo de referencia no se encuentra, no se puede agregar después de él
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

bool listaDobleLineal::agregarOrdenadoAscendente(int pnum)
{
    nodoD* nuevo = new nodoD(pnum);

    // Si la lista esta vacia o el nodo debe ser agregado al inicio
    if (esVacia() || pnum < getCab()->getDato()) {
        nuevo->setSgte(getCab()); // Enlace el nuevo nodo con la cabeza actual
        getCab()->setAnte(nuevo);  // Actualice el puntero anterior de la cabeza anterior para apuntar al nuevo nodo
        setCab(nuevo); // Actualice la cabeza para que apunte al nuevo nodo
        setLargo(getLargo() + 1); // Incrementa la longitud de la lista
        return true; // Devuelve true para indicar que la inserción fue exitosa
    }

    // Encuentra la posicion adecuada para el nuevo nodo
    nodoD* actual = getCab();
    while (actual->getSgte() != nullptr && actual->getSgte()->getDato() < pnum) {
        actual = actual->getSgte();
    }

    //Enlaza al nuevo nodo en la posición adecuada
    nuevo->setSgte(actual->getSgte());
    if (actual->getSgte() != nullptr) {
        actual->getSgte()->setAnte(nuevo);
    }
    nuevo->setAnte(actual);
    actual->setSgte(nuevo);
    setLargo(getLargo() + 1);
    return true; // Devuelve true para indicar que la inserción fue exitosa
}
