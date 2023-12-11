#include "ListaUsuarios.h";
#include "Usuario.h";

bool ListaUsuarios::agregarUsuario(Usuario* usuario)
{
    return this->agregarOrdenadoAscendente(usuario);
}

bool ListaUsuarios::modificarUsuario(Usuario* usuario)
{
    Usuario* usuarioEncontrado = dirNodo(usuario->getCedula());

    if (usuarioEncontrado == nullptr)
    {
        return false;
    }

    usuarioEncontrado->setNombre(usuario->getNombre());
    usuarioEncontrado->setApellidos(usuario->getApellidos());
    usuarioEncontrado->setCorreoElectronico(usuario->getCorreoElectronico());
    usuarioEncontrado->setNumeroTelefonico(usuario->getNumeroTelefonico());

    return true;
}

bool ListaUsuarios::removerUsuario(int x)
{
    Usuario* usuarioEncontrado = dirNodo(x);


    if (usuarioEncontrado == nullptr)
    {
        return false;
    }

    if (getLargo() == 1)
    {
        this->setCab(nullptr);
        delete usuarioEncontrado;

        setLargo(0);
        return true;
    }

    if (usuarioEncontrado == getCab())
    {
        usuarioEncontrado->getAnte()->setSgte(usuarioEncontrado->getSgte());
        usuarioEncontrado->getSgte()->setAnte(usuarioEncontrado->getAnte());
        setCab(usuarioEncontrado->getSgte());

        delete usuarioEncontrado;
         
        setLargo(getLargo() - 1);
        return true;
    }

    if (usuarioEncontrado == getCab()->getAnte())
    {

        usuarioEncontrado->getAnte()->setSgte(usuarioEncontrado->getSgte());
        usuarioEncontrado->getSgte()->setAnte(usuarioEncontrado->getAnte());
        delete usuarioEncontrado;

        setLargo(getLargo() - 1);
        return true;
    }


    usuarioEncontrado->getAnte()->setSgte(usuarioEncontrado->getSgte());
    usuarioEncontrado->getSgte()->setAnte(usuarioEncontrado->getAnte());
    delete usuarioEncontrado;


    setLargo(getLargo() - 1);
    return false;
}

Usuario* ListaUsuarios::dirAnterior(int x)
{
    Usuario* aux = dirNodo(x);
    if (aux == NULL)
        return NULL;
    else
        return aux->getAnte();

}



void ListaUsuarios::agregarInicio(int x)
{
    Usuario* nuevo = new Usuario(x);//Paso 1. crear el nodo
    if (!esVacia()) {
        nuevo->setSgte(getCab());//Paso 2. Enlazar el nuevo nodo a lista
        getCab()->setAnte(nuevo);
    }
    //Paso 3 Reacomodar la lista con el nuevo nodo
    setCab(nuevo);
    setLargo(getLargo() + 1);
}

ListaUsuarios::ListaUsuarios()
{
    this->cab = NULL;
    this->largo = 0;
}

ListaUsuarios::~ListaUsuarios()
{
}

Usuario* ListaUsuarios::getCab()
{
    return this->cab;
}

int ListaUsuarios::getLargo()
{
    return this->largo;
}

void ListaUsuarios::setCab(Usuario* ptr)
{
    this->cab = ptr;
}

void ListaUsuarios::setLargo(int n)
{
    this->largo = n;
}

bool ListaUsuarios::esVacia()
{
    return this->getLargo() == 0;
}

Usuario* ListaUsuarios::dirNodo(int pdato)
{
    if (esVacia()) {
        return nullptr; // La lista está vacía, no se puede encontrar el nodo.
    }
    else {
        Usuario* aux = getCab();
        do {
            if (aux->getCedula() == pdato) {
                return aux; // Se encontró el nodo con el valor deseado.
            }
            aux = aux->getSgte();
        } while (aux != getCab()); // Hasta que dé una vuelta entera
    }

    return nullptr; // No se encontró el valor en la lista.
}

Usuario* ListaUsuarios::dirUltimo()
{
    Usuario* last = getCab();

    while (last != getCab()->getAnte())
    {
        last = last->getSgte();
    }
    return last;
}

