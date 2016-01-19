#ifndef NODE_H
#define NODE_H
#include<memory> 
template<data_type>
class Node{
public:
  void add_right_child(const Node<data_type>& right_child);
  void add_left_child(const Node<data_type>& left_child);
private:
  typedef data_type T;
  T data;
  std::shared_ptr<Node> left_child_ptr,right_child_ptr;
};
#endif
