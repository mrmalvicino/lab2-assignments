#include "EmpleadoAsociado.h"

EmpleadoAsociado::EmpleadoAsociado() : Empleado() {
    setCantidadDeHoras(8);
}

EmpleadoAsociado::EmpleadoAsociado(int legajo, std::string nombre, std::string apellido, std::string email, int salario_base, int valor_porcentual) {
    setCantidadDeHoras(salario_base);
    setValorHora(valor_porcentual);
}

void EmpleadoAsociado::setCantidadDeHoras(int salario_base) {
    _salario_base = salario_base;
}

int EmpleadoAsociado::getCantidadDeHoras() {
    return _salario_base;
}

void EmpleadoAsociado::setValorHora(int valor_porcentual) {
    _valor_porcentual = valor_porcentual;
}

int EmpleadoAsociado::getValorHora() {
    return _valor_porcentual;
}