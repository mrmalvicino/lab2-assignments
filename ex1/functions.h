#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

const int QUANT_CHARS = 50; // Cantidad de caracteres que puede tener el nombre de una materia
const int CANT_MATERIAS = 20; // Usado en lote_de_proceso y lote_de_carga
const int CANT_MESES = 12; // Usado en lote_de_proceso
const int CANT_DIAS = 31; // Usado en lote_de_proceso

struct MATERIA{ // El codigo de cada materia esta dado por el indice de un vector de materias
    char nombre_de_materia[QUANT_CHARS];
    int cant_alumnos;
    int cant_profesores;
};

void print_char_array(char arr[], int size);
void menu_switch(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS], int march_logins[CANT_MATERIAS][CANT_DIAS]);
void cargar_lote_de_carga(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS], int march_logins[CANT_MATERIAS][CANT_DIAS]);
void mostrar_lote_de_carga(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS], int march_logins[CANT_MATERIAS][CANT_DIAS]);
void cargar_lote_de_proceso(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS], int march_logins[CANT_MATERIAS][CANT_DIAS]);
void mostrar_lote_de_proceso(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS], int march_logins[CANT_MATERIAS][CANT_DIAS]);
void consulta_A(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS], int march_logins[CANT_MATERIAS][CANT_DIAS]);
void consulta_B(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS], int march_logins[CANT_MATERIAS][CANT_DIAS]);
void consulta_C(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS], int march_logins[CANT_MATERIAS][CANT_DIAS]);

#endif // FUNCTIONS_H