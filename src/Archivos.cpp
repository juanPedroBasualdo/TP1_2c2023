#include "Archivos.hpp"

using namespace std;

Archivos::Archivos() {
    vectorCarga = new Vector;
}

Vector* Archivos::cargar(const string& archivoCSV) {
    ifstream archivoCarga(archivoCSV);
    if(!archivoCarga.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
    } else{
        string linea;
        string lineas[2] = {};
        while(getline(archivoCarga,linea)){
            string carga;
            for(char caracterLinea : linea){
                if(caracterLinea == ','){
                    lineas[0] = carga;
                    carga.clear();
                }else{
                    carga += caracterLinea;
                }
                lineas[1] = carga;
            }
            Item* itemCarga = new Item(lineas[0], lineas[1]);
            vectorCarga->alta(itemCarga);
            lineas[0] = ' ';
            lineas[1] = ' ';
        }
    }
    archivoCarga.close();
    return vectorCarga;
}

void Archivos::guardar(const Vector& Guardado, const string& archivoCSV) {
    ofstream archivoGuardado(archivoCSV);
    if(!archivoGuardado.is_open()){
        cout << "No se pudo realizar el guardado." << endl;
    } else{
        vectorGuardado = Guardado;
        for(size_t itemId = 0; itemId < vectorGuardado.tamanio() ; itemId++){
            Item itemActual = *vectorGuardado.operator[](itemId);
            operator<<(archivoGuardado, itemActual);
            archivoGuardado << "\n";
        }
    }
    archivoGuardado.close();
}

Archivos::~Archivos() {
    vectorCarga->~Vector();
    vectorGuardado.~Vector();
}


