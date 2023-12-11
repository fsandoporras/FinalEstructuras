#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>


enum TipoUsuario
{
	Administrador,
	Cliente
};

class Usuario
{


private:
	int cedula;
	std::string nombre;
	std::string apellidos;
	std::string correoElectronico;
	std::string numeroTelefonico;
	Usuario* sgte;
	Usuario* ante;
	TipoUsuario tipoUsuario;

public:


	Usuario(int); //constructor sin datos, no puede existir un usuario sin cedula.
	Usuario(int, std::string, std::string, std::string, std::string, TipoUsuario);// constructor sobrecargado
	~Usuario(); //destructor


	//gets y sets:

	int getCedula();
	Usuario* getSgte();
	Usuario* getAnte();

	void setCedula(int);
	void setSgte(Usuario*);
	void setAnte(Usuario*);

	std::string getNombre();
	void setNombre(std::string);

	std::string getApellidos();
	void setApellidos(std::string);
	
	std::string getCorreoElectronico();
	void setCorreoElectronico(std::string);

	std::string getNumeroTelefonico();
	void setNumeroTelefonico(std::string);

	TipoUsuario getTipoUsuario();
	void setTipoUsuario(TipoUsuario tipoUsuario);

};



