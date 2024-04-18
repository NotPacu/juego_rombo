#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Dados {
private:
    int dados[4];

public:
    Dados() {
        srand(time(0)); // Semilla para la generación de números aleatorios
    }

    // Método para lanzar los dados
    void tirar() {
        for (int i = 0; i < 4; ++i) {
            dados[i] = generar_numero();
        }
    }

    // Método para generar un número aleatorio entre 1 y 6
    int generar_numero() {
        return rand() % 6 + 1;
    }

    // Método para devolver los números de los dados
    int* devolver_numeros() {
        return dados;
    }

    // Método para devolver las sumas posibles
    int* devolver_sumas() {
        static int sumas[6];
        
        // Sumas con el dado del capitán -> con dados[0]
        sumas[0] = dados[0] + dados[1];
        sumas[1] = dados[0] + dados[2];
        sumas[2] = dados[0] + dados[3];
        
        // Sumas sin el dado del capitán -> sin dados[0]
        sumas[3] = dados[1] + dados[2];
        sumas[4] = dados[1] + dados[3];
        sumas[5] = dados[2] + dados[3];
        return sumas;
    }
};
