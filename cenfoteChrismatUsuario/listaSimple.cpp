#include "listaSimple.h";
#include "nodoS.h";

listaSimple::listaSimple()
{
	this->cab = NULL;
	this->largo = 0;
}

listaSimple::~listaSimple()
{
}

nodoS* listaSimple::getCab()
{
	return this->cab;
}

int listaSimple::getLargo()
{
	return this->largo;
}

void listaSimple::setCab(nodoS* ptr)
{
	this->cab = ptr;
}

void listaSimple::setLargo(int n)
{
	this->largo = n;
}

nodoS* listaSimple::dirNodo(int pnum)
{// Devolver la direccion donde se ubica pnum

	nodoS * aux = getCab();
	while ((aux != NULL) && (aux -> getDato() != pnum)) {
		aux = aux->getSgte();
	}
	
	return aux;

}

nodoS* listaSimple::dirAnterior(int pnum)
{   // devuelve la direccion del nodo anterior en que se ubica pnum
	// si la lista esta vacia, o no se ubica el nodo anterior devuelve NULL 

	nodoS* aux = getCab();

	if (getCab() == NULL || getCab()->getDato() == pnum) {
		return NULL;
	}
	while (aux->getSgte() != NULL && aux->getSgte()->getDato() != pnum) {
		aux = aux->getSgte();
	}

	return aux;
}

nodoS* listaSimple::dirULtimo()
{
	nodoS* last = getCab();

	while (last != NULL && last->getSgte() != NULL) 
	{
		last = last->getSgte();
	}
	return last;
}

bool listaSimple::esVacia()
{
	return this ->getLargo() == 0;
}

void listaSimple::desplegar()
{
	nodoS* aux = getCab(); //aux toma el valor de la cabeza
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


void listaSimple::agregarInicio(int x)
{
	nodoS* nuevo = new nodoS(x); //Paso 1. Crear el nodo
	nuevo->setSgte(getCab());//Paso 2. Enlazar el nuevo nodo a la lista
	setCab(nuevo); //Paso 3. Reacomodar la lista con el nuevo nodo
	largo++;
}

bool listaSimple::agregarAntesDe(int x, int ref)
{
	// agregar un nodo con el valor de x y lo voy a colocar antes del nodo que contiene a ref
	// si no existe ref no lo agrega

	bool agregado = false;
	if (getCab() != NULL) {
		if (getCab()->getDato() == ref) {
			agregarInicio(x);
			agregado = true;
		}
		else {
			nodoS* ant = getCab();
			while (ant->getSgte() != NULL && !agregado) {
				if (ant->getSgte()->getDato() == ref) {
					nodoS* nuevo = new nodoS(x); //Paso 1. Crear el nodo
					nuevo->setSgte(ant->getSgte()); //Paso 2. Enlazar el nuevo nodo a la lista
					ant->setSgte(nuevo);// Paso 3. Reacomodar la lista con el nuevo nodo
					largo++;
					agregado = true;
				}
				else {
					ant = ant->getSgte();
				}

			}

		}
	}
	return agregado;
}
bool listaSimple::agregarAscendente(int pnum)
{
	// agregar en forma ascendente en la lista, considerando que no pueden darse valores repetidos

	bool agregado = false;
	bool repetido = false;
	if (esVacia()) {
		agregarInicio(pnum);
		agregado = true;
	}
	else {
		if (pnum < getCab()->getDato()) {
			agregarInicio(pnum);
			agregado = true;
		}
		else {
			nodoS* ant = getCab();
			nodoS* aux = NULL;
			while (ant != NULL && !repetido) {
				if (ant->getSgte() == NULL) {
					nodoS* nuevo = new nodoS(pnum);//paso1
					ant->setSgte(nuevo); //paso3
					largo++;
					agregado = true;
				}
				else {
					nodoS* aux = ant->getSgte();
					if (pnum < aux->getDato()) {
						nodoS* nuevo = new nodoS(pnum);//paso1
						nuevo->setSgte(aux);//paso2
						ant->setSgte(nuevo); //paso3
						largo++;
						agregado = true;
					}
					else {
						ant = ant->getSgte();
					}
				}
			}
		}
	}

	return false;
}

bool listaSimple::agregarOrdenadoDescendiente(int dato)
{
	nodoS* nuevoNodo = new nodoS(dato);
	if (esVacia() || dato > cab->getDato()) { // si la lista está vacía o el nuevo dato es mayor que el primer nodo
		nuevoNodo->setSgte(cab);
		cab = nuevoNodo;
		largo++;
		return true;
	}
	if (dato == cab->getDato()) {  // si el nuevo dato es igual al primer nodo (evitamos duplicados)
		delete nuevoNodo;
		return false;
	}
	nodoS* actual = cab;    // vamos a buscar la ubicación adecuada para el nuevo dato
	nodoS* anterior = NULL;
	while (actual != NULL && dato < actual->getDato()) {
		anterior = actual;
		actual = actual->getSgte();
	}
	if (actual != NULL && dato == actual->getDato()) {   // aqui es por si el nuevo dato es igual a un nodo existente (evitamos duplicados)
		delete nuevoNodo;
		return false;
	}
	nuevoNodo->setSgte(actual); // se va a insertar el nuevo nodo entre el nodo anterior y el actual
	anterior->setSgte(nuevoNodo);
	largo++;
	return true;
}


int listaSimple::cantpares() {

	int cont = 0;
	nodoS* aux = getCab();

	while (aux != NULL) {
		if (aux->getDato() % 2 == 0) {
			cont++;
		}
		aux = aux->getSgte();
	}
	return cont;
}

bool listaSimple::elimnar(int pdato)
{
	//Eliminar de la lista el primer nodo que tenga el valor de dato
	// devuelve true si lo elimina, false si no lo elimino (no se encontro)

	bool eliminado = false;
	if (!esVacia()) {
		nodoS* ant;
		nodoS* aux;
		if (getCab()->getDato() == pdato){
			//paso1: señale el nodo a eleminar
			aux = getCab();
			//paso2: reacomodar la lista sin el nodo
			setCab(aux->getSgte());
			setLargo(getLargo() - 1);
			//paso3: liberar la memoria
			delete aux;
			eliminado = true;
		}
		else {
			nodoS* ant = dirAnterior(pdato); // localiza la direccion del nodo anterior a pdato
			if (ant != NULL) {
				aux = ant->getSgte(); // paso 1: señale el nodo a eliminar
				ant->setSgte(aux->getSgte()); // paso 2: reacomodar la lista sin el nodo
				setLargo(getLargo() - 1);
				delete aux; //paso#: liberar la memoria del nodo
				eliminado = true;
			}
		}
	}

	return eliminado;
}

void listaSimple::eliminarTodo()
{
	bool eliminada = false;
	nodoS* aux = getCab();//paso1
	while (aux != NULL) {
			setCab(getCab()->getSgte());//paso2
			delete aux;
			aux = getCab();

	}
	setLargo(0);
}

void listaSimple::eliminarTodo(int dato)
{
	nodoS* actual = cab;
	nodoS* anterior = nullptr;

	while (actual != nullptr) {
		if (actual->getDato() == dato) {
			if (anterior != nullptr) {  // Elimina el nodo actual
				anterior->setSgte(actual->getSgte());
				delete actual;
				actual = anterior->getSgte();
			}
			else {
				cab = actual->getSgte();// Si es el primer nodo, actualiza la cabeza
				delete actual;
				actual = cab;
			}
		}
		else {
			anterior = actual;// Si el nodo no coincide con el valor, avanza en la lista
			actual = actual->getSgte();
		}
	}
}
