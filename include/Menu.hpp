#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "Item.hpp"
#include "Archivos.hpp"
#include "Inventario.hpp"
#include "Logica.hpp"

const int OPCION_RECOGER = 1;
const int OPCION_SOLTAR = 2;
const int OPCION_CONSULTA = 3;
const int OPCION_GUARDAR = 4;
const int OPCION_SALIR = 0;

class Menu{

private:

    std::string nombreItem;
    Logica logica;

public:

    Menu();

    void imprimirMenu();

    void logicaMenu(int opcion, Inventario inventario, const Archivos& archivos);

};

#endif