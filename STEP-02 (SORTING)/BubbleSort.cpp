#include <bits/stdc++.h>
using namespace std;

// Approach: Compare each element with its adjacent element and swap them if they are in the wrong order. 

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) { 
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) { // Swap if the element is greater than the next element
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}