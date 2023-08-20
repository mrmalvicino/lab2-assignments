#include "DateTime.h"

// Construct

DateTime::DateTime(){}

DateTime::DateTime(Date date, Time time){
    _date = date;
    _time = time;
}

DateTime::DateTime(int day, int month, int year, int second, int minute, int hour){
    set_date(day, month, year);
    set_time(second, minute, hour);
}

// Public Methods

void DateTime::set_date(Date date){
    _date = date;
}

void DateTime::set_time(Time time){
    _time = time;
}

void DateTime::set_date(int day, int month, int year){
    if(0 < day && day <= _date.get_days_in_month(month, year) && 0 < month && month <= 12 && 0 < year){
        _date.set_day(day);
        _date.set_month(month);
        _date.set_year(year);
    }
}

void DateTime::set_time(int second, int minute, int hour){
    if(0 <= second && second < 60 && 0 <= minute && minute < 60 && 0 <= hour && hour < 24){
        _time.set_second(second);
        _time.set_minute(minute);
        _time.set_hour(hour);
    }
}

Date DateTime::get_date(){
    return _date;
}

Time DateTime::get_time(){
    return _time;
}

std::string DateTime::to_string(){
    return _date.to_string() + " " + _time.to_string();
}