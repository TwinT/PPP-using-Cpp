#ifndef TOKEN_H
#define TOKEN_H

#include "std_lib_facilities.h"

class Token {
public:
  char kind;    // what kind of token
  double value{0}; // for numbers: a value
  string name{""};
  Token(char ch) // make a Token from a char
      : kind(ch),
        value(0)
{}
  Token(char ch, double val) // make a Token from a char and a double
      : kind(ch),
        value(val)
         {}
  Token(char ch, string n) // make a Token from a char and a double
      : kind(ch),
        name(n) {}
};

#endif // TOKEN_H
