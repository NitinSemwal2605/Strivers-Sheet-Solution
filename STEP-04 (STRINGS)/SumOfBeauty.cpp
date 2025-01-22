// Sum of Beauty of all substring

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int total = 0;

        for(int i=0;i<n;i++){
            unordered_map<char,int>freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;

                int max_freq = 0;
                int min_freq = INT_MAX;
                
                for(auto& st : freq){
                    max_freq = max(max_freq, st.second);
                    min_freq = min(min_freq , st.second);
                }
                total += (max_freq-min_freq);
            }
        }
        return total;
    }
};

int main() {
    string s = "aab";
    Solution obj;
    cout << obj.beautySum(s) << endl;
    return 0;
}