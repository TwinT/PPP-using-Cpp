#ifndef VARIABLE_H
#define VARIABLE_H

#include "std_lib_facilities.h"

class Variable {
public:
  string name;
  double value;
};

double get_value(string s);
void set_value(string s, double d);
bool is_declared(string var);
double define_name(string var, double val);

#endif // VARIABLE_H
