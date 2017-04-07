#include "../std_lib_facilities.h"

int main()
{
    constexpr double dollars_in_yen{1};
    constexpr double dollars_in_pound{1};
    constexpr double dollars_in euro{1}:

    double monto{0};
    char unidad{0};
    cout << "Ingrese el monto a convertir en (p)pounds, (e)euros o (y) yenes: " << endl;
    cin >> monto >> unidad;

    if (unidad == 'p'){
        cout << monto << " pounds son " << monto * dollars_in_pound << endl;
    }else if(unidad == 'y'){
        cout << monto << " yenes son " << monto * dollars_in_yenes << endl;
    }else if(unidad == 'e'){
        cout << monto << " euros son " << monto * dollars_in_euro << endl;
    }else{
        cout << "No conozco la unidad " << unidad << endl;
    }

}
