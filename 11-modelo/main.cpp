#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include "parcial1l.h"

class JugadorSobrecargado{
private:
    int DNI, claustro, idDeporte, idEquipo;
    char nombre[25], apellido[30];
    char email[30];
    int telefono;
    Fecha inscripcion;
    float matricula;
    bool estado;
public:
    bool operator == (Deporte deporte) {
        if (idDeporte == deporte.getIdDeporte()) {
            return true;
        }
        return false;
    }

    void setIdDeporte(int id_deporte) {
        idDeporte = id_deporte;
    }

    void Cargar(){
        cin>>DNI;
        cargarCadena(nombre,24);
        cargarCadena(apellido,29);
        cargarCadena(email, 29);
        cin>>telefono;
        cin>>claustro;
        cin>>idDeporte;
        cin>>idEquipo;
        inscripcion.Cargar();
        cin>>matricula;
        estado=true;
    }
   int getDNI(){return DNI;}
   int getClaustro(){return claustro;}
   int getIdDeporte(){return idDeporte;}
   int getIdEquipo(){return idEquipo;}
   const char *getNombre(){return nombre;}
   const char *getApellido(){return apellido;}
   bool getEstado(){return estado;}
   Fecha getFechaInscirpcion(){return inscripcion;}

   void setEstado(bool e){estado=e;}

   void Mostrar(){
        cout<<DNI<<endl;
        cout<<nombre<<endl;
        cout<<apellido<<endl;
        cout<<email<<endl;
        cout<<telefono<<endl;
        cout<<claustro<<endl;
        cout<<idDeporte<<endl;
        cout<<idEquipo<<endl;
        inscripcion.Mostrar();
        cout<<matricula<<endl;
   }
};

class EquipoConDiez {
    public:

    void setIdDeporte(int id_deporte) {
        _id_deporte = id_deporte;
    }

    int getIdDeporte() {
        return _id_deporte;
    }

    void setNombre(const char * nombre) {
        strcpy(_nombre, nombre);
    }

    const char * getNombre() {
        return _nombre;
    }

    void setCategoria(int categoria) {
        _categoria = categoria;
    }

    int getCategoria() {
        return _categoria;
    }

    private:

    int _id_deporte;
    char _nombre[30];
    int _categoria;
};

class ArchivoEquiposConDiez {
    public:

    ArchivoEquiposConDiez() {
        setPath("equipos_con_diez.dat");
    }

    ArchivoEquiposConDiez(const char * path) {
        setPath(path);
    }

    void setPath(const char * path) {
        strcpy(_path, path);
    }

    const char * getPath() {
        return _path;
    }

    bool write(EquipoConDiez & reg) {
        FILE * file_pointer = fopen(getPath(), "ab");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return 0;
        }

        bool successful_write = fwrite(& reg, sizeof(EquipoConDiez), 1, file_pointer);
        fclose(file_pointer);

        return successful_write;
    }

    bool overWrite(EquipoConDiez & reg, int index) {
        FILE * file_pointer = fopen(getPath(), "rb+");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return 0;
        }

        fseek(file_pointer, sizeof(EquipoConDiez) * index, 0);
        bool successful_write = fwrite(& reg, sizeof(EquipoConDiez), 1, file_pointer);
        fclose(file_pointer);

        return successful_write;
    }

    EquipoConDiez read(int index) {
        EquipoConDiez reg;
        FILE * file_pointer = fopen(getPath(), "rb");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return reg;
        }

        fseek(file_pointer, sizeof(EquipoConDiez) * index, 0);
        fread(& reg, sizeof(EquipoConDiez), 1, file_pointer);
        fclose(file_pointer);

        return reg;
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
        int total_registros = bytes / sizeof(EquipoConDiez);

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

void checkAllocation(EquipoConDiez * arr) {
    if (arr == NULL) {
        std::cout << "Error de asignación de memoria.\n";
        exit(1);
    }
}

int getIndex(int id_deporte, ArchivoDeportes archivo_deportes) {
    int i = 0;
    Deporte reg;
    reg = archivo_deportes.leerRegistro(i);

    while (reg.getIdDeporte() != id_deporte && i < archivo_deportes.contarRegistros()) {
        i ++;
        reg = archivo_deportes.leerRegistro(i);
    }

    return i;
}

