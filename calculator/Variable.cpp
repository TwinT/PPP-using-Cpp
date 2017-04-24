#include "Variable.h"
#include "std_lib_facilities.h"

vector<Variable> var_table;

double get_value(string s)
// return the value of the Variable named s
{
  for (const Variable &v : var_table)
    if (v.name == s)
      return v.value;
  error("get: undefined variable ", s);
  return 0;
}

void set_value(string s, double d)
// set the Variable named s to d
{
  for (Variable &v : var_table)
    if (v.name == s) {
      v.value = d;
      return;
    }
  error("set: undefined variable ", s);
}

bool is_declared(string var)
// is var already in var_table?
{
  for (const Variable &v : var_table)
    if (v.name == var)
      return true;
  return false;
}
double define_name(string var, double val)
// add (var,val) to var_table
{
  if (is_declared(var))
    error(var, " declared twice");
  var_table.push_back(Variable(var, val));
  return val;
}
