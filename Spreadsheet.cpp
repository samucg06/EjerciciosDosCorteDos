#include <iostream>
#include <map>
#include <string>
using namespace std;

class Spreadsheet {
private:
    map<string, int> celdas;

public:
    Spreadsheet(int filas) {
    }

    void setCell(string celda, int valor) {
        celdas[celda] = valor;
    }

    void resetCell(string celda) {
        celdas.erase(celda); 
    }

    int getValue(string formula) {
        int resultado = 0;

        formula = formula.substr(1);
        
        string actual = "";
        
        for(int i = 0; i <= formula.size(); i++) {

            if(i == formula.size() || formula[i] == '+') {

                if(isdigit(actual[0])) {
                    resultado += stoi(actual);
                } else {
                    if(celdas.count(actual)) {
                        resultado += celdas[actual];
                    } else {
                        resultado += 0;
                    }
                }
                
                actual = "";
            } else {
                actual += formula[i];
            }
        }
        
        return resultado;
    }
};
