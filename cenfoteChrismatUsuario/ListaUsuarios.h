#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Usuario.h"


class ListaUsuarios
{
private:
	Usuario* cab;
	int largo;
	bool ordenadoAscendente;

	Usuario* dirNodo(int); //ILS
	Usuario* dirUltimo();//ILS
	Usuario* dirAnterior(int);
	void agregarInicio(int);

	bool agregarOrdenadoAscendente(Usuario* usuario);

public:
	ListaUsuarios();
	~ListaUsuarios();

	Usuario* getCab(); 
	int getLargo();

	void setCab(Usuario*);
	void setLargo(int);

	bool esVacia(); 

	bool modificarUsuario(Usuario*);

	ListaUsuarios* filtrarPorCliente();
	ListaUsuarios* filtrarPorAdministrador();

	void agregarFinal(Usuario*);

	bool agregarUsuario(Usuario* usuario);

	ListaUsuarios* filtrarAscendente();
	ListaUsuarios* filtrarDescendente();

	bool removerUsuario(int);

	bool removerPorNombre(std::string);
	bool removerPorCorreoElectronico(std::string);
	bool removerPorNumeroTelefono(std::string);
	bool removerPorApellidos(std::string);

	void desplegar();

	
};


