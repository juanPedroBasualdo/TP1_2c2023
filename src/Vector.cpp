#include "Vector.hpp"
#include <string>

Vector::Vector() {
    cantidadDatos = 0;
    tamanioMaximo = 0;
    datos = new Item*[tamanioMaximo];
}

void Vector::alta(Item *dato) {
    if(tamanioMaximo == 0){
        tamanioMaximo = 1;
        datos[1] = dato;
        cantidadDatos++;
    } else if(cantidadDatos == tamanioMaximo){
        tamanioMaximo *= 2;
        Item** auxDatos = new Item*[tamanioMaximo];
        for(size_t i = 0 ; i < cantidadDatos ; i++){
            auxDatos[i] = datos[i];
        }
        auxDatos[cantidadDatos] = dato;
        cantidadDatos++;
        delete[] datos;
        datos = auxDatos;
    } else {
        datos[cantidadDatos] = dato;
        cantidadDatos++;
    }
}

void Vector::alta(Item *dato, size_t indice) {
    if(indice >= tamanioMaximo){
        throw VectorException();
    }
    else{
        if(cantidadDatos == tamanioMaximo){
            tamanioMaximo *= 2;
            Item** auxDatos = new Item*[tamanioMaximo];
            for(size_t i = 0 ; i < cantidadDatos ; i++){
                auxDatos[i] = datos[i];
            }
            auxDatos[indice] = dato;
            cantidadDatos++;
            delete[] datos;
            datos = auxDatos;
        } else{
            datos[indice] = dato;
            cantidadDatos++;
        }
    }
}

Item* Vector::baja() {

}

Item* Vector::baja(size_t indice) {

}

bool Vector::vacio() {
    bool vectorVacio;
    if(cantidadDatos == 0){
        vectorVacio = true;
    } else{
        vectorVacio = false;
    }
    return vectorVacio;
}

size_t Vector::tamanio() {
    return cantidadDatos;
}

Item*& Vector::operator[](size_t indice) {

}

Vector::~Vector() {

}

