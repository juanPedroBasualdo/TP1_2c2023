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
        Item** auxDatos = new Item*[tamanioMaximo];
        auxDatos[0] = dato;
        cantidadDatos++;
        delete[] datos;
        datos = auxDatos;
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
    Item* datoEliminar = datos[cantidadDatos];
    if(cantidadDatos == 0){
        throw VectorException();
    } else{
        Item** auxArray = new Item*[tamanioMaximo];
        for(size_t i = 0; i < cantidadDatos - 1 ; i++){
            auxArray[i] = datos[i];
        }
        cantidadDatos--;
        delete[] datos;
        datos = auxArray;
        if(cantidadDatos == (tamanioMaximo/2)){
            tamanioMaximo /= 2;
            Item** auxDatos = new Item*[tamanioMaximo];
            for(size_t i = 0 ; i < cantidadDatos ; i++){
                auxDatos[i] = datos[i];
            }
            delete[] datos;
            datos = auxDatos;
        }
    }
    return datoEliminar;
}

Item* Vector::baja(size_t indice) {
    Item* datoEliminar;
    if (cantidadDatos == 0 || indice > cantidadDatos) {
        throw VectorException();
    } else {
        datoEliminar = datos[indice];
        if (indice == cantidadDatos) {
            Item** auxArray = new Item *[tamanioMaximo];
            for (size_t i = 0; i < cantidadDatos - 1; i++) {
                auxArray[i] = datos[i];
            }
            cantidadDatos--;
            delete[] datos;
            datos = auxArray;
            if (cantidadDatos == (tamanioMaximo / 2)) {
                tamanioMaximo /= 2;
                Item **auxDatos = new Item *[tamanioMaximo];
                for (size_t i = 0; i < cantidadDatos; i++) {
                    auxDatos[i] = datos[i];
                }
                delete[] datos;
                datos = auxDatos;
            }
        } else{
            Item **auxArray = new Item *[tamanioMaximo];
            for (size_t i = 0; i < indice; i++) {
                auxArray[i] = datos[i];
            }
            for (size_t i = indice; i < cantidadDatos; i++) {
                auxArray[i] = datos[i + 1];
            }
            cantidadDatos--;
            delete[] datos;
            datos = auxArray;
            if (cantidadDatos == (tamanioMaximo / 2)) {
                tamanioMaximo /= 2;
                Item **auxDatos = new Item *[tamanioMaximo];
                for (size_t i = 0; i < cantidadDatos; i++) {
                    auxDatos[i] = datos[i];
                }
                delete[] datos;
                datos = auxDatos;
            }
        }
    }
    return datoEliminar;
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
    return *&datos[indice];
}

Vector::~Vector() {
    delete[] datos;
}

