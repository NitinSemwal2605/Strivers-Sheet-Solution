#include <bits/stdc++.h>
using namespace std;

void leftRotate(int arr[], int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    leftRotate(arr, n);
    return 0;
}