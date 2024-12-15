#include "Simulacion.hh"

#include <iostream>
using namespace std;
typedef BinTree<int> BT;

Simulacion::Simulacion() {}

Simulacion::Simulacion(BinTree<string>, int) {}

void Simulacion::leerTienda() {
  BinTree<string> t;
  t.setInputOutputFormat(BT::VISUALFORMAT);
  cin >> t;
  mapaTienda = t;
}
void Simulacion::leerNumCajas() {
  int x;
  cin >> x;
  numCajas = x;
}

void Simulacion::añadirCliente(Cliente cliente) { clientes.push_back(cliente); }

void Simulacion::escribirTienda() {
  cout << endl << "Organizacion de las salas:" << endl;
  mapaTienda.setInputOutputFormat(BT::VISUALFORMAT);
  cout << mapaTienda << endl;
  cout << "Hay " << numCajas << " cajas" << endl;
}

BinTree<string> Simulacion::getMapaTienda() const { return mapaTienda; }

vector<Cliente> Simulacion::getClientes() const { return clientes; }