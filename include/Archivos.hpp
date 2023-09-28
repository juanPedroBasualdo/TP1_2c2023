#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "Vector.hpp"
#include <fstream>

class Archivo{
private:

public:
    Vector cargar();

    std::ostream guardar(Vector vector);
};


#endif