#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}
};

int main()
{
    Solution obj;
    vector<int> arr = {7,1,5,3,6,4};
    cout << obj.maxProfit(arr);
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

