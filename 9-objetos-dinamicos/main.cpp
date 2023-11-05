#include <iostream>
#include <cstring>

class String {
    public:

    String(const char * arr = "Hello world!") {
        _size = strlen(arr) + 1;
        _array = new char[_size];
        checkAllocation(_array);
        strcpy(_array, arr);
        _array[_size - 1] = '\0';
    }

    String(int length) {
        _size = length + 1;
        _array = new char[_size];
        checkAllocation(_array);
        _array[_size - 1] = '\0';

        for (int i = 0; i < _size - 1; i ++) {
            _array[i] = 'a';
        }
    }

    ~String() {
        delete [] _array;
    }

    void operator = (const char * arr) {
        delete [] _array;
        _size = strlen(arr) + 1;
        _array = new char[_size];
        checkAllocation(_array);
        strcpy(_array, arr);
        _array[_size - 1] = '\0';
    }

    void operator = (const String & str) {
        delete [] _array;
        _size = str._size;
        _array = new char[_size];
        checkAllocation(_array);
        strcpy(_array, str._array);
        _array[_size - 1] = '\0';
    }

    void operator += (const String & str) {
        concatenate(str);
    }

    void operator += (const char * arr) {
        concatenate(arr);
    }

    bool operator == (const String & compared_str) {
        if (strcmp(_array, compared_str._array) == 0) {
            return true;
        }
        return false;
    }

    bool operator != (const String & compared_str) {
        if (strcmp(_array, compared_str._array) != 0) {
            return true;
        }
        return false;
    }

    bool operator < (const String & compared_str) { // Una palabra mayor que otra está más cerca del final en el diccionario.
        if (strcmp(_array, compared_str._array) < 0) {
            return true;
        }
        return false;
    }

    bool operator < (int length) {
        if (_size - 1 < length) {
            return true;
        }
        return false;
    }

    bool operator <= (const String & compared_str) {
        if (strcmp(_array, compared_str._array) <= 0) {
            return true;
        }
        return false;
    }

    bool operator <= (int length) {
        if (_size - 1 <= length) {
            return true;
        }
        return false;
    }

    friend std::ostream & operator << (std::ostream & output, const String & string) {
        output << string._array;
        return output;
    }

    friend std::istream & operator >> (std::istream & input, String & string) {
        char aux[50];
        input >> aux;
        string = aux;
        return input;
    }

    void addChar(char character) {
        _size ++;

        char * aux_arr;
        aux_arr = new char[_size];
        checkAllocation(aux_arr);

        strcpy(aux_arr, _array);
        aux_arr[_size - 2] = character;
        aux_arr[_size - 1] = '\0';
        delete [] _array;
        _array = new char[_size];
        strcpy(_array, aux_arr);
        delete [] aux_arr;
    }

    void concatenate(const char * arr) {
        _size += strlen(arr);

        char * aux_arr;
        aux_arr = new char[_size];
        checkAllocation(aux_arr);

        strcpy(aux_arr, _array);

        for (size_t i = 0; i < strlen(arr); i ++) { // Definí la variable de incremento como size_t en vez de int para que no haya un warning al comparar con strlen() que no tiene signo
            aux_arr[strlen(_array) + i] = arr[i];
        }

        aux_arr[_size - 1] = '\0';
        delete [] _array;
        _array = new char[_size];
        strcpy(_array, aux_arr);
        delete [] aux_arr;
    }

    void concatenate(const String & str) {
        _size += str._size - 1;

        char * aux_arr;
        aux_arr = new char[_size];
        checkAllocation(aux_arr);

        strcpy(aux_arr, _array);

        for (int i = 0; i < str._size - 1; i ++) { // Definí la variable de incremento como size_t en vez de int para que no haya un warning al comparar con strlen() que no tiene signo
            aux_arr[strlen(_array) + i] = str._array[i];
        }

        aux_arr[_size - 1] = '\0';
        delete [] _array;
        _array = new char[_size];
        strcpy(_array, aux_arr);
        delete [] aux_arr;
    }

    void onCaps() {
        for (int i = 0; i < _size; i ++) {
            if ('a' <= _array[i] && _array[i] <= 'z') {
                _array[i] = _array[i] + ('A' - 'a');
            }
        }
    }

    void noCaps() {
        for (int i = 0; i < _size; i ++) {
            if ('A' <= _array[i] && _array[i] <= 'Z') {
                _array[i] = _array[i] - ('A' - 'a');
            }
        }
    }

    void print() {
        std::cout << _array << "\n";
    }

    private:

    int _size;
    char * _array;

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

    // SOBRECARGA DE CIN Y COUT (CON FUNCIONES AMIGAS):
    /*
    String str_14;
    std::cout << "Ingresar cadena:\n";
    std::cin >> str_14;
    std::cout << str_14 << "\n";
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