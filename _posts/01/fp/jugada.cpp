/*
 * AEC 2 - Práctica 2 de programación con C++
 * Realizado por Juan del Rio Huertas
 */

/* 
 * Módulo que implementa la función que solicita 
 * al usuario los datos de la partida 
 */

#include <iostream>
#include "jugada.h"

using namespace std;

void solicitarJugada(Jugada &jugada) {

    int tipo_jugada;

    do {
        cout << "Introduzca el tipo de apuesta (1-unDado / 2-dosDados ):";
        cin.clear(); // Limpio el canal de entrada para que no se produzca error en el caso
        cin.ignore(2, '\n'); // de haber introducido un carácter no numérico anteriormente.
        cin >> tipo_jugada;
        jugada.tipo_jugada = Tipos_Jugada(tipo_jugada);
    } while (jugada.tipo_jugada < 1 || jugada.tipo_jugada > 2 || cin.fail()); //filtro para evitar valores no permitidos

    if (jugada.tipo_jugada == unDado) {
        do {
            cout << "Introduzca el número de la apuesta (de 1 a 6):";
            cin.clear(); // Limpio el canal de entrada para que no se produzca error en el caso
            cin.ignore(2, '\n'); // de haber introducido un carácter no numérico anteriormente.
            cin >> jugada.num_jugado;
        } while (jugada.num_jugado > 6 || jugada.num_jugado < 1 || cin.fail()); //filtros para evitar valores no permitidos

    } else {
        do {
            cout << "Introduzca el número de la apuesta (de 2 a 12):";
            cin.clear(); // Limpio el canal de entrada para que no se produzca error en el caso
            cin.ignore(2, '\n'); // de haber introducido un carácter no numérico anteriormente.
            cin >> jugada.num_jugado;
        } while (jugada.num_jugado > 12 || jugada.num_jugado < 2 || cin.fail()); //filtro para evitar valores no permitidos
    }
    do {
        cout << "Por favor, introduzca la cantidad de puntos que desea apostar:";
        cin.clear(); // Limpio el canal de entrada para que no se produzca error en el caso
        cin.ignore(2, '\n'); // de haber introducido un carácter no numérico anteriormente.
        cin >> jugada.cantidad_puntos;
    } while (jugada.cantidad_puntos < 0 || cin.fail()); //se permite jugar sin apostar puntos


}