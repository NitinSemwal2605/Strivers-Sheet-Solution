#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n, int pos) {
    // Create the frequency array
    vector<int> freq(10, 0);
    
    // Count the occurrences 
    for (int i = 0; i < n; i++) {
        freq[(arr[i] / pos) % 10]++;
    }

    // Update frequency array to contain the position 
    for (int i = 1; i < 10; i++) {
        freq[i] += freq[i - 1];
    }

    // Create temporary array to store the sorted array
    int temp[n];
    for (int i = n - 1; i >= 0; i--) {
        temp[freq[(arr[i] / pos) % 10] - 1] = arr[i];
        freq[(arr[i] / pos) % 10]--;
    }

    // Copy the sorted array back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

void radixSort(int arr[], int n) {
    // Find maximum element 
    int max = *max_element(arr, arr + n);
    
    // Perform counting sort for every digit
    for (int pos = 1; max / pos > 0; pos *= 10) {
        countSort(arr, n, pos);
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}