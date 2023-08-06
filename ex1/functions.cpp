#include <iostream>
using namespace std;
#include "functions.h"

void print_char_array(char arr[], int size){
    for(int i = 0; i < size; i ++){
        cout << arr[i];
    }
}

void menu_switch(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    cout << "\n(1) INGRESAR LOTE DE CARGA: Cargar la informacion de las materias.\n";
    cout << "(2) MOSTRAR LOTE DE CARGA: Mostrar informacion de las materias.\n";
    cout << "(3) INGRESAR LOTE DE PROCESO: Cargar accesos de alumnos a las aulas virtuales.\n";
    cout << "(4) MOSTRAR LOTE DE PROCESO: Recorrer matriz de preocesos para ver accesos.\n";
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
            consulta_A(lote_de_carga, lote_de_proceso);
            break;
        case 6:
            consulta_B(lote_de_carga, lote_de_proceso);
            break;
        case 7:
            consulta_C(lote_de_carga, lote_de_proceso);
            break;
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

    //menu_switch(lote_de_carga, lote_de_proceso);
}

void mostrar_lote_de_carga(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    for(int i = 0; i < CANT_MATERIAS; i ++){
        cout << "Materia " << i + 1 << ": ";
        print_char_array(lote_de_carga[i].nombre_de_materia, QUANT_CHARS);
        cout << endl;
        cout << "- Cantidad de alumnos inscriptos: " << lote_de_carga[i].cant_alumnos << endl;
        cout << "- Cantidad de profesores a cargo: " << lote_de_carga[i].cant_profesores << endl;
    }

    //menu_switch(lote_de_carga, lote_de_proceso);
}

void cargar_lote_de_proceso(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    int num_legajo;
    int dia_acceso;
    int mes_acceso;
    int num_materia;
    int cant_hs;

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
        cin >> cant_hs;

        lote_de_proceso[num_materia - 1][mes_acceso - 1][dia_acceso - 1] += cant_hs;

        cout << endl << "Ingresar numero de legajo:" << endl;
        cin >> num_legajo;
    }

    //menu_switch(lote_de_carga, lote_de_proceso);
}

void mostrar_lote_de_proceso(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    bool flag_materia_is_print = 0; // Determina si se imprimió el nombre de la materia
    bool flag_mes_is_print = 0; // Determina si se imprimió el número de mes
    
    for(int i = 0; i < CANT_MATERIAS; i ++){
        for(int j = 0; j < CANT_MESES; j ++){
            for(int k = 0; k < CANT_DIAS; k ++){
                if(lote_de_proceso[i][j][k] != 0){
                    if(flag_materia_is_print == 0){
                        cout << endl << "Materia " << i + 1 << ": ";
                        print_char_array(lote_de_carga[i].nombre_de_materia, QUANT_CHARS);
                        cout << endl;
                        flag_materia_is_print = 1;
                    }

                    if(flag_mes_is_print == 0){
                        cout << "\tMes " << j + 1 << ":\n";
                        flag_mes_is_print = 1;
                    }
                    cout << "\t-Dia " << k + 1 << ": " << lote_de_proceso[i][j][k] << " hs" << endl;
                }
            }

            flag_mes_is_print = 0;
        }
    
    flag_materia_is_print = 0;
    }

    //menu_switch(lote_de_carga, lote_de_proceso);
}

void consulta_A(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    int sum_hs = 0;

    cout << "\nMaterias que no tuvieron acceso de alumnos nunca:\n\n";

    for(int i = 0; i < CANT_MATERIAS; i++){
        for(int j = 0; j < CANT_MESES; j++){
            for(int k = 0; k < CANT_MESES; k++){
                sum_hs += lote_de_proceso[i][j][k];
            }
        }

        if(sum_hs == 0){
            cout << "Materia " << i + 1 << ": ";
            print_char_array(lote_de_carga[i].nombre_de_materia, QUANT_CHARS);
            cout << "\n";
        }

        sum_hs = 0;
    }
}

void consulta_B(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    int sum_hs = 0;
    int max_hs = 0;
    int max_index;

    cout << "\nMateria que mas cantidad de horas registro accceso de alumnos:\n\n";

    for(int i = 0; i < CANT_MATERIAS; i++){
        for(int j = 0; j < CANT_MESES; j++){
            for(int k = 0; k < CANT_MESES; k++){
                sum_hs += lote_de_proceso[i][j][k];
            }
        }

        if(max_hs < sum_hs){
            max_hs = sum_hs;
            max_index = i;
        }

        sum_hs = 0;
    }

    cout << "\tMateria " << max_index + 1 << ": ";
    print_char_array(lote_de_carga[max_index].nombre_de_materia, QUANT_CHARS);
    cout << "\n";
}

void consulta_C(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    cout << "\nCantidad de accesos de alumnos por materia para cada dia de marzo:\n\n";
}