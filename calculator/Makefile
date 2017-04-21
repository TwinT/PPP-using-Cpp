CPP = g++
INC_PATH = -I../
CPPFLAGS= -Wall -Wextra -Weffc++ -g -std=c++14 $(INC_PATH)

TARGETS= calculator

all: $(TARGETS)

# $< and $@ are macros defined by make
#     $< refers to the file being processed (i.e., compiled or linked)
#     $@ refers to the generated file
%.o: %.cpp
	$(CPP) -c $(CPPFLAGS) -o $@ $<


.PHONY: clean
clean:
	rm -f $(TARGETS) *.o
