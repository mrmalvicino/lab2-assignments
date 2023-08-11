/*
Un comerciante que tiene una tienda en la que vende batidos a turistas. En la tienda se venden 3 tipos de batidos con diferentes sabores, los cuales se almacenan en bidones de diferentes tamaños: un bidón de 20L con sabor a "Banana", un bidón de 35L con sabor a "Ananá" y un bidón de 44L con sabor a "Sandia".
Al inicio de cada día, los 3 bidones se llenan completamente para comenzar a vender. Cada vez que se hace una venta, se registra el código de batido y el tipo de vaso que el cliente desea: el código de batido puede ser 1 para "Banana", 2 para "Ananá" o 3 para "Sandia", mientras que el tipo de vaso puede ser 1 para 150 ml, 2 para 200 ml o 3 para 300 ml.
Cada venta que se realiza implica el descuento de una cantidad de litros del bidón correspondiente al sabor y tamaño del vaso elegido. Además, se debe tener en cuenta que no se pueden realizar ventas si no hay suficiente batido en el bidón correspondiente.
Al final del día, se debe leer el nivel de cada bidón para saber cuánto batido sobró en cada uno de ellos.
La carga de ventas finaliza cuando se ingresa un código de batido igual a cero. Para resolver este problema, se debe hacer un programa que procese todas las ventas del día y calcule cuánto batido queda en cada bidón al final del mismo.
Al finalizar la carga de ventas, el programa debe imprimir la cantidad de litros que quedó en cada bidón y cuántos batidos vendió de cada uno.
*/

#include <iostream>

int main(){
    const int CANT_VASOS = 3;
    const int CANT_SABORES = 3;

    const int VASO_1 = 150;         // Capacidad del vaso en mL
    const int VASO_2 = 200;         // Capacidad del vaso en mL
    const int VASO_3 = 300;         // Capacidad del vaso en mL

    const int VOL_BANANA = 20000;   // Capacidad del bidón de batido en mL
    const int VOL_ANANA = 35000;    // Capacidad del bidón de batido en mL
    const int VOL_SANDIA = 44000;   // Capacidad del bidón de batido en mL

    const int VASOS[CANT_VASOS] = {VASO_1, VASO_2, VASO_3};
    int bidones[CANT_SABORES] = {VOL_BANANA, VOL_ANANA, VOL_SANDIA}; // Array que contiene por componente la cantidad en mL de batido disponible

    int codigo_de_batido;
    int tipo_de_vaso;

    std::cout << "Ingresar codigo de batido.\n";
    std::cin >> codigo_de_batido;

    while(codigo_de_batido != 0){
        std::cout << "Ingresar tipo de vaso.\n";
        std::cin >> tipo_de_vaso;

        if(bidones[codigo_de_batido - 1] - VASOS[tipo_de_vaso - 1] > 0){
            bidones[codigo_de_batido - 1] -= VASOS[tipo_de_vaso - 1];
        } else{
            std::cout << "No hay suficiente batido.\n";
        }

        std::cout << "Ingresar codigo de batido.\n";
        std::cin >> codigo_de_batido;
    }

    for(int i = 0; i < CANT_SABORES; i ++){
        std::cout << "Disponible: " << bidones[i] << " mL\n";
    }
}

/*
COMPILAR:
g++ -o ./bin/main main.cpp functions.cpp

EJECUTAR
./bin/main

CORRER PRUEBA DE ESCRITORIO:
./bin/main < ./test.txt
*/