// Caja.hh
#ifndef CAJA_HH
#define CAJA_HH

#include "Hora.hh"
#include <queue>

// Clase que representa una caja de pago
// Gestiona una cola de clientes y su tiempo de atención
class Caja
{
public:
    int id;               // Identificador único de la caja
    std::queue<int> cola; // Cola de clientes asignados a la caja
    Hora tiempoActual;    // Tiempo actual de la caja

    // Constructor
    // Inicializa la caja con un identificador y el tiempo en 0
    Caja(int id);

    // Método para asignar un cliente a la caja
    // Agrega el cliente a la cola
    void asignarCliente(int clienteId);

    // Método para procesar al siguiente cliente en la cola
    // Elimina al cliente que está al frente de la cola
    void procesar();
};

#endif
