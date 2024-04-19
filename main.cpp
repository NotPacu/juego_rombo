#include "headers/dados.h"
#include "headers/graficador.h"
#include "headers/jugador.h"
#include "headers/menu.h"
#include "headers/registrador.h"
#include "headers/tablero.h"
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <string>
#include <windows.h>
#include <cctype>

#undef max
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#include <limits>

#ifdef _WIN32

bool EnableVTMode()
{
    // Set output mode to handle virtual terminal sequences
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return false;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    return SetConsoleMode(hOut, dwMode) != 0;
}

#endif

// Ejecute el archivo compile.bat
// eso le crea el exe
// si está trabajando en replit le toca averigurar como compilar

class juego
{
    int jugadores;
    int turno_actual;
    int turnos_totales;
    Menu menu_m;
    Graficador graficador_m;
    Dados dados_m;
    Tablero tablero_m = Tablero(4);
    int puntos[4] = {0, 0, 0, 0};
    int puntos_para_ganar = 100;

public:
    juego();
    void start();
    void mainloop();
};

juego::juego()
{
    dados_m = Dados();
    menu_m = Menu();
    graficador_m = Graficador();
}
void juego::start()
{

    menu_m.preguntar_info();
    jugadores = menu_m.num_jugadores;
    turno_actual = 1;
    turnos_totales = 0;
    system("cls");
    mainloop();
}

void juego::mainloop()
{
    int exp = 2;
    int caps = 1;
    while (true)
    {
        graficador_m.imprimir_turno(turno_actual, menu_m.nombres_jugadores[turno_actual - 1]);
        dados_m.tirar();
        graficador_m.graficador_tablero(&tablero_m);
        std::vector<int> selec = graficador_m.mostrar_tirada(dados_m.devolver_sumas(), &tablero_m, turno_actual, exp, caps);

        if (selec[0] == -1)
        {
            
            std::cout<<"\033[33mNo tiene jugadas posibles, pierde el turno \033[0m\nPresiona una tecla para continuar...";
            getch();
            system("cls");
            tablero_m.perder_turno(turno_actual);
        }
        else
        {

            std::cout << "\n";
            
            if (selec[1] == 0)
            {
                int pts = tablero_m.mover_explorador(turno_actual, selec[0] - 2);
                if (pts < 0){
                    std::cout<<"error : "<<pts<<selec[0]<<std::endl;
                }
                puntos[turno_actual - 1] += pts;

            }
            else if (selec[1] == 1)
            {
                int pts = tablero_m.mover_capitan(turno_actual, selec[0] - 2);
                if (pts < 0){
                    std::cout<<"error : "<<pts<<selec[0]<<std::endl;
                }
                puntos[turno_actual - 1] += pts;
            }

            if (selec[3] == 0)
            {
                int pts =tablero_m.mover_explorador(turno_actual, selec[2] - 2);
                if (pts < 0){
                    std::cout<<"error : "<<pts<<selec[0]<<std::endl;
                }
                puntos[turno_actual - 1] += pts;
                
            }
            else if (selec[3] == 1)
            {
                int pts =tablero_m.mover_capitan(turno_actual, selec[2] - 2);
                if (pts < 0){
                    std::cout<<"error : "<<pts<<selec[0]<<std::endl;
                }
                puntos[turno_actual - 1] += pts;

            }
            //system("cls");
            graficador_m.graficador_tablero(&tablero_m);

            char option = ' ';
            std::cout << "Selecione X para salir \nSelecione S para tirar otra vez \nSelecione P para terminar turno\nSelecion: ";
            bool entradaValida = false;
            do {
                
                std::cout << "Ingrese un solo caracter: ";
                std::cin >> option;

                // Verificar si se ingresó solo un caracter
                if (std::cin.peek() == '\n') { // Verifica si el siguiente caracter es una nueva línea
                    entradaValida = true;
                } else {
                    std::cout << "Error: Ingrese solo un caracter. Intentelo de nuevo." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer de entrada
                }
                if (tolower(option) != 'x' && tolower(option) != 's' && tolower (option) != 'p'){
                    entradaValida = false;
                    std::cout << "\nIngrese un valor valido" << std::endl;
                }


            } while (!entradaValida);

            system("cls");
            if (tolower(option) == 'p')
            {
                tablero_m.cerrar_turno(turno_actual);
            }
            else if (tolower(option) == 's')
            {
                continue;
            }else{
                break;
            }

            
        }

        turno_actual = (turno_actual) % jugadores + 1;
    }
}

int main()
{

    setlocale(LC_ALL, "spanish");
#ifdef _WIN32
    EnableVTMode();
#endif

    juego mjg; // Declare an object of type juego

    mjg.start();

    return 1;
}