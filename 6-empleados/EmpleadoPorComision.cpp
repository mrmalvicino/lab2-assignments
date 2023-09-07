#include "EmpleadoPorComision.h"

EmpleadoPorComision::EmpleadoPorComision() : Empleado() {
    setSalarioBase(50000);
    setValorPorcentual(2000);
}

EmpleadoPorComision::EmpleadoPorComision(int legajo, std::string nombre, std::string apellido, std::string email, int salario_base, int valor_porcentual) {
    setSalarioBase(salario_base);
    setValorPorcentual(valor_porcentual);
}

void EmpleadoPorComision::setSalarioBase(int salario_base) {
    _salario_base = salario_base;
}

int EmpleadoPorComision::getSalarioBase() {
    return _salario_base;
}

void EmpleadoPorComision::setValorPorcentual(int valor_porcentual) {
    _valor_porcentual = valor_porcentual;
}

int EmpleadoPorComision::getValorPorcentual() {
    return _valor_porcentual;
}