void ListaUsuarios::desplegar()
{
    std::string tipoUsuarioToString = "";

    TipoUsuario tipoUsuario = Cliente;

    Usuario* aux = getCab(); //aux toma el valor de la cabeza
    if (aux == NULL) { // si la lista esta vacia no retorna nada.
        cout << "LA LISTA ESTA VACIA .." << endl;
    }
    else {
        cout << "ELEMENTOS EN LA LISTA:" << endl;
        cout << "cedula    || nombre    || apellidos    || correo electronico    || numero de teléfono    || Tipo Usuario" << endl;
        while (aux != getCab()->getAnte()) { // hasta que el aux no sea el ultimo elemento de la lista. continua


            tipoUsuario = aux->getTipoUsuario();

            switch (tipoUsuario) // logica para obtener el tipoUsuario relacionado al usuario como String para mostrar.
            {
            case Administrador:
                tipoUsuarioToString = "Administrador";
                break;
            case Cliente:
                tipoUsuarioToString = "Cliente";
                break;
            default:
                break;
            }
            cout << aux->getCedula() << " | " << aux->getNombre() << " | " << aux->getApellidos() << " | " << aux->getCorreoElectronico() << " | " << aux->getNumeroTelefonico() << " | " << tipoUsuarioToString << endl;
            aux = aux->getSgte();
        }


        Usuario* final = getCab()->getAnte();

        tipoUsuario = final->getTipoUsuario();

        switch (tipoUsuario)
        {
        case Administrador:
            tipoUsuarioToString = "Administrador";
            break;
        case Cliente:
            tipoUsuarioToString = "Cliente";
            break;
        default:
            break;
        }
        cout << final->getCedula() << " | " << final->getNombre() << " | " << final->getApellidos() << " | " << final->getCorreoElectronico() << " | " << final->getNumeroTelefonico() << " | " << tipoUsuarioToString << endl;
        cout << "Vuelve a comenzar en: " << getCab()->getAnte()->getCedula() << "=>" << getCab()->getCedula() << endl;
    }
}

bool ListaUsuarios::removerPorCorreoElectronico(std::string correoElectronico)
{
    Usuario* aux = this->getCab();

    if (aux == nullptr) // si no hay datos entonces devuelve falso, que no pudo eliminar datos.
    {
        return false;
    }

    Usuario* tempSgte = nullptr; // esta variable obtendra siempre el valor de la posicion actual de nodo a continuar. Evita que se avance al siguiente nodo y se evalue antes de tiempo.

    /*
    // 1. Verifica si es la cabeza (empieza por cabeza + 1
    // 2. eliminar el nodo si es la condicion correcta (el valor correcto).
    // 3. sigue al nodo siguiente y repite el ciclo.
    */

    tempSgte = aux->getSgte();
    do {

        aux = tempSgte;

        if (aux->getCorreoElectronico() == correoElectronico)
        {
            if (getLargo() == 1)
            {
                delete aux;
                setCab(nullptr);
                setLargo(0);

                return true;
            }

            Usuario* temp = aux->getSgte();
            aux->getAnte()->setSgte(temp);

            temp->setAnte(aux->getAnte());

            if (aux == this->getCab())
            {
                this->setCab(temp);
            }

            Usuario* toDelete = aux;

            tempSgte = aux->getSgte();
            delete toDelete;

            setLargo(getLargo() - 1);
        }

        else {
            tempSgte = aux->getSgte();
        }


    }while (aux != this->getCab()); // 1. el valor no es la cabeza (osea hizo una vuelta entera).

    return true;
}

bool ListaUsuarios::removerPorNombre(std::string nombre)
{
    Usuario* aux = this->getCab();

    if (aux == nullptr)
    {
        return false;
    }

    Usuario* tempSgte = nullptr;

    tempSgte = aux->getSgte();
    do {

        aux = tempSgte;

        if (aux->getNombre() == nombre)
        {
            if (getLargo() == 1)
            {
                delete aux;
                setCab(nullptr);
                setLargo(0);

                return true;
            }

            Usuario* temp = aux->getSgte();
            aux->getAnte()->setSgte(temp);

            temp->setAnte(aux->getAnte());

            if (aux == this->getCab())
            {
                this->setCab(temp);
            }

            Usuario* toDelete = aux;

            tempSgte = aux->getSgte();
            delete toDelete;

            setLargo(getLargo() - 1);
        }

        else {
            tempSgte = aux->getSgte();
        }


    } while (aux != this->getCab());

    return true;
}

bool ListaUsuarios::removerPorNumeroTelefono(std::string numeroTelefonico)
{
    Usuario* aux = this->getCab();

    if (aux == nullptr)
    {
        return false;
    }

    Usuario* tempSgte = nullptr;

    tempSgte = aux->getSgte();
    do {

        aux = tempSgte;

        if (aux->getNumeroTelefonico() == numeroTelefonico)
        {
            if (getLargo() == 1)
            {
                delete aux;
                setCab(nullptr);
                setLargo(0);

                return true;
            }

            Usuario* temp = aux->getSgte();
            aux->getAnte()->setSgte(temp);

            temp->setAnte(aux->getAnte());

            if (aux == this->getCab())
            {
                this->setCab(temp);
            }

            Usuario* toDelete = aux;

            tempSgte = aux->getSgte();
            delete toDelete;

            setLargo(getLargo() - 1);
        }

        else {
            tempSgte = aux->getSgte();
        }


    } while (aux != this->getCab());

    return true;
}

