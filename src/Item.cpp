#include "Item.hpp"
#include <iostream>

using namespace std;

Item::Item(std::string nombre, std::string tipo) {
    this->nombre = nombre;
    this->tipo = tipo;
}



void Item::listarInformacion() {
    std::cout << "Nombre: " << nombre << " Tipo: " << tipo;
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << item.nombre << ',' << item.tipo;
    return os;
}

bool Item::operator==(const std::string& s) {
    return nombre == s;
}

bool Item::puzzleDefault(std::string nombreItem) {
    bool palabraDefault;
    string nombres[4] = {"anillo", "mechero", "moneda", "llave"};
    for(string palabras : nombres){
        if (nombreItem == palabras){
            palabraDefault = true;
        } else{
            palabraDefault = false;
        }
    }
    return palabraDefault;
}

bool Item::municionDefault(std::string nombreItem) {
    bool palabraDefault;
    string nombres[4] = {"municion pistola", "municion escopeta", "municion rifle",
                         "municion revolver"};
    for(string palabras : nombres){
        if (nombreItem == palabras){
            palabraDefault = true;
        } else{
            palabraDefault = false;
        }
    }
    return palabraDefault;
}

bool Item::curativoDefault(std::string nombreItem) {
    bool palabraDefault;
    string nombres[3] = {"bebida curativa", "botiquin", "ampolla"};
    for(string palabras : nombres){
        if (nombreItem == palabras){
            palabraDefault = true;
        } else{
            palabraDefault = false;
        }
    }
    return palabraDefault;
}

