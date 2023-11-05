#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include "parcial2.h"

int main() {

}

/*
ENUNCIADO
---------

Una empresa constructora tiene, entre otros, los siguientes archivos en su sistema de información:

obras.dat
Código de obra (char[5])
Direccion (char [30])
Provincia (1 a 24)
Superficie (en metros cuadrados)
Estado de ejecución (1: en proyecto; 2: proyecto aprobado en espera;3: en ejecución; 4: terminada; 5: suspendida:)
Activo (si/no)

materiales.dat
Código de material (entero)
Nombre (char[30])
Marca (char[30])
Tipo (1: obra gruesa; 2: techos; 3: aberturas; 4: revestimientos; 5: sanitarios; 6: electricidad)
Precio unitario 
Activo (si/no)

compras.dat
Número de compra (entero)
Número de proveedor
Código de material
Código de obra
Cantidad
Importe
Fecha (día, mes y año)
Activo (si/no)

Las compras corresponden a los materiales utilizados para las obras registradas en el archivo obras.dat. Puede haber muchos registros para cada obra.

proveedores.dat
Número de proveedor (1 a 60)
Nombre
Teléfono
Dirección
Provincia (1 a 24)
Activo (si/no)

CONSIGNAS
---------

(1) Generar un archivo con los proveedores a los que no se les haya hecho compras el año actual. Por cada proveedor al que no se le hayan hecho compras este año se debe registrar el número de proveedor, el nombre del proveedor y la provincia del proveedor.

(2) El tipo de material con menos cantidad de materiales (ignorando los tipos sin materiales).

(3) Generar un vector dinámico con todos los materiales y listar luego los materiales del vector que pertenezcan a un tipo que se ingresa por teclado.

(4) Sobrecargar el operador == para la clase Obra de manera tal que sea verdadero cuando el objeto que llama al método tenga un valor de superficie igual a un valor de tipo float que se recibe como parámetro. Dejar el código comentado en el cpp que se entrega para evitar problemas de compilación.
*/