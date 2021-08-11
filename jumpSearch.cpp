#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int searchedValue, int noElement) {
    int step = sqrt(noElement);
    int prev = 0;
    
    while(arr[min(step, noElement) - 1] < searchedValue) {
        
        int prev = step;
        step += sqrt(noElement);
        
        if(prev > noElement) return -1;
        
    }
    
    while(arr[prev] < searchedValue) {
        prev++;
        if(prev > min(step, noElement)) return -1;
        
    }
    
    if(arr[prev] == searchedValue) return prev;
    return  -1;
    
}



int main() {
	int arr[] = {2, 5, 8, 15, 23, 89, 95, 109, 121, 200, 356, 458, 489, 555};
	int searchedValue = 15;
	cout<< "Position of searched value " << searchedValue << " is " << jumpSearch(arr, searchedValue, sizeof(arr));
	return 0;
}