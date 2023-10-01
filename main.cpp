#include <iostream>
#include "Menu.hpp"

using namespace std;

int main() {
    Inventario inventario;
    Archivos archivos;
    inventario.recibirInventarioArchivo(archivos.cargar("savefile.csv"));
    Menu menu;
    int operadorMenu = 1;
    while (operadorMenu != 0){
        menu.imprimirMenu();
        cin >> operadorMenu;
        menu.logicaMenu(operadorMenu, inventario, archivos);
        menu.imprimirMenu();
        cin >> operadorMenu;
        menu.logicaMenu(operadorMenu,inventario,archivos);
    }
    inventario.guardar(archivos, "savefile.csv");
    inventario.~Inventario();
    archivos.~Archivos();


    return 0;
}