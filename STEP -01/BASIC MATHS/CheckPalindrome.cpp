#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        int ulta = 0;
        while (x > ulta) {
            ulta = ulta * 10 + x % 10;
            x /= 10;
        }
        return (x == ulta) || (x == ulta / 10);
}

int main() {
    int N;
    cin>>N;
    cout<<isPalindrome(N);
    return 0;
}