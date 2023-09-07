#pragma once
#include <iostream>
#include <string>

class Empleado{
    public:
        Empleado();
        Empleado(int legajo, std::string nombre, std::string apellido, std::string email);
        void setLegajo(int legajo);
        int getLegajo();
        void setNombre(std::string first_name);
        std::string getNombre();
        void setApellido(std::string last_name);
        std::string getApellido();
        void setEmail(std::string email);
        std::string getEmail();

    private:
        int _legajo;
        std::string _nombre;
        std::string _apellido;
        std::string _email;
};