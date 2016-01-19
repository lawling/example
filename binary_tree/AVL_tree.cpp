
template<typename data_t>
void  AVL_tree<data_t>::add_data(const data_t & d){
if( root == nullptr)
	root = make_shared<node<data_t> > ( d );



}

template<typename data_t>
void  AVL_tree<data_t>::del_data(const data_t& d){


}

template<typename data_t>
std::vector<data_t>  AVL_tree<data_t>::get_data( UnaryFunction f){


}

template<typename data_t>
bool  AVL_tree<data_t>::contains_data(const data_t & ){



}

template<typename data_t>
std::size_t AVL_tree<data_t>::balance_factor( std::shared_ptr<node<data_t> >n ){
      return n->LEFT_CHILD_PTR()->HEIGHT() - n->RIGHT_CHILD_PTR()->HEIGHT();
}
template<typename data_t>
void  AVL_tree<data_t>::balance(std::shared_ptr<node<data_t> > np){
        //check double rotation or single rotatio
       // may be recursive

        if (balance_factor(np) >= 2){
	    if (balance_factor(np->LEFT_CHILD_PTR() ) == -1 ){


	      }else if (balance_factor(np->
	    balance( np->LEFT_CHILD_PTR());
         //incompletee
	}else if (balance_factor() =< -2){
            balance( np->RIGHT_CHILD_PTR());

	}


	return;
}

template<typename data_t>
void  AVL_tree<data_t>::left_rotate(std::shared_ptr<node<data_t> > root){
   if (root->PARENT_PTR() == nullptr) // need refactor
                           ;
   else if (root->PARENT_PTR()->LEFT_CHILD_PTR() == root)
       root->PARENT_PTR()->attach_left_child(root->RIGHT_CHILD_PTR() );
   else 
       root->PARENT_PTR()->attach_right_child(root->RIGHT_CHILD_PTR() );

//continue
   std::shared_ptr<node<data_t> > tmp{root->RIGHT_CHILD_PTR() };


   if( root->LEFT_CHILD_PTR() != nullptr){
      root->attach_right_child( root->RIGHT_CHILD_PTR()->LEFT_CHILD_PTR() );        
      
   }

   tmp->attach_left_child( root);

}

template<typename data_t>
void AVL_tree<data_t>::right_rotate(std::shared_ptr<node<data_t> > root){
     
   if (root->PARENT_PTR() == nullptr) // need refactor
                           ;
   else if (root->PARENT_PTR()->LEFT_CHILD_PTR() == root)
       root->PARENT_PTR()->attach_left_child(root->RIGHT_CHILD_PTR() );
   else 
       root->PARENT_PTR()->attach_right_child(root->RIGHT_CHILD_PTR() );


   std::shared_ptr<node<data_t> > tmp{root->LEFT_CHILD_PTR() };

   if (root->RIGHT_CHILD_PTR() != nullptr){
      root->attach_left_child( root->LEFT_CHILD_PTR()->RIGHT_CHILD_PTR() );
   }

   tmp->attach_right_child(root);

}
