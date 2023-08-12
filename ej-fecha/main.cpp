/*
Hacer una clase Fecha que permita generar objetos capaces de almacenar fechas y hacer operaciones con las mismas. La clase en ningún momento debe almacenar una fecha inválida. Es decir, una fecha que no exista en el calendario.

- Actividad 1
Realizar la declaración de la clase en un archivo H y la definición de los métodos en un archivo CPP. La clase fecha debe almacenar los siguientes atributos enteros: _dia, _mes y _year.

- Actividad 2
Realizar métodos getters para cada una de las propiedades mencionadas anteriormente.

- Actividad 3
Realizar un constructor que reciba tres parámetros llamados dia, mes y year. El mismo debe almacenar la fecha sólo si la misma es válida. De lo contrario, debe asignar por defecto la fecha 1/1/2023.

- Actividad 4
Realizar un constructor que no reciba parámetros. El mismo debe asignar a la fecha el valor 1/1/2023.

- Actividad 5
Hacer dos métodos privados llamados AgregarDia y RestarDia. El método AgregarDia debe aumentar en uno la fecha y el método RestarDia debe disminuir en uno la fecha. Tener en cuenta que los métodos deben tener en cuenta los cambios de mes y años si corresponde.
Por ejemplo, si la fecha almacenada en el objeto es 30/04/2023 y se llama a AgregarDia, entonces la fecha debería cambiar a 01/05/2023. Por otro lado, si la fecha almacenada es 01/01/2024 y se llama a RestarDia entonces la fecha debería cambiar a 31/12/2023. Los métodos deben tener en cuenta los años bisiestos para los cálculos.

- Actividad 6
Hacer un método público llamado AgregarDias que reciba un entero con la cantidad de días a agregar. El mismo debe añadir la cantidad de días recibidos como parámetro si el mismo es positivo o restarlos si valor del parámetro en negativo. En caso de ser cero no se debe modificar el estado del objeto.

- Actividad 7
Hacer un método toString que devuelva un string con la fecha que registra el objeto en el siguiente formato: DD/MM/AAAA. Por ejemplo, si el objeto registra la fecha 5/7/2023 entonces debe devolver el siguiente string: "05/07/2023".
*/

#include <iostream>
#include "Date.h"

int main(){
    Date yesterday(10,8,2023);
    Date today(11,8,2023);
    Date tomorrow(12,8,2023);

    std::cout << yesterday.to_string() << "\n";
    std::cout << today.to_string() << "\n";
    std::cout << tomorrow.to_string() << "\n";

    yesterday.add_days(1);
    today.add_days(-365);
    tomorrow.add_days(-1);

    std::cout << yesterday.to_string() << "\n";
    std::cout << today.to_string() << "\n";
    std::cout << tomorrow.to_string() << "\n";
}

/*
COMPILAR:
g++ -o ./bin/main main.cpp Date.cpp

EJECUTAR
./bin/main

CORRER PRUEBA DE ESCRITORIO:
./bin/main < ./test.txt
*/