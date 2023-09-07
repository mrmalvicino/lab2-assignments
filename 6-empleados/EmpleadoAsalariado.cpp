#include "EmpleadoAsalariado.h"

EmpleadoAsalariado::EmpleadoAsalariado() : Empleado() {
    setSalarioFijo(200000);
}

EmpleadoAsalariado::EmpleadoAsalariado(int legajo, std::string nombre, std::string apellido, std::string email, int salario_fijo) {
    setSalarioFijo(salario_fijo);
}

void EmpleadoAsalariado::setSalarioFijo(int salario_fijo) {
    _salario_fijo = salario_fijo;
}

int EmpleadoAsalariado::getSalarioFijo() {
    return _salario_fijo;
}