// proyectoListas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "ListaUsuarios.h"


int main()
{
    cout << "OPERACIONES CON LISTAS DOBLE LINEAL\n";

    ListaUsuarios* lista; // Se crea un puntero a un objeto de tipo lista
    lista = new ListaUsuarios(); // Se reserva el espacio para el objeto lista doble y la dirección de memoria se asigna a lista

    cout << "Creado la lista doble \n";
    cout << "Cantidad de nodos en la lista doble ="<< lista->getLargo() << endl;

   /* lista->agregarAntesDe(10, 5);
    cout << "Cantidad de nodos en la lista doble =" << lista->getLargo() << endl;
    lista->desplegar();

    lista->agregarAntesDe(30, 25);
    cout << "Cantidad de nodos en la lista doble =" << lista->getLargo() << endl;
    lista->desplegar();*/

    /*lista->agregarInicio(10);
    cout << "Cantidad de nodos en la lista doble =" << lista->getLargo() << endl;
    lista->desplegar();

    lista->agregarInicio(10);
    cout << "Cantidad de nodos en la lista doble =" << lista->getLargo() << endl;
    lista->desplegar();*/

    TipoUsuario cliente = Cliente;
    TipoUsuario admin = Administrador;

    //lista->agregarUsuario(new Usuario(702790200, "Zach", "Hernandez", "zah@gmail.com", "23123123", admin));
    //lista->agregarUsuario(new Usuario(702790201, "Zacheeeee", "Hernandeeeez", "zaheee@gmail.com", "2312322123", admin));
    //lista->agregarUsuario(new Usuario(702790198, "Zachoooo", "Hernandoooz", "zahoooo@gmail.com", "23124", admin));
    //lista->agregarUsuario(new Usuario(702790203, "Zachuuuuu", "Hernanduuz", "zahuuu@gmail.com", "1243453", admin));
    lista->agregarUsuario(new Usuario(702790199, "Zachasdf", "Hernander", "zach@gmail.com", "8888881", admin));
    lista->agregarUsuario(new Usuario(702790200, "Zachasdf", "Hernander", "zach@gmail.com", "8888881", admin));
    lista->agregarUsuario(new Usuario(702790202, "Zacha39393", "Hernandwerewr", "zeta@gmail.com", "8888881", admin));
    lista->agregarUsuario(new Usuario(702790180, "Zacha39393", "Hernandwer", "zach@gmail.com", "8888881", admin));
    lista->agregarUsuario(new Usuario(702790194, "Zacha39393", "Hernandwer", "zach@gmail.com", "8888881", admin));
    lista->agregarUsuario(new Usuario(702790300, "Zacha39393", "Hernandwer", "zach@gmail.com", "8888881", cliente));
    lista->agregarUsuario(new Usuario(702790181, "Zachary200ddd", "HERHED", "zachary@gmail.com", "888882", admin));

    ListaUsuarios* listaFiltrada = lista->filtrarPorCliente();

    lista->desplegar();

    cout << endl;


    cout << "-----------------------------------------------------------" << endl;
    cout << "Lista filtrada por clientes:" << endl;
    cout << "-----------------------------------------------------------" << endl;

    listaFiltrada->desplegar();

    listaFiltrada = lista->filtrarPorAdministrador();

    cout << endl;

    cout << "-----------------------------------------------------------" << endl;
    cout << "Lista filtrada por administrador:" << endl;
    cout << "-----------------------------------------------------------" << endl;

    listaFiltrada->desplegar();

    listaFiltrada = lista->filtrarAscendente();
    
    cout << endl;

    cout << "-----------------------------------------------------------" << endl;
    cout << "Lista filtrada descendente:" << endl;
    cout << "-----------------------------------------------------------" << endl;

    listaFiltrada->desplegar();

    std::string val = "1243453";

    listaFiltrada->removerPorNumeroTelefono(val);

    cout << endl;

    cout << "-----------------------------------------------------------" << endl;
    cout << "Lista sin valor " << val << endl;
    cout << "-----------------------------------------------------------" << endl;

    listaFiltrada->desplegar();

}