int main() {
    system("clear");

    /* DECLARACIONES */

    Jugador jugador;
    ArchivoJugadores archivo_jugadores("jugadores.dat");

    Deporte deporte;
    ArchivoDeportes archivo_deportes("deportes.dat");

    Equipo equipo;
    ArchivoEquipos archivo_equipos("equipos.dat");

    EquipoConDiez equipo_con_diez;
    ArchivoEquiposConDiez archivo_equipos_con_diez;
    archivo_equipos_con_diez.createEmptyArchive();

    int cant_jugadores = archivo_jugadores.contarRegistros();
    int cant_equipos = archivo_equipos.contarRegistros();
    int cant_deportes = archivo_deportes.contarRegistros();

    int id_equipo;
    int id_deporte;

    /* PUNTO 1 */

    int cant_jugs_del_equipo;
    bool deporte_determinado;

    for (int i = 0; i < cant_equipos; i ++) { // Para cada equipo
        equipo = archivo_equipos.leerRegistro(i);
        id_equipo = equipo.getIdEquipo();
        cant_jugs_del_equipo = 0;
        deporte_determinado = false;

        for (int j = 0; j < cant_jugadores; j ++) { // Recorro jugadores
            jugador = archivo_jugadores.leerRegistro(j);

            if (jugador.getIdEquipo() == id_equipo) { // Cuento cantidad de jugadores del equipo
                cant_jugs_del_equipo ++;

                if (deporte_determinado == false) { // Obtengo el deporte del equipo (una sola vez)
                    id_deporte = jugador.getIdDeporte();
                    deporte = archivo_deportes.leerRegistro(getIndex(id_deporte, archivo_deportes));
                    deporte_determinado = true;
                }
            }
        }

        if (2 <= cant_jugs_del_equipo) {
            equipo_con_diez.setNombre(equipo.getNombre());
            equipo_con_diez.setIdDeporte(deporte.getIdDeporte());
            equipo_con_diez.setIdDeporte(deporte.getIdCtegoria());

            archivo_equipos_con_diez.write(equipo_con_diez);
        }
    }

    /* PUNTO 2 */

    int cant_equip_diez = archivo_equipos_con_diez.getAmountOfRegisters();
    EquipoConDiez * arr_equipos_diez;
    arr_equipos_diez = new EquipoConDiez[cant_equip_diez];
    checkAllocation(arr_equipos_diez);

    for (int i = 0; i < cant_equip_diez; i ++) {
        equipo_con_diez = archivo_equipos_con_diez.read(i);
        arr_equipos_diez[i].setCategoria(equipo_con_diez.getCategoria());
        arr_equipos_diez[i].setIdDeporte(equipo_con_diez.getIdDeporte());
        arr_equipos_diez[i].setNombre(equipo_con_diez.getNombre());
    }

    for (int i = 0; i < cant_equip_diez; i ++) {
        std::cout << "NOMBRE: " << arr_equipos_diez[i].getNombre() << "\n";
        std::cout << "DEPORTE: " << arr_equipos_diez[i].getIdDeporte() << "\n";
        std::cout << "CAT.: " << arr_equipos_diez[i].getCategoria() << "\n";
    }

    delete [] arr_equipos_diez;

    /* PUNTO 3 */

    JugadorSobrecargado messi;
    Deporte futbol;

    messi.setIdDeporte(10);

    if (messi == futbol) {
        std::cout << messi.getIdDeporte() << "=" << futbol.getIdDeporte() << "\n";
    } else {
        std::cout << messi.getIdDeporte() << "!=" << futbol.getIdDeporte() << "\n";
    }

    /* PUNTO 4 */

    int claustro_del_jug;
    int arr_claustros[4]; // Array que tiene la cantidad de jugadores de un deporte por cada claustro
    bool tiene_todos = true;

    for (int i = 0; i < cant_deportes; i ++) { // Recorro cada deporte
        deporte = archivo_deportes.leerRegistro(i);
        std::cout << deporte.getNombre() << "\t";

        for (int c = 0; c < 4; c ++) { // Pongo en cero el array
            arr_claustros[c] = 0;
        }

        for (int j = 0; j < cant_jugadores; j ++) { // Recorro los jugadores
            jugador = archivo_jugadores.leerRegistro(j);
            id_deporte = jugador.getIdDeporte();

            if (id_deporte == deporte.getIdDeporte()) { // Aumento array de claustros si el jugador es de el deporte
                claustro_del_jug = jugador.getClaustro();
                arr_claustros[claustro_del_jug - 1] ++;
            }
        }

        for (int i = 0; i < 4; i ++) { // Si algun claustro no percenece a ningun jugador, el deporte no tiene todos los claustros
            if (arr_claustros[i] == 0) {
                tiene_todos = false;
            }
        }

        if (tiene_todos) {
            archivo_deportes.grabarRegistro(deporte);
            std::cout << " se escribe en archivo.\n";
        } else {
            std::cout << " no tiene todos los claustros.\n";
        }
    }
}

/*
ENUNCIADO
---------

La Facultad está organizando torneos de deportes entre los integrantes de los distintos claustros. Para gestionar las actividades tiene los siguientes archivos  con el formato que se muestra a continuación: 

jugadores.dat 
DNI
Nombre
Apellido 
Email 
Teléfono 
Claustro (1: docente; 2 alumno; 3 no docente; 4 graduado) 
Id de deporte (número entero) 
Número de equipo (número entero) 
Fecha de inscripción 
Matrícula ($)
Estado

deportes.dat
Id de deporte
Nombre
Categoría de deporte
Año de origen
Estado

equipos.dat
Número de equipo: el número del equipo es único y no se repite
Nombre
Nivel (1: inicial; 2: intermedio; 3: avanzado)
Estado

CONSIGNAS
---------

(1) Generar un archivo con los equipos que tengan al menos 10 jugadores inscriptos. Cada registro debe tener el ID de deporte, el nombre y la categoría.

(2) Hacer un vector dinámico para listar el archivo del punto anterior.

(3) Sobrecargar el operador == para comparar un objeto Jugador con un objeto Deporte. Debe devolver verdadero cuando coinciden los Id de deporte

(4) Hacer un archivo con los deportes que tengan jugadores de todos los claustros. Los registros del archivo nuevo deben tener el mismo formato que el archivo de deportes.

(5) Crear un vector dinámico con los equipos de nivel inicial. Listar el vector.

(6) Sobrecargar el operador == para la clase Jugador, que reciba un valor entero y lo compare con el Id de claustro.

(7) Generar un archivo con los jugadores que hayan pagado más de $10000 de matrícula y que se hayan inscripto este año. Cada registro del archivo debe tener el siguiente formato: DNI, nombre, apellido, claustro y nombre del deporte.

(8) Crear un vector con los jugadores pertenecientes a un equipo cuyo número de equipo se ingresa por teclado. Listar el vector

(9) Agregar una sobrecarga para el operador > de la clase Jugador de manera tal que sea verdadero cuando el año de inscripción sea mayor a un valor de año que se recibe cmo parámetro.
*/