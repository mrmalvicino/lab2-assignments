#include "EmpleadoAsociado.h"

EmpleadoAsociado::EmpleadoAsociado() : Empleado() {
    setSalarioFijo(500000);
    setAniosDeIngreso(0);
}

EmpleadoAsociado::EmpleadoAsociado(int legajo, std::string nombre, std::string apellido, std::string email, int salario_fijo, int anios_de_ingreso) {
    setSalarioFijo(salario_fijo);
    setAniosDeIngreso(anios_de_ingreso);
}

void EmpleadoAsociado::setSalarioFijo(int salario_fijo) {
    _salario_fijo = salario_fijo;
}

int EmpleadoAsociado::getSalarioFijo() {
    return _salario_fijo;
}

void EmpleadoAsociado::setAniosDeIngreso(int anios_de_ingreso) {
    _anios_de_ingreso = anios_de_ingreso;
}

int EmpleadoAsociado::getAniosDeIngreso() {
    return _anios_de_ingreso;
}