#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include "parcial1l.h"

int main() {

}

/*
ENUNCIADO
---------

La Facultad está organizando torneos de deportes entre los integrantes de los distintos claustros. Para gestionar las actividades tiene los siguientes archivos  con el formato que se muestra a continuación: 

jugadores.dat 
DNI
Nombre
Apellido 
Email 
Teléfono 
Claustro (1: docente; 2 alumno; 3 no docente; 4 graduado) 
Id de deporte (número entero) 
Número de equipo (número entero) 
Fecha de inscripción 
Matrícula ($)
Estado

deportes.dat
Id de deporte
Nombre
Categoría de deporte
Año de origen
Estado

equipos.dat
Número de equipo: el número del equipo es único y no se repite
Nombre
Nivel (1: inicial; 2: intermedio; 3: avanzado)
Estado

CONSIGNAS
---------

(1) Generar un archivo con los equipos que tengan al menos 10 jugadores inscriptos. Cada registro debe tener el ID de deporte, el nombre y la categoría.

(2) Hacer un vector dinámico para listar el archivo del punto anterior.

(3) Sobrecargar el operador == para comparar un objeto Jugador con un objeto Deporte. Debe devolver verdadero cuando coinciden los Id de deporte

(4) Hacer un archivo con los deportes que tengan jugadores de todos los claustros. Los registros del archivo nuevo deben tener el mismo formato que el archivo de deportes.

(5) Crear un vector dinámico con los equipos de nivel inicial. Listar el vector.

(6) Sobrecargar el operador == para la clase Jugador, que reciba un valor entero y lo compare con el Id de claustro.

(7) Generar un archivo con los jugadores que hayan pagado más de $10000 de matrícula y que se hayan inscripto este año. Cada registro del archivo debe tener el siguiente formato: DNI, nombre, apellido, claustro y nombre del deporte.

(8) Crear un vector con los jugadores pertenecientes a un equipo cuyo número de equipo se ingresa por teclado. Listar el vector

(9) Agregar una sobrecarga para el operador > de la clase Jugador de manera tal que sea verdadero cuando el año de inscripción sea mayor a un valor de año que se recibe cmo parámetro.
*/