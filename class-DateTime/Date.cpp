#include "Date.h"

// Construct

Date::Date(){
    set_day(1);
    set_month(1);
    set_year(0);
}

Date::Date(int day, int month, int year){
    if(0 < day && day <= days_in_month(month, year) && 0 < month && month <= 12 && 0 < year){
        set_day(day);
        set_month(month);
        set_year(year);
    } else{
        set_day(1);
        set_month(1);
        set_year(0);
    }
}

// Public Methods

void Date::set_day(int day){
    _day = day;
}

void Date::set_month(int month){
    _month = month;
}

void Date::set_year(int year){
    _year = year;
}

int Date::get_day(){
    return _day;
}

int Date::get_month(){
    return _month;
}

int Date::get_year(){
    return _year;
}

void Date::add_days(int amount_days){
    if(0 < amount_days){
        for(int i = 0; i < amount_days; i++){
            increase_day();
        }
    } else if (amount_days < 0){
        for(int i = 0; i < - amount_days; i++){
            decrease_day();
        }
    }
}

std::string Date::to_string(){
    std::string dd;
    std::string mm;
    std::string yyyy = std::to_string(_year);

    if(_day < 10){
        dd = "0" + std::to_string(_day);
    } else{
        dd = std::to_string(_day);
    }

    if(_month < 10){
        mm = "0" + std::to_string(_month);
    } else{
        mm = std::to_string(_month);
    }

    return dd + "/" + mm + "/" + yyyy;
}

// Private Methods

int Date::days_in_month(int month, int year){
    int amount_days = 31; // Enero, marzo, mayo, julio, agosto, octubre, diciembre

    if (month == 4 || month == 6 || month == 9 || month == 11){
        amount_days = 30; // Abril, junio, septiembre, noviembre
    } else if (month == 2){
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            amount_days = 29; // Febrero en años bisiestos
        } else {
            amount_days = 28; // Febrero en años no bisiestos
        }
    }

    return amount_days;
}

void Date::increase_day(){
    if(_day == days_in_month(_month, _year)){
        _day = 1;

        if(_month == 12){
            _month = 1;
            _year ++;
        } else{
            _month ++;
        }
    } else{
        _day ++;
    }
}

void Date::decrease_day(){
    if(_day == 1){
        if(_month == 1){
            _day = days_in_month(12, _year - 1);
            _month = 12;
            _year --;
        } else{
            _day = days_in_month(_month - 1, _year);
            _month --;
        }
    } else{
        _day --;
    }
}