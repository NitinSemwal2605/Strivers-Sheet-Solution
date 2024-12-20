#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(int arr[], int n) {
    int res = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[res - 1]) {
            arr[res] = arr[i];
            res++;
        }
    }
    for (int i = 0; i < res; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {10, 20, 20, 30, 30, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    removeDuplicates(arr, n);
    return 0;
}