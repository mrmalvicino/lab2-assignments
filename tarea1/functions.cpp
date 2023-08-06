#include <iostream>
using namespace std;
#include "functions.h"

int char_array_length(char arr[]){
    int i = 0;

    while(arr[i] != '\0'){
        i++;
    }

    return i;
}

void print_char_array(char arr[], int size){
    for(int i = 0; i < size; i ++){
        cout << arr[i];
    }
}

void cargar_lote_de_carga(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    int num_materia;

    for(int i = 0; i < CANT_MATERIAS; i ++){
        cout << endl << "Ingresar numero de materia:" << endl;
        cin >> num_materia;
        cin.ignore(); // Ignora el enter de cin >> num_materia;
        cout << endl << "Ingresar nombre de materia:" << endl;
        cin.getline(lote_de_carga[num_materia - 1].nombre_de_materia, QUANT_CHARS);
        cout << endl << "Ingresar cantidad de alumnos inscriptos:" << endl;
        cin >> lote_de_carga[num_materia - 1].cant_alumnos;
        cout << endl << "Ingresar cantidad de profesores a cargo:" << endl;
        cin >> lote_de_carga[num_materia - 1].cant_profesores;
    }

    menu_switch(lote_de_carga, lote_de_proceso);
}

void mostrar_lote_de_carga(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    for(int i = 0; i < CANT_MATERIAS; i ++){
        cout << "Materia " << i + 1 << ": ";
        print_char_array(lote_de_carga[i].nombre_de_materia, QUANT_CHARS);
        cout << endl;
        cout << "- Cantidad de alumnos inscriptos: " << lote_de_carga[i].cant_alumnos << endl;
        cout << "- Cantidad de profesores a cargo: " << lote_de_carga[i].cant_profesores << endl;
    }

    menu_switch(lote_de_carga, lote_de_proceso);
}

void cargar_lote_de_proceso(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    int num_legajo;
    int dia_acceso;
    int mes_acceso;
    int num_materia;

    cout << endl << "Ingresar numero de legajo:" << endl;
    cin >> num_legajo;

    while(num_legajo != 0){
        cout << endl << "Ingresar dia de acceso:" << endl;
        cin >> dia_acceso;

        cout << endl << "Ingresar mes de acceso:" << endl;
        cin >> mes_acceso;

        cout << endl << "Ingresar numero de materia:" << endl;
        cin >> num_materia;

        cout << endl << "Ingresar cantidad de horas:" << endl;
        cin >> lote_de_proceso[num_materia - 1][mes_acceso - 1][dia_acceso - 1];

        cout << endl << "Ingresar numero de legajo:" << endl;
        cin >> num_legajo;
    }

    menu_switch(lote_de_carga, lote_de_proceso);
}

void mostrar_lote_de_proceso(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    for(int i = 0; i < CANT_MATERIAS; i ++){
        cout << endl << "Materia " << i + 1 << ": ";
        print_char_array(lote_de_carga[i].nombre_de_materia, QUANT_CHARS);
        cout << endl;

        for(int j = 0; j < CANT_MESES; j ++){
            cout << "Mes " << j + 1 << endl;

            for(int k = 0; k < CANT_DIAS; k ++){
                cout << "Dia " << k + 1 << ": " << lote_de_proceso[i][j][k] << " hs" << endl;
            }
        }
    }

    menu_switch(lote_de_carga, lote_de_proceso);
}

void menu_switch(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    cout << "\n(1) INGRESAR LOTE DE CARGA: Cargar la informacion de las materias.\n";
    cout << "(2) MOSTRAR LOTE DE CARGA: Mostrar informacion de las materias.\n";
    cout << "(3) INGRESAR LOTE DE PROCESO: Cargar accesos de alumnos a las aulas virtuales.\n";
    cout << "(4) MOSTRAR LOTE DE PROCESO: Mostrar toda la matriz de accesos.\n";
    cout << "-------------------------\n";
    cout << "(5) CONSULTA A: Ver materias que no tuvieron acceso de alumnos nunca.\n";
    cout << "(6) CONSULTA B: Ver materia que mas cantidad de horas registro accceso de alumnos.\n";
    cout << "(7) CONSULTA C: Ver cantidad de accesos de alumnos por materia para cada dia de marzo.\n";
    cout << "-------------------------\n";
    cout << "(0) SALIR\n";
    
    int opcion;

    cin >> opcion;

    switch(opcion){
        case 1:
            cargar_lote_de_carga(lote_de_carga, lote_de_proceso);
            break;
        case 2:
            mostrar_lote_de_carga(lote_de_carga, lote_de_proceso);
            break;
        case 3:
            cargar_lote_de_proceso(lote_de_carga, lote_de_proceso);
            break;
        case 4:
            mostrar_lote_de_proceso(lote_de_carga, lote_de_proceso);
            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
    }
}

void consulta_A(){

}

void consulta_B(){
    
}

void consulta_C(){
    
}