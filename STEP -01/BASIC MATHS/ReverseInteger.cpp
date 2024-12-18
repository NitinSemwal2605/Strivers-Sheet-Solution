#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
        long long int rev=0;
        while(x!=0)
        {
            rev=rev*10+x%10;
            x=x/10;
        }
        if(rev>INT_MAX || rev<INT_MIN)
            return 0;
        return rev;
}

int main() {
    int N;
    cin>>N;
    cout<<reverse(N);
    return 0;
}