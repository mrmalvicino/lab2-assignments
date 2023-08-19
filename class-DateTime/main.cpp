#include <iostream>
#include "Date.h"
#include "Time.h"

int main(){
    Date yesterday;
    Date today;
    Date tomorrow;

    yesterday.add_days(-1);
    today.add_days(-365);
    tomorrow.add_days(1);

    std::cout << "Fecha de ayer:\t\t" << yesterday.to_string() << "\n";
    std::cout << "Fecha de hoy:\t\t" << today.to_string() << "\n";
    std::cout << "Fecha de mañana:\t" << tomorrow.to_string() << "\n";

    Time current_time;
    std::cout << "Hora actual:\t\t" << current_time.to_string() << "\n";
}