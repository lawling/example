#if !defined BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include "./node.hpp"
#include <memory>
#include <functional>
#include <vector>

template<typename data_t, typename comparator>
class binary_tree
{
   public:
      binary_tree() = default;

      virtual void add_data(const data_t& ) = 0;
      virtual void del_data(const data_t& ) = 0;

      template<typename UnaryFunction>
       virtual std::vector<data_t> get_data( UnaryFunction f) = 0; 		

      virtual bool contains_data(const data_t& ) = 0;
   protected:
      std::shared_ptr<node<data_t> > root;



};
#include "./binary_tree.cpp"
#endif
