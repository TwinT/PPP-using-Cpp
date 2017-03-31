#include "../std_lib_facilities.h"

int main()
{
          cout << "Please enter a integer value: ";
          int n;
          cin >> n;
          double d = n;
          cout << "n == " << n
                    << "\nn+1 == " << n+1
                    << "\nthree times n == " << 3*n
                    << "\ntwice n == " << n+n
                    << "\nn squared == " << n*n
                    << "\nhalf of n == " << d/2
                    << "\nsquare root of n == " << sqrt(d)
                    << "\ninteger division by 3 == " << n/3
                    << "\nmodulo 5 == " << n % 5
                    << '\n';  // another name for newline (“end of line”) in output
}
