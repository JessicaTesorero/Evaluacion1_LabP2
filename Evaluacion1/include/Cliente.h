#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
using namespace std;

class Cliente{
   private:
    int idCliente;
    string nombre;
    string apellido;

public:
    Cliente(int id, string nom, string ap);
    int getidCliente();
    string getNombre();
    string getApellido();
};

#endif // CLIENTE_H
