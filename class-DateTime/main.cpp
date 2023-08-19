#include <iostream>
#include "DateTime.h"

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
}

// ¡Faltan validaciones!