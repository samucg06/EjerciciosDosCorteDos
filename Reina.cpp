#include <iostream>
#include <stdexcept>
using namespace std;

class Reina {
public:
    int fila;
    int columna;

    Reina(int f, int c) {
        if(f < 0 || f > 7 || c < 0 || c > 7) {
            throw invalid_argument("Posicion fuera del tablero");
        }
        fila = f;
        columna = c;
    }
};

bool puedenAtacarse(Reina r1, Reina r2) {

    if(r1.fila == r2.fila && r1.columna == r2.columna) {
        throw invalid_argument("Misma posicion");
    }

    if(r1.fila == r2.fila) return true;

    if(r1.columna == r2.columna) return true;

    if(abs(r1.fila - r2.fila) == abs(r1.columna - r2.columna)) return true;

    return false;
}
