// Cliente.cc
#include "Cliente.hh"

typedef BinTree<string> BT;
// Constructor de la clase Cliente
// Inicializa un cliente con un identificador único y los productos que desea
Cliente::Cliente() {};

Cliente::Cliente(int id, const set<string>& productosDeseados,
                 set<string> salas_a_visitar, BinTree<string> subArbol) {}

// Método para obtener el identificador del cliente
int Cliente::getId() const { return id; }

// Método para obtener los productos deseados por el cliente
set<string> Cliente::setProductosDeseados() {
  string producto;
  while (cin >> producto and producto != "#") {
    productosDeseados.insert(producto);
  }
  return productosDeseados;
}
void Cliente::setId(int _id) { id = _id; }
// Método para obtener el subárbol de la tienda que el cliente debe recorrer
BinTree<string> Cliente::getSubArbol(BinTree<string> arbolTienda,
                                     set<string>& productosDeseados) {
  if (arbolTienda.empty()) {
    return BinTree<string>();
  }
  BinTree<string> leftSubtree =
      getSubArbol(arbolTienda.left(), productosDeseados);
  BinTree<string> rightSubtree =
      getSubArbol(arbolTienda.right(), productosDeseados);

  if (productosDeseados.count(arbolTienda.value()) > 0 ||
      !leftSubtree.empty() || !rightSubtree.empty()) {
    return BinTree<string>(arbolTienda.value(), leftSubtree, rightSubtree);
  }

  return BinTree<string>();
}

void Cliente::printSubArbol(BinTree<string> subArbol) {
  subArbol.setInputOutputFormat(BT::VISUALFORMAT);
  cout << subArbol << endl;
}

void Cliente::recorrer_arbol(const BinTree<string>& arbol,
                             vector<string>& instrucciones) {
  if (arbol.empty()) return;

  // Procesar nodo actual (por ejemplo, imprimir el valor del nodo)
  cout << arbol.value() << endl;
  // Explorar el hijo izquierdo
  if (!arbol.left().empty()) {
    instrucciones.push_back("left");
    cout << "left" << endl;
    recorrer_arbol(arbol.left(), instrucciones);
    instrucciones.push_back("back");
    cout << "back" << endl;
  }

  // Explorar el hijo derecho
  if (!arbol.right().empty()) {
    instrucciones.push_back("right");
    cout << "right" << endl;
    recorrer_arbol(arbol.right(), instrucciones);
    instrucciones.push_back("back");
    cout << "back" << endl;
  }
}
set<string> Cliente::getProductosDeseados() const { return productosDeseados; }

void Cliente::insertSalas_a_visitar(string sala) {
  cout << sala << endl;
  this->salas_a_visitar.insert(sala);
}

void Cliente::comprovacion() const { cout << salas_a_visitar.size() << endl; }

set<string> Cliente::getSalas_a_visitar() {
  // cout << "#salas_a_visitar " << idCliente << endl;
  for (string i : salas_a_visitar) {
    cout << i << "& ";
  }
  return this->salas_a_visitar;
}
// vector<string> Cliente::getInstrucciones() const { return instrucciones; }

void Cliente::setSubArbol(const BinTree<string>& subArbol) {
  this->subArbol = subArbol;
}
BinTree<string> Cliente::readSubArbol() const { return subArbol; }

void Cliente::recorrerYGuardar(const BinTree<string>& arbol) {
  if (arbol.empty()) return;

  // Añadir el valor del nodo actual al set
  cout << salas_a_visitar.size() << endl;
  this->salas_a_visitar.insert(arbol.value());

  // Recorrer el hijo izquierdo
  recorrerYGuardar(arbol.left());

  // Recorrer el hijo derecho
  recorrerYGuardar(arbol.right());
  cout << salas_a_visitar.size() << endl;
}