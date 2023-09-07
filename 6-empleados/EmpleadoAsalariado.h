#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

class EmpleadoAsalariado : public Empleado {
    public:
        EmpleadoAsalariado();
        EmpleadoAsalariado(int legajo, std::string nombre, std::string apellido, std::string email, int salario_fijo);
        void setSalarioFijo(int salario_fijo);
        int getSalarioFijo();

    private:
        int _salario_fijo;
};