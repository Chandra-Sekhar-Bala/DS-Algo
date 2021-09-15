#include<iostream>
using namespace std;
// When range is given 1:N
int main(){
    int arr []= {3,4,5,1,2}; 

    /*
    1. 1 
    */
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << n << endl;
    for(int i=0 ; i < n; ++i){

        while(1){
            if(arr[i] == i+1)break;
            swap(arr[i],arr[arr[i]-1]);
        }
    }

    for(auto it : arr)cout << it <<" ";
    return 0;
}