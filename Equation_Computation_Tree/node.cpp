void Node<data_type>::add_right_child(const Node<data_type> & right_child){
               right_child_ptr = make_shared(right_child);
}
void Node<data_type>::add_left_child(const Node<data_type> & left_child){
                left_child_ptr = make_shared(left_child);
}
