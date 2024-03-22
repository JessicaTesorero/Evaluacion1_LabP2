#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Cliente.h"
#include "Fecha.h"
#include "Pago.h"
using namespace std;
class Prestamo {
private:
    int numeroPrestamo, contadorPagos;
    Cliente cliente;
    Fecha fechaAprobacion;
    float montoAprobado, saldoPendiente;
    Pago* lstPagos;

public:
    Prestamo();
    Prestamo(int num, Cliente cl, Fecha fecha, float monto);
    ~Prestamo();
    int getNumeroPrestamo();
    void setNumeroPrestamo(int num);
    Cliente getCliente();
    void setCliente(Cliente cl);
    void setFechaAprobacion(Fecha fecha);
    Fecha getFechaAprobacion();
    void setMontoAprobado(float monto);
    float getMontoAprobado();
    bool hacerPago(Pago pago);
    Pago* getLstPagos();
    float getSaldoPendiente();
    int getContadorPagos();
};

#endif // PRESTAMO_H
