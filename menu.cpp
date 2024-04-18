#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "headers/menu.h"






Menu::Menu(int partida, int codigos, int num_jugadores) {
    nombres_jugadores = {};
    colores_jugadores = {};
    num_jugadores = 0;
    partida = 0;
    codigos = 0;
    this->partida = partida;
    this->codigos = codigos;
    this->num_jugadores = num_jugadores;
}

void Menu::preguntar_info() {
    int opcion = 0;
    std::cout << "\n\t••••••BIENVENIDO A NUESTRO JUEGO••••••" << std::endl;
    std::cout << "\nPara continuar digita la opción que sea de tu agrado para empezar" << std::endl;
    std::cout << "1. Si quieres empezar una nueva partida" << std::endl;
    std::cout << "2. Si quieres cargar una partida antigua" << std::endl;
    std::cin >> opcion;

    switch (opcion) {
    case 1:
        Menu::nueva_partida();
        break;
    case 2:
        Menu::partida_antigua();
        break;
    default:
        std::cout << "Has ingresado una opción Invalida.\nPor Favor Intentalo de nuevo" << std::endl;
        preguntar_info();
        break;
    }
}

void Menu::nueva_partida() {
    std::cout << "\nIngrese la cantidad de jugadores para la partida (2 o 4): ";
    std::cin >> num_jugadores;

    nombres_jugadores.clear();
    colores_jugadores.clear();

    for (int i = 0; i < num_jugadores; i++) {
        std::string nombre;
        std::cout << "Ingresa el nombre del jugador " << i + 1 << ": ";
        std::cin >> nombre;
        nombres_jugadores.push_back(nombre);

        std::string color;
        std::cout << "Ingresa el color de " << nombre << ": ";
        std::cin >> color;
        colores_jugadores[nombre] = color;
    }

    std::cout << "\nPartida guardada exitosamente con el código número " << partida << "." << std::endl;
}

void Menu::partida_antigua() {
    int codigo;
    std::cout << "\nPor Favor Ingresa el código de la partida antigua: ";
    std::cin >> codigo;

    std::cout << "\nPartida antigua cargada exitosamente." << std::endl;
}


