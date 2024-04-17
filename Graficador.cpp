#include <iostream>
#include <vector>
#include <string>


/*   AGREGAR estos metodos a la clase tablero 
 void colocar_ficha(int fila, int columna, int jugador_id) {
    tablero[fila][columna] = jugador_id;
    }

    int obtener_valor_casilla(int fila, int columna) const {
        return tablero[fila][columna];
*/

class graficador{
    public:
    void imprimir_rombo(const Tablero& tablero) {
    int mitad = 7; // Calcular la mitad del rombo
    
    // Mitad arriba
    int numCasillasVerticales = 1; 
    for (int i = 1; i <= (mitad-1); ++i) {
        // Espacios a la izquierda
        for (int j = mitad - i; j > 0; --j) {
            std::cout << " ";
        }
        // Casillas verticales
        for (int k = 0; k < numCasillasVerticales; ++k) {
            int valor = tablero.obtener_valor_casilla(i, k);
            if (valor != 0) {
                std::cout << valor; // Mostrar el valor de la ficha si hay una ficha en esta posición
            } else {
                std::cout << "0"; // Si no hay ficha, mostrar un espacio vacío
            }
        }
        std::cout << std::endl;
        numCasillasVerticales += 2; 
    }

    // Mitad
    // Espacios a la izquierda
    for (int j = 0; j < 1; ++j) {
        std::cout << " ";
    }
    // Casillas verticales
    for (int k = 0; k < 11; ++k) {
        int valor = tablero.obtener_valor_casilla(mitad, k);
        if (valor != 0) {
            std::cout << valor; // Mostrar el valor de la ficha si hay una ficha en esta posición
        } else {
            std::cout << "0"; // Si no hay ficha, mostrar un espacio vacío
        }
    }  
    std::cout << std::endl;
    
    // Mitad abajo
    for (int i = mitad - 1; i >= 1; --i) {
        // Espacios a la izquierda
        for (int j = 0; j < mitad - i; ++j) {
            std::cout << " ";
        }
        // Casillas verticales
        for (int k = 0; k < (numCasillasVerticales-2); ++k) {
            int valor = tablero.obtener_valor_casilla(i, k);
            if (valor != 0) {
                std::cout << valor; // Mostrar el valor de la ficha si hay una ficha en esta posición
            } else {
                std::cout << "0"; // Si no hay ficha, mostrar un espacio vacío
            }
        }
        std::cout << std::endl;
        numCasillasVerticales -= 2; 
    }
}

        void graficador_tablero(const Tablero* tablero) {
            std::cout << "Jugador 1: rojo, Jugador 2: azul, Jugador 3: verde, Jugador 4: amarillo" << std::endl;
            for (int i = 0; i < tablero->tab; i++) {
                for (int j = 0; j < tablero->size[i]; j++) {
                    int ficha = tablero->tablero[i][j];
                    if (ficha == 0) {
                        std::cout << "0 ";
                    } else {
                        std::string color;
                        switch (ficha) {
                            case 1:
                            case 9:
                            case 13:
                                color = "\033[31m"; // Rojo fichas jugador 1
                                break;
                            case 5:
                                color = "\033[91m"; // Rojo claro guardian 1
                                break;
                            case 2:
                            case 10:
                            case 14:
                                color = "\033[34m"; // Azul jugador 2
                                break;
                            case 6:
                                color = "\033[94m"; // azul claro guardian 2
                                break;
                            case 3:
                            case 11:
                            case 15:
                                color = "\033[32m"; // Verde jugador 3
                                break;
                            case 7:
                                color = "\033[92m"; // verde claro guardian 3
                                break;
                            case 4:
                            case 12:
                            case 16:
                                color = "\033[33m"; // Amarillo jugador 4
                                break;
                            case 8:
                                color = "\033[93m"; // Amarillo claro guardian 4
                                break;
                            default:
                                color = "\033[0m"; // Color predeterminado
                                break;
                        }
                        std::cout << color << ficha << " \033[0m"; // Restaurar color predeterminado
                    }
                }
                std::cout << std::endl; 
            }
        }
        void imprimir_tablero_rombo(const Tablero& tablero) {
            imprimir_rombo(tablero);
            std::cout << std::endl;
            graficador_tablero(&tablero);
        }

        
        void imprimir_turno(int turno){
            std::string color;
                switch (turno) {
                    case 1:
                        color = "\033[31m"; // Rojo
                        std::cout << color << "Es el turno del jugador 1" << "\033[0m" << std::endl; 
                        break;
                    case 2:
                        color = "\033[34m"; // Azul
                        std::cout << color << "Es el turno del jugador 2" << "\033[0m" << std::endl; 
                        break;
                    case 3:
                        color = "\033[32m"; // Verde
                        std::cout << color << "Es el turno del jugador 3" << "\033[0m" << std::endl; 
                        break;
                    case 4:
                        color = "\033[33m"; // Amarillo
                        std::cout << color << "Es el turno del jugador 4" << "\033[0m" << std::endl;
                        break;
                    default:
                        std::cout << "Turno inválido" << std::endl;
                        break;
                }
            
        }
        
