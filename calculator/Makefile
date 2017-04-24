CPP = g++
INC_PATH = -I../
CPPFLAGS= -Wall -Wextra -Weffc++ -g -std=c++14 

TARGET= calculator
SRCS= *.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

($TARGET): $(OBJS)
	$(CPP) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS) 

# $< and $@ are macros defined by make
#     $< refers to the file being processed (i.e., compiled or linked)
#     $@ refers to the generated file

%.o: %.cpp
	$(CPP) -c $(CPPFLAGS) $(INC_PATH) -o $@ $<


.PHONY: clean
clean:
	rm -f $(TARGETS) *.o
