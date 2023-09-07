#include "EmpleadoPorComision.h"

EmpleadoPorComision::EmpleadoPorComision() : Empleado() {
    setCantidadDeHoras(8);
}

EmpleadoPorComision::EmpleadoPorComision(int legajo, std::string nombre, std::string apellido, std::string email, int salario_base, int valor_porcentual) {
    setCantidadDeHoras(salario_base);
    setValorHora(valor_porcentual);
}

void EmpleadoPorComision::setCantidadDeHoras(int salario_base) {
    _salario_base = salario_base;
}

int EmpleadoPorComision::getCantidadDeHoras() {
    return _salario_base;
}

void EmpleadoPorComision::setValorHora(int valor_porcentual) {
    _valor_porcentual = valor_porcentual;
}

int EmpleadoPorComision::getValorHora() {
    return _valor_porcentual;
}