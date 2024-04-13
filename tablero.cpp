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

class Tablero{
    private:
        static const int tab = 11;
        int casillas(int x);
        

    public:
        int tamanos[tab]; 
        int numero_jugadores;
        std::vector<int*> tablero;
        std::vector<int*> tablero_bac;
        
        Tablero(int numero_jugadores);
        int* retornar_columna(int columna);
        int mover_ficha(int jugador_id,int movimiento_1,int movimiento_2);
        int traducir_codigo(int ficha);
        bool tiene_movimientos(int* movimientos,int jugador_id);
        void perder_turno(int jugador_id);
        void cerrar_turno(int jugaodr_id);
        void imprimir_tablero();
};


int Tablero::traducir_codigo(int cod){
    cod = abs(cod);
   
    int id = cod%4;
    if(id == 0) id = numero_jugadores;
    return id;

}

void Tablero::imprimir_tablero(){
    for (int i = 0;i<tab;i++){
        for (int t = 0; t < tamanos[i];t++){
            std::cout<<tablero[i][t]<<"/";
        }
        std::cout<<"\n";
    }
    std::cout<<ro<<"tablero copia\n";
    for (int i = 0;i<tab;i++){
        for (int t = 0; t < tamanos[i];t++){
            std::cout<<tablero_bac[i][t]<<"/";
        }
        std::cout<<"\n";
    }
    std::cout<<"ESTO NO ES PARA GRAFICAR SOLO PARA AYUDAR A ENCONTRAR BUGS O DEPURAR , NO USEN ESTO EN LA VERSION FINAL"<<rs<<"\n";
}

int Tablero::casillas(int x){
    return (x*2+1);
}

int* Tablero::retornar_columna(int columna){
    //retorna el puntero de cada columna
    //el indice empieza desde 0
    return tablero[columna];
}



int Tablero::mover_ficha(int jugador_id,int movimiento_1,int movimiento_2){
    //retorna la cantidad de puntos coronados
    //movimiento 1 de un explorador normal
    //movimiento 2 del capitan
    int coronados = 0;
    int* c1 = retornar_columna(movimiento_1-2);
    int* c2 = retornar_columna(movimiento_2-2);

    for (int i = tamanos[movimiento_1-2];i >= 0 ;i++){
        if(traducir_codigo(c1[i]) == jugador_id){
            if (i >= tamanos[movimiento_1-2]){
                coronados++;
                
            }
        }
    }


}


Tablero::Tablero(int numero_jugadores_){
    numero_jugadores = numero_jugadores_;

    for (int i = 0;i <= 5;i++){
        tamanos[i] = casillas(i+1);
    }
    for (int i = 6;i <= 10;i++){
        tamanos[i] = casillas(tab-i);
    }

    for (int i = 0;i<tab;i++){
        tablero.push_back(new int[tamanos[i]]);
        tablero_bac.push_back(new int[tamanos[i]]);
    }

    for (int i = 0;i<tab;i++){
        for (int t = 0; t < tamanos[i];t++){
            tablero[i][t] = 0;
            tablero_bac[i][t] = 0;
        }

    }

    /*
    0-0-0-
    0-0-0-0-0-
    0-0-0-0-0-0-0-
    0-0-0-0-0-0-0-0-0-
    0-0-0-0-0-0-0-0-0-0-0-
    0-0-0-0-0-0-0-0-0-0-0-0-0-
    0-0-0-0-0-0-0-0-0-0-0-
    0-0-0-0-0-0-0-0-0-
    0-0-0-0-0-0-0-
    0-0-0-0-0-
    0-0-0-
    */
}

int main(){
    Tablero t(4);
    t.imprimir_tablero();

    return 0;
}