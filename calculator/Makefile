CPP = g++
INC_PATH= -I../
CPPFLAGS= -Wall -Wextra -Weffc++ -g -std=c++14 $(INC_PATH)

TARGET= calculator
SRCS= calculator.cpp Token_stream.cpp Variable.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

($TARGET): $(OBJS)
	$(CPP) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS) 

# $< and $@ are macros defined by make
#     $< refers to the file being processed (i.e., compiled or linked)
#     $@ refers to the generated file

calculator.o: Token.h Token_stream.h Variable.h
Token_stream.o: Token_stream.h Token.h
Variable.o: Variable.h

.PHONY: clean
clean:
	rm -f $(TARGET) *.o
