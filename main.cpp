
#include <iostream>
#include <string>
#include <cstdlib>
#include "tablero.h"
#include "movimiento.h"
#include "juego.h"
using namespace std;



string solicitaNombreFichero();

int main() {
bool cargado = false;
string nombre;
char respuesta;
int contNumPartidas = 1;
int victorias = 0, derrotas = 0;
tJuego juego;
srand(time(NULL)); //Genera los números aleatorios
int pasos = 0;

  do {
	
	cout << "----------BIENVENIDO AL SOLITARIO----------" << endl;
	cout << " " << endl;
	cout << "Desea cargar de archivo un tablero (C) o generar un tablero aleatorio (A) :"; cin >> respuesta;//Hay que responder con a o c en mayúscula
	if (respuesta == 'A') {
		generar(juego, pasos);
		cout << "Tablero aleatorio creado" << endl;
		while (juego.estado == JUGANDO) {
			ejecutarMovimiento(juego);
		}
		if (juego.estado == BLOQUEO) {
			cout << "HAS PERDIDO LA PARTIDA" << endl;
			cout << "-------------------------" << endl;
			derrotas++;
		}
		else {
			cout << "ENHORABUENA!!" << endl;
			victorias++;
		}
	}
	else {
		do {
			nombre = solicitaNombreFichero();
			cargado = cargar(juego, nombre);
			if (cargado) {
				mostrar(juego);
			
				while (juego.estado == JUGANDO) {
					ejecutarMovimiento(juego);
					
				}
				if (juego.estado == BLOQUEO) {
					cout << "HAS PERDIDO LA PARTIDA" << endl;
					cout << "-------------------------" << endl;
					derrotas++;
				}
				else {
					cout << "ENHORABUENA!!" << endl;
					cout << "-------------------" << endl;
					victorias++;
			    }

			}
			else {
				cout << "Nombre del fichero incorrecto" << endl;
				cout << "Error en la carga del juego" << endl;
				cout << "PULSE ENTER PARA INTRODUCIR EL NOMBRE DE NUEVO" << endl;
				char boton;
				boton = getchar();
				boton = getchar();
			}

		} while (!cargado);
	}
	cout << "Partida numero: " << contNumPartidas << endl;
	contNumPartidas++;
	cout << "PULSE ENTER PARA CONTINUAR" << endl; 
	char boton;
	boton = getchar();
	boton = getchar();
	cout << "-----------------------------" << endl;
	cout<<"Desea jugar de nuevo (S / N)" << endl;//Hay que responder en mayúscula
	cin >> respuesta;
} while (respuesta != 'N');
	cout << "GAME OVER" << endl;
	cout << endl;
	cout << "---Has jugado " << contNumPartidas - 1 << " partidas---" << endl;
	cout << endl;
	cout << "Has ganado : " << victorias <<" partidas" << endl;
	cout << "Has perdido: " << derrotas << " partidas" << endl;
 return 0;//Excepcion a veces
}



string solicitaNombreFichero() {
	string nombre;
	cout << "Nombre del fichero: ";
	cin >> nombre; // se introduce nombre, sin extensión
	nombre = nombre + ".txt";
	return nombre;

}
