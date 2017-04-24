#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H

#include "std_lib_facilities.h"

const char number{'8'};
const char print{';'};
const char quit{'q'};
const char prompt{'>'};
const char result{'='};
const char name = 'a';        // name token
const char let = 'L';         // declaration token
const string declkey = "let"; // declaration keyword

class Token_stream {
public:
  Token_stream();        // make a Token_stream that reads from cin
  Token get();           // get a Token (get() is defined elsewhere)
  void putback(Token t); // put a Token back
private:
  bool full;    // is there a Token in the buffer?
  Token buffer; // here is where we keep a Token put back using putback()
};

#endif // TOKEN_STREAM_H
