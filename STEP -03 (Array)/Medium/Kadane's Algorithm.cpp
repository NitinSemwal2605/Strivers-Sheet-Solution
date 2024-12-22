#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) { // kadane's Algorithm
        int maxi = INT_MIN;  // abhut chota 
        int sum = 0; // initial

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i]; // add karna hai sum mai

            if (sum > maxi) {
                maxi = sum; // update the maxi if it is greater than the sum .
            }
            if (sum < 0) {
                sum = 0; // if negative make it 0.
            }
        }

        return maxi;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << obj.maxSubArray(nums);
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)