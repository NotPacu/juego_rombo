#include "headers/graficador.h"
#include "headers/dados.h"
#include "headers/tablero.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <unordered_map> 
// -*- coding: utf-8 -*-


int contarRepeticiones(int numeros[3]) {
    // Creamos un mapa para contar las repeticiones de cada número
    std::unordered_map<int, int> contador;

    // Contamos las repeticiones de cada número en el arreglo
    for (int i = 0; i < 3; ++i) {
        int num = numeros[i];
        if (num != 0) {
            if (contador.find(num) == contador.end()) {
                contador[num] = 1; // Inicializamos el contador para este número
            } else {
                contador[num]++; // Incrementamos el contador para este número
            }
        }
    }

    // Encontramos el número con más repeticiones
    int maxRepeticiones = 0;
    for (const auto& pair : contador) {
        if (pair.second > maxRepeticiones) {
            maxRepeticiones = pair.second;
        }
    }

    return maxRepeticiones;
}
void Graficador::graficador_tablero(Tablero *tablero)
{
  std::cout << "Jugador 1: rojo, Jugador 2: azul, Jugador 3: verde, Jugador 4: "
               "amarillo"
            << std::endl;
  for (int i = 0; i < 11; i++)
  {
    if (i+2 < 10){
      std::cout<<" :  "<<i+2<<" : ";
    }else{
      std::cout<<" : "<<i+2<<" : ";
    }

    for (int j = 0; j < tablero->size[i]; j++)
    {
      int ficha = tablero->tablero[i][j];
      if (ficha == 0)
      {
        std::cout << "0 ";
      }
      else
      {
        std::string color;
        switch (ficha)
        {
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
        std::cout << color << ficha
                  << " \033[0m"; // Restaurar color predeterminado
      }
    }
    std::cout << std::endl;
  }
}

void Graficador::imprimir_turno(int turno, std::string nombre)
{
  std::string color;
  switch (turno)
  {
  case 1:
    color = "\033[31m"; // Rojo
    std::cout << color << "Es el turno del jugador 1 :" << nombre
              << "\033[0m" << std::endl;
    break;
  case 2:
    color = "\033[34m"; // Azul
    std::cout << color << "Es el turno del jugador 2 :" << nombre
              << "\033[0m" << std::endl;
    break;
  case 3:
    color = "\033[32m"; // Verde
    std::cout << color << "Es el turno del jugador 3 :" << nombre
              << "\033[0m" << std::endl;
    break;
  case 4:
    color = "\033[33m"; // Amarillo
    std::cout << color << "Es el turno del jugador 4 :" << nombre
              << "\033[0m" << std::endl;
    break;
  default:
    std::cout << "Turno inválido" << std::endl;
    break;
  }
}
/*
  color = "\033[36m"; // Cyan
  color = "\033[95m"; // Magenta claro
  color = "\033[97m";
*/
// Antes deben estar definidos los dados
std::vector<int> Graficador::mostrar_tirada(int *tirada, Tablero *tab, int jugador_id, int exp, int caps)
{
  std::cout << "\033[36m Capitan: [" << tirada[0] << " - " << tirada[1] << " - " << tirada[2] << " - " << "] \033[0m";
  std::cout << "\033[95m Exploradores: [" << tirada[3] << " - " << tirada[4] << " - " << tirada[5] << " - " << "] \033[0m" << std::endl;

  std::cout << "\033[36m Movimientos Validos [";

  int exp_val[3] = {0, 0, 0};
  int cap_val[3] = {0, 0, 0};

  int selector = 1;

  for (int i = 0; i < 3; i++)
  {

    if (tab->descartar_movimiento(jugador_id, tirada[i] - 2, true) == 1)
    {
      
      cap_val[i] = tirada[i];
    }
    else
    {
      std::cout<<"descartado : "<<tirada[i]<<std::endl;
      std::cout<<i<<":"<<jugador_id<<std::endl;
      std::cout<<tab->descartar_movimiento(jugador_id, tirada[i] - 2, true)<<std::endl;
      cap_val[i] = 0;
    }
  }
  for (int i = 3; i < 6; i++)
  {
    if (exp == 0)
    {
      break;
    }
    if (tab->descartar_movimiento(jugador_id, tirada[i] - 2, false) == 1)
    {
      exp_val[i - 3] = tirada[i];
    }
    else
    {
      exp_val[i - 3] = 0;
    }
  }


  for (int i = 0; i < 3; i++)
  {
    if (cap_val[i] != 0)
    {
      std::cout << i + 1 << ":" << cap_val[i] << " - ";
    };
  }
  std::cout << "]\033[95m [";
  for (int i = 3; i < 6; i++)
  {
    if (exp_val[i-3] != 0)
    {
      std::cout << i + 1 << ":" << exp_val[i - 3] << " - ";
    };
  }

  std::cout << "]\033[97m \n\n";

  int s1;
  int s2;
  std::cout << "Exploradores: " << tab->exp << "\n";

  int sin_exp = 0;
  int repetidas = 0;
  int exp_zeros = 0;
  int cap_zeros = 0;
  for (int i = 0; i < 3; i++)
  {
    if (exp_val[i] != 0)
    {
      if (!tab->tiene_exp(jugador_id, exp_val[i] - 2))
      {
        sin_exp += 1;
      };
    }
     if (exp_val[i] == 0){
      exp_zeros += 1;
    }
    if (cap_val[i] == 0){
      cap_zeros += 1;
    }
  }

  if (cap_zeros + exp_zeros >= 5 ){
    return {-1};
  }

  sin_exp -= contarRepeticiones(exp_val)-1;

  int test[3] = {10, 10, 10};

  for (int i = 0; i < 3; i++){
    if (cap_val[i] != 0){
      sin_exp -= 1;
      break;
    }
  }
  if (sin_exp > tab->exp){
    return {-1};
  }
  if (exp_val[0] == 0 && exp_val[1] == 0 && exp_val[2] == 0){

    return {-1};
  }

  while (true)
  {
    bool check = true;
    std::cout << "\nIngresa el primer movimiento: ";
    while (check)
    {
      while (!(std::cin >> s1))
      {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Entrada inválida. Por favor ingresa un número entero: ";
      }

      if (s1 <= 3 && s1 > 0)
      {

        if (cap_val[s1 - 1] != 0)
        {
          check = false;
        }
      }
      else if (s1 <= 6 && s1 > 3)
      {
        if (exp_val[s1 - 1] != 0)
        {
          check = false;
        }
      }

      if (check)
      {
        std::cout << "Movimiento inválido. Por favor intenta de nuevo: ";
        s1 = 0;
      }
    }

    check = true;
    while (check)
    {
      std::cout << "\nIngresa el segundo movimiento: ";
      while (!(std::cin >> s2))
      {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Entrada inválida. Por favor ingresa un número entero: ";
      }

      if (s2 <= 3 && s2 > 0)
      {

        if (cap_val[s2 - 1] != 0)
        {
          check = false;
        }
      }
      else if (s2 <= 6 && s2 > 3)
      {

        if (exp_val[s2 - 1] != 0)
        {
          check = false;
        }
      }

      if (check)
      {
        std::cout << "Movimiento inválido. Por favor intenta de nuevo: ";
        s2 = 0;
      }
    }

    if (s1 > 3 && s2 <= 3){
        int v1 = exp_val[s1 - 4];
        int v2 = cap_val[s2 - 1];

        if (v1 == v2){
          std::cout << "No puedes mover un explorador y un capitan en la misma columna\n";
          continue;
        }
    }else if (s1 <= 3 && s2 > 3){
        int v1 = cap_val[s1 - 1];
        int v2 = exp_val[s2 - 4];
        if (v1 == v2){
          std::cout << "No puedes mover un explorador y un capitan en la misma columna\n";
          continue;
        }
    }

    if (s1 != s2)
    {
      if (s1 <= 3 && s2 <= 3){

        int v1 = cap_val[s1 - 1];
        int v2 = cap_val[s2 - 1];

        if (v1 != v2){
          std::cout << "No puedes mover el capitan en 2 columnas distintas\n";
          continue;
        }
      }
      if (s1 > 3 && s2 > 3 && tab->exp == 1)
      {
        int v1 = exp_val[s1 - 4];
        int v2 = exp_val[s2 - 4];

        tab->tiene_exp(jugador_id, v1 - 2);
        tab->tiene_exp(jugador_id, v2 - 2);

        if (tab->tiene_exp(jugador_id, v1 - 2) || tab->tiene_exp(jugador_id, v2 - 2))
        {
        }
        else
        {
          std::cout << "no tiene suficientes exploradores" << std::endl;
          continue;
        }
      }
      else if (s1 > 3 && s2 > 3 && tab->exp == 0)
      {

        int v1 = exp_val[s1 - 4];
        int v2 = exp_val[s2 - 4];

        tab->tiene_exp(jugador_id, v1 - 2);
        tab->tiene_exp(jugador_id, v2 - 2);

        if (tab->tiene_exp(jugador_id, v1 - 2) && tab->tiene_exp(jugador_id, v2 - 2))
        {
        }
        else
        {
          std::cout << "no tiene suficientes exploradores" << std::endl;
          continue;
        }
      }
      break;
    }
    else
    {
      std::cout << "\nNo se puede escoger la misma suma" << std::endl;
    }
  }
  ////////////////
  std::vector<int> selec;

  if (s1 > 3)
  {
    std::cout << "explorador : " << s1 - 1 << std::endl;
    selec.push_back(exp_val[s1 - 4]);
    selec.push_back(0);
  }
  else
  {
    selec.push_back(cap_val[s1 - 1]);
    selec.push_back(1);
  }

  if (s2 > 3)
  {
    selec.push_back(exp_val[s2 - 4]);
    selec.push_back(0);
  }
  else
  {
    selec.push_back(cap_val[s2 - 1]);
    selec.push_back(1);
  }

  return selec;
}

int Graficador::continuar_jugando()
{
  char opcion;
  std::cout << "¿Deseas continuar jugando? (S/N): ";
  std::cin >> opcion;
  if (opcion == 'S' || opcion == 's')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

/*
int main() {
    //main de jero por aqui, muak muak

    Tablero tablero(4);

    graficador graficador;

    tablero.tablero[0][0] = 5;
    graficador.graficador_tablero(&tablero);

    graficador.imprimir_turno(2); //mandar numero de turno



    return 0;
}

*/
