#include "../std_lib_facilities.h"

int main() {
  double num1, num2;
  cout << "Ingrese dos números ('|' para terminar)" << endl;
  while (cin >> num1 >> num2) {
    int min{0}, max{0};
    if (num1 < num2) {
      min = num1;
      max = num2;
    } else {
      min = num2;
      max = num1;
    }
    cout << "El valor mínimo es: " << min << endl;
    cout << "El valor máximo es: " << max << endl;
    if (abs(num1 - num2) < 1.0 / 100.0) {
      cout << "Los números son casi iguales " << endl;
    }
  }

  return 0;
}
