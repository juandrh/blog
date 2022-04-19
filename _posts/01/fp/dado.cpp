/*
 * AEC 2 - Práctica 2 de programación con C++
 * Realizado por Juan del Rio Huertas
 */

/* 
 * Módulo que implementa la generación aleatoria de tirada de dado
 */

#include <cstdlib>
#include "dado.h"

int tirarDado() {

    return rand() % 6 + 1;

}