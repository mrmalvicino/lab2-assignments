#include "Person.h"

// Construct

Person::Person(){
    _first_name = "\0";
    _last_name = "\0";
}

Person::Person(std::string first_name, std::string last_name){
    _first_name = first_name;
    _last_name = last_name;
}

// Public Methods

void Person::set_first_name(std::string first_name){
    _first_name = first_name;
}

void Person::set_last_name(std::string last_name){
    _last_name = last_name;
}

std::string Person::get_first_name(){
    return _first_name;
}

std::string Person::get_last_name(){
    return _last_name;
}