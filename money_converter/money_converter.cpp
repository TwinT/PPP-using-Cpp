#include "../std_lib_facilities.h"

int main()
{
    constexpr double dollars_in_yen{0.0089900};
    constexpr double dollars_in_pound{1.2385};
    constexpr double dollars_in_euro{1.0595};

    double monto{0};
    char unidad{0};
    cout << "Ingrese el monto a convertir en (p)pounds, (e)euros o (y) yenes: ";
    cin >> monto >> unidad;

    if (unidad == 'p'){
        cout << monto << " pounds son " << monto * dollars_in_pound << " dolares" << endl;
    }else if(unidad == 'y'){
        cout << monto << " yenes son " << monto * dollars_in_yen << " dolares" << endl;
    }else if(unidad == 'e'){
        cout << monto << " euros son " << monto * dollars_in_euro << " dolares" << endl;
    }else{
        cout << "No conozco la unidad " << unidad << endl;
    }

}
