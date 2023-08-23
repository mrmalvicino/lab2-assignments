#include <iostream>
#include "Meeting.h"

int main(){
    // Prueba de Date:

    Date yesterday;
    Date today;
    yesterday.add_days(-1);
    yesterday.add_days(-365);
    std::cout << "Fecha de ayer hace 1 año:\t" << yesterday.to_string() << "\n";
    std::cout << "Fecha de hoy:\t\t\t" << today.to_string() << "\n";

    // Prueba de Time:

    Time current_time;
    std::cout << "Hora actual:\t\t\t" << current_time.to_string() << "\n";

    // Prueba de DateTime:

    DateTime today_now;
    std::cout << "Fecha de hoy con hora actual:\t" << today_now.to_string() << "\n";

    // Prueba de Person:

    Person natalia_natalia;
    natalia_natalia.set_first_name("Maximiliano");
    natalia_natalia.set_last_name("Malvicino");
    std::cout << natalia_natalia.get_first_name() + " " + natalia_natalia.get_last_name() + "\n";

    // Prueba de Meeting:

    Meeting reuniones[2];

    DateTime fecha_hora_1(1, 10, 2023, 0, 0 , 19);
    std::string lugar_1 = "Buenos Aires";
    std::string tema_1 = "Programación en C++";
    reuniones[0].set_date_time(fecha_hora_1);
    reuniones[0].set_where(lugar_1);
    reuniones[0].set_topic(tema_1);
    reuniones[0].set_duration(90);
    reuniones[0].add_participant("Brian", "Lara");
    reuniones[0].add_participant("Angel", "Simón");
    
    DateTime fecha_hora_2(1, 4, 2023, 0, 0 , 19);
    std::string lugar_2 = "Internet";
    std::string tema_2 = "Estadística y programación";
    reuniones[1].set_date_time(fecha_hora_2);
    reuniones[1].set_where(lugar_2);
    reuniones[1].set_topic(tema_2);
    reuniones[1].set_duration(100);
    reuniones[1].add_participant("Maxi", "Wenner");

    std::cout << "FECHA Y HORA\t\tLUGAR\t\tTEMA\t\t\tDURACIÓN\t\tPARTICIPANTES\n";

    for(int i = 0; i < 2; i ++){ // Recorre cada reunión
        std::cout << reuniones[i].get_date_time().to_string() + "\t" + reuniones[i].get_where() + "\t" + reuniones[i].get_topic() + "\t" << reuniones[i].get_duration() << "\t\t";
        for(int j = 0; j < reuniones[i].get_amount_of_participants(); j ++){ // Recorre cada participante de cada reunión
            if(j < reuniones[i].get_amount_of_participants() - 1){ // Solo para no mostrar la última coma
                std::cout << reuniones[i].get_participant(j) + ", ";
            } else{
                std::cout << reuniones[i].get_participant(j);
            }
        }
        std::cout << "\n";
    }
}