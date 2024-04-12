# juego rombo

## Tablero
El tablero es un vector que contiene 11 arrays de tamaño ` t = x2+1  ` 
osea  
``` c++
vector<int*> tablero
```
Para identificar cada ficha
- **0**: Vacío
- **1, 2, 3, 4**: Fichas de jugadores 1, 2, 3, y 4 respectivamente.
- **5, 6, 7, 8**: Fichas de capitanes 1, 2, 3, y 4 respectivamente.
- **9, 10, 11, 12**: Fichas de guardianes 1, 2, 3, y 4 respectivamente.

### Metodos
``` c++
tablero* retornar_tablero()
int* retornar_columna(int columna)
int mover_ficha(int jugador_id,int movimiento_1,movimiento_2)
// mover ficha retorna cuantos puntos gana en esa tirada,
// en caso de no coronar ninguna ficha retorna 0  
int traducir_codigo(int ficha)
// traducir codigo debe retorna la truduccion de la cada codigo
// de ficha a un id de jugador
// la ficha 6 es del jugador 2
bool tiene_movimientos(int* movimientos,int jugador_id)
void perder_turno(int jugador_id)
```
## Dados
La clase dados debe tener una semilla de devolver la sumas 
``` c++
srand (time(NULL));
// iniciar la semilla
```
### Metodos

``` c++v
void tirar()
int generar_numero()
int* devolver_numeros()
int+ devolver_sumas()
// primeras 3 sumas son las generales y las otras 3 son
// del capitan
```

## Jugador
La clase del jugador debe guardar la información básica del jugador tal como
``` c++
int Id
int Puntos
int guardianes_restantes
int exploradore 
string nombre 
// no es muy necesario , puede ser omitido pero debe tenerse en 
// cuenta con la parte de guardado y carga
```

### Metodos
``` c++
int mover_ficha(int jugador_id,int movimiento_1,movimiento_2)
void forzar_turno_perdido()
```

## Graficador

El graficador debe mostrar todo la parte grafica del juego excepto el menú
debe implementar colores y recibir las entradas del jugador.

### Colores
``` c++
#define ANSI_COLOR_RED "\033[31m"  
#define ANSI_COLOR_RESET "\033[0m"

int main() { 
	std::cout << ANSI_COLOR_RED << "Este texto está en rojo." << ANSI_COLOR_RESET << std::endl; 
	return  0; 
}

```
-   `\033[0m`: Restablecer todos los estilos y colores a los valores predeterminados.
-   `\033[1m`: Establecer texto en negrita o intensificado.
-   `\033[2m`: Establecer texto con intensidad baja o débil.
-   `\033[3m`: Establecer estilo de texto en cursiva (no compatible en todas las consolas).
-   `\033[4m`: Establecer subrayado de texto.
-   `\033[30m`: Establecer color de texto a negro.
-   `\033[31m`: Establecer color de texto a rojo.
-   `\033[32m`: Establecer color de texto a verde.
-   `\033[33m`: Establecer color de texto a amarillo.
-   `\033[34m`: Establecer color de texto a azul.
-   `\033[35m`: Establecer color de texto a magenta (púrpura).
-   `\033[36m`: Establecer color de texto a cyan (azul claro).
-   `\033[37m`: Establecer color de texto a blanco (gris claro).
-   `\033[90m`: Establecer color de texto a gris oscuro.
-   `\033[91m`: Establecer color de texto a rojo claro.
-   `\033[92m`: Establecer color de texto a verde claro.
-   `\033[93m`: Establecer color de texto a amarillo claro.
-   `\033[94m`: Establecer color de texto a azul claro.
-   `\033[95m`: Establecer color de texto a magenta claro.
-   `\033[96m`: Establecer color de texto a cyan claro.
-   `\033[97m`: Establecer color de texto a blanco brillante.


### Metodos
``` c++
bool* juego_activo
void referenciar_estado(bool* estado){
	juego_activo = estado
}

void imprimir_tablero(tablero* tablero)
void imprimir_turno(int turno)
void mostrar_tirada(int* tirada)
int consultar_eleccion()
bool continuar_turno()

// en caso de consultar o continuar turno reciba una X 
// 'juego_activo' debe tomar una valor de False

```
