CXX:=g++
FLAGS:= -std=c++14 
test_node.x:test_node.o  node.hpp node.cpp
	$(CXX) $(FLAGS)  test_node.o -o test_node.x 

test_node.o:test_node.cpp node.hpp node.cpp
	$(CXX) $(FLAGS) -c test_node.cpp -o test_node.o

clean:
	-rm test_node.x test_node.o
