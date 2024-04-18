#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
class Registrador
{
public:
    // Funciones para guardar y cargar la partida
    bool guardar_partida(const std::string& nombre_archivo, const std::vector<int*>& tablero, const int* size);
    bool cargar_partida(const std::string& nombre_archivo, std::vector<int*>& tablero, int* size);
};