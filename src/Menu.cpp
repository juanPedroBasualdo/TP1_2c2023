#include "Menu.hpp"

using namespace std;

void Menu::imprimirMenu() {
    cout << "James Sunderland" << endl
         << "--------------------------" << endl
         << "Inventario:" << endl
         << "1] Recoger objeto" << endl
         << "2] Soltar/Usar objeto" << endl
         << "3] Consultar inventario" << endl
         << "4] Guardar" << endl
         << "0] Salir y guardar" << endl;
}

void Menu::logicaMenu(int opcion, Inventario inventario, const Archivos& archivos) {
    if(opcion == OPCION_RECOGER){
        logica.logicaAltaInventario(inventario);
    } else if(opcion == OPCION_SOLTAR){
        logica.logicaBajaInventario(inventario, nombreItem);
    } else if(opcion == OPCION_CONSULTA){
        inventario.consultaInventario();
    } else if(opcion == OPCION_GUARDAR){
        inventario.guardar(archivos, "savefile.csv");
    } else if(opcion == OPCION_SALIR){
        inventario.~Inventario();
    }
}

Menu::Menu() {}

