#ifndef ITEM_H
#define ITEM_H

#include <string>

const std::string TIPO_PUZZLE = "PUZZLE";
const std::string TIPO_MUNICION = "MUNICION";
const std::string TIPO_CURATIVO = "CURATIVO";

class Item {
private:
    std::string nombre;
    std::string tipo;
    // Otros atributos relacionados al item.

public:
    // Constructor
    Item(std::string nombre, std::string tipo);

    // Constructor default
    Item() = default;

    // Pre: -
    // Post: Muestra por pantalla la informacion del item.
    void listarInformacion();

    // Pre: -
    // Post: Carga la informacion al stream de salida, con el formato especificado.
    // NOTA: Utilizar este metodo (archivo << item) para cargar la informacion al archivo .csv.
    friend std::ostream& operator<<(std::ostream& os, const Item& item);

    // Pre: -
    // Post: Devuelve true si el nombre coincide.
    bool operator==(const std::string& s);

    // Otros metodos relacionados al uso del item.

    //pre: debe recibir un string que sea el nombre de un item
    //post: lo compara entre distintos nombres defaults y devuelve true si coincide entre los
    //nombres de items de tipo puzzle defaults caso contrario devuelve false.
    bool puzzleDefault(std::string nombreItem);
    //nombres defaults de (algunos) items puzzle del juego: anillo, mechero, moneda, llave.

    //pre: debe recibir un string que sea el nombre de un item
    //post: devuelve true si coincide entre los nombres de items de tipo municion defaults
    //caso contrario devuelve false.
    bool municionDefault(std::string nombreItem);
    //nombres defaults de items municion del juego: municion pistola, municion escopeta,
    //municion rifle, municion revolver.

    //pre: debe recibir un string que sea el nombre de un item
    //post: devuelve true si coincide entre los nombres de items de tipo curativos default
    //caso contrario devuelve false.
    bool curativoDefault(std::string nombreItem);
    //nombres defaults de items curativos del juego: bebida curativa, botiquin, ampolla.
};

#endif