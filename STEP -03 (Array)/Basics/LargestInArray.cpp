#include <bits/stdc++.h>
using namespace std;

void largestAndSecondLargest(int arr[], int n) {
    int largest = INT_MIN, secondLargest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    if (secondLargest == INT_MIN) {
        cout << "No second largest element found\n";
    } else {
        cout << "Largest element: " << largest << ", Second largest element: " << secondLargest << "\n";
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    largestAndSecondLargest(arr, n);
    return 0;
}