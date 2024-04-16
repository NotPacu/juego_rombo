#include <iostream>

class Juego {
private:
    bool juego_activo;

public:
    Juego() {
        juego_activo = true;  // Inicialmente el juego está activo
    }

    void referenciar_estado(bool* estado) {
        juego_activo = *estado;
    }

    int consultar_eleccion() {
        if (juego_activo) {
            // Aquí se solicita la elección del jugador
            // En este ejemplo, devolvemos un valor específico para representar una elección válida
            return 1; // Por ejemplo, 1 representa "Sí"
        } else {
            // Si el juego no está activo, devolvemos un valor especial que indica que no se puede realizar una elección
            return -1; // Por ejemplo, -1 representa que no se puede realizar una elección
        }
    }

    bool continuar_turno() {
        // El jugador puede continuar su turno si el juego está activo
        return juego_activo;
    }
};

int main() {
    Juego juego;

    // Simulamos que el juego se vuelve inactivo
    bool estado_juego = false;
    juego.referenciar_estado(&estado_juego);

    // Consultamos si el jugador puede continuar su turno
    if (juego.continuar_turno()) {
        std::cout << "El jugador puede continuar su turno." << std::endl;
    } else {
        std::cout << "El jugador no puede continuar su turno." << std::endl;
    }

    // Consultamos la elección del jugador
    int eleccion = juego.consultar_eleccion();
    if (eleccion != -1) {
        std::cout << "El jugador ha elegido la opción " << eleccion << "." << std::endl;
    } else {
        std::cout << "No se puede realizar una elección en este momento." << std::endl;
    }

    return 0;
}