bool ListaUsuarios::removerPorApellidos(std::string apellidos)
{
    Usuario* aux = this->getCab();

    if (aux == nullptr)
    {
        return false;
    }

    Usuario* tempSgte = nullptr;

    tempSgte = aux->getSgte();
    do {

        aux = tempSgte;

        if (aux->getApellidos() == apellidos)
        {
            if (getLargo() == 1)
            {
                delete aux;
                setCab(nullptr);
                setLargo(0);

                return true;
            }

            Usuario* temp = aux->getSgte();
            aux->getAnte()->setSgte(temp);

            temp->setAnte(aux->getAnte());

            if (aux == this->getCab())
            {
                this->setCab(temp);
            }

            Usuario* toDelete = aux;

            tempSgte = aux->getSgte();
            delete toDelete;

            setLargo(getLargo() - 1);
        }

        else {
            tempSgte = aux->getSgte();
        }


    } while (aux != this->getCab());

    return true;
}

ListaUsuarios* ListaUsuarios::filtrarPorCliente()
{
    ListaUsuarios* listaUsuarios = new ListaUsuarios();

    Usuario* actual = this->getCab();
    Usuario* actualListaNueva = nullptr;

    if (actual == nullptr)
    {
        return listaUsuarios;
    }

    do {

        // analiza si el usuario actual es cliente y añade la conexion.
        if (actual->getTipoUsuario() == Cliente && listaUsuarios->getCab() != nullptr)
        {
            // crea una copia de los datos.
            Usuario* nuevoListaNueva = new Usuario(
                actual->getCedula(),
                actual->getNombre(),
                actual->getApellidos(),
                actual->getCorreoElectronico(),
                actual->getNumeroTelefonico(),
                actual->getTipoUsuario()
            );
            actualListaNueva->setSgte(nuevoListaNueva);
            nuevoListaNueva->setAnte(actualListaNueva);

            actualListaNueva = nuevoListaNueva;

            listaUsuarios->setLargo(listaUsuarios->getLargo() + 1);
        }
        // buscar el primer usuario que sea de tipo cliente y crea la cabeza sin ningun conexión.
        else if (actual->getTipoUsuario() == Cliente)
        {
            listaUsuarios->setCab(new Usuario(
                actual->getCedula(),
                actual->getNombre(),
                actual->getApellidos(),
                actual->getCorreoElectronico(),
                actual->getNumeroTelefonico(),
                actual->getTipoUsuario()));

            listaUsuarios->setLargo(1);

            actualListaNueva = listaUsuarios->getCab();
        }

        // seguimos con el otro usuario.
        actual = actual->getSgte();

    } while (actual != this->getCab());


    if (listaUsuarios->getCab() == nullptr)
    {
        return listaUsuarios;
    }

    else
    {
        listaUsuarios->getCab()->setAnte(actualListaNueva);
    }
    actualListaNueva->setSgte(listaUsuarios->getCab());

    return listaUsuarios;
}

ListaUsuarios* ListaUsuarios::filtrarPorAdministrador()
{
    ListaUsuarios* listaUsuarios = new ListaUsuarios();

    Usuario* actual = this->getCab();
    Usuario* actualListaNueva = nullptr;

    if (actual == nullptr)
    {
        return listaUsuarios;
    }

    do {

        // analiza si el usuario actual es cliente y añade la conexion.
        if (actual->getTipoUsuario() == Administrador && listaUsuarios->getCab() != nullptr)
        {
            // crea una copia de los datos.
            Usuario* nuevoListaNueva = new Usuario(
                actual->getCedula(),
                actual->getNombre(),
                actual->getApellidos(),
                actual->getCorreoElectronico(),
                actual->getNumeroTelefonico(),
                actual->getTipoUsuario()
            );
            actualListaNueva->setSgte(nuevoListaNueva);
            nuevoListaNueva->setAnte(actualListaNueva);

            actualListaNueva = nuevoListaNueva;

            listaUsuarios->setLargo(listaUsuarios->getLargo() + 1);
        }
        // buscar el primer usuario que sea de tipo cliente y crea la cabeza sin ningun conexión.
        else if (actual->getTipoUsuario() == Administrador)
        {
            listaUsuarios->setCab(new Usuario(
                actual->getCedula(),
                actual->getNombre(),
                actual->getApellidos(),
                actual->getCorreoElectronico(),
                actual->getNumeroTelefonico(),
                actual->getTipoUsuario()));

            listaUsuarios->setLargo(1);

            actualListaNueva = listaUsuarios->getCab();
        }

        // seguimos con el otro usuario.
        actual = actual->getSgte();

    } while (actual != this->getCab());

    if (listaUsuarios->getCab() == nullptr)
    {
        return listaUsuarios;
    }

    else
    {
        listaUsuarios->getCab()->setAnte(actualListaNueva);
    }
    actualListaNueva->setSgte(listaUsuarios->getCab());

    return listaUsuarios;
}

