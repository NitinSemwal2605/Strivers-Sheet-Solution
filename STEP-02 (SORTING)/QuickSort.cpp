#include <bits/stdc++.h>
using namespace std;

// Approach: Choose a pivot element and partition the array such that all elements less than the pivot are on the left side and all elements greater than the pivot are on the right side. Recursively sort the left and right halves.

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for(int j = start; j < end; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}

void quickSort(int arr[], int start, int end) {
    if(start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
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
    quickSort(arr, 0, n-1);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}