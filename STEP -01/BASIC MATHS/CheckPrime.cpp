#include <bits/stdc++.h>
using namespace std;

bool isPrime(int N){
    if(N<=1)
        return false;
    for(int i=2;i*i<=N;i++){
        if(N%i==0)
            return false;
    }
    return true;
}

int main() {
    int N;
    cin>>N;
    cout<<isPrime(N);
    return 0;
}