CPPFLAGS=-Wall -Wextra -Weffc++ -g -std=c++14
CPP = g++

TARGETS= money_converter

all: $(TARGETS)

# $< and $@ are macros defined by make
#     $< refers to the file being processed (i.e., compiled or linked)
#     $@ refers to the generated file
%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -f $(TARGETS) *.o
