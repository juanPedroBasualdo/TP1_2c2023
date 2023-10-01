#ifndef LOGICA_H
#define LOGICA_H

#include <iostream>
#include "Item.hpp"
#include "Inventario.hpp"
#include "Archivos.hpp"

class Logica{

private:

    std::string nombreItem, tipoItem;
    Item* item;

public:

    Logica();

    void logicaAltaInventario(Inventario inventario);

    void logicaBajaInventario(Inventario inventario, std::string nombreItemObjetivo);

    ~Logica();
};

#endif