void ListaUsuarios::agregarFinal(Usuario* usuario)
{
    Usuario* nuevo = usuario; // Paso 1: Crear el nuevo nodo

    if (esVacia()) {  // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
        setCab(nuevo);
    }
    else {
        Usuario* ultimo = getCab()->getAnte(); // Si la lista no está vacía, buscamos el último nodo
        nuevo->setAnte(ultimo); // Enlazamos el nuevo nodo al final
        ultimo->setSgte(nuevo);

        nuevo->setSgte(getCab());
        ultimo->setSgte(nuevo);
        getCab()->setAnte(nuevo);
    }
    setLargo(getLargo() + 1); // Incrementar la longitud de la lista
}

bool ListaUsuarios::agregarOrdenadoAscendente(Usuario* usuario)
{
    Usuario* nuevo = usuario;

    if (esVacia())
    {
        this->setCab(usuario);

        this->getCab()->setSgte(cab);
        this->getCab()->setAnte(cab);
        setLargo(getLargo() + 1); // Incrementa la longitud de la lista
        return true;
    }

    // Si el nodo debe ser agregado al inicio cuando la cabeza es mayor
    if (usuario->getCedula() < getCab()->getCedula()) {
        
        Usuario* oldCab = getCab();
        setCab(nuevo); // Actualice la cabeza para que apunte al nuevo nodo

        nuevo->setSgte(oldCab); // Enlace el nuevo nodo con la cabeza actual
        nuevo->setAnte(oldCab->getAnte());  // Actualice el puntero anterior de la cabeza anterior para apuntar al nuevo nodo
        oldCab->getAnte()->setSgte(nuevo);
        oldCab->setAnte(nuevo);

        setLargo(getLargo() + 1); // Incrementa la longitud de la lista
        return true; // Devuelve true para indicar que la inserción fue exitosa
    }

    // Encuentra la posicion adecuada para el nuevo nodo
    Usuario* actual = getCab();
    do {
        actual = actual->getSgte();

    } while (actual != getCab()->getAnte() && actual->getCedula() < usuario->getCedula());
    
    if (actual == getCab()->getAnte() && actual->getCedula() < usuario->getCedula())
    {
        this->agregarFinal(usuario);
        return true;
    }

    if (actual->getCedula() == usuario->getCedula())
    {
        return false;
    }

    nuevo->setAnte(actual->getAnte());
    nuevo->setSgte(actual);

    actual->getAnte()->setSgte(nuevo);
    actual->setAnte(nuevo);

    setLargo(getLargo() + 1);
    return true; // Devuelve true para indicar que la inserción fue exitosa
}



ListaUsuarios* ListaUsuarios::filtrarAscendente()
{
    return this;
}

ListaUsuarios* ListaUsuarios::filtrarDescendente()
{
    ListaUsuarios* usuarios = new ListaUsuarios();

    Usuario* currNodo = dirUltimo();

    if (currNodo == nullptr)
    {
        return nullptr;
    }

    usuarios->setCab(new Usuario(
        currNodo->getCedula(),
        currNodo->getNombre(),
        currNodo->getApellidos(),
        currNodo->getCorreoElectronico(),
        currNodo->getNumeroTelefonico(),
        currNodo->getTipoUsuario()
    ));

    Usuario* aux = usuarios->getCab();


    do {

        currNodo = currNodo->getAnte();
        aux->setSgte(new Usuario(
            currNodo->getCedula(),
            currNodo->getNombre(),
            currNodo->getApellidos(),
            currNodo->getCorreoElectronico(),
            currNodo->getNumeroTelefonico(),
            currNodo->getTipoUsuario()
        ));

        aux = aux->getSgte();

    } while (currNodo != getCab());

    return usuarios;
}
