#include "Logica.hpp"

using namespace std;

void Logica::logicaAltaInventario(Inventario inventario) {
    while (nombreItem != "salir") {
        cout << "Escriba el nombre del item a agregar ('salir' para terminar): ";
        cin >> nombreItem;
        if (nombreItem != "salir") {
            cout << "Escriba el tipo de item a agregar: ";
            cin >> tipoItem;
            if (tipoItem == TIPO_MUNICION || tipoItem == TIPO_PUZZLE || tipoItem == TIPO_CURATIVO) {
                item = new Item(nombreItem, tipoItem);
                inventario.recogerItem(item);
                nombreItem.clear();
                tipoItem.clear();
            } else {
                cout << "Tipo de item no valido" << endl;
            }
        }
    }
}

void Logica::logicaBajaInventario(Inventario inventario, std::string nombreItemObjetivo) {
    cout << "Que item desea Soltar/Usar? ";
    cin >> nombreItemObjetivo;
    inventario.soltarItem(nombreItemObjetivo);
    nombreItemObjetivo.clear();
}

Logica::Logica() {}

Logica::~Logica() {
    delete item;
}

