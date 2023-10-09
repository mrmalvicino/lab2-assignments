#include <iostream>
#include <cstring>
using namespace std;
#include "parcial1l.h"

class DocenteAvanzado {
    public:

    void setDni(int dni) {
        _dni = dni;
    }

    int getDni() {
        return _dni;
    }

    void setNombre(const char * nombre) {
        strcpy(_nombre, nombre);
    }

    const char * getNombre() {
        return _nombre;
    }

    void setApellido(const char * apellido) {
        strcpy(_apellido, apellido);
    }

    const char * getApellido() {
        return _apellido;
    }

    void setInscripcion(int dia, int mes, int anio) {
        _inscripcion.setAnio(anio);
        _inscripcion.setMes(mes);
        _inscripcion.setDia(dia);
    }

    private:

    int _dni;
    char _nombre[25];
    char _apellido[30];
    Fecha _inscripcion;
};

class ArchivoDocentesAvanzados {
    public:

    ArchivoDocentesAvanzados() {
        setPath("docentes_avanzados.dat");
    }

    ArchivoDocentesAvanzados(const char * path) {
        setPath(path);
    }

    void setPath(const char * path) {
        strcpy(_path, path);
    }

    const char * getPath() {
        return _path;
    }

    bool write(DocenteAvanzado & reg) {
        FILE * file_pointer = fopen(getPath(), "ab");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return 0;
        }

        bool successful_write = fwrite(& reg, sizeof(DocenteAvanzado), 1, file_pointer);
        fclose(file_pointer);

        return successful_write;
    }

    bool overWrite(DocenteAvanzado & reg, int index) {
        FILE * file_pointer = fopen(getPath(), "rb+");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return 0;
        }

        fseek(file_pointer, sizeof(DocenteAvanzado) * index, 0);
        bool successful_write = fwrite(& reg, sizeof(DocenteAvanzado), 1, file_pointer);
        fclose(file_pointer);

        return successful_write;
    }

    DocenteAvanzado read(int index) {
        DocenteAvanzado reg;
        FILE * file_pointer = fopen(getPath(), "rb");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return reg;
        }

        fseek(file_pointer, sizeof(DocenteAvanzado) * index, 0);
        fread(& reg, sizeof(DocenteAvanzado), 1, file_pointer);
        fclose(file_pointer);

        return reg;
    }

    int getIndex(int dni) {
        int i = 0;
        DocenteAvanzado reg;
        reg = read(i);

        while (reg.getDni() != dni && i < getAmountOfRegisters()) {
            i ++;
            reg = read(i);
        }

        return i;
    }

    int getAmountOfRegisters() {
        FILE * file_pointer = fopen(getPath(), "rb");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return 0;
        }

        fseek(file_pointer, 0, SEEK_END);
        int bytes = ftell(file_pointer);
        fclose(file_pointer);
        int total_registros = bytes / sizeof(DocenteAvanzado);

        return total_registros;
    }

    void createEmptyArchive() {
        FILE * file_pointer = fopen(getPath(), "wb");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
        } else {
            fclose(file_pointer);
        }
    }

    private:

    char _path[50];
};

int main() {
    Jugador jugador;
    Equipo equipo;
    DocenteAvanzado docente_avanzado;
    ArchivoJugadores archivo_jugadores("jugadores.dat");
    ArchivoEquipos archivo_equipos("equipos.dat");
    ArchivoDocentesAvanzados archivo_docentes_avanzados;

    int cant_jugadores = archivo_jugadores.contarRegistros();
    int cant_equipos = archivo_equipos.contarRegistros();
    int numero_de_equipo;
    int nivel;
    int dia;
    int mes;
    int anio;

    for (int i = 0; i < cant_jugadores; i ++) { // recorro jugadores
        jugador = archivo_jugadores.leerRegistro(i);

        std::cout << "\n\nCLAUSTRO: " << jugador.getClaustro(); // VERIFICACION
        std::cout << "\nID EQUIPO: " << jugador.getIdEquipo(); // VERIFICACION

        if (jugador.getClaustro() == 1 && jugador.getEstado()) { // si es docente
            numero_de_equipo = jugador.getIdEquipo(); // leo equipo al que pertenece el docente
            equipo = archivo_equipos.leerRegistro(numero_de_equipo - 1);
            nivel = equipo.getNivel();

            if (nivel == 3) { // si es avanzado, seteo registro ...
                docente_avanzado.setDni(jugador.getDNI());
                docente_avanzado.setNombre(jugador.getNombre());
                docente_avanzado.setApellido(jugador.getApellido());
                dia = jugador.getFechaInscirpcion().getDia();
                mes = jugador.getFechaInscirpcion().getMes();
                anio = jugador.getFechaInscirpcion().getAnio();
                docente_avanzado.setInscripcion(dia, mes, anio);

                archivo_docentes_avanzados.write(docente_avanzado); // ...y escribo en nuevo archivo
            }
        }
    }

    for (int i = 0; i < cant_equipos; i ++) { // VERIFICACION
        equipo = archivo_equipos.leerRegistro(i);
        std::cout << "\n\nNivel de equipo " << i + 1 << ": " << equipo.getNivel();
    }

    std::cout << "\n\nDOCENTES AVANZADOS:\n";

    int cant_docentes_avanzados = archivo_docentes_avanzados.getAmountOfRegisters();

    for (int i = 0; i < cant_docentes_avanzados; i ++) {
        docente_avanzado = archivo_docentes_avanzados.read(i);

        std::cout << "DNI:" << docente_avanzado.getDni() << "\n";
        std::cout << "Nombre y apellido:" << docente_avanzado.getNombre() << " " << docente_avanzado.getApellido() << "\n";
    }

    return 0;
}

/*

COMPILAR:
g++ -o ./bin/main *.cpp

EJECUTAR:
./bin/main
.\bin\main.exe

*/