#include "EmpleadoPorHora.h"

EmpleadoPorHora::EmpleadoPorHora() : Empleado() {
    setCantidadDeHoras(8);
    setValorHora(2000);
}

EmpleadoPorHora::EmpleadoPorHora(int legajo, std::string nombre, std::string apellido, std::string email, int cantidad_de_horas, int valor_hora) {
    setCantidadDeHoras(cantidad_de_horas);
    setValorHora(valor_hora);
}

void EmpleadoPorHora::setCantidadDeHoras(int cantidad_de_horas) {
    _cantidad_de_horas = cantidad_de_horas;
}

int EmpleadoPorHora::getCantidadDeHoras() {
    return _cantidad_de_horas;
}

void EmpleadoPorHora::setValorHora(int valor_hora) {
    _valor_hora = valor_hora;
}

int EmpleadoPorHora::getValorHora() {
    return _valor_hora;
}