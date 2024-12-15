// Tienda.hh
#ifndef TIENDA_HH
#define TIENDA_HH

#include "BinTree.hh"
#include <string>
#include <vector>
#include <map>

// Clase que representa la estructura de la tienda
// Gestiona las salas y permite calcular recorridos mínimos
class Tienda
{
private:
    BinTree<std::string> arbol_salas; // Árbol binario que representa las salas de la tienda

public:
    // Constructor
    // Inicializa un árbol vacío
    Tienda();

    // Construye la tienda a partir de un vector de salas y sus conexiones
    // Cada sala tiene un identificador y conexiones izquierda y derecha
    void construirTienda(const std::vector<std::pair<std::string, std::pair<std::string, std::string>>> &salas);

    // Obtiene el árbol de salas completo
    BinTree<std::string> getArbolSalas() const;

    // Calcula el subárbol mínimo que contiene los productos deseados
    // Devuelve una lista de identificadores de salas relevantes
    std::vector<std::string> calcularSubarbolMinimo(const std::vector<std::string> &productos);

private:
    // Método recursivo para calcular el subárbol mínimo
    // Verifica si un nodo o sus hijos contienen productos deseados
    bool calcularSubarbolRec(const BinTree<std::string> &nodo, const std::vector<std::string> &productos, std::vector<std::string> &resultado);
};

#endif
