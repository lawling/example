#include<iostream>
#include<thread>

int main(){
using namespace std;

cout<<"hardware_concurrency "<<thread::hardware_concurrency()<<endl;

}
