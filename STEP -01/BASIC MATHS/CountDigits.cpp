#include <bits/stdc++.h>
using namespace std;

int evenlyDivides(int N){
        
        string temp=to_string(N);
        int count=0;
        for(int i=0;i<temp.size();i++)
        {
            int key=temp[i]-'0';
             if(key==0)
                continue;
             if(N%key==0)
                count++; 
            
        }
        
        return count;
}

int main() {
    int N;
    cin>>N;
    cout<<evenlyDivides(N);
    return 0;
}
