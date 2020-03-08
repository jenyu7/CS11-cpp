NAME = lab4
CXXFLAGS = -Wall -Wpedantic -Werror=sign-compare -std=c++14
CONVERT_OBJS = units.o convert.o
TEST_OBJS = units.cpp testbase.cpp hw3testunits.cpp 

all : convert hw3testunits

convert : $(CONVERT_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

hw3testunits: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

doc : 
	doxygen Doxyfile
test : 
	./hw3testunits

clean :
	rm -f convert hw3testunits *.o *~ 
	rm -rf docs

.PHONY: all clean test doc

