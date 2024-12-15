#include <iostream>

#include "BinTree.hh"
#include "Caja.hh"
#include "Cliente.hh"
#include "Hora.hh"
#include "Simulacion.hh"
#include "Tienda.hh"

using namespace std;

typedef BinTree<string> BT;

int main() {
  int id = 0;
  Simulacion simulacion;
  simulacion.leerTienda();
  simulacion.leerNumCajas();
  simulacion.escribirTienda();
  string instruccion;
  while (cin >> instruccion && instruccion != "fin") {
    if (instruccion == "nuevo_cliente") {
      id++;
      Cliente cliente;
      cliente.setId(id);
      set<string> productosDeseados = cliente.setProductosDeseados();
      simulacion.añadirCliente(cliente);
      cout << "#nuevo_cliente" << endl
           << "Subarbol del cliente " << id << ":" << endl;
      BinTree<string> subArbol =
          cliente.getSubArbol(simulacion.getMapaTienda(), productosDeseados);
      cliente.printSubArbol(subArbol);
      cliente.setSubArbol(subArbol);
      cout << "Recorrido por la tienda del cliente " << id << ":" << endl;
      vector<string> instrucciones;
      cliente.recorrer_arbol(subArbol, instrucciones);
      cliente.recorrerYGuardar(cliente.readSubArbol());
      set<string> salas_a_visitar = cliente.getSalas_a_visitar();
      for (string i : salas_a_visitar) {
        cout << i << ' ';
      }
      cout << endl;
    } else if (instruccion == "quiere_comprar") {
      set<string> productosDeseados;
      int idCliente;
      cin >> idCliente;
      Cliente cliente;
      vector<Cliente> clientes = simulacion.getClientes();
      cliente = clientes[idCliente - 1];
      productosDeseados = cliente.getProductosDeseados();
      cout << "#quiere_comprar " << idCliente << endl;
      for (auto &&i : productosDeseados) {
        cout << i << ' ';
      }
      cout << endl;

    } else if (instruccion == "salas_a_visitar") {
      int idCliente;
      cin >> idCliente;
      Cliente cliente;
      vector<Cliente> clientes = simulacion.getClientes();
      cliente = clientes[idCliente - 1];
      cout << cliente.getId() << endl;
      set<string> salas_a_visitar = cliente.getSalas_a_visitar();
      cout << "#salas_a_visitar " << idCliente << endl;
      for (string i : salas_a_visitar) {
        cout << i << ' ';
      }
      cout << endl;
    } else if (instruccion == "escribir_caja") {
    } else if (instruccion == "escribir_cajas") {
    } else if (instruccion == "pago_cliente") {
    } else if (instruccion == "compra_y_no_quiere") {
    } else if (instruccion == "compran_y_no_quieren") {
    }
  }
}