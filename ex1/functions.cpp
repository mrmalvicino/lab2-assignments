#include <iostream>
#include "functions.h"

void print_char_array(char arr[], int size){
    for(int i = 0; i < size; i ++){
        std::cout << arr[i];
    }
}

void menu_switch(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS], int march_logins[CANT_MATERIAS][CANT_DIAS]){
    int selection = 1;

    do{
        std::cout << "\n(1) INGRESAR LOTE DE CARGA: Cargar la informacion de las materias.\n";
        std::cout << "(2) MOSTRAR LOTE DE CARGA: Mostrar informacion de las materias.\n";
        std::cout << "(3) INGRESAR LOTE DE PROCESO: Cargar accesos de alumnos a las aulas virtuales.\n";
        std::cout << "(4) MOSTRAR LOTE DE PROCESO: Recorrer matriz de preocesos para ver accesos.\n";
        std::cout << "-------------------------\n";
        std::cout << "(5) CONSULTA A: Ver materias que no tuvieron acceso de alumnos nunca.\n";
        std::cout << "(6) CONSULTA B: Ver materia que mas cantidad de horas registro accceso de alumnos.\n";
        std::cout << "(7) CONSULTA C: Ver cantidad de accesos de alumnos por materia para cada dia de marzo.\n";
        std::cout << "-------------------------\n";
        std::cout << "(0) SALIR\n";

        std::cin >> selection;

        switch(selection){
            case 1:
                cargar_lote_de_carga(lote_de_carga);
                break;
            case 2:
                mostrar_lote_de_carga(lote_de_carga);
                break;
            case 3:
                cargar_lote_de_proceso(lote_de_proceso, march_logins);
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
                consulta_C(lote_de_carga, march_logins);
                break;
        }
    } while(selection != 0);
}

void cargar_lote_de_carga(MATERIA lote_de_carga[]){
    int num_materia;

    for(int i = 0; i < CANT_MATERIAS; i ++){
        std::cout << "\nIngresar numero de materia:\n";
        std::cin >> num_materia;
        std::cin.ignore(); // Ignora el enter de std::cin >> num_materia;
        std::cout << "\nIngresar nombre de materia:\n";
        std::cin.getline(lote_de_carga[num_materia - 1].nombre_de_materia, QUANT_CHARS);
        std::cout << "\nIngresar cantidad de alumnos inscriptos:\n";
        std::cin >> lote_de_carga[num_materia - 1].cant_alumnos;
        std::cout << "\nIngresar cantidad de profesores a cargo:\n";
        std::cin >> lote_de_carga[num_materia - 1].cant_profesores;
    }
}

void mostrar_lote_de_carga(MATERIA lote_de_carga[]){
    for(int i = 0; i < CANT_MATERIAS; i ++){
        std::cout << "Materia " << i + 1 << ": ";
        print_char_array(lote_de_carga[i].nombre_de_materia, QUANT_CHARS);
        std::cout << "\n";
        std::cout << "- Cantidad de alumnos inscriptos: " << lote_de_carga[i].cant_alumnos << "\n";
        std::cout << "- Cantidad de profesores a cargo: " << lote_de_carga[i].cant_profesores << "\n";
    }
}

void cargar_lote_de_proceso(float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS], int march_logins[CANT_MATERIAS][CANT_DIAS]){
    int num_legajo;
    int dia_acceso;
    int mes_acceso;
    int num_materia;
    int cant_hs;

    std::cout << "\nIngresar numero de legajo:\n";
    std::cin >> num_legajo;

    while(num_legajo != 0){
        std::cout << "\nIngresar dia de acceso:\n";
        std::cin >> dia_acceso;

        std::cout << "\nIngresar mes de acceso:\n";
        std::cin >> mes_acceso;

        std::cout << "\nIngresar numero de materia:\n";
        std::cin >> num_materia;

        std::cout << "\nIngresar cantidad de horas:\n";
        std::cin >> cant_hs;

        lote_de_proceso[num_materia - 1][mes_acceso - 1][dia_acceso - 1] += cant_hs;

        if(mes_acceso == 3){
            march_logins[num_materia - 1][dia_acceso - 1] ++;
        }

        std::cout << "\nIngresar numero de legajo:\n";
        std::cin >> num_legajo;
    }
}

