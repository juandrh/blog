/*
 * AEC 2 - Práctica 2 de programación con C++
 * Realizado por Juan del Rio Huertas
 */

/* 
 * Archivo de cabecera de usuario.cpp
 */

#include <string>
#include "jugada.h"
using namespace std;

#ifndef USUARIO_H
#define USUARIO_H

typedef struct {
    string nombre;
    int saldo;
} Usuario;


void solicitarUsuario(Usuario &usuario);
void actualizarSaldo(Usuario &usuario, int numeroDado, Jugada &jugada);

#endif /* USUARIO_H */

