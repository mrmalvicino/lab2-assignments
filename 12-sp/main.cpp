#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include "parcial2.h"

/* PUNTO 3 */

/*
class Fecha{
private:
    int dia,mes, anio;
public:
    bool operator == (int anio_comparar) {
        if (anio == anio_comparar) {
            return true;
        }
        return false;
    }

    void Cargar(){
        cin>>dia;
        cin>>mes;
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};
*/

class ClienteAnoPasado {
    public:

    void setCodigoCliente(const char * codigo_cliente) {
        strcpy(_codigo_cliente, codigo_cliente);
    }

    const char * getCodigoCliente() {
        return _codigo_cliente;
    }

    void setNombre(const char * nombre) {
        strcpy(_nombre, nombre);
    }

    const char * getNombre() {
        return _nombre;
    }

    void setFechaTour(Fecha fecha_tour) {
        _fecha_tour = fecha_tour;
    }

    Fecha getFechaTour() {
        return _fecha_tour;
    }

    private:

    char _codigo_cliente[5];
    char _nombre[30];
    Fecha _fecha_tour;
};

class ArchivoClientesAnoPasado {
    public:

    ArchivoClientesAnoPasado() {
        setPath("equipos_con_diez.dat");
    }

    ArchivoClientesAnoPasado(const char * path) {
        setPath(path);
    }

    void setPath(const char * path) {
        strcpy(_path, path);
    }

    const char * getPath() {
        return _path;
    }

    bool write(ClienteAnoPasado & reg) {
        FILE * file_pointer = fopen(getPath(), "ab");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return 0;
        }

        bool successful_write = fwrite(& reg, sizeof(ClienteAnoPasado), 1, file_pointer);
        fclose(file_pointer);

        return successful_write;
    }

    bool overWrite(ClienteAnoPasado & reg, int index) {
        FILE * file_pointer = fopen(getPath(), "rb+");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return 0;
        }

        fseek(file_pointer, sizeof(ClienteAnoPasado) * index, 0);
        bool successful_write = fwrite(& reg, sizeof(ClienteAnoPasado), 1, file_pointer);
        fclose(file_pointer);

        return successful_write;
    }

    ClienteAnoPasado read(int index) {
        ClienteAnoPasado reg;
        FILE * file_pointer = fopen(getPath(), "rb");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return reg;
        }

        fseek(file_pointer, sizeof(ClienteAnoPasado) * index, 0);
        fread(& reg, sizeof(ClienteAnoPasado), 1, file_pointer);
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
        int total_registros = bytes / sizeof(ClienteAnoPasado);

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

void checkAllocation(ClienteAnoPasado * arr) {
    if (arr == NULL) {
        std::cout << "Error de asignacion de memoria.\n";
        exit(1);
    }
}

int main() {
    Cliente cliente;
    ArchivoClientes archivo_clientes("clientes.dat");

    Venta venta;
    ArchivoVentas archivo_ventas("ventas.dat");

    ClienteAnoPasado cliente_ano_pasado;
    ArchivoClientesAnoPasado archivo_cli_ano_pasado;

    int cant_clientes = archivo_clientes.contarRegistros();
    int cant_ventas = archivo_ventas.contarRegistros();

    /* PUNTO 1 */

    char cod_cli[5];
    Fecha fech_venta;
    bool compro_anio_pasado;
    bool client_ya_cargado;

    for (int i = 0; i < cant_clientes; i ++) { // Recorro clientes
        cliente = archivo_clientes.leerRegistro(i);
        strcpy(cod_cli, cliente.getCodigoCliente());
        compro_anio_pasado = false;
        client_ya_cargado = false;

        for (int j = 0; j < cant_ventas; j ++) { // Recorro ventas
            venta = archivo_ventas.leerRegistro(j);
            fech_venta.setDia(venta.getFechaVenta().getDia());
            fech_venta.setMes(venta.getFechaVenta().getMes());
            fech_venta.setAnio(venta.getFechaVenta().getAnio());

            if (fech_venta.getAnio() == 2022 && strcmp(cod_cli, venta.getNumeroDeCliente()) == 0) { // Seria util poder comparar directamente el anio con sobrecarga de Fecha para ==
                compro_anio_pasado = true;
            }
        }

        if (compro_anio_pasado && client_ya_cargado == false) {
            cliente_ano_pasado.setCodigoCliente(cod_cli);
            cliente_ano_pasado.setFechaTour(fech_venta);
            cliente_ano_pasado.setNombre(cliente.getNombre());
            archivo_cli_ano_pasado.write(cliente_ano_pasado);
            client_ya_cargado = true;
        }
    }

    /* PUNTO 2 */

    int cant_cli_an_pas = archivo_cli_ano_pasado.getAmountOfRegisters();
    ClienteAnoPasado * arr_cli_anio_pas;
    arr_cli_anio_pas = new ClienteAnoPasado[cant_cli_an_pas];
    checkAllocation(arr_cli_anio_pas);

    for (int i = 0; i < cant_cli_an_pas; i ++) { // De disco a RAM
        cliente_ano_pasado = archivo_cli_ano_pasado.read(i);
        arr_cli_anio_pas[i].setNombre(cliente_ano_pasado.getNombre());
        arr_cli_anio_pas[i].setCodigoCliente(cliente_ano_pasado.getCodigoCliente());
        arr_cli_anio_pas[i].setFechaTour(cliente_ano_pasado.getFechaTour());
    }

    for (int i = 0; i < cant_cli_an_pas; i ++) { // Muestro vector
        std::cout << "NOMBRE: " << arr_cli_anio_pas[i].getNombre() << "\n";
        std::cout << "COD.: " << arr_cli_anio_pas[i].getCodigoCliente() << "\n";
        std::cout << "FECHA: " << arr_cli_anio_pas[i].getFechaTour().getDia() << "/" << arr_cli_anio_pas[i].getFechaTour().getMes() << "/" << arr_cli_anio_pas[i].getFechaTour().getAnio() << "\n";
    }

    delete [] arr_cli_anio_pas;

}

/*
ENUNCIADO
---------

Una empresa de turismo tiene, entre otros, los siguientes archivos en su sistema de informacion:

clientes.dat
Codigo de cliente (char[5])
Categoria de cliente (1 a 5)
Nombre
Direccion (char [30])
Telefono
Email
Fecha de inscripcion.
Estado (si/no)

tours.dat
Codigo de tour (entero)
Nombre (char[30])
Tipo de tour (1: recorrido local; 2: recorrido con viaje y regreso en el dia; 3: semanal destino nacional; 4: destino internacional)
Estado (si/no)

ventas.dat
Numero de venta (entero)
Codigo de tour
Codigo de cliente
ID personal del guia
Importe
Fecha (dia, mes y ano)
Estado (si/no)

El archivo tiene registros desde el ano 2020. Puede haber muchos registros para cada cliente y/o guia y/o tour. Cada vez que un cliente contrata una salida, se le genera un boleto. 

guias.dat
ID personal 
Nombre
Telefono
Email
Direccion
Estado (si/no)

CONSIGNAS
---------

(1) Generar un archivo con los clientes que hayan realizado compras el ano pasado. Cada registro debe tener el codigo de cliente, el nombre del cliente y la fecha del tour. En caso de que haya mas de una compra para ese ano se debe registrar la fecha de la primera.

(2) Hacer una funcion que cree un vector dinamico para cargar los registros del archivo generado en el punto 1. Mostrar los registros del vector.

(3) Hacer una sobrecarga de operador para la clase nueva del punto 1 que sea util para la resolucion de alguno de los puntos.

FORMATO
-------
apellido_nombre.cpp
*/