/*
LAS AUTORIDADES DE LA CARRERA TUP DE LA UTN ESTÁN REALIZANDO UN ANÁLISIS DE LOS CURSOS VIRTUALES DE LAS DISTINTAS MATERIAS.

POR CADA UNA DE LAS 20 MATERIAS DE LA CARRERA SE TIENE LA SIGUIENTE INFORMACIÓN:

- NÚMERO DE MATERIA (ENTRE 1 Y 20)
- NOMBRE
- CANTIDAD DE ALUMNOS INSCRIPTOS
- CANTIDAD DE PROFESORES

ADEMÁS POR CADA INGRESO DE LOS ESTUDIANTES AL AULA VIRTUAL SE REGISTRA LO SIGUIENTE:

- LEGAJO
- FECHA DE ACCESO (DÍA Y MES)
- NÚMERO DE LA MATERIA A LA QUE INGRESO
- CANTIDAD DE HORAS (NÚMERO REAL)

EL FIN DE LOS DATOS SE INDICA CON UN NÚMERO DE LEGAJO IGUAL A 0.

SE QUIERE RESPONDER LAS SIGUIENTES PREGUNTAS:

(a) LAS MATERIAS QUE NO TUVIERON ACCESO DE ALUMNOS NUNCA
(b) LA MATERIA QUE MAS CANTIDAD DE HORAS REGISTRO DE ACCESO DE ALUMNOS
(c) POR CADA MATERIA Y DIA DE MARZO, LA CANTIDAD DE ACCESOS DE ALUMNOS A LAS AULAS VIRTUALES.

HACER UN PROGRAMA EN EL MARCO DE UN PROYECTO DE CODEBLOCK CON UN MENÚ CON OPCIONES PARA CARGAR LOS DATOS, MOSTRAR CADA PUNTO Y SALIR DEL PROGRAMA.
*/

#include <iostream>
using namespace std;

struct MATERIA{ // El codigo de cada materia esta dado por el indice de un vector de materias
    char nombre_de_materia[30];
    int cant_alumnos;
    int cant_profesores;
};

struct INGRESO{
    int legajo;
    int fecha_de_acceso[2]; // Array con dia y mes en formato {dd mm}
    int codigo_de_materia;
    float cant_horas;
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
    for(int i = 0; i < CANT_MATERIAS; i ++){
        cout << endl << "Ingresar nombre de materia:" << endl;
        cin.getline(lote_de_carga[i].nombre_de_materia, 30);
    }
}

void procesar_lote(){

}

int main(){
    const int CANT_MATERIAS = 2;
    MATERIA lote_de_carga[CANT_MATERIAS] = {};
    cargar_lote(lote_de_carga, CANT_MATERIAS);

}

/*
COMPILAR Y EJECUTAR:
g++ -o ./bin/tarea1 tarea1.cpp
./bin/tarea1

COMPILAR Y CORRER PRUEBA DE ESCRITORIO:
g++ -o ./bin/tarea1 tarea1.cpp
./bin/tarea1 < ./tarea1-test.txt
*/