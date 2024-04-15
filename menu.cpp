#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Menu {
public:
    static vector<string> nombres_jugadores;
    static map<string, string> colores_jugadores;
    static int num_jugadores;
    static int partida;
    static int codigos;
    Menu(int partida, int codigos, int num_jugadores);
    static void preguntar_info();
    static void nueva_partida();
    static void partida_antigua();
};

vector<string> Menu::nombres_jugadores = {};
map<string, string> Menu::colores_jugadores = {};
int Menu::num_jugadores = 0;
int Menu::partida = 0;
int Menu::codigos = 0;

Menu::Menu(int partida, int codigos, int num_jugadores) {
    this->partida = partida;
    this->codigos = codigos;
    this->num_jugadores = num_jugadores;
}

void Menu::preguntar_info() {
    int opcion = 0;
    cout << "\n\t••••••BIENVENIDO A NUESTRO JUEGO••••••" << endl;
    cout << "\nPara continuar digita la opción que sea de tu agrado para empezar" << endl;
    cout << "1. Si quieres empezar una nueva partida" << endl;
    cout << "2. Si quieres cargar una partida antigua" << endl;
    cin >> opcion;

    switch (opcion) {
    case 1:
        Menu::nueva_partida();
        break;
    case 2:
        Menu::partida_antigua();
        break;
    default:
        cout << "Has ingresado una opción Invalida.\nPor Favor Intentalo de nuevo" << endl;
        preguntar_info();
        break;
    }
}

void Menu::nueva_partida() {
    cout << "\nIngrese la cantidad de jugadores para la partida (2 o 4): ";
    cin >> num_jugadores;

    nombres_jugadores.clear();
    colores_jugadores.clear();

    for (int i = 0; i < num_jugadores; i++) {
        string nombre;
        cout << "Ingresa el nombre del jugador " << i + 1 << ": ";
        cin >> nombre;
        nombres_jugadores.push_back(nombre);

        string color;
        cout << "Ingresa el color de " << nombre << ": ";
        cin >> color;
        colores_jugadores[nombre] = color;
    }

    cout << "\nPartida guardada exitosamente con el código número " << partida << "." << endl;
}

void Menu::partida_antigua() {
    int codigo;
    cout << "\nPor Favor Ingresa el código de la partida antigua: ";
    cin >> codigo;

    cout << "\nPartida antigua cargada exitosamente." << endl;
}

int main() {
    Menu::preguntar_info();
    return 0;
}
