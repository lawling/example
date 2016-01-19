#include<iostream>
#include<array>
#include<vector>
static std::array<std::size_t,2>
	partition(std::size_t){


	}

template<typename T, std::size_t size>
void merge_sort(std::array<T, size> & arr){
   using namespace std;

   auto two_pow = [](size_t i)
   {return 2 << i; };//2 in the power of i

   array<T,size> tmp;
   for(size_t i = 0; two_pow(i) < arr.size(); i++)//log2(N) operations
     //then do merge for each segment 
      for( size_t j = 0; j < arr.size(); j += two_pow(i) ) 
	 for( size_t k = 0; k < 2*two_pow(i) ; k++){
             size_t m = j,n = j + two_pow(i);
	     //s2 : use tmp array
	     if (m > j + two_pow(i) ){
                 for ( ; n < j + two_pow(i+1) ; n++){
		    tmp;//mistake in here
		 }
		 k = 2 * two_pow(i);
		 break;
	     }else if ( n > j + two_pow(i+1) ){
                  
	     }


	     if ( arr[m] < arr[n]){
                 tmp[j+k] = arr[m];
                 m++;
	     }else{
                 tmp[j+k] = arr[n];
                 n++;
	     }

	 }

   arr.swap(tmp);
}

int main(){
   std::array<int,10> ARR{10,20,30,40,50,60,70,80,9,10};
   merge_sort(ARR);
   
}
