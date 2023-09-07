#include "Empleado.h"

Empleado::Empleado() {
    setLegajo(0);
    setNombre("\0");
    setApellido("\0");
    setEmail("\0");
}

Empleado::Empleado(int legajo, std::string nombre, std::string apellido, std::string email) {
    setLegajo(legajo);
    setNombre(nombre);
    setApellido(apellido);
    setEmail(email);
}

void Empleado::setLegajo(int legajo) {
    _legajo = legajo;
}

int Empleado::getLegajo() {
    return _legajo;
}

void Empleado::setNombre(std::string nombre) {
    _nombre = nombre;
}

std::string Empleado::getNombre() {
    return _nombre;
}

void Empleado::setApellido(std::string apellido) {
    _apellido = apellido;
}

std::string Empleado::getApellido() {
    return _apellido;
}

void Empleado::setEmail(std::string email) {
    _email = email;
}

std::string Empleado::getEmail() {
    return _email;
}