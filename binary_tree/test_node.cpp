#include<iostream>
#include"./node.hpp"
using namespace std;
int main(){
	auto n1 = make_shared<node<int> > ( int(10));

	cout<<"node data is "<<*n1->DATA_PTR()<<endl;

	n1->attach_left_child(make_shared<node<int> >(  int(11) ));

	cout<<"node leftchild is "<<*n1->LEFT_CHILD_PTR()->DATA_PTR()<<endl;

	n1->attach_right_child(make_shared<node<int> >( int(12) ) );
	
	cout<<"node right child is "<<*n1->RIGHT_CHILD_PTR()->DATA_PTR()<<endl;
 
	cout<<"node right child depth is "
		<<n1->RIGHT_CHILD_PTR()->DEPTH()<<endl;

	cout<<"node left child depth is "
		<<n1->LEFT_CHILD_PTR()->DEPTH()<<endl;

	cout<<" n1 depth is "<<n1->DEPTH()<<endl;
	
	auto ln = n1->LEFT_CHILD_PTR();
        auto rn = n1->RIGHT_CHILD_PTR();

        n1.reset();

	cout<<"left child depth"<<ln->DEPTH()<<endl;
	cout<<"right child depth"<<rn->DEPTH()<<endl;

	try{

               ln->detach_left_child();
	}catch(std::exception& e){
           cout<<e.what()<<endl;
	}
}
