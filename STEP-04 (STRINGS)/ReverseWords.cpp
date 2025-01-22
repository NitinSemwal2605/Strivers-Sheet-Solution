// Reverse Words in String

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string word = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (word.size() > 0) {
                    res = word + " " + res;
                    word = "";
                }
            } else {
                word += s[i];
            }
        }
        if (word.size() > 0) {
            res = word + " " + res;
        }
        return res.substr(0, res.size() - 1);
    }
};

int main() {
    string s = "the sky is blue";
    Solution obj;
    cout << obj.reverseWords(s) << endl;
    return 0;
}