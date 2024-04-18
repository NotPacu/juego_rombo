#pragma once
#include "tablero.h"

class graficador
{
public:
    void graficador_tablero(Tablero *tablero);
    void imprimir_turno(int turno);
    std::vector<int> mostrar_tirada(int *tirada);
    int continuar_jugando();
};