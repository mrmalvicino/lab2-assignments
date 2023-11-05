#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include "parcial2.h"

class ProveedorSinCompras {
    public:

    void setNumero(int numero) {
        _numero = numero;
    }

    int getNumero() {
        return _numero;
    }

    void setNombre(const char * nombre) {
        strcpy(_nombre, nombre);
    }

    const char * getNombre() {
        return _nombre;
    }

    void setProvincia(int provincia) {
        _provincia = provincia;
    }

    int getProvincia() {
        return _provincia;
    }

    private:

    int _numero;
    char _nombre[30];
    int _provincia;
};

class ArchivoProveedoresSinCompras {
    public:

    ArchivoProveedoresSinCompras() {
        setPath("proveedores_sin_compras.dat");
    }

    ArchivoProveedoresSinCompras(const char * path) {
        setPath(path);
    }

    void setPath(const char * path) {
        strcpy(_path, path);
    }

    const char * getPath() {
        return _path;
    }

    bool write(ProveedorSinCompras & reg) {
        FILE * file_pointer = fopen(getPath(), "ab");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return 0;
        }

        bool successful_write = fwrite(& reg, sizeof(ProveedorSinCompras), 1, file_pointer);
        fclose(file_pointer);

        return successful_write;
    }

    bool overWrite(ProveedorSinCompras & reg, int index) {
        FILE * file_pointer = fopen(getPath(), "rb+");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return 0;
        }

        fseek(file_pointer, sizeof(ProveedorSinCompras) * index, 0);
        bool successful_write = fwrite(& reg, sizeof(ProveedorSinCompras), 1, file_pointer);
        fclose(file_pointer);

        return successful_write;
    }

    ProveedorSinCompras read(int index) {
        ProveedorSinCompras reg;
        FILE * file_pointer = fopen(getPath(), "rb");

        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return reg;
        }

        fseek(file_pointer, sizeof(ProveedorSinCompras) * index, 0);
        fread(& reg, sizeof(ProveedorSinCompras), 1, file_pointer);
        fclose(file_pointer);

        return reg;
    }

    int getIndex(int numero) {
        int i = 0;
        ProveedorSinCompras reg;
        reg = read(i);

        while (reg.getNumero() != numero && i < getAmountOfRegisters()) {
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
        int total_registros = bytes / sizeof(ProveedorSinCompras);

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

class ObraSobrecargada{
private:
    char codigoObra[5];
    char direccion[30];
    int provincia;
    float superficie;
    int estadoEjecucion;
    bool activo;

public:
    bool operator == (int compared_sup) {
        if (superficie == compared_sup) {
            return true;
        }
        return false;
    }

    void Cargar(){
        cargarCadena(codigoObra,4);
        cargarCadena(direccion,29);
        cin>>provincia;
        cin>>superficie;
        cin>>estadoEjecucion;
        activo=true;
    }

    void Mostrar(){
        cout<<codigoObra<<endl;
        cout<<direccion<<endl;
        cout<<provincia<<endl;
        cout<<superficie<<endl;
        cout<<estadoEjecucion<<endl;
    }

    const char* getCodigoObra(){return codigoObra;}
    const char* getDireccion(){return direccion;}
    int getProvincia(){return provincia;}
    int getEstadoEjecucion(){return estadoEjecucion;}
    float getSuperficie(){return superficie;}
    bool getActivo(){return activo;}

    void setCodigoObra(const char *co){strcpy(codigoObra, co);}
    void setDireccion(const char *d){strcpy(direccion,d);}
    void setProvincia(int p){provincia=p;}
    void setEstadoEjecucion(int e){estadoEjecucion=e;}
    void setSuperficie(float s){superficie=s;}
    void setActivo(bool a){activo=a;}
};

void checkAllocation(int * arr) {
    if (arr == NULL) {
        std::cout << "Error de asignación de memoria.\n";
        exit(1);
    }
}

void checkAllocation(char * arr) {
    if (arr == NULL) {
        std::cout << "Error de asignación de memoria.\n";
        exit(1);
    }
}

void checkAllocation(Material * arr) {
    if (arr == NULL) {
        std::cout << "Error de asignación de memoria.\n";
        exit(1);
    }
}

int main() {
    system("clear");

    /* PUNTO 1 */

    Compra compra;
    ArchivoCompras archivo_compras("compras.dat");
    Proveedor proveedor;
    ArchivoProveedores archivo_proveedores("proveedores.dat");
    ProveedorSinCompras prov_sc;
    ArchivoProveedoresSinCompras archivo_prov_sc;

    int cant_compras_prov[60] = {}; // Cantidad de compras en año actual por cada proveedor

    for (int i = 0; i < archivo_compras.contarRegistros(); i ++) { // recorro archivo y aumento vector de compras
        compra = archivo_compras.leerRegistro(i);

        if (compra.getFechaCompra().getAnio() == 2023) {
            cant_compras_prov[compra.getNumeroproveedor() - 1] ++;
        }
    }

    archivo_prov_sc.createEmptyArchive();

    for (int i = 0; i < archivo_proveedores.contarRegistros(); i ++) { // recorro vector de compras y escribo nuevo archivo
        if (cant_compras_prov[i] == 0) {
            proveedor = archivo_proveedores.leerRegistro(i);
            prov_sc.setNumero(proveedor.getNumeroProveedor());
            prov_sc.setNombre(proveedor.getNombre());
            prov_sc.setProvincia(proveedor.getProvincia());
            archivo_prov_sc.write(prov_sc);
        }
    }

    /*
    for (int i = 0; i < archivo_prov_sc.getAmountOfRegisters(); i ++) { // Verificación punto 1
        prov_sc = archivo_prov_sc.read(i);
        std::cout << "NUM. DE PROV.:" << prov_sc.getNumero() << "\tNOMBRE:" << prov_sc.getNombre() << "\tPROVINCIA:" << prov_sc.getProvincia() << "\n";
    }
    */

    /* PUNTO 2 */

    Material material;
    ArchivoMateriales archivo_materiales("materiales.dat");

    int cant_por_tipos[6] = {};
    int cant_min_materiales;
    int min_tipo;

    for (int i = 0; i < archivo_materiales.contarRegistros(); i ++) { // Recorro archivo y aumento vector de tipos
        material = archivo_materiales.leerRegistro(i);
        cant_por_tipos[material.getTipo() - 1] ++;
    }

    cant_min_materiales = cant_por_tipos[0];
    min_tipo = 1;

    for (int i = 1; i < 6; i ++) { // Recorro vector de tipos y busco minimo
        if (cant_por_tipos[i] < cant_min_materiales && cant_por_tipos[i] != 0) {
            cant_min_materiales = cant_por_tipos[i];
            min_tipo = i + 1;
        }
    }

    std::cout << "TIPO CON MENOS MATERIALES: " << min_tipo << " (" << cant_min_materiales << " materiales de este tipo)\n";

    /*
    for (int i = 0; i < 6; i ++) { // Verificación punto 2
        std::cout << "Tipo " << i + 1 << ": " << cant_por_tipos[i] << "\n";
    }
    */

    /* PUNTO 3 */

    // Material material;
    // ArchivoMateriales archivo_materiales("materiales.dat");

    int size = archivo_materiales.contarRegistros();
    Material * vector_materiales;
    vector_materiales = new Material[size];
    checkAllocation(vector_materiales);

    for (int i = 0; i < size; i ++) {
        vector_materiales[i] = archivo_materiales.leerRegistro(i);
    }

    int tipo_cin;
    std::cout << "Ingresar tipo de material a mostrar:\n";
    std::cin >> tipo_cin;

    for (int i = 0; i < size; i ++) {
        if (vector_materiales[i].getTipo() == tipo_cin) {
            vector_materiales[i].Mostrar();
        }
    }

    delete [] vector_materiales;

    /* PUNTO 4 */

    /*
    ObraSobrecargada obra;
    obra.setSuperficie(200);

    if (obra == 200) {
        std::cout << "Superficie igual a 200 m2.\n";
    } else {
        std::cout << "Superficie distinta.\n";
    }
    */
}

/*
ENUNCIADO
---------

Una empresa constructora tiene, entre otros, los siguientes archivos en su sistema de información:

obras.dat
Código de obra (char[5])
Direccion (char [30])
Provincia (1 a 24)
Superficie (en metros cuadrados)
Estado de ejecución (1: en proyecto; 2: proyecto aprobado en espera;3: en ejecución; 4: terminada; 5: suspendida:)
Activo (si/no)

materiales.dat
Código de material (entero)
Nombre (char[30])
Marca (char[30])
Tipo (1: obra gruesa; 2: techos; 3: aberturas; 4: revestimientos; 5: sanitarios; 6: electricidad)
Precio unitario 
Activo (si/no)

compras.dat
Número de compra (entero)
Número de proveedor
Código de material
Código de obra
Cantidad
Importe
Fecha (día, mes y año)
Activo (si/no)

Las compras corresponden a los materiales utilizados para las obras registradas en el archivo obras.dat. Puede haber muchos registros para cada obra.

proveedores.dat
Número de proveedor (1 a 60)
Nombre
Teléfono
Dirección
Provincia (1 a 24)
Activo (si/no)

CONSIGNAS
---------

(1) Generar un archivo con los proveedores a los que no se les haya hecho compras el año actual. Por cada proveedor al que no se le hayan hecho compras este año se debe registrar el número de proveedor, el nombre del proveedor y la provincia del proveedor.

(2) El tipo de material con menos cantidad de materiales (ignorando los tipos sin materiales).

(3) Generar un vector dinámico con todos los materiales y listar luego los materiales del vector que pertenezcan a un tipo que se ingresa por teclado.

(4) Sobrecargar el operador == para la clase Obra de manera tal que sea verdadero cuando el objeto que llama al método tenga un valor de superficie igual a un valor de tipo float que se recibe como parámetro. Dejar el código comentado en el cpp que se entrega para evitar problemas de compilación.
*/