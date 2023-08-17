#include <iostream>
#include "functions.h"

int main(){
    int var1 = 3;
    int var2;
    std::cin >> var2;
    var1 = var2;
    hello_world();
}

/*
COMPILAR:
g++ -o ./bin/main main.cpp functions.cpp

EJECUTAR:
./bin/main
./bin/main.exe

CORRER PRUEBA DE ESCRITORIO:
./bin/main < ./test.txt
*/