// Majority Element (n/3 times)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mpp;
        int n=nums.size()/3;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<int>res;
        for(auto& it : mpp){
            if(it.second>n){
                res.push_back(it.first);
            }
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution obj;
    vector<int> res = obj.majorityElement(nums);
    for(int x : res) cout << x << " ";
    cout << endl;
    return 0;
}