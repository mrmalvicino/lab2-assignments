#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include "parcialm1.h"

class ObrasArchivo {
    public:

    ObrasArchivo() {
        setPath("obras.dat");
    }

    ObrasArchivo(const char * path) {
        setPath(path);
    }

    void setPath(const char * path) {
        strcpy(_path, path);
    }

    const char * getPath() {
        return _path;
    }

    bool write(Obra & reg) {
        FILE * file_pointer = fopen(getPath(), "ab");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return 0;
        }

        bool successful_write = fwrite(& reg, sizeof(Obra), 1, file_pointer);
        fclose(file_pointer);

        return successful_write;
    }

    bool overWrite(Obra & reg, int index) {
        FILE * file_pointer = fopen(getPath(), "rb+");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return 0;
        }

        fseek(file_pointer, sizeof(Obra) * index, 0);
        bool successful_write = fwrite(& reg, sizeof(Obra), 1, file_pointer);
        fclose(file_pointer);

        return successful_write;
    }

    Obra read(int index) {
        Obra reg;
        FILE * file_pointer = fopen(getPath(), "rb");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return reg;
        }

        fseek(file_pointer, sizeof(Obra) * index, 0);
        fread(& reg, sizeof(Obra), 1, file_pointer);
        fclose(file_pointer);

        return reg;
    }

    int getIndex(const char * codigo_de_obra) {
        int i = 0;
        Obra reg;
        reg = read(i);

        while (reg.getCodigoObra() != codigo_de_obra && i < getAmountOfRegisters()) {
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
        int total_obras = bytes / sizeof(Obra);

        return total_obras;
    }

    void createEmptyObraArchive() {
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
    Obra obra;
    ObrasArchivo obras_archivo;
    ObrasArchivo obras_ejecucion_archivo("obras_ejecucion.dat");

    int cant_obras = obras_archivo.getAmountOfRegisters();
    obras_ejecucion_archivo.createEmptyObraArchive();

    for (int i = 0; i < cant_obras; i ++) {
        obra = obras_archivo.read(i);

        if (obra.getEstadoEjecucion() == 3) {
            obras_ejecucion_archivo.write(obra);
        }
    }

    std::cout << "\nTODOS: " << cant_obras << "\n";

    for (int i = 0; i < cant_obras; i ++) {
        obra = obras_archivo.read(i);
        std::cout << "COD. DE OBRA:" << obra.getCodigoObra() << "\nDIR:" << obra.getDireccion() << "\nESTADO:" << obra.getEstadoEjecucion() << "\n\n";
    }

    int cant_obras_ejecucion = obras_ejecucion_archivo.getAmountOfRegisters();

    std::cout << "\nEJECUCION: " << cant_obras_ejecucion << "\n";

    for (int i = 0; i < cant_obras_ejecucion; i ++) {
        obra = obras_ejecucion_archivo.read(i);
        std::cout << "COD. DE OBRA:" << obra.getCodigoObra() << "\nDIR:" << obra.getDireccion() << "\nESTADO:" << obra.getEstadoEjecucion() << "\n\n";
    }

    Proveedor proveedor;
    ArchivoProveedor archivo_proveedores("proveedores.dat");

    int cant_proveedores = archivo_proveedores.contarRegistros();
    int cant_prooveedores_en_cada_provincia[24] = {};
    int menor_cant_de_proveedores;
    int provincia_con_menor_cant_de_proveedores;

    for (int i = 0; i < cant_proveedores; i ++) {
        proveedor = archivo_proveedores.leerRegistro(i);
        cant_prooveedores_en_cada_provincia[proveedor.getProvincia() - 1] ++;
    }

    menor_cant_de_proveedores = cant_prooveedores_en_cada_provincia[0];
    provincia_con_menor_cant_de_proveedores = 1;

    for (int i = 1; i < 24; i ++) {
        if (cant_prooveedores_en_cada_provincia[i] < menor_cant_de_proveedores && cant_prooveedores_en_cada_provincia[i] != 0) {
            menor_cant_de_proveedores = cant_prooveedores_en_cada_provincia[i];
            provincia_con_menor_cant_de_proveedores = i + 1;
        }
    }

    std::cout << "provincia_con_menor_cant_de_proveedores: " << provincia_con_menor_cant_de_proveedores;
}

/*

COMPILAR:
g++ -o ./bin/main *.cpp

EJECUTAR:
./bin/main
.\bin\main.exe

*/