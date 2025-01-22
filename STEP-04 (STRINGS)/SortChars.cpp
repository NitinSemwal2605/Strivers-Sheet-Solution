// Sort Characters by frequency

#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    sort(s.begin(), s.end(), [&](char a, char b) {
        return freq[a] > freq[b] || (freq[a] == freq[b] && a < b);
    });
    return s;
}

int main() {
    string s = "tree";
    cout << frequencySort(s) << endl;
    return 0;
}
