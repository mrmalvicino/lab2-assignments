#include <iostream>
#include "Date.h"
#include "Time.h"

int main(){
    Date yesterday(10,8,2023);
    Date today(11,8,2023);
    Date tomorrow(12,8,2023);

    yesterday.add_days(1);
    today.add_days(-365);
    tomorrow.add_days(-1);

    std::cout << yesterday.to_string() << "\n";
    std::cout << today.to_string() << "\n";
    std::cout << tomorrow.to_string() << "\n";

    Time current_time;
    std::cout << current_time.to_string() << "\n";
}