#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto x:mpp){
            if(x.second > n/2){
                return x.first;
            }
        }
        return 0;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << obj.majorityElement(nums);
    return 0;
}