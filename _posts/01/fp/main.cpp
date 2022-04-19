/*
 * AEC 2 - Práctica 2 de programación con C++
 * Realizado por Juan del Rio Huertas
 */

/* 
 * Módulo principal 
 *  
 */

#include <iostream>
#include <cstdlib>
#include "dado.h"
#include "jugada.h"
#include "usuario.h"

using namespace std;

/*
 * 
 */
int main(void) {
    srand(time(NULL));
    Usuario usuario;
    Jugada jugada;
    int totalDados = 0;
    int valorDado = 0;

    bool salir = false;
    solicitarUsuario(usuario);

    do {
        char seguir;
        solicitarJugada(jugada);

        if (usuario.saldo >= jugada.cantidad_puntos) {

            if (jugada.tipo_jugada == unDado) {
                cout << "Tipo de apuesta solicitada: unDado." << endl;
                valorDado = tirarDado();
                cout << "Tiramos el dado y sale el..." << valorDado << endl;
                totalDados = valorDado;

            } else if (jugada.tipo_jugada == dosDados) {
                cout << "Tipo de apuesta solicitada: dosDados." << endl;
                valorDado = tirarDado();
                cout << "Tiramos el dado y sale el..." << valorDado << endl;
                totalDados = valorDado;
                valorDado = tirarDado();
                cout << "Tiramos el dado y sale el..." << valorDado << endl;
                totalDados += valorDado;
                cout << "Resultado de los dos dados: # # " << totalDados << endl;

            }
            cout << "Número elegido:" << jugada.num_jugado << endl;
            cout << "Puntos jugados:" << jugada.cantidad_puntos << endl << endl;


            actualizarSaldo(usuario, totalDados, jugada);
            totalDados = 0;

            if (usuario.saldo > 0) {
                cout << "¿Desea seguir jugando(s/n)?" << endl;
                cin >> seguir;
                if (seguir == 'n' || seguir == 'N') { // con cualquier entrada continua el juego, salvo que quiera salir
                    salir = true;
                }
            } else {
                cout << "\e[1mNo dispones de saldo para seguir jugando\e[0m" << endl;
                salir = true;
            }
        } else {

            cout << "¡¡Tu saldo de puntos es menor que los puntos apostados !!" << endl;
            cout << "Por favor, realice una nueva apuesta" << endl;
        }

    } while (!salir);

    return 0;
}

