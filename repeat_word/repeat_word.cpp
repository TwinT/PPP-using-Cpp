#include "../std_lib_facilities.h"

int main()
{
    string previous = " ";
    string current;
    while(cin >> current){
        if(current == previous){
            cout << "Palabra repetida: " << current << "\n";
        }
    previous = current;
    }
}
