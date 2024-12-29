#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> output;
    if (n < 3)
        return output;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {
        // Skip duplicate elements
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int target = -nums[i];
        int low = i + 1, high = n - 1;

        while (low < high)
        {
            int sum = nums[low] + nums[high];
            if (sum < target)
            {
                low++;
            }
            else if (sum > target)
            {
                high--;
            }
            else
            {
                output.push_back({nums[i], nums[low], nums[high]});
                // Skip duplicate elements for `low`
                while (low < high && nums[low] == nums[low + 1])
                    low++;
                // Skip duplicate elements for `high`
                while (low < high && nums[high] == nums[high - 1])
                    high--;
                low++;
                high--;
            }
        }
    }
    return output;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> output = threeSum(nums);
    for (auto triplet : output)
    {
        for (int num : triplet)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}