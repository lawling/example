#if !defined TEST_NODE_HPP
#define TEST_NODE_HPP
#include<vector>
#include "./node.hpp"
/*
this test uses random data by defualt

verify function by using accesor`


*/
template<typename DATA_T>
class test_node{
	public:
	
	    test_node();
	    ~test_node();
	    test_node(test_node&) = delete;
	    test_node& operator=(const test_node&) = delete;

	    void test_attach_left_child ( std::size_t times);
            void test_attach_right_child ( std::size_t times);

	    void test_detach_left_child ( std::size_t  times);
	    void test_detach_right_child ( std::size_t  times);


	private:
             std::vector<DATA_T>  test_data;
      
	     node <DATA_T> test_node;
}
#include"./test_node.cpp"
#endif
