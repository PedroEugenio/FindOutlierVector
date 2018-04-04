/*You are given an array (which will have a length of at least 3, but could be very large) containing integers. 
The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. 
Write a method that takes the array as an argument and returns this "outlier" N.
Examples:
[2, 4, 0, 100, 4, 11, 2602, 36]
Should return: 11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21]
Should return: 160 (the only even number)
*/

#include <iostream>
#include<vector>

using namespace std;

int FindOutlier(vector<int> arr){
    int result, index_even, index_odd, size;
    index_even=index_odd=0;
    size = arr.size(); //get arr size
    vector<int> even(size), odd(size); //allocate memory
    for(int i=0; i<size; i++){
      if(arr[i]%2==0){  //check if it's even
        even[index_even]=arr[i];
        index_even++;
      }
      else{
        odd[index_odd]=arr[i];
        index_odd++;
      }
    }
    cout<<"index_even: "<<index_even<<endl;
    cout<<"index_odd: "<<index_odd<<endl;
    cout<<"Even: ";
    even.resize(index_even); //resize array to eliminate the 0's at the end
    odd.resize(index_odd);
    for(int i=0; i<even.size(); i++){
        cout<<even[i]<<" ";    
    }
    
    cout<<"Odd: ";
    for(int i=0; i<odd.size(); i++){
        cout<<odd[i]<<" ";    
    }
    
    if(odd.size()>1){
      result=even[0];
    }
    else{
      result=odd[0];
    }
    return result;
}

int main()
{
    vector<int> arr = {2,3,4};
    cout<<endl<<FindOutlier(arr)<<endl;
}
