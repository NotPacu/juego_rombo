# juego_rombo

## Tablero

El tablero del juego se representa como un vector de punteros a enteros (`int*`). Cada posición del vector representa una casilla del tablero, donde se pueden encontrar diferentes tipos de fichas:

- **0**: Vacío
- **1, 2, 3, 4**: Fichas de jugadores 1, 2, 3, y 4 respectivamente.
- **5, 6, 7, 8**: Fichas de capitanes 1, 2, 3, y 4 respectivamente.
- **9, 10, 11, 12**: Fichas de guardianes 1, 2, 3, y 4 respectivamente.

### Métodos

- `ObtenerMapa(todo)`: Retorna el mapa completo del tablero.
- `int* posiciones(int id)`: Retorna un vector de punteros a enteros que contiene las posiciones de la ficha con el ID especificado.

## Graficador

El graficador se encarga de mostrar visualmente el estado actual del tablero y otros elementos relevantes del juego.

### Funciones

- `void mostrarTablero(tablero)`: Muestra el tablero actual.
- `imprimirTurno()`: Imprime el turno actual del juego.
- `mostrarTirada()`: Muestra el resultado de la tirada de dados.
- `preguntarElección()`: Pregunta al jugador por su elección.
- `procesarTurno()`: Procesa el turno actual del jugador.
- Opción para salir del juego.

## Jugador

Representa a un jugador con su respectivo ID, nombre y puntaje.

### Atributos

- `int id`: Identificador único del jugador.
- `string nombre`: Nombre del jugador.
- `int puntaje`: Puntaje acumulado del jugador.

### Método

- `int moverFicha(int columna, int idJugador)`: Mueve la ficha del jugador identificado por `idJugador` a la columna especificada del tablero.

## Controlador

El controlador del juego gestiona los jugadores, el tablero y otros componentes clave del juego.

### Componentes

- `Vector jugadores`: Vector que contiene los jugadores del juego.
- `Objeto tablero`: Objeto que representa el tablero del juego.
- `Objeto dados`: Objeto que simula el lanzamiento de dados y devuelve los resultados.

## Menú

El menú ofrece opciones para configurar y empezar el juego.

### Opciones

- Preguntar por el número de jugadores.
- Ingresar nombres de los jugadores.
- Cargar un juego guardado o empezar uno nuevo.

## Registrador

El registrador guarda información importante del juego para poder retomarlo en el futuro.

### Guardar

Se guarda la siguiente información:

- Último estado del tablero.
- Nombres de los jugadores.
- Historial de turnos.
- Puntajes acumulados por cada jugador.