void mostrar_lote_de_proceso(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    bool flag_materia_is_print = 0; // Determina si se imprimió el nombre de la materia
    bool flag_mes_is_print = 0; // Determina si se imprimió el número de mes
    
    for(int i = 0; i < CANT_MATERIAS; i ++){
        for(int j = 0; j < CANT_MESES; j ++){
            for(int k = 0; k < CANT_DIAS; k ++){
                if(lote_de_proceso[i][j][k] != 0){
                    if(flag_materia_is_print == 0){
                        std::cout << "\nMateria " << i + 1 << ": ";
                        print_char_array(lote_de_carga[i].nombre_de_materia, QUANT_CHARS);
                        std::cout << "\n";
                        flag_materia_is_print = 1;
                    }

                    if(flag_mes_is_print == 0){
                        std::cout << "\tMes " << j + 1 << ":\n";
                        flag_mes_is_print = 1;
                    }
                    std::cout << "\t-Dia " << k + 1 << ": " << lote_de_proceso[i][j][k] << " hs\n";
                }
            }

            flag_mes_is_print = 0;
        }
    
        flag_materia_is_print = 0;
    }
}

void consulta_A(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    int sum_hs = 0;

    std::cout << "\nMaterias que no tuvieron acceso de alumnos nunca:\n\n";

    for(int i = 0; i < CANT_MATERIAS; i++){
        for(int j = 0; j < CANT_MESES; j++){
            for(int k = 0; k < CANT_DIAS; k++){
                sum_hs += lote_de_proceso[i][j][k];
            }
        }

        if(sum_hs == 0){
            std::cout << "Materia " << i + 1 << ": ";
            print_char_array(lote_de_carga[i].nombre_de_materia, QUANT_CHARS);
            std::cout << "\n";
        }

        sum_hs = 0;
    }
}

void consulta_B(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    int sum_hs = 0;
    int max_hs = 0;
    int max_index;

    std::cout << "\nMateria que mas cantidad de horas registro accceso de alumnos:\n\n";

    for(int i = 0; i < CANT_MATERIAS; i++){
        for(int j = 0; j < CANT_MESES; j++){
            for(int k = 0; k < CANT_DIAS; k++){
                sum_hs += lote_de_proceso[i][j][k];
            }
        }

        if(max_hs < sum_hs){
            max_hs = sum_hs;
            max_index = i;
        }

        sum_hs = 0;
    }

    std::cout << "\tMateria " << max_index + 1 << ": ";
    print_char_array(lote_de_carga[max_index].nombre_de_materia, QUANT_CHARS);
    std::cout << "\n";
}

void consulta_C(MATERIA lote_de_carga[], int march_logins[CANT_MATERIAS][CANT_DIAS]){
    bool flag_materia_is_print = 0; // Determina si se imprimió el nombre de la materia
    
    std::cout << "\nCantidad de accesos de alumnos por materia para cada dia de marzo:\n\n";

    for(int i = 0; i < CANT_MATERIAS; i ++){
        for(int k = 0; k < CANT_DIAS; k ++){
            if(march_logins[i][k] != 0){
                if(flag_materia_is_print == 0){
                    std::cout << "\nMateria " << i + 1 << ": ";
                    print_char_array(lote_de_carga[i].nombre_de_materia, QUANT_CHARS);
                    std::cout << "\n";
                    flag_materia_is_print = 1;
                }
                std::cout << "\t-Dia " << k + 1 << ": " << march_logins[i][k] << " accesos\n";
            }
        }

        flag_materia_is_print = 0;
    }
}