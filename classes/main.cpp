#include <iostream>
#include "Meeting.h"

int main(){/*
    // Prueba de Date:

    Date yesterday;
    Date today;
    yesterday.addDays(-1);
    yesterday.addDays(-365);
    std::cout << "Fecha de ayer hace 1 año:\t" << yesterday.toString() << "\n";
    std::cout << "Fecha de hoy:\t\t\t" << today.toString() << "\n";

    // Prueba de Time:

    Time current_time;
    std::cout << "Hora actual:\t\t\t" << current_time.toString() << "\n";

    // Prueba de DateTime:

    DateTime today_now;
    std::cout << "Fecha de hoy con hora actual:\t" << today_now.toString() << "\n";

    // Prueba de Person:

    Person natalia_natalia;
    natalia_natalia.setFirstName("Maximiliano");
    natalia_natalia.setLastName("Malvicino");
    std::cout << natalia_natalia.getFirstName() + " " + natalia_natalia.getLastName() + "\n";
*/
    // Prueba de Meeting:

    const int cant_participantes = 5; // Máximo de participantes que cada reunión puede tener
    const int cant_reuniones = 2;

    Meeting * reuniones[cant_reuniones];

    for (int i = 0; i < cant_reuniones; i++) {
        reuniones[i] = new Meeting(cant_participantes);
    }

    DateTime fecha_hora_1(1, 10, 2023, 0, 0 , 19);
    std::string lugar_1 = "Buenos Aires";
    std::string tema_1 = "Programación en C++";
    (* reuniones[0]).setDateTime(fecha_hora_1);
    (* reuniones[0]).setWhere(lugar_1);
    (* reuniones[0]).setTopic(tema_1);
    (* reuniones[0]).setDuration(90);
    (* reuniones[0]).addParticipant("Brian", "Lara");
    (* reuniones[0]).addParticipant("Angel", "Simón");
    
    DateTime fecha_hora_2(1, 4, 2023, 0, 0 , 19);
    std::string lugar_2 = "Internet";
    std::string tema_2 = "Estadística y programación";
    (* reuniones[1]).setDateTime(fecha_hora_2);
    (* reuniones[1]).setWhere(lugar_2);
    (* reuniones[1]).setTopic(tema_2);
    (* reuniones[1]).setDuration(100);
    (* reuniones[1]).addParticipant("Maxi", "Wenner");

    std::cout << "FECHA Y HORA\t\tLUGAR\t\tTEMA\t\t\tDURACIÓN\t\tPARTICIPANTES\n";

    for(int i = 0; i < 2; i ++){
        std::cout << (* reuniones[i]).toString() + "\n";
    }

    for (int i = 0; i < cant_reuniones; i++) {
        delete reuniones[i];
    }
}

/*

COMPILAR:
g++ -o ./bin/main *.cpp

EJECUTAR:
./bin/main

CORRER PRUEBA DE ESCRITORIO:
./bin/main < ./bin/test.txt

*/