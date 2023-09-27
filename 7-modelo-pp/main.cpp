#include <iostream>
#include <cstring>
#include <cstdio>
// #include "parcialm1.h"

class Terminal {
    public:

    Terminal() {
        setLineLenght(50);
        setBackCaption("ATRÁS");
    }

    void setLineLenght(int line_lenght) {
        _line_lenght = line_lenght;
    }

    int getLineLenght() {
        return _line_lenght;
    }

    void setBackCaption(const char * back_caption) {
        strcpy(_back_caption, back_caption);
    }

    const char * getBackCaption() {
        return _back_caption;
    }

    void clear() {
        #ifdef _WIN64
            system("cls");
        #endif

        #ifdef __linux__
            system("clear");
        #endif

        #ifdef __APPLE__
            system("clear");
        #endif
    }

    void pause() {
        #ifdef _WIN64
            system("pause");
        #endif

        #ifdef __linux__
            int aux = 1;

            do{
                std::cout << "Ingresar 0 para continuar.\n";
                std::cin >> aux;
            } while (aux != 0);
        #endif

        #ifdef __APPLE__
            int aux = 1;
            std::cout << "\nIngresar 0 para continuar.\n";

            while (true) {
                if (std::cin >> aux && aux == 0) {
                    break;
                } else {
                    std::cin.clear();
                    cleanBuffer();
                    std::cout << "Ingresar 0 para continuar.\n";
                }
            }
        #endif
    }

    void printLine() {
        for (int i = 0; i < getLineLenght(); i ++) {
            std::cout << "-";
        }

        std::cout << "\n";
    }

    void centerAndPrint(std::string text) {
        int blanks = (getLineLenght() - text.length()) / 2;
        
        for (int i = 0; i < blanks; i ++) {
            std::cout << " ";
        }

        std::cout << text;

        for (int i = 0; i < blanks; i ++) {
            std::cout << " ";
        }

        std::cout << "\n";
    }

    void printBackOption() {
        std::cout << "(0) " << getBackCaption() << "\n";
    }

    void displayMenuHeader(std::string title) {
        printLine();
        centerAndPrint(title);
        printLine();
    }

    void displayMenuFooter() {
        printLine();
        printBackOption();
    }

    void printBool(bool parameter, std::string text_if_true, std::string text_if_false) {
        if (parameter == true) {
            std::cout << text_if_true;
        } else {
            std::cout << text_if_false;
        }
    }

    bool validateBool() {
        char input;
        bool rtn;

        while (true) {
            if (std::cin >> input && (input == 'y' || input == 'Y' || input == 's' || input == 'S' || input == 'n' || input == 'N')) {
                break;
            } else {
                std::cin.clear();
                cleanBuffer();
                std::cout << "Error de validación: Ingresar 'S' para confirmar o 'N' para denegar.\n";
            }
        }

        if (input == 'y' || input == 'Y' || input == 's' || input == 'S') {
            rtn = true;
        } else {
            rtn = false;
        }

        return rtn;
    }

    int validateInt() {
        int rtn;
        
        while (true) {
            if (std::cin >> rtn) {
                break;
            } else {
                std::cin.clear();
                cleanBuffer();
                std::cout << "Error de validación: Ingrese un número entero.\n";
            }
        }

        return rtn;
    }

    int validateInt(int min) {
        int rtn;
        
        while (true) {
            if (std::cin >> rtn && min <= rtn) {
                break;
            } else {
                std::cin.clear();
                cleanBuffer();
                std::cout << "Error de validación: Ingrese un número entero mayor o igual a " << min << ".\n";
            }
        }

        return rtn;
    }

    int validateInt(int min, int max) {
        int rtn;
        
        while (true) {
            if (std::cin >> rtn && min <= rtn && rtn <= max) {
                break;
            } else {
                std::cin.clear();
                cleanBuffer();
                if (min < max) {
                    std::cout << "Error de validación: Ingrese un número entero mayor (o igual) a " << min << " y menor (o igual) a " << max << ".\n";
                } else if (min == max) {
                    std::cout << "Error de validación: El único ingreso válido es " << min << ".\n";
                } else {
                    std::cout << "Error de validación: Los extremos están definidos de manera que no haya ingresos válidos.\n";
                }
            }
        }

        return rtn;
    }

    long long int validateLongInt() {
        long long int rtn;
        
        while (true) {
            if (std::cin >> rtn) {
                break;
            } else {
                std::cin.clear();
                cleanBuffer();
                std::cout << "Error de validación: Ingrese un número entero.\n";
            }
        }

        return rtn;
    }

