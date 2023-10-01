#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "Vector.hpp"
#include <fstream>
#include <iostream>

class Archivos{
private:
    Vector* vectorCarga;
    Vector vectorGuardado;
public:

    Archivos();

    //pre: Recibe un archivo CSV, si no existe lo crea.
    //post: Lo guarda dentro de un vector dinamico
    Vector* cargar(const std::string& archivoCSV);

    //pre: Recibe un vector y un archivo CSV objetivo, si no existe lo crea.
    //post: guarda los contenidos del vector en un archivo csv.
    void guardar(const Vector& Guardado, const std::string& archivo);

    ~Archivos();

};


#endif