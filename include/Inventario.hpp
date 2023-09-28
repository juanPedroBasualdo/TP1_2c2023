#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <cstddef>
#include <fstream>
#include <iostream>
#include "vector.hpp"
#include "Item.hpp"
#include "Archivos.hpp"

class Inventario {
private:

    const size_t CANT_ITEMS_MAX = 15;
    std::string nombreItem, tipoItem;
    Vector* vectorInventario;


public:

    Inventario();

    //pre: Debe recibir un item existente dentro del inventario.
    //post: Elimina el item del inventario.
    void soltarItem();
    void soltarItem(size_t indice);

    //pre: Debe recibir un objeto de tipo item.
    //post: Genera un nuevo item dentro del inventario y lo guarda.
    void recogerItem();
    void recogerItem(size_t indice);

    //pre: -
    //post: Muestra en pantalla todos los items dentro del inventario, con su tipo determinado.
    void consultaInventario();

    //pre: debe recibir un vector de items.
    //post: guarda los items en un archivo csv.
    void guardarPartida();

    //pre: Debe recibir un archivo csv que contenga items y sus tipos. De no existir, se crea
    //un nuevo archivo vacio.
    //post: carga el archivo dentro de un vector de items.
    void cargarPartida();

    ~Inventario();
};

#endif