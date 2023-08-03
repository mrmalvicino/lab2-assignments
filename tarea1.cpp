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
#include <cstdlib>

struct MATERIA{
    char nombre_de_materia[30];
    int cant_alumnos;
    int cant_profesores;
};

void texto_a_vector(char texto[30], char vector[30]){
    for(int i = 0; i < 30; i ++){
        vector[i] = texto[i];
    }
}

int main(){
    int const CANT_MATERIAS = 20;
    MATERIA lote_de_carga[CANT_MATERIAS] = {};

    texto_a_vector("materia 1", lote_de_carga[0].nombre_de_materia);
    std::cout << lote_de_carga[0].nombre_de_materia << std::endl;

    for(int i = 0; i < CANT_MATERIAS; i ++){
        //lote_de_carga[i].nombre_de_materia = 'Materia';
        lote_de_carga[i].cant_alumnos = 30;
        lote_de_carga[i].cant_profesores = 30;
    }
}

/*
COMPILAR Y EJECUTAR:
g++ -o ./bin/hmwk1 hmwk1.cpp
./bin/hmwk1
*/