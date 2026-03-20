#include <iostream>
#include <string>
using namespace std;

class Robot {
private:
    int x;
    int y;
    int direccion;

public:
    Robot(int xInicial, int yInicial, char dirInicial) {
        x = xInicial;
        y = yInicial;
        
        if(dirInicial == 'N') direccion = 0;
        else if(dirInicial == 'E') direccion = 1;
        else if(dirInicial == 'S') direccion = 2;
        else direccion = 3;
    }

    void girarDerecha() {
        direccion = (direccion + 1) % 4;
    }

    void girarIzquierda() {
        direccion = (direccion + 3) % 4;
    }

    void avanzar() {
        if(direccion == 0) y++;
        else if(direccion == 1) x++;
        else if(direccion == 2) y--;
        else x--;
    }

    void ejecutar(string instrucciones) {
        for(int i = 0; i < instrucciones.size(); i++) {
            if(instrucciones[i] == 'R') {
                girarDerecha();
            }
            else if(instrucciones[i] == 'L') {
                girarIzquierda();
            }
            else if(instrucciones[i] == 'A') {
                avanzar();
            }
        }
    }

    pair<int,int> obtenerPosicion() {
        return {x, y};
    }

    char obtenerDireccion() {
        if(direccion == 0) return 'N';
        if(direccion == 1) return 'E';
        if(direccion == 2) return 'S';
        return 'O';
    }
};
