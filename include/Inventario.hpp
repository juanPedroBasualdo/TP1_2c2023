#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.hpp"
#include <cstddef>
#include <fstream>
#include "vector.hpp"
#include "Archivos.hpp"

class Inventario {
private:

    const size_t CANT_ITEMS_MAX;
    std::string nombreItem, tipoItem;
    Item* item = new Item(nombreItem, tipoItem);
    Vector* vectorInventario = new Vector();
    std::fstream archivo;

public:

    //pre: Debe recibir un item existente dentro del inventario.
    //post: Elimina el item del inventario.
    void bajaItem();

    //pre: Debe recibir un objeto de tipo item.
    //post: Genera un nuevo item dentro del inventario y lo guarda.
    void altaItem();

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

};

#endif