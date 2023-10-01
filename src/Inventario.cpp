#include "Inventario.hpp"

using namespace std;

Inventario::Inventario(){
    vectorInventario = new Vector();
}

void Inventario::recibirInventarioArchivo(Vector* vector) {
    vectorInventario = vector;
}

void Inventario::soltarItem(const string& nombreItemObjetivo) {
    size_t indiceItem;
    bool itemEncontrado;
    for(size_t i = 0 ; i < vectorInventario->tamanio() ; i++){
        Item itemActual = *vectorInventario->operator[](i);
        if(itemActual.operator==(nombreItemObjetivo)){
            indiceItem = i;
            itemEncontrado = true;
        }
    }
    if(itemEncontrado){
        vectorInventario->baja(indiceItem);
        cout << "Se ha soltado/usado el objeto" << endl;
    } else{
        cout << "El nombre del item ingresado no se encuentra dentro del inventario!" << endl;
    }
}

void Inventario::recogerItem(Item* itemRecoger) {
    if (vectorInventario->tamanio() <= CANT_ITEMS_MAX) {
        vectorInventario->alta(itemRecoger);
        cout << "El item se agrego al inventario";
    } else {
        cout << "El inventario se encuentra lleno!" << endl;
    }
}

void Inventario::consultaInventario() {
    for(size_t i = 0 ; i < vectorInventario->tamanio() ; i++){
        Item itemActual = *vectorInventario->operator[](i);
        itemActual.listarInformacion();
    }
}

void Inventario::guardar(Archivos archivos , std::string archivo) {
    archivos.guardar(*vectorInventario, archivo);
}


Inventario::~Inventario() {
    delete[] vectorInventario;
}




