/*
 * AEC 2 - Práctica 2 de programación con C++
 * Realizado por Juan del Rio Huertas
 */

/* 
 * Archivo de cabecera de jugada.cpp
 */

#ifndef JUGADA_H
#define JUGADA_H

enum Tipos_Jugada {
    unDado = 1, dosDados, Otras
};

typedef struct {
    Tipos_Jugada tipo_jugada;
    int num_jugado;
    int cantidad_puntos;

} Jugada;

void solicitarJugada(Jugada &jugada);

#endif /* JUGADA_H */

