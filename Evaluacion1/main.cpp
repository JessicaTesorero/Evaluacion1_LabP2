#include "Cliente.h"
#include "Fecha.h"
#include "Pago.h"
#include "Prestamo.h"
#include <iostream>
#include <vector>

using namespace std;

void mostrarMenu() {
    cout << "MENU DE OPCIONES" << endl;
    cout << "1. Agregar clientes a la lista" << endl;
    cout << "2. Agregar prestamo a la lista" << endl;
    cout << "3. Hacer pagos de prestamos" << endl;
    cout << "4. Mostrar lista de clientes" << endl;
    cout << "5. Mostrar lista de prestamos" << endl;
    cout << "6. Mostrar detalles del prestamo" << endl;
    cout << "7. Salir" << endl;
}

int main() {
    vector<Cliente> listaClientes;
    vector<Prestamo> listaPrestamos;

    int opcion;

    do {
        mostrarMenu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int id;
                string nombre, apellido;

                cout << "Ingrese el codigo del cliente: ";
                cin >> id;
                cout << "Ingrese el nombre del cliente: ";
                cin >> nombre;
                cout << "Ingrese el apellido del cliente: ";
                cin >> apellido;

                Cliente cliente(id, nombre, apellido);
                listaClientes.push_back(cliente);

                cout << "Cliente agregado exitosamente." << endl;
                break;
            }

            case 2: {
                int codigoCliente, numeroPrestamo;
                float montoAprobado;
                Fecha fechaAprobacion;

                cout << "Ingrese el codigo del cliente: ";
                cin >> codigoCliente;

                bool clienteEncontrado = false;
                Cliente cliente;

                for (const auto &c : listaClientes) {
                    if (c.getidCliente() == codigoCliente) {
                        clienteEncontrado = true;
                        cliente = c;
                        break;
                    }
                }

                if (!clienteEncontrado) {
                    cout << "No se encontro el cliente. No se puede agregar el prestamo." << endl;
                    break;
                }

                cout << "Ingrese el numero del prestamo: ";
                cin >> numeroPrestamo;
                cout << "Ingrese la fecha de aprobacion (DD MM AA): ";
                int dia, mes, anio;
                cin >> dia >> mes >> anio;
                fechaAprobacion = Fecha(dia, mes, anio);
                cout << "Ingrese el monto aprobado: ";
                cin >> montoAprobado;

                Prestamo prestamo(numeroPrestamo, cliente, fechaAprobacion, montoAprobado);
                listaPrestamos.push_back(prestamo);

                cout << "Prestamo agregado exitosamente." << endl;
                break;
            }

            case 3: {
                int numeroPrestamo;
                float montoPago;
                Fecha fechaPago;

                cout << "Ingrese el numero del prestamo: ";
                cin >> numeroPrestamo;

                bool prestamoEncontrado = false;
                Prestamo prestamo;

                for (auto &p : listaPrestamos) {
                    if (p.getNumeroPrestamo() == numeroPrestamo) {
                        prestamoEncontrado = true;
                        prestamo = p;
                        break;
                    }
                }

                if (!prestamoEncontrado) {
                    cout << "No se encontro el prestamo. No se puede realizar el pago." << endl;
                    break;
                }

                cout << "Ingrese la fecha del pago (DD MM AA): ";
                int dia, mes, anio;
                cin >> dia >> mes >> anio;
                fechaPago = Fecha(dia, mes, anio);
                cout << "Ingrese el monto del pago: ";
                cin >> montoPago;

                Pago pago(fechaPago, montoPago);

                if (prestamo.hacerPago(pago)) {
                    cout << "Pago realizado exitosamente." << endl;
                } else {
                    cout << "Error al realizar el pago. Verifique el numero del prestamo." << endl;
                }

                break;
            }

            case 4: {
                cout << "Lista de clientes:" << endl;
                for (const auto &cliente : listaClientes) {
                    cout << "Codigo: " << cliente.getidCliente() << ", Nombre: " << cliente.getNombre() << " " << cliente.getApellido() << endl;
                }
                break;
            }

            case 5: {
                cout << "Lista de prestamos:" << endl;
                for (const auto &prestamo : listaPrestamos) {
                    cout << "Numero de prestamo: " << prestamo.getNumeroPrestamo() << ", Monto aprobado: " << prestamo.getMontoAprobado() << ", Saldo pendiente: " << prestamo.getSaldoPendiente() << endl;
                }
                break;
            }

            case 6: {
                int numeroPrestamo;

                cout << "Ingrese el numero del prestamo: ";
                cin >> numeroPrestamo;

                bool prestamoEncontrado = false;

                for (const auto &prestamo : listaPrestamos) {
                    if (prestamo.getNumeroPrestamo() == numeroPrestamo) {
                        prestamoEncontrado = true;

                        cout << "Detalles del prestamo:" << endl;
                        cout << "N�mero de prestamo: " << prestamo.getNumeroPrestamo() << endl;
                        cout << "Cliente: Codigo " << prestamo.getCliente().getidCliente() << ", Nombre: " << prestamo.getCliente().getNombre() << " " << prestamo.getCliente().getApellido() << endl;
                        cout << "Fecha de aprobacion: ";
                        prestamo.getFechaAprobacion().mostrarFecha();
                        cout << "Monto aprobado: " << prestamo.getMontoAprobado() << endl;
                        cout << "Saldo pendiente: " << prestamo.getSaldoPendiente() << endl;

                        cout << "Pagos realizados:" << endl;
                        Pago *pagos = prestamo.getLstPagos();
                        for (int i = 0; i < prestamo.getContadorPagos(); ++i) {
                            cout << "Pago " << i + 1 << ": Fecha ";
                            pagos[i].getFechaPago().mostrarFecha();
                            cout << ", Monto: " << pagos[i].getMontoPago
                            cout << "Pago " << i + 1 << ": Fecha ";
                            pagos[i].getFechaPago().mostrarFecha();
                            cout << ", Monto: " << pagos[i].getMontoPago() << endl;
                        }

                        break;
                    }
                }

                if (!prestamoEncontrado) {
                    cout << "Prestamo no encontrado." << endl;
                }

                break;
            }

            case 7:
                cout << "Saliendo del programa" << endl;
                break;

            default:
                cout << "Opcion no valida. Por favor, elija una opcion correcta" << endl;
        }

    } while (opcion != 7);

    return 0;
}
