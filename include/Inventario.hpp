#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <cstddef>
#include <fstream>
#include <iostream>
#include "Vector.hpp"
#include "Item.hpp"
#include "Archivos.hpp"

class Inventario {
private:

    const size_t CANT_ITEMS_MAX = 15;
    Vector* vectorInventario;


public:

    Inventario();

    void recibirInventarioArchivo(Vector* vector);

    //pre: Debe recibir el nombre de un item existente dentro del inventario.
    //post: Elimina el item del inventario, de no existir el item, .
    void soltarItem(const std::string& nombreItemObjetivo);

    //pre: Debe recibir un objeto de tipo item.
    //post: Genera un nuevo item dentro del inventario y lo guarda.
    void recogerItem(Item* item);

    //pre: -
    //post: Muestra en pantalla todos los items dentro del inventario, con su tipo determinado.
    void consultaInventario();

    void guardar(Archivos archivos, std::string archivo);

    ~Inventario();
};

#endif