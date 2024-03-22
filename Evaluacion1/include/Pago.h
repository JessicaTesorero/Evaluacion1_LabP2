#ifndef PAGO_H
#define PAGO_H
#include "Fecha.h"

class Pago{
   private:
    Fecha fechaPago;
    float montoPago;

public:
    Pago(Fecha fecha, float monto);
    Fecha getFechaPago();
    float getMontoPago();
};

#endif // PAGO_H
