CXXFLAGS = -Wall -std=c++14
TEST_OBJS = test-matrix.o testbase.o matrix.o 

all : test-matrix

test-matrix: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

test : test-matrix
	./test-matrix

clean :
	rm -f test-matrix *.o *~

.PHONY: all clean test 
