#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "Vector.hpp"
#include <fstream>

class Archivos{
private:

public:

    //pre: Recibe un archivo CSV, si no existe lo crea.
    //post: Lo guarda dentro de un vector dinamico
    static Vector cargar();

    //pre: Recibe un vector y un archivo CSV objetivo, si no existe lo crea.
    //post: guarda los contenidos del vector en un archivo csv.
    static void guardar(Vector* vector, std::istream archivoCSVObjetivo);

};


#endif