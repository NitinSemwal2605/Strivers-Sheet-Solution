#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i <= 10000; i++) {
            int flag = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == i) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) return i;
        }
        return -1;
    }
};


int main()
{
    Solution obj;
    vector<int> nums = {3, 0, 1};
    cout << obj.missingNumber(nums);
    return 0;
}