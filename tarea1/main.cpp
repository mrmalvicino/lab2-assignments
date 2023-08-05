/*
LAS AUTORIDADES DE LA CARRERA TUP DE LA UTN ESTÁN REALIZANDO UN ANÁLISIS DE LOS CURSOS VIRTUALES DE LAS DISTINTAS MATERIAS.

POR CADA UNA DE LAS 20 MATERIAS DE LA CARRERA SE TIENE LA SIGUIENTE INFORMACIÓN:

- NÚMERO DE MATERIA (ENTRE 1 Y 20)
- NOMBRE
- CANTIDAD DE ALUMNOS INSCRIPTOS
- CANTIDAD DE PROFESORES

ADEMÁS, POR CADA INGRESO DE LOS ESTUDIANTES AL AULA VIRTUAL SE REGISTRA LO SIGUIENTE:

- LEGAJO
- FECHA DE ACCESO (DÍA Y MES)
- NÚMERO DE LA MATERIA A LA QUE INGRESA
- CANTIDAD DE HORAS (NÚMERO REAL)

EL FIN DE LOS DATOS SE INDICA CON UN NÚMERO DE LEGAJO IGUAL A 0.

SE QUIERE RESPONDER LAS SIGUIENTES PREGUNTAS:

(a) LAS MATERIAS QUE NO TUVIERON ACCESO DE ALUMNOS NUNCA
(b) LA MATERIA QUE MAS CANTIDAD DE HORAS REGISTRO ACCESO DE ALUMNOS
(c) POR CADA MATERIA Y DIA DE MARZO, LA CANTIDAD DE ACCESOS DE ALUMNOS A LAS AULAS VIRTUALES.

HACER UN PROGRAMA EN EL MARCO DE UN PROYECTO DE CODEBLOCK CON UN MENÚ CON OPCIONES PARA CARGAR LOS DATOS, MOSTRAR CADA PUNTO Y SALIR DEL PROGRAMA.
*/

#include <iostream>
using namespace std;

const int QUANT_CHARS = 30; // Cantidad de caracteres que puede tener el nombre de una materia
const int CANT_MATERIAS = 2; // Usado en lote_de_proceso y lote_de_carga
const int CANT_MESES = 12; // Usado en lote_de_proceso
const int CANT_DIAS = 31; // Usado en lote_de_proceso

struct MATERIA{ // El codigo de cada materia esta dado por el indice de un vector de materias
    char nombre_de_materia[QUANT_CHARS];
    int cant_alumnos;
    int cant_profesores;
};

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

void cargar_lote(MATERIA lote_de_carga[], const int CANT_MATERIAS){
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
}

void procesar_lote(float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
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
}

void mostrar_lote_de_carga(MATERIA lote_de_carga[], const int CANT_MATERIAS){
    for(int i = 0; i < CANT_MATERIAS; i ++){
        cout << "Materia " << i + 1 << ": ";
        print_char_array(lote_de_carga[i].nombre_de_materia, QUANT_CHARS);
        cout << endl;
        cout << "- Cantidad de alumnos inscriptos: " << lote_de_carga[i].cant_alumnos << endl;
        cout << "- Cantidad de profesores a cargo: " << lote_de_carga[i].cant_profesores << endl;
    }
}

void mostrar_lote_de_proceso(float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS], MATERIA lote_de_carga[]){
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
}

void menu(MATERIA lote_de_carga[], float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS]){
    cout << "(1) INGRESAR LOTE DE CARGA: Cargar la informacion de las materias." << endl;
    cout << "(2) MOSTRAR LOTE DE CARGA: Mostrar informacion de las materias." << endl;
    cout << "(3) INGRESAR LOTE DE PROCESO: Cargar accesos de alumnos a las aulas virtuales." << endl;
    cout << "(4) MOSTRAR LOTE DE PROCESO: Mostrar toda la matriz de accesos." << endl;
    cout << "-------------------------" << endl;
    cout << "(5) CONSULTA A: Ver materias que no tuvieron acceso de alumnos nunca." << endl;
    cout << "(6) CONSULTA B: Ver materia que mas cantidad de horas registro accceso de alumnos." << endl;
    cout << "(7) CONSULTA C: Ver cantidad de accesos de alumnos por materia para cada dia de marzo." << endl;
    cout << "-------------------------" << endl;
    cout << "(0) SALIR" << endl;
    
    int opcion;

    cin >> opcion;

    switch(opcion){
        case 1:
            cargar_lote(lote_de_carga, CANT_MATERIAS);
            break;
        case 2:
            mostrar_lote_de_carga(lote_de_carga, CANT_MATERIAS);
            break;
        case 3:
            procesar_lote(lote_de_proceso);
            break;
        case 4:
            mostrar_lote_de_proceso(lote_de_proceso, lote_de_carga);
            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
    }
}

int main(){
    MATERIA lote_de_carga[CANT_MATERIAS] = {};
    float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS] = {};
    menu(lote_de_carga, lote_de_proceso);
}

/*
COMPILAR:
g++ -o ./bin/main main.cpp

EJECUTAR
./bin/main

CORRER PRUEBA DE ESCRITORIO:
./bin/main < ./test.txt
*/