/*
          Simple calculator

          Revision history:

                    Revised by Bjarne Stroustrup November 2013
                    Revised by Bjarne Stroustrup May 2007
                    Revised by Bjarne Stroustrup August 2006
                    Revised by Bjarne Stroustrup August 2004
                    Originally written by Bjarne Stroustrup
                               (bs@cs.tamu.edu) Spring 2004.

          This program implements a basic expression calculator.
          Input from cin; output to cout.
          The grammar for input is:

          Statement:
                    Expression
                    Print
                    Quit
          Print:
                    ;

          Quit:
                    q

          Expression:
                    Term
                    Expression + Term
                    Expression – Term
          Term:
                    Primary
                    Term * Primary
                    Term / Primary
                    Term % Primary
          Primary:
                    Number
                    ( Expression )
                    – Primary
                    + Primary
          Number:
                    floating-point-literal


          Input comes from cin through the Token_stream called ts.
*/

#include "Token.h"
#include "Token_stream.h"
#include "Variable.h"
#include "std_lib_facilities.h"

Token_stream ts; // provides get() and putback()

double expression(); // declaration so that primary() can call expression()
double declaration();

//------------------------------------------------------------------------------
// deal with numbers and parentheses
double primary() {
  Token t = ts.get();
  switch (t.kind) {
  case '(': // handle '(' expression ')'
  {
    double d = expression();
    t = ts.get();
    if (t.kind != ')')
      error("')' expected");
    return d;
  }
  case '{': // handle '{' expression '}'
  {
    double d = expression();
    t = ts.get();
    if (t.kind != '}')
      error("'}' expected");
    return d;
  }
  case number:
    return t.value; // return the number's value
  case '+':
    return primary();
  case '-':
    return -primary();
  default:
    error("primary expected");
    return 0;
  }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term() {
  double left = primary();
  Token t = ts.get(); // get the next token from token stream

  while (true) {
    switch (t.kind) {
    case '*':
      left *= primary();
      t = ts.get();
      break;
    case '/': {
      double d = primary();
      if (d == 0)
        error("divide by zero");
      left /= d;
      t = ts.get();
    } break;
    case '%': {
      double d = primary();
      if (d == 0)
        error("divide by zero");
      left = fmod(left, d);
      t = ts.get();
    } break;
    default:
      ts.putback(t); // put t back into the token stream
      return left;
    }
  }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression() {
  double left = term(); // read and evaluate a Term
  Token t = ts.get();   // get the next token from token stream

  while (true) {
    switch (t.kind) {
    case '+':
      left += term(); // evaluate Term and add
      t = ts.get();
      break;
    case '-':
      left += term(); // evaluate Term and subtract
      t = ts.get();
      break;
    default:
      ts.putback(t); // put t back into the token stream
      return left;   // finally: no more + or -: return the answer
    }
  }
}

//------------------------------------------------------------------------------
double statement() {
  Token t = ts.get();
  switch (t.kind) {
  case let:
    return declaration();
  default:
    ts.putback(t);
    return expression();
  }
}
//------------------------------------------------------------------------------
double declaration()
// assume we have seen "let”
// handle: name = expression
// declare a variable called "name” with the initial value "expression”
{
  Token t = ts.get();
  if (t.kind != name)
    error("name expected in declaration");
  string var_name = t.name;

  Token t2 = ts.get();
  if (t2.kind != '=')
    error("= missing in declaration of ", var_name);

  double d = expression();
  define_name(var_name, d);
  return d;
}
//------------------------------------------------------------------------------
void calculate() {
  while (cin) {
    cout << prompt;
    Token t = ts.get();
    if (t.kind == print)
      t = ts.get(); // eat ';'
    if (t.kind == quit)
      return;
    ts.putback(t);
    cout << result << statement() << '\n';
  }
}
//------------------------------------------------------------------------------

int main() {
  cout << "Welcome to our simple calculator.\n";
  cout << "Please enter expressions using floating-point numbers.\n";
  cout << "Operators: + - * / () {}\n";
  cout << "q for exit\n";

  try {
    calculate();
  } catch (exception &e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
  } catch (...) {
    cerr << "exception!\n";
    return 2;
  }
}
//------------------------------------------------------------------------------
