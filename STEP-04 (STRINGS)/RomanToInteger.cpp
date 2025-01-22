// Roman to integers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int n = s.size();
        int res = roman[s[n - 1]];
        for (int i = n - 2; i >= 0; i--) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                res -= roman[s[i]];
            } else {
                res += roman[s[i]];
            }
        }
        return res;
    }
};

int main() {
    string s = "III";
    Solution obj;
    cout << obj.romanToInt(s) << endl;
    return 0;
}
