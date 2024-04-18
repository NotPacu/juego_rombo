
#pragma once

#include <vector>
#include <iostream>

class Tablero
{
private:
    static const int tab = 11;

    int casiilas_bloqueadas[44];
    int movimientos_cap[11];
    int movimientos_exp[11];

public:
    int size[tab];
    int numero_jugadores;
    std::vector<int *> tablero;
    std::vector<int *> tablero_bac;

    Tablero(int numero_jugadores);

    int traducir_codigo(int ficha);
    void perder_turno(int jugador_id);
    void cerrar_turno(int jugador_id);
    void imprimir_tablero();

    int *movimientos_capitan(int jugador_id);
    int *movimientos_explorador(int jugador_id);
    int mover_explorador(int jugador_id, int columna);
    // no me hago responsable si le ponen un numero que no está permitido
    // para eso le hice funciones que descartan los movimientos ilegales
    // att: jero
};

