#include<bits/stdc++.h>
using namespace std;


// Approach: Divide the array into two halves and recursively sort them. Then merge the two sorted halves.

void mergeSort(int arr[], int start , int end){
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

void merge(int arr[] , int start, int mid, int end){
    vector<int> temp(end-start+1);
    int mid = (start + end) / 2;
    int left = start;
    int right = mid+1;
    int index = 0;

    while(left <= mid && right <= end){
        if(arr[left] < arr[right]){
            temp[index++] = arr[left++];
        } else {
            temp[index++] = arr[right++];
        }
    }

    while(left <= mid){
        temp[index++] = arr[left++];
    }

    while(right <= end){
        temp[index++] = arr[right++];
    }

    index = 0;
    while(start <= end){
        arr[start++] = temp[index++];
    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n-1);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
