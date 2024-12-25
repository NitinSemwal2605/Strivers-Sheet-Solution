#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Kadanes Algorithm Solution
        unordered_map<int,int> mp;
        mp[0] = 1;
        int preSum = 0,cnt = 0;

        for(int i=0;i<nums.size();i++){
            preSum += nums[i];
            cnt += mp[preSum - k];
            mp[preSum] += 1;
        }
        return cnt;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout<<obj.subarraySum(nums,k);
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)