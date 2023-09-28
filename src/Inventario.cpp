#include "Inventario.hpp"



using namespace std;

void Inventario::bajaItem() {

}

void Inventario::altaItem() {

}

void Inventario::consultaInventario() {
    Item itemActual;
    for(size_t i = 0 ; i < vectorInventario->tamanio() ; i++){
        itemActual = &vectorInventario[i];
        itemActual.listarInformacion();
    }
}

void Inventario::guardarPartida() {
   //Archivos::guardar(vectorInventario, archivo);
}

void Inventario::cargarPartida() {
    Archivos::cargar();
}

