CXXFLAGS = -Wall -std=c++14
TEST_OBJS = test-rational.o testbase.o rational.o 

all : test-rational

test-rational: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

test : test-rational
	./test-rational 

clean :
	rm -f test-rational *.o *~

.PHONY: all clean test 
