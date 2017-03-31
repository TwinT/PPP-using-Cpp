#include "../std_lib_facilities.h"

int main()
{
    cout << "Por favor, ingrese su nombre y edad \n";
    double age = -1;
    string name = "???";
    cin >> name >> age;
    cout << "Hola, " << name << " (edad " << age*12 << " meses)\n";

    return 0;
}
