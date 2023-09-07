#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

class EmpleadoPorComision : public Empleado {
    public:
        EmpleadoPorComision();
        EmpleadoPorComision(int legajo, std::string nombre, std::string apellido, std::string email, int salario_base, int valor_porcentual);
        void setSalarioBase(int salario_base);
        int getSalarioBase();
        void setValorPorcentual(int valor_porcentual);
        int getValorPorcentual();

    private:
        int _salario_base;
        int _valor_porcentual;
};