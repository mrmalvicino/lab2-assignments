#include <iostream>
#include <cstring>

class String {
    public:

    String(const char * str) {
        _length = strlen(str) + 1;
        _string = new char[_length];

        if (_string == NULL) {
            std::cout << "Error de asignación de memoria.\n";
            exit(1);
        }

        strcpy(_string, str);
        _string[_length - 1] = '\0';
    }

    String(int length) {
        _length = length + 1;
        _string = new char[_length];

        if (_string == NULL) {
            std::cout << "Error de asignación de memoria.\n";
            exit(1);
        }

        for (int i = 0; i < _length - 1; i ++) {
            _string[i] = 'a';
        }

        _string[_length - 1] = '\0';
    }

    ~String() {
        delete _string;
    }

    int getLength() {
        return _length;
    }

    void print() {
        std::cout << _string << "\n";
    }

    void addChar(char character) {
        _length ++;

        char * new_string;
        new_string = new char[_length];

        if (new_string == NULL) {
            std::cout << "Error de asignación de memoria.\n";
            exit(1);
        }

        strcpy(new_string, _string);
        new_string[_length - 2] = character;
        new_string[_length - 1] = '\0';
        delete _string;
        _string = new char[_length];
        strcpy(_string, new_string);
        delete new_string;
    }

    void concatenate(const char * str) {
        _length += strlen(str);

        char * new_string;
        new_string = new char[_length];

        if (new_string == NULL) {
            std::cout << "Error de asignación de memoria.\n";
            exit(1);
        }

        strcpy(new_string, _string);

        for (size_t i = 0; i < strlen(str); i ++) { // Definí la variable de incremento como size_t en vez de int para que no haya un warning al comparar con strlen() que no tiene signo
            new_string[strlen(_string) + i] = str[i];
        }

        new_string[_length - 1] = '\0';
        delete _string;
        _string = new char[_length];
        strcpy(_string, new_string);
        delete new_string;
    }

    void onCaps() {
        for (int i = 0; i < _length; i ++) {
            if ('a' <= _string[i] && _string[i] <= 'z') {
                _string[i] = _string[i] + ('A' - 'a');
            }
        }
    }

    void noCaps() {
        for (int i = 0; i < _length; i ++) {
            if ('A' <= _string[i] && _string[i] <= 'Z') {
                _string[i] = _string[i] - ('A' - 'a');
            }
        }
    }

    private:

    char * _string;
    int _length;
};

int main() {
    String str_2(4);
    str_2.print();
    String str("Hello world");
    str.print();
    str.addChar('!');
    str.print();
    str.concatenate(" This is C++!");
    str.print();
    str.onCaps();
    str.print();
    str.noCaps();
    str.print();
}

/*
COMPILAR:
g++ -o ./bin/main *.cpp

EJECUTAR:
./bin/main
.\bin\main.exe
*/