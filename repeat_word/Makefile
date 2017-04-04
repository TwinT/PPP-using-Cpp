CPPFLAGS=-Wall -Wextra -Weffc++ -g -std=c++14
CPP = g++

TARGETS= repeat_word

all: $(TARGETS)

# $< and $@ are macros defined by make
#     $< refers to the file being processed (i.e., compiled or linked)
#     $@ refers to the generated file
%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -f $(TARGETS) *.o
