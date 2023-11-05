#include <iostream>
#include <cstring>

class String {
    public:

    String(const char * str = "Hello world!") {
        _length = strlen(str) + 1;
        _string = new char[_length];
        checkAllocation(_string);

        strcpy(_string, str);
        _string[_length - 1] = '\0';
    }

    String(int length) {
        _length = length + 1;
        _string = new char[_length];
        checkAllocation(_string);

        for (int i = 0; i < _length - 1; i ++) {
            _string[i] = 'a';
        }

        _string[_length - 1] = '\0';
    }

    ~String() {
        delete [] _string;
    }

    void operator = (const char * str) {
        delete [] _string;
        _length = strlen(str) + 1;
        _string = new char[_length];
        checkAllocation(_string);

        strcpy(_string, str);
        _string[_length - 1] = '\0';
    }

    void operator = (const String & str) {
        delete [] _string;
        _length = str._length;
        _string = new char[_length];
        checkAllocation(_string);

        strcpy(_string, str._string);
        _string[_length - 1] = '\0';
    }

    void operator += (const String & str) {
        concatenate(str);
    }

    void operator += (const char * str) {
        concatenate(str);
    }

    bool operator == (const String & compared_str) {
        if (strcmp(_string, compared_str._string) == 0) {
            return true;
        }
        return false;
    }

    bool operator != (const String & compared_str) {
        if (strcmp(_string, compared_str._string) != 0) {
            return true;
        }
        return false;
    }

    bool operator < (const String & compared_str) { // Una palabra mayor que otra está más cerca del final en el diccionario.
        if (strcmp(_string, compared_str._string) < 0) {
            return true;
        }
        return false;
    }

    bool operator < (int compared_length) {
        if (_length - 1 < compared_length) {
            return true;
        }
        return false;
    }

    bool operator <= (const String & compared_str) { // Una palabra mayor que otra está más cerca del final en el diccionario.
        if (strcmp(_string, compared_str._string) <= 0) {
            return true;
        }
        return false;
    }

    bool operator <= (int compared_length) {
        if (_length - 1 <= compared_length) {
            return true;
        }
        return false;
    }

    void addChar(char character) {
        _length ++;

        char * new_string;
        new_string = new char[_length];
        checkAllocation(new_string);

        strcpy(new_string, _string);
        new_string[_length - 2] = character;
        new_string[_length - 1] = '\0';
        delete [] _string;
        _string = new char[_length];
        strcpy(_string, new_string);
        delete [] new_string;
    }

    void concatenate(const char * str) {
        _length += strlen(str);

        char * new_string;
        new_string = new char[_length];
        checkAllocation(new_string);

        strcpy(new_string, _string);

        for (size_t i = 0; i < strlen(str); i ++) { // Definí la variable de incremento como size_t en vez de int para que no haya un warning al comparar con strlen() que no tiene signo
            new_string[strlen(_string) + i] = str[i];
        }

        new_string[_length - 1] = '\0';
        delete [] _string;
        _string = new char[_length];
        strcpy(_string, new_string);
        delete [] new_string;
    }

    void concatenate(const String & str) {
        _length += str._length - 1;

        char * new_string;
        new_string = new char[_length];
        checkAllocation(new_string);

        strcpy(new_string, _string);

        for (int i = 0; i < str._length - 1; i ++) { // Definí la variable de incremento como size_t en vez de int para que no haya un warning al comparar con strlen() que no tiene signo
            new_string[strlen(_string) + i] = str._string[i];
        }

        new_string[_length - 1] = '\0';
        delete [] _string;
        _string = new char[_length];
        strcpy(_string, new_string);
        delete [] new_string;
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

    void print() {
        std::cout << _string << "\n";
    }

    private:

    char * _string;
    int _length;

    void checkAllocation(char * string) {
        if (string == NULL) {
            std::cout << "Error de asignación de memoria.\n";
            exit(1);
        }
    }
};

int main() {
    // system("clear");

    // CONSTRUCTORES Y MÉTODOS

    /*
    String str_0(4);
    str_0.print();
    String str_1("Hello world");
    str_1.print();
    str_1.addChar('!');
    str_1.print();
    str_1.concatenate(" This is C++!");
    str_1.print();
    str_1.onCaps();
    str_1.print();
    str_1.noCaps();
    str_1.print();
    */

    // SOBRECARGA DEL OPERADOR ==

    /*
    String str_2;
    str_2.print();

    String str_3("¡Hola mundo!");
    str_3.print();

    if (str_2 == str_3) {
        std::cout << "Son iguales.\n";
    } else {
        std::cout << "Son distintos.\n";
    }
    */

    // SOBRECARGA DEL OPERADOR <

    /*
    String str_4("Auto");
    str_4.print();

    String str_5("Zorro");
    str_5.print();

    if (str_4 < str_5) {
        std::cout << "str_4 < str_5\n";
    } else {
        std::cout << "str_4 >= str_5\n";
    }

    if (str_4 < 5) {
        std::cout << "Longitud < 5\n";
    } else {
        std::cout << "Longitud >= 5\n";
    }
    */

   // SOBRECARGA DEL OPERADOR =

    /*
    String str_6;
    str_6 = "...some text...";
    str_6.print();

    String str_7;
    str_7 = str_6;
    str_7.print();
    */

    // SOBRECARGA DEL OPERADOR !=

    /*
    String str_8("Lorem Ipsum");
    str_8.print();
    String str_9("lorem ipsum");
    str_9.print();

    if (str_8 != str_9) {
        std::cout << "8 != 9\n";
    }
    */

    // SOBRECARGA DEL OPERADOR +=

    /*
    String str_10("¡Hola");
    String str_11(" mundo!");
    str_10 += str_11;
    str_10.print();
    */

    // SOBRECARGA DEL OPERADOR <=

    /*
    String str_12("Taxi");
    str_12.print();

    String str_13("Maxi");
    str_13.print();

    if (str_12 <= str_13) {
        std::cout << "str_12 <= str_13\n";
    } else {
        std::cout << "str_12 > str_13\n";
    }

    if (str_12 <= 4) {
        std::cout << "Longitud <= 4\n";
    } else {
        std::cout << "Longitud > 4\n";
    }
    */

   return 0;
}

/*
COMPILAR:
g++ -o ./bin/main *.cpp

EJECUTAR:
./bin/main
.\bin\main.exe
*/