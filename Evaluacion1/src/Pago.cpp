#include "Pago.h"

Pago::Pago(Fecha fecha, float monto) : fechaPago(fecha), montoPago(monto) {}

Fecha Pago::getFechaPago() {
    return fechaPago;
}

float Pago::getMontoPago() {
    return montoPago;
}
