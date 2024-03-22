#include "Prestamo.h"
#include <iostream>

Prestamo::Prestamo(): numeroPrestamo(0), contadorPagos(0), montoAprobado(0), saldoPendiente(0) {
    lstPagos = new Pago[10];
}

Prestamo::Prestamo(int num, Cliente cl, Fecha fecha, float monto) : numeroPrestamo(num), cliente(cl), fechaAprobacion(fecha), montoAprobado(monto), saldoPendiente(monto), contadorPagos(0) {
    lstPagos = new Pago[10];
}

Prestamo::~Prestamo() {
    delete[] lstPagos;
}

int Prestamo::getNumeroPrestamo() {
    return numeroPrestamo;
}

void Prestamo::setNumeroPrestamo(int num) {
    numeroPrestamo = num;
}

Cliente Prestamo::getCliente() {
    return cliente;
}

void Prestamo::setCliente(Cliente cl) {
    cliente = cl;
}

void Prestamo::setFechaAprobacion(Fecha fecha) {
    fechaAprobacion = fecha;
}

Fecha Prestamo::getFechaAprobacion() {
    return fechaAprobacion;
}

void Prestamo::setMontoAprobado(float monto) {
    montoAprobado = monto;
}

float Prestamo::getMontoAprobado() {
    return montoAprobado;
}

bool Prestamo::hacerPago(Pago pago) {
    if (contadorPagos < 10) {
        lstPagos[contadorPagos++] = pago;
        saldoPendiente -= pago.getMontoPago();
        return true;
    } else {
        std::cout << "No se pueden realizar mas pagos para este prestamo." << std::endl;
        return false;
    }
}

Pago* Prestamo::getLstPagos() {
    return lstPagos;
}

float Prestamo::getSaldoPendiente() {
    return saldoPendiente;
}

int Prestamo::getContadorPagos() {
    return contadorPagos;
}
