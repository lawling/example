/*
   This code is written by Yuan Liang
   Email: yliang12@terpmail.umd.edu

   1. implement basic node operations for AVL tree,
         include a pointer to data, height, depth and pointers to left and right children
   2. depth and height should be assigned by client and positive only.

   implementation details:

   concepts:
 */
#ifndef NODE_H
#define NODE_H
#include<memory>
#include<exception>
template < typename DATA_T >
class node {

   public:

      node();
      node(DATA_T  d);
      virtual ~ node() = default;
      node(node&) = delete;
      node(node&&) noexcept;
      node < DATA_T > &operator = (const node<DATA_T>& ) = delete;


      void attach_left_child(const std::shared_ptr<node>) noexcept(false);
      void attach_right_child(const std::shared_ptr<node>) noexcept(false);

      void detach_left_child() noexcept(false);
      void  detach_right_child() noexcept(false);

      std::shared_ptr <DATA_T> DATA_PTR();

      std::shared_ptr<node<DATA_T> > LEFT_CHILD_PTR();
      std::shared_ptr<node<DATA_T> > RIGHT_CHILD_PTR();
      node<DATA_T> * PARENT_PTR();

      std::size_t& DEPTH();
      std::size_t& HEIGHT();
   private:
      std::size_t  height;
      std::size_t  depth;

      std::shared_ptr <DATA_T > data_ptr;

      std::shared_ptr <node<DATA_T> > left_child;
      std::shared_ptr <node<DATA_T> > right_child;
      node<DATA_T>* parent;

      bool is_parent_right_child(); 
      bool is_parent_left_child();
      void reset_parent();
};
#include"./node.cpp"
#endif
