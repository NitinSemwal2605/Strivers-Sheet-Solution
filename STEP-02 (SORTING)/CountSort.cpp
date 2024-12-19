#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n) {
    // Find maximum element 
    int max = *max_element(arr, arr + n);
    
    // Create the frequency array
    vector<int> freq(max + 1, 0);
    
    // Count the occurrences 
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Update frequency array to contain the position 
    for (int i = 1; i <= max; i++) {
        freq[i] += freq[i - 1];
    }

    // Create temporary array to store the sorted array
    int temp[n];
    for (int i = n - 1; i >= 0; i--) {
        temp[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    // Copy the sorted array back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countSort(arr, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
