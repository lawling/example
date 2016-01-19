#if!defined NODE_CPP
#define NODE_CPP
template<typename DATA_T>
node<DATA_T>::node():parent{nullptr},data_ptr{},depth{0},height{}
{
}

template <typename DATA_T>
node<DATA_T>::node(DATA_T d ):parent{nullptr},data_ptr{new DATA_T{d} },depth{0},height{}
{

}
template<typename DATA_T>
node<DATA_T>::node(node&& n) noexcept{
   std::cout<<"move semantic \n";

}
template<typename DATA_T>
void node<DATA_T>::attach_left_child(const std::shared_ptr<node> n)
{
   if(n == nullptr)
      throw std::runtime_error("node does not exist");

   n->reset_parent();
   n->parent = this;
   this->left_child = n;
   return;
}

   template<typename DATA_T>
void node<DATA_T>::attach_right_child(const std::shared_ptr<node> n)
{
   if(n == nullptr)
      throw std::runtime_error("node does not exist");

   n->reset_parent();
   n->parent = this;
   this->right_child = n;
   return;
}

   template<typename DATA_T>
void node<DATA_T>::detach_left_child()
{
   if(this->left_child == nullptr)
      throw std::runtime_error("no left_child to detach");

   this->left_child->parent = nullptr;
   this->left_child.reset();
  
   return ;
}

template<typename DATA_T>
void node<DATA_T>::detach_right_child()
{
   if(this->right_child == nullptr)
      throw std::runtime_error("no right_child to detach");

   this->right_child->parent = nullptr;
   this->right_child.reset();
   return;
}

template<typename DATA_T>
std::shared_ptr<DATA_T>
   node<DATA_T>::DATA_PTR(){
   return this->data_ptr;
}

template<typename DATA_T>
std::shared_ptr<node<DATA_T>>
    node<DATA_T>::LEFT_CHILD_PTR(){
   return this->left_child;
}

   template<typename DATA_T>
std::shared_ptr<node<DATA_T> >
  node<DATA_T>::RIGHT_CHILD_PTR()
{
   return this->right_child;
}

template<typename DATA_T>
node<DATA_T>*
node<DATA_T>::PARENT_PTR()
{
   return this->parent;
}

template<typename DATA_T>
std::size_t& node<DATA_T>::DEPTH()
{
   return this->depth;
}

template<typename DATA_T>
std::size_t& node<DATA_T>::HEIGHT(){
      return height;
}
template<typename DATA_T>
bool node<DATA_T>::is_parent_right_child(){
   if(this->parent == nullptr)
      throw std::runtime_error("parent is null\n");
   else if (this->parent->left_child.get() == this)
      return false;
   else return true;
}

template<typename DATA_T>
bool node<DATA_T>::is_parent_left_child(){
   return !is_parent_right_child();
}

template<typename DATA_T>
void node<DATA_T>::reset_parent(){
   if (parent == nullptr)
      return ;
   else if (is_parent_right_child() )
      parent->right_child.reset();
   else if (is_parent_left_child() )
      parent->left_child.reset();

   parent = nullptr;
   return ; 
}
#endif
