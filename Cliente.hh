// Cliente.hh
#ifndef CLIENTE_HH
#define CLIENTE_HH

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "BinTree.hh"
#include "Hora.hh"
using namespace std;

// Clase que representa a un cliente
// Gestiona sus productos deseados y las instrucciones para recorrer la tienda
class Cliente {
 private:
  // Identificador único del cliente
  Hora horaCaja;  // Hora a la que el cliente llega a la caja

  set<string> productosDeseados;  // Productos deseados por el cliente
  int id;                         // Identificador único del cliente
  vector<string> instrucciones;   // Instrucciones para recorrer la tienda
  set<string> salas_a_visitar;    // Salas que el cliente debe visitar
  int contador = 0;
  BinTree<string>
      subArbol;  // Subárbol de la tienda que el cliente debe recorrer

 public:
  // Constructor de la clase Cliente
  // Inicializa un cliente con un identificador único y los productos que desea
  Cliente();
  Cliente(int id, const set<string> &productosDeseados,
          set<string> salas_a_visitar, BinTree<string> subArbol);

  // Método para obtener el identificador del cliente
  int getId() const;

  // Método para obtener los productos deseados por el cliente
  set<string> setProductosDeseados();

  // Método para obtener el subárbol de la tienda que el cliente debe recorrer
  BinTree<string> getSubArbol(BinTree<string>, set<string> &productosDeseados);

  // Método para obtener la hora a la que el cliente llega a la caja
  Hora getHoraCaja() const;

  // Método para asignar el subárbol de la tienda que el cliente debe recorrer
  void setSubArbol(const BinTree<string> &subArbol);

  // Método para asignar la hora a la que el cliente llega a la caja
  void setHoraCaja(const Hora &horaCaja);

  void setId(int id);

  void printSubArbol(BinTree<string> subArbol);

  void recorrer_arbol(const BinTree<string> &arbol,
                      vector<string> &instrucciones);
  // vector<string> getInstrucciones() const;
  set<string> getProductosDeseados() const;
  set<string> getSalas_a_visitar();
  void insertSalas_a_visitar(string sala);
  void comprovacion() const;
  set<string> getSalas_a_visitar() const;
  void printSalas();
  BinTree<string> readSubArbol() const;
  void recorrerYGuardar(const BinTree<string> &arbol);
};

#endif
