#include <bits/stdc++.h>
using namespace std; 

int findUnion(int arr1[], int arr2[], int n, int m) {
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        s.insert(arr2[i]);
    }
    return s.size();
}

int main() {
    int arr1[] = {10, 15, 20, 5, 30};
    int arr2[] = {30, 5, 30, 80};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    cout << findUnion(arr1, arr2, n, m) << "\n";
    return 0;
}