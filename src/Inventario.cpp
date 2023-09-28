#include "Inventario.hpp"

using namespace std;

Inventario::Inventario() {
    vectorInventario = new Vector();
}

void Inventario::soltarItem() {

}

void Inventario::recogerItem() {
    while(vectorInventario->tamanio() < CANT_ITEMS_MAX){
        getline(cin, nombreItem);
        if(Item::puzzleDefault(nombreItem)){
            Item* itemNuevo = new Item(nombreItem, TIPO_PUZZLE);
            vectorInventario->alta(itemNuevo);
        } else if(Item::municionDefault(nombreItem)){
            Item* itemNuevo = new Item(nombreItem, TIPO_MUNICION);
            vectorInventario->alta(itemNuevo);
        } else if(Item::curativoDefault(nombreItem)){
            Item* itemNuevo = new Item(nombreItem, TIPO_CURATIVO);
            vectorInventario->alta(itemNuevo);
        } else {
            getline(cin, tipoItem);
            if(tipoItem != TIPO_CURATIVO || tipoItem != TIPO_MUNICION || tipoItem != TIPO_PUZZLE){
                cout << "Ese tipo de item no es valido." << endl;
                getline(cin, tipoItem);
            } else{
                Item* itemNuevo = new Item(nombreItem, tipoItem);
                vectorInventario->alta(itemNuevo);
            }
        }
    }

}

void Inventario::consultaInventario() {
    Item itemActual;
    for(size_t i = 0 ; i < vectorInventario->tamanio() ; i++){
        //itemActual = vectorInventario[i];
        itemActual.listarInformacion();
    }
}

void Inventario::guardarPartida() {
   //Archivos::guardar(vectorInventario, archivo);
}

void Inventario::cargarPartida() {
    //Archivos::cargar();
}

Inventario::~Inventario() {
    delete[] vectorInventario;
}

void Inventario::soltarItem(size_t indice) {

}

void Inventario::recogerItem(size_t indice) {
    while(vectorInventario->tamanio() < CANT_ITEMS_MAX){
        getline(cin, nombreItem);
        if(Item::puzzleDefault(nombreItem)){
            Item* itemNuevo = new Item(nombreItem, TIPO_PUZZLE);
            vectorInventario->alta(itemNuevo, indice);
        } else if(Item::municionDefault(nombreItem)){
            Item* itemNuevo = new Item(nombreItem, TIPO_MUNICION);
            vectorInventario->alta(itemNuevo, indice);
        } else if(Item::curativoDefault(nombreItem)){
            Item* itemNuevo = new Item(nombreItem, TIPO_CURATIVO);
            vectorInventario->alta(itemNuevo, indice);
        } else {
            getline(cin, tipoItem);
            if(tipoItem != TIPO_CURATIVO || tipoItem != TIPO_MUNICION || tipoItem != TIPO_PUZZLE){
                cout << "Ese tipo de item no es valido." << endl;
                getline(cin, tipoItem);
            } else{
                Item* itemNuevo = new Item(nombreItem, tipoItem);
                vectorInventario->alta(itemNuevo, indice);
            }
        }
    }
}

