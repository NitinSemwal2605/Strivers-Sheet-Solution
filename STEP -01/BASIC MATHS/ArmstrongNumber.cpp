#include<bits/stdc++.h>
using namespace std;

bool isArmstrong(int N){
        int temp=N;
        int sum=0;
        while(N!=0)
        {
            int rem=N%10;
            sum+=rem*rem*rem;
            N=N/10;
        }
        return sum==temp;
}

int main() {
    int N;
    cin>>N;
    cout<<isArmstrong(N);
    return 0;
}
