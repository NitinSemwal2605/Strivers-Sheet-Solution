#include<bits/stdc++.h>
using namespace std;

int faboncaii(int n){
    if (n ==0 || n==1){
        return n;
    }

    return faboncaii(n-1)+faboncaii(n-2);
}

int main (){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<faboncaii(i)<<" ";
    }
    return 0;
}