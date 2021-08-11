#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int searchedValue, int noElement) {

    // the optimized value of step is sqrt(n) where n is number of elements in array
    int step = sqrt(noElement);
    int prev = 0;

     // jump until element at step position >= element needs to be search or reach out of array range
     // prev is position where last check

    while(arr[min(step, noElement) - 1] < searchedValue) {
        
        int prev = step;
        step += sqrt(noElement);
        
        if(prev > noElement) return - 1;
        
    }
    
    // Stop at left-side of needed element
    while(arr[prev] < searchedValue) {

        prev++;

        // traversal from prev to last step or to end of array
        // When traversal to last step or end of array, there is no needed element
        if(prev > min(step, noElement)) return -1;
        
    }
       //  Check if next element is needed one?
    if(arr[prev] == searchedValue) return prev;
       // The prev element is smaller than needed one! 
    return  -1;
    
}

int main() {
	int arr[] = {2, 5, 8, 15, 23, 89, 95, 109, 121, 200, 356, 458, 489, 555};

	int searchedValue = 15;

	cout<< "Position of searched value " << searchedValue << " is " << jumpSearch(arr, searchedValue, sizeof(arr));
    
	return 0;
}