    long long int validateLongInt(int min) {
        long long int rtn;
        
        while (true) {
            if (std::cin >> rtn && min <= rtn) {
                break;
            } else {
                std::cin.clear();
                cleanBuffer();
                std::cout << "Error de validación: Ingrese un número entero mayor o igual a " << min << ".\n";
            }
        }

        return rtn;
    }

    long long int validateLongInt(int min, int max) {
        long long int rtn;
        
        while (true) {
            if (std::cin >> rtn && min <= rtn && rtn <= max) {
                break;
            } else {
                std::cin.clear();
                cleanBuffer();
                if (min < max) {
                    std::cout << "Error de validación: Ingrese un número entero mayor (o igual) a " << min << " y menor (o igual) a " << max << ".\n";
                } else if (min == max) {
                    std::cout << "Error de validación: El único ingreso válido es " << min << ".\n";
                } else {
                    std::cout << "Error de validación: Los extremos están definidos de manera que no haya ingresos válidos.\n";
                }
            }
        }

        return rtn;
    }

    char validateChar() {
        char rtn;
        
        while (true) {
            if (std::cin >> rtn) {
                break;
            } else {
                std::cin.clear();
                cleanBuffer();
            }
        }

        return rtn;
    }

    void configureUTF8() {
        #ifdef _WIN64
            system("chcp 65001");
        #endif
    }

    void cleanBuffer() {
        int aux;
        while ((aux = std::cin.get()) != '\n' && aux != EOF) {}
    }

    private:

    int _line_lenght;
    char _back_caption[30];
};

class Obra {
    public:

    void setCodigoDeObra(const char * codigo_de_obra) {
        strcpy(_codigo_de_obra, codigo_de_obra);
    }

    const char * getCodigoDeObra() {
        return _codigo_de_obra;
    }

    void setDireccion(const char * direccion) {
        strcpy(_direccion, direccion);
    }

    const char * getDireccion() {
        return _direccion;
    }

    void setProvincia(int provincia) {
        _provincia = provincia;
    }

    int getProvincia() {
        return _provincia;
    }

    void setSuperficie(int superficie) {
        _superficie = superficie;
    }

    int getSuperficie() {
        return _superficie;
    }

    void setEstadoDeEjecucion(int estado_de_ejecucion) {
        _estado_de_ejecucion = estado_de_ejecucion;
    }

    int getEstadoDeEjecucion() {
        return _estado_de_ejecucion;
    }

    void setActivo(bool activo) {
        _activo = activo;
    }

    bool getActivo() {
        return _activo;
    }

    private:

    char _codigo_de_obra[5];
    char _direccion[30];
    int _provincia; // de 1 a 24
    int _superficie;
    int _estado_de_ejecucion; // 1 proyecto | 2 espera | 3 ejecucion | 4 terminada | 5 suspendida
    bool _activo; // 1 si | 2 no
};

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

        while (reg.getCodigoDeObra() != codigo_de_obra && i < getAmountOfRegisters()) {
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
    Terminal terminal;
    Obra obra;
    ObrasArchivo obras_archivo;
    ObrasArchivo obras_ejecucion_archivo("obras_ejecucion.dat");

    int cant_obras = obras_archivo.getAmountOfRegisters();
    obras_ejecucion_archivo.createEmptyObraArchive();

    for (int i = 0; i < cant_obras; i ++) {
        obra = obras_archivo.read(i);

        if (obra.getEstadoDeEjecucion() == 3) {
            obras_ejecucion_archivo.write(obra);
        }
    }

    std::cout << "\nTODOS: " << cant_obras << "\n";

    for (int i = 0; i < cant_obras; i ++) {
        obra = obras_archivo.read(i);
        std::cout << "COD. DE OBRA:" << obra.getCodigoDeObra() << "\nDIR:" << obra.getDireccion() << "\nESTADO:" << obra.getEstadoDeEjecucion() << "\n\n";
    }

    int cant_obras_ejecucion = obras_ejecucion_archivo.getAmountOfRegisters();

    std::cout << "\nEJECUCION: " << cant_obras_ejecucion << "\n";

    for (int i = 0; i < cant_obras_ejecucion; i ++) {
        obra = obras_ejecucion_archivo.read(i);
        std::cout << "COD. DE OBRA:" << obra.getCodigoDeObra() << "\nDIR:" << obra.getDireccion() << "\nESTADO:" << obra.getEstadoDeEjecucion() << "\n\n";
    }
}

/*

COMPILAR:
g++ -o ./bin/main *.cpp

EJECUTAR:
./bin/main
.\bin\main.exe

*/