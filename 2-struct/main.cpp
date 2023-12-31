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
#include "functions.h"

int main(){
    MATERIA lote_de_carga[CANT_MATERIAS] = {};
    float lote_de_proceso[CANT_MATERIAS][CANT_MESES][CANT_DIAS] = {};
    int march_logins[CANT_MATERIAS][CANT_DIAS] = {};
    menu_switch(lote_de_carga, lote_de_proceso, march_logins);
    
    // PRUEBA DE ESCRITORIO:
    // Comentar la línea 36 y descomentar el siguiente bloque (líneas 41 y 49).

    /*
    cargar_lote_de_carga(lote_de_carga); 
    cargar_lote_de_proceso(lote_de_proceso, march_logins);
    mostrar_lote_de_carga(lote_de_carga);
    mostrar_lote_de_proceso(lote_de_carga, lote_de_proceso);
    consulta_A(lote_de_carga, lote_de_proceso);
    consulta_B(lote_de_carga, lote_de_proceso);
    consulta_C(lote_de_carga, march_logins);
    */

   return 0;
}

/*
COMPILAR:
g++ -o ./bin/main main.cpp functions.cpp

EJECUTAR
./bin/main

CORRER PRUEBA DE ESCRITORIO:
./bin/main < ./test.txt
*/