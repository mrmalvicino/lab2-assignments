#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

class EmpleadoPorHora : public Empleado {
    public:
        EmpleadoPorHora();
        EmpleadoPorHora(int legajo, std::string nombre, std::string apellido, std::string email, int cantidad_de_horas, int valor_hora);
        void setCantidadDeHoras(int cantidad_de_horas);
        int getCantidadDeHoras();
        void setValorHora(int valor_hora);
        int getValorHora();

    private:
        int _cantidad_de_horas;
        int _valor_hora;
};