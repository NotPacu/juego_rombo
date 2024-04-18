#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>



class Menu {
    public:
        std::vector<std::string> nombres_jugadores;
        std::map<std::string, std::string> colores_jugadores;
        int num_jugadores;
        int partida;
        int codigos;
        Menu(int partida, int codigos, int num_jugadores);
        void preguntar_info();
        void nueva_partida();
        void partida_antigua();
};