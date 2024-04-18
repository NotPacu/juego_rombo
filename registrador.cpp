#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "headers/registrador.h"




bool Registrador::guardar_partida(const std::string& nombre_archivo, const std::vector<int*>& tablero, const int* size)
{
    std::ofstream archivo(nombre_archivo);
    if (!archivo)
    {
        std::cerr << "Error al abrir el archivo para guardar la partida.\n";
        return false;
    }

    // Escribir el tamaño del tablero en el archivo
    for (int i = 0; i < 11; ++i)
    {
        archivo << size[i] << " ";
    }
    archivo << std::endl;

    // Serializar el estado del tablero y escribirlo en el archivo
    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; j < size[i]; ++j)
        {
            archivo << tablero[i][j] << " ";
        }
    }

    archivo.close();
    return true;
}

bool Registrador::cargar_partida(const std::string& nombre_archivo, std::vector<int*>& tablero, int* size)
{
    std::ifstream archivo(nombre_archivo);
    if (!archivo)
    {
        std::cerr << "Error al abrir el archivo para cargar la partida.\n";
        return false;
    }

    // Leer el tamaño del tablero del archivo
    int valor;
    for (int i = 0; i < 11; ++i)
    {
        archivo >> size[i];
    }

    // Limpiar el tablero antes de cargar la partida
    for (int i = 0; i < tablero.size(); ++i)
    {
        delete[] tablero[i];
    }
    tablero.clear();

    // Leer los datos del archivo y cargarlos en el tablero
    int index = 0;
    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; j < size[i]; ++j)
        {
            archivo >> valor;
            if (index == 0)
            {
                tablero.push_back(new int[size[i]]);
            }
            tablero.back()[index++] = valor;
            if (index == size[i])
            {
                index = 0;
            }
        }
    }

    archivo.close();
    return true;
}
