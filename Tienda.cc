// Tienda.cc
#include "Tienda.hh"
#include <algorithm> // Para std::find

// Constructor de la clase Tienda
// Inicializa un árbol binario vacío
Tienda::Tienda() : arbol_salas(BinTree<std::string>()) {}

// Método para construir la estructura de la tienda utilizando un vector de salas
// Cada sala se representa con un identificador y sus conexiones izquierda y derecha
void Tienda::construirTienda(const std::vector<std::pair<std::string, std::pair<std::string, std::string>>> &salas)
{
    std::map<std::string, BinTree<std::string>> nodos;
    for (const auto &sala : salas)
    {
        std::string id = sala.first;
        std::string izquierda = sala.second.first;
        std::string derecha = sala.second.second;

        BinTree<std::string> izquierdaNodo = izquierda.empty() ? BinTree<std::string>() : nodos[izquierda];
        BinTree<std::string> derechaNodo = derecha.empty() ? BinTree<std::string>() : nodos[derecha];
        nodos[id] = BinTree<std::string>(id, izquierdaNodo, derechaNodo);
    }
    if (!nodos.empty())
    {
        arbol_salas = nodos.begin()->second; // La raíz será la primera sala añadida
    }
}

// Método para obtener el árbol de salas completo
BinTree<std::string> Tienda::getArbolSalas() const
{
    return arbol_salas;
}

// Método para calcular el subárbol mínimo que contiene los productos deseados
// Devuelve una lista de identificadores de salas en el subárbol
std::vector<std::string> Tienda::calcularSubarbolMinimo(const std::vector<std::string> &productos)
{
    std::vector<std::string> resultado;
    calcularSubarbolRec(arbol_salas, productos, resultado);
    return resultado;
}

// Método recursivo para encontrar el subárbol mínimo
// Marca las salas relevantes para los productos deseados
bool Tienda::calcularSubarbolRec(const BinTree<std::string> &nodo, const std::vector<std::string> &productos, std::vector<std::string> &resultado)
{
    if (nodo.empty())
        return false;

    // Verificar subárbol izquierdo y derecho
    bool encontradoIzquierda = calcularSubarbolRec(nodo.left(), productos, resultado);
    bool encontradoDerecha = calcularSubarbolRec(nodo.right(), productos, resultado);

    // Si el nodo actual contiene un producto deseado o algún hijo lo contiene
    if (std::find(productos.begin(), productos.end(), nodo.value()) != productos.end() || encontradoIzquierda || encontradoDerecha)
    {
        resultado.push_back(nodo.value());
        return true;
    }

    return false;
}
