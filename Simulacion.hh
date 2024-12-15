// Simulacion.hh
#ifndef SIMULACION_HH
#define SIMULACION_HH

#include <list>
#include <vector>

#include "Caja.hh"
#include "Cliente.hh"
#include "Hora.hh"
#include "Tienda.hh"

class Simulacion {
 private:
  int numCajas;
  BinTree<string> mapaTienda;
  vector<Cliente> clientes;

 public:
  Simulacion();
  Simulacion(BinTree<string>, int);

  void leerTienda();

  void leerNumCajas();

  void escribirTienda();

  BinTree<string> getMapaTienda() const;
  void añadirCliente(Cliente cliente);
  vector<Cliente> getClientes() const;
};

#endif
