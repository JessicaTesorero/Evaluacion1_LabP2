#include "Cliente.h"
#include <string.h>

Cliente::Cliente(int id, string nom, string ap) : idCliente(id), nombre(nom), apellido(ap) {}

int Cliente::getidCliente() {
    return idCliente;
}

string Cliente::getNombre() {
    return nombre;
}

string Cliente::getApellido() {
    return apellido;
}
