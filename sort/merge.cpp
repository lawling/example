#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main(){
array<size_t, 5> arr1{1,3,5,7,9},
   arr2{2,4,6,8,10};

array<size_t,10> arr3;

merge(arr1.cbegin(),arr1.cend(),
      arr2.cbegin(),arr2.cend(),
      arr3.begin());

cout<<"before merge \n";
for (auto& i:arr1)
   cout<<i<<" ";
cout<<"\n";

for (auto& i:arr2)
   cout<<i<<" ";
cout<<"\n";

cout<<"after merge \n";
for (auto& i:arr3)
   cout<<i<<" ";

cout<<endl;
}
