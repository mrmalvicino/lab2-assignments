#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

class EmpleadoAsociado : public Empleado {
    public:
        EmpleadoAsociado();
        EmpleadoAsociado(int legajo, std::string nombre, std::string apellido, std::string email, int salario_fijo, int anios_de_ingreso);
        void setSalarioFijo(int salario_fijo);
        int getSalarioFijo();
        void setAniosDeIngreso(int anios_de_ingreso);
        int getAniosDeIngreso();

    private:
        int _salario_fijo;
        int _anios_de_ingreso;
};