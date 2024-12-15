// Caja.cc
#include "Caja.hh"

// Constructor de la clase Caja
// Inicializa la caja con un identificador y establece el tiempo actual a 0:0:0
Caja::Caja(int id) : id(id), tiempoActual(0, 0, 0) {}

// Método para asignar un cliente a la cola de esta caja
// Recibe el identificador del cliente y lo agrega al final de la cola
void Caja::asignarCliente(int clienteId)
{
    cola.push(clienteId);
}

// Método para procesar al siguiente cliente en la cola
// Elimina el cliente que está al frente de la cola (si la cola no está vacía)
void Caja::procesar()
{
    if (!cola.empty())
    {
        cola.pop();
    }
}
