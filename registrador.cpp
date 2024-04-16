#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Registrador
{
public:
    // Funciones para guardar y cargar la partida
    static bool guardar_partida(const string& nombre_archivo, const vector<int*>& tablero, const int* size);
    static bool cargar_partida(const string& nombre_archivo, vector<int*>& tablero, int* size);
};

bool Registrador::guardar_partida(const string& nombre_archivo, const vector<int*>& tablero, const int* size)
{
    ofstream archivo(nombre_archivo);
    if (!archivo)
    {
        cerr << "Error al abrir el archivo para guardar la partida.\n";
        return false;
    }

    // Escribir el tamaño del tablero en el archivo
    for (int i = 0; i < 11; ++i)
    {
        archivo << size[i] << " ";
    }
    archivo << endl;

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

bool Registrador::cargar_partida(const string& nombre_archivo, vector<int*>& tablero, int* size)
{
    ifstream archivo(nombre_archivo);
    if (!archivo)
    {
        cerr << "Error al abrir el archivo para cargar la partida.\n";
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
