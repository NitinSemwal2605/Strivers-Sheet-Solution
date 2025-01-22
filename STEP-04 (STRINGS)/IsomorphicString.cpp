// Isomorphic String

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for (int i = 0; i < s.size(); i++) {
            if ((s2t.count(s[i]) && s2t[s[i]] != t[i]) || (t2s.count(t[i]) && t2s[t[i]] != s[i])) {
                return false;
            }
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }
        return true;
    }
};

int main() {
    string s = "egg";
    string t = "add";
    Solution obj;
    cout << obj.isIsomorphic(s, t) << endl;
    return 0;
}