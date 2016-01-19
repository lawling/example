#include <iostream>

template<typename T> 
void bubble_sort(T arr[], std::size_t size){
for(int i = size; i != 0 ; i--)
	for( int j = 0;j != i; j++){
           if(arr[j] > arr[j+1]){
	     T tmp = arr[j];
	     arr[j] = arr[j+1];
	     arr[j+1] = tmp;
	   }
	}
    return ;
}
int main(){
  int ARR[] = {10, 4, 5, 6, 7, 3, 2, 100};
  bubble_sort(ARR,8);

  for(int i = 0; i != 8; i++)
  std::cout<<ARR[i]<<std::endl;  
  return 0;

}
