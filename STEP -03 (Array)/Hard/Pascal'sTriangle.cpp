#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if(numRows == 0) return res;
    res.push_back({1});
    for(int i = 1; i < numRows; i++) {
        vector<int> row;
        row.push_back(1);
        for(int j = 1; j < i; j++) {
            row.push_back(res[i-1][j-1] + res[i-1][j]);
        }
        row.push_back(1);
        res.push_back(row);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> res = generate(n);
    for(auto row : res) {
        for(int x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}