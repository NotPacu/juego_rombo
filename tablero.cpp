#include <vector>
class Tablero{
    public:
        std::vector<int*> tablero;
        
        int* retornar_columna(int columna);
        int mover_ficha(int jugador_id,int movimiento_1,int movimiento_2);
        int traducir_codigo(int ficha);
        bool tiene_movimientos(int* movimientos,int jugador_id);
        void perder_turno(int jugador_id);
};