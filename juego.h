//�lvaro Gil Arjona
//V�ctor Verd� Garc�a
//Grupo: LAB 11 G12

#ifndef juego_h
#define juego_h
#include <string>
#include "tablero.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

typedef enum tEstado { JUGANDO, GANADOR, BLOQUEO };

struct tJuego {
	tTablero tablero;
	tEstado estado;
};


// Subprogramas del enunciado
// IMPORTANTE: decide cu�les permanecen p�blicos y traslada los que creas que deben ser privados (si es el caso)

bool cargar(tJuego& juego, std::string nombre);
void mostrar(const tJuego& juego);
void ejecutarMovimiento(tJuego& juego);
void generar(tJuego& juego, int pasos);





#endif