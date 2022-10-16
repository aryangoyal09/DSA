#include <iostream>
using namespace std;

/*

QUESTION: How would you search for an element in an array/list whose size is unknown?

ANSWER: We can do this by making some modification in binary search technique

The concept behind this approach is:
  1. Take inital value of i as 0 and j as 1.
  2. Now increase j to j*2 until arr[j] exceed the key to be searched.
  3. Now search the key using binary search between i and j.

*/

// Binary Search Function
int binary_search(int arr[],int i,int j,int key){
    // m=middle element
    int m=(i+j)/2;
    // i=starting index j=ending index
    while(i<=j){
    // if key to be searched is present we will return index of the key
    if(arr[m]==key){return m;}
    else{
        if(arr[m]<key){i=m+1;}
        else{j=m-1;}
    }
    m=(i+j)/2;
    }
    return -1;  // when element is not present we will return -1
}
// Binary search for array with unknown lenght
int binary_search_unknown(int arr[],int key){
    // Initializing i as 0 and j as 1.
    int i=0,j=1;
    // We will increase j until arr[j] exceeds key to be searched.
    while(arr[j]<key){
        i=j;
        j=2*j;
    }
    // Now calling Simple Binary Search on range i to j.
    return binary_search(arr,i,j,key);
}
