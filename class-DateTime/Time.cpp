#include "Time.h"

// Construct

Time::Time(){
    std::time_t now = std::time(NULL);
    std::tm * local_time = std::localtime(& now);
    _second = (* local_time).tm_sec; // La siguiente notación es equivalente usando el operador flecha: _second = local_time -> tm_sec;
    _minute = (* local_time).tm_min;
    _hour = (* local_time).tm_hour;
}

Time::Time(int second, int minute, int hour){
    _second = second;
    _minute = minute;
    _hour = hour;
}

// Public Methods

void Time::set_second(int second){
    _second = second;
}

void Time::set_minute(int minute){
    _minute = minute;
}

void Time::set_hour(int hour){
    _hour = hour;
}

int Time::get_second(){
    return _second;
}

int Time::get_minute(){
    return _minute;
}

int Time::get_hour(){
    return _hour;
}

std::string Time::to_string(){
    std::string ss;
    std::string mm;
    std::string hh;

    if(_second < 10){
        ss = "0" + std::to_string(_second);
    } else{
        ss = std::to_string(_second);
    }

    if(_minute < 10){
        mm = "0" + std::to_string(_minute);
    } else{
        mm = std::to_string(_minute);
    }

    if(_hour < 10){
        hh = "0" + std::to_string(_hour);
    } else{
        hh = std::to_string(_hour);
    }

    return hh + ":" + mm + ":" + ss;
}