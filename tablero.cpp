#include <vector>
#include <iostream>
/*
0: Vacío
1, 2, 3, 4: Fichas de jugadores 1, 2, 3, y 4 respectivamente.
5, 6, 7, 8: Fichas de capitanes 1, 2, 3, y 4 respectivamente.
9, 10, 11, 12: Fichas de guardianes 1, 2, 3, y 4 respectivamente.
13, 14, 15, 16: Fichas coronadas 1, 2, 3, y 4 respectivamente.

si es negativo no está confirmado
*/

#define ro "\033[31m"
#define rs "\033[0m"

/*
Documetando y trauducido por IA
si algo lean el codigo o me preguntan
Att: jero

Tablero(int numero_jugadores): Este es el constructor de la clase Tablero. Inicializa el tablero de juego con el número especificado de jugadores.
int traducir_codigo(int ficha): Este método traduce un código dado en una pieza de juego correspondiente.
bool tiene_movimientos(int *movimientos, int jugador_id): Este método verifica si el jugador con el ID dado tiene movimientos disponibles.
void perder_turno(int jugador_id): Este método marca el final del turno de un jugador, indicando que ha perdido el turno.
void cerrar_turno(int jugador_id): Este método marca el final del turno de un jugador, indicando que ha ganado el turno.
void imprimir_tablero(): Este método imprime el estado actual del tablero de juego.
int *movimientos_capitan(int jugador_id): Este método devuelve una serie de movimientos posibles para un capitán de un jugador determinado.
int *movimientos_explorador(int jugador_id): Este método devuelve una matriz de movimientos posibles para un explorador de un jugador determinado.
int mover_explorador(int jugador_id, int columna): este método mueve un explorador de un jugador determinado a una columna específica.
La clase también incluye varios métodos privados, como mover_ficha_c, que se utiliza para mover una pieza del juego. La clase tiene varias variables privadas,
incluyendo casiilas_bloqueadas que es una matriz que indica celdas bloqueadas, movimientos_cap y movimientos_exp que son matrices utilizadas para almacenar 
posibles movimientos de capitanes y exploradores respectivamente, y acciones que es una matriz utilizada para almacenar acciones. La clase también tiene
varias variables públicas, incluido size, que es una matriz utilizada para almacenar el tamaño del tablero de juego, numero_jugadores, que es el número
de jugadores en el juego, tablero y tablero_bac, que son vectores utilizados para almacenar los estados actual y de respaldo de el tablero de juego.
*/
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

void Tablero::cerrar_turno(int jugador_id)
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < size[i]; j++)
        {
            if (traducir_codigo(tablero[i][j]) == jugador_id)
            {
                tablero[i][j] = jugador_id + 8;
                tablero_bac[i][j] = tablero[i][j];
            }
        }
    }
}
void Tablero::perder_turno(int jugador_id)
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < size[i]; j++)
        {
            tablero[i][j] = tablero_bac[i][j];
        }
    }
}
int Tablero::traducir_codigo(int cod)
{
    cod = abs(cod);

    int id = cod % 4;
    if (id == 0)
        id = numero_jugadores;
    return id;
}
int *Tablero::movimientos_capitan(int jugador_id)
{
    for (int col = 0; col < 11; col++)
    {
        movimientos_cap[col] = -1;
    }
    for (int col = 0; col < 11; col++)
    {
        for (int row = 0; row < 11; row++)
        {
            if (tablero[col][row] == jugador_id + 4)
            {
                movimientos_cap[col] = col;
                return movimientos_cap;
            }
        }
    }

    for (int i = 0; i < 11; i++)
    {
        if (casiilas_bloqueadas[i + (jugador_id - 1) * 11] == 1)
        {
            movimientos_cap[i] = -1;
        }
        else
        {
            movimientos_cap[i] = i;
        }
    }
    return movimientos_cap;
}
int Tablero::mover_explorador(int jugador_id, int columna)
{
    for (int fila = size[columna] - 1; fila >= 0; fila--)
    {
        /*
        std::cout<<traducir_codigo(tablero[columna][fila])<<std::endl;
        std::cout<<fila<<std::endl;
        std::cout<<tablero[columna][fila]<<std::endl;
        */
        if (traducir_codigo(tablero[columna][fila]) == jugador_id)
        {
            for (int i = fila + 1; i <= size[columna] + 1; i++)
            {
                if (i >= size[columna])
                {
                    tablero[columna][fila] = 0;
                    return 1;
                }
                if (tablero[columna][i] == 0)
                {
                    tablero[columna][fila] = 0;
                    tablero[columna][i] = jugador_id;
                    return 0;
                }
            }
        }
    }

    if (casiilas_bloqueadas[columna + (jugador_id - 1) * 11] == 1)
    {
        return -1;
    }
    for (int fila = 0; fila <= size[columna]; fila++)
    {
        if (fila >= size[columna])
        {
            return 1;
        }
        if (tablero[columna][fila] == 0)
        {
            tablero[columna][fila] = jugador_id;
            return 0;
        }
    }
    return -1;
}
int *Tablero::movimientos_explorador(int jugador_id)
{
    for (int col = 0; col < 11; col++)
    {
        movimientos_exp[col] = -1;
    }
    return movimientos_exp;
}
Tablero::Tablero(int numero_jugadores)
{
    this->numero_jugadores = numero_jugadores;

    for (int i = 0; i <= 5; i++)
    {
        size[i] = (i + 1) * 2 + 1;
    }
    for (int i = 6; i <= 10; i++)
    {
        size[i] = ((tab - i) * 2 + 1);
    }

    for (int i = 0; i < tab; i++)
    {
        tablero.push_back(new int[size[i]]);
        tablero_bac.push_back(new int[size[i]]);
    }

    for (int i = 0; i < tab; i++)
    {
        for (int t = 0; t < size[i]; t++)
        {
            tablero[i][t] = 0;
            tablero_bac[i][t] = 0;
        }
    }

    for (int i = 0; i < 44; i++)
    {
        casiilas_bloqueadas[i] = 0;
    }
}
void Tablero::imprimir_tablero()
{
    std::cout << "\n";
    for (int i = 0; i < tab; i++)
    {
        for (int t = 0; t < size[i]; t++)
        {
            std::cout << tablero[i][t] << "  ";
        }
        std::cout << "\n";
    }

    std::cout << ro << "tablero copia\n";
    for (int i = 0; i < tab; i++)
    {
        for (int t = 0; t < size[i]; t++)
        {
            std::cout << tablero_bac[i][t] << "/";
        }
        std::cout << "\n";
    }

    std::cout << "ESTO NO ES PARA GRAFICAR SOLO PARA AYUDAR A ENCONTRAR BUGS O DEPURAR , NO USEN ESTO EN LA VERSION FINAL" << rs << "\n";
}

/*
int main()
{
    return 0;
}
*/
int main()
{
    Tablero t(4);

    t.imprimir_tablero();
    return 1111111111111;
}