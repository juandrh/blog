/*
 * AEC 2 - Práctica 2 de programación con C++
 * Realizado por Juan del Rio Huertas
 */

/* 
 * Módulo que implementa las funciones 
 * relacionadas con el usuario
 */

#include <iostream>
#include "usuario.h"

using namespace std;

void solicitarUsuario(Usuario &usuario) {
    cout << "Introduzca su nombre:";
    cin >> usuario.nombre;

    do {
        cout << "Introduzca su saldo de puntos inicial:";
        cin.clear(); // Limpio el canal de entrada para que no se produzca error en el caso
        cin.ignore(2, '\n'); // de haber introducido un carácter no numérico anteriormente.
        cin >> usuario.saldo;
    } while (usuario.saldo < 1 || cin.fail()); //filtro para evitar valores no permitidos)
    cout << "El usuario actual es ... \e[1m" << usuario.nombre << "\e[0m y partes con un saldo de " << usuario.saldo << " puntos." << endl;
}

void actualizarSaldo(Usuario &usuario, int numeroDado, Jugada &jugada) {

    if (jugada.tipo_jugada == unDado and numeroDado == jugada.num_jugado) {

        usuario.saldo += jugada.cantidad_puntos;
        cout << " \e[1mHAS ACERTADO!!!\e[0m" << endl;

    } else if (jugada.tipo_jugada == dosDados and numeroDado == jugada.num_jugado) {

        usuario.saldo += jugada.cantidad_puntos * 2;
        cout << " \e[1mHAS ACERTADO!!!\e[0m" << endl;
    } else {
        usuario.saldo = usuario.saldo - jugada.cantidad_puntos;

    }

    cout << usuario.nombre << ", ahora tu saldo es: " << usuario.saldo << " puntos." << endl;

}