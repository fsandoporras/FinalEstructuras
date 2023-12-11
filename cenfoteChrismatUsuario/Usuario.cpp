#include "Usuario.h"
#include <stdlib.h>

Usuario::Usuario(int cedula)
{
	this->cedula = cedula;
	this->sgte = NULL;
	this->ante = NULL;
}

Usuario::Usuario(int cedula, std::string nombre, std::string apellidos, std::string correoElectronico, std::string numeroTelefonico, TipoUsuario tipoUsuario)
{
	this->cedula = cedula;
	this->nombre = nombre;
	this->apellidos = apellidos;
	this->correoElectronico = correoElectronico;
	this->numeroTelefonico = numeroTelefonico;
	this->tipoUsuario = tipoUsuario;
}

Usuario::~Usuario()
{
}

int Usuario::getCedula()
{
	return this->cedula;
}

Usuario* Usuario::getSgte()
{
	return this->sgte;
}

Usuario* Usuario::getAnte()
{
	return  this->ante;
}

void Usuario::setCedula(int cedula)
{
	this->cedula = cedula;
}

void Usuario::setSgte(Usuario* ptr)
{
	this->sgte = ptr;
}

void Usuario::setAnte(Usuario* ptr)
{
	this->ante = ptr;
}

std::string Usuario::getNombre()
{
	return this->nombre;
}

std::string Usuario::getApellidos()
{
	return this->apellidos;
}

std::string Usuario::getCorreoElectronico()
{
	return this->correoElectronico;
}

std::string Usuario::getNumeroTelefonico()
{
	return this->numeroTelefonico;
}

void Usuario::setNombre(std::string nombre)
{
	this->nombre = nombre;
}

void Usuario::setApellidos(std::string apellidos)
{
	this->apellidos = apellidos;
}

void Usuario::setCorreoElectronico(std::string correoElectronico)
{
	this->correoElectronico = correoElectronico;
}

void Usuario::setNumeroTelefonico(std::string numeroTelefonico)
{
	this->numeroTelefonico = numeroTelefonico;
}

void Usuario::setTipoUsuario(TipoUsuario tipoUsuario)
{
	this->tipoUsuario = tipoUsuario;
}

TipoUsuario Usuario::getTipoUsuario()
{
	return this->tipoUsuario;
}