        //Antes deben estar definidos los dados
        std::vector<int> mostrar_tirada(int* tirada){
            std::string color;
            std::cout << "Resultados de la tirada:" << std::endl;
            
            color = "\033[36m"; //Cyan
            
            std::cout << color << "1. Con el dado del capitan " << tirada[0] << std::endl;
            std::cout << "2. Con el dado del capitan " << tirada[1] << std::endl;
            std::cout << "3. Con el dado del capitan " << tirada[2] << std::endl;
            
            color = "\033[95m"; //Magenta claro
            
            std::cout << color << "4. Sin el dado del capitan " << tirada[3] << std::endl;
            std::cout << "5. Sin el dado del capitan " << tirada[4] << std::endl;
            std::cout << "6. Sin el dado del capitan " << tirada[5] << std::endl;
            
            color = "\033[97m";
            
            int a;
            int b;
            
            std::cout<< color << "Elija la primera opcion: " << std::endl;
            std::cin >> a;
            
            while (a < 1 || a > 6) {
                std::cout << "Opción no válida. Elija la primera opción nuevamente: " << std::endl;
                std::cin >> a;
                }
            
                std::cout << "Elija la segunda opcion: " << std::endl;
                std::cin >> b;
            
                while ((b < 1 || b > 6) || ((a <= 3 && b <= 3) || (a > 3 && b > 3))) {
                    std::cout << "Conflicto de opciones. Elija la segunda opción nuevamente: " << std::endl;
                    std::cin >> b;
                }
            
                std::vector<int> seleccion = {a, b};
                if (a <= 3) { // Si la primera opción es 1, 2 o 3, moverla a la primera posición
                    std::swap(seleccion[0], seleccion[1]);
                }
                
                //Siempre la primera posicion es la suma del capitan
                // Se devuelven las opciones elegidas para que avancen las fichas
                return seleccion;
        }
        
        int continuar_jugando() {
            char opcion;
            std::cout << "¿Deseas continuar jugando? (S/N): ";
            std::cin >> opcion;
            if (opcion == 'S' || opcion == 's'){
                return 1;
            }
            else{
                return 0;  
            }
        }

};


int main()
{
    //main de jero por aqui, muak muak
    Tablero tablero(4); 

    graficador graficador;

    graficador.imprimir_tablero_rombo(tablero);
    graficador.imprimir_turno(2);//mandar numero de turno
    
    //mandarle el apuntador de las sumas de los dados
    int tirada[6]; // Definir tirada antes de usarlo
    graficador.mostrar_tirada(tirada); // Pasar un puntero a tirada
     //devuelve posiciones a avanzar
    //Siempre la primera posicion es la suma del capitan
    
    int t = graficador.continuar_jugando();
    while(t=1){
        //turno de x jugador
    }
    
    return 0;
}
