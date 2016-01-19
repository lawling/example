#if !defined AVL_TREE_HPP
#define AVL_TREE_HPP
#include "./binary_tree.hpp"
template<typename data_t>
class AVL_tree:public binary_tree<data_t,comparator>
{
	public:
               void add_data(const data_t&) override;
	       void del_data(const data_t&) override;

	       template<typename UnaryFunction>
		  std::vector<data_t> 
		      get_data( UnaryFunction f ) override;

	       bool contains_data(const data_t& ) override;
	private:
	       std::size_t balance_factor( std::shared_ptr<node<data_t> > subtree_root) const ;
	       void balance(std::shared_ptr<node<data_t> > newnode_ptr);
	       typedef bool (*comparator)(data_t,data_t);

               void left_rotate(std::shared_ptr<node<data_t> >root );
	       void right_rotate( std::shared_ptr<node<data_t> > root );
}
#include "./AVL_tree.cpp"
#endif
