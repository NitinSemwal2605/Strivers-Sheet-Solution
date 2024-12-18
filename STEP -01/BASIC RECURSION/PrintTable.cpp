#include <bits/stdc++.h>
using namespace std;

void printTable(int n, int i) {
    if(i == 11) return;
    cout << n << " x " << i << " = " << n*i << endl;
    printTable(n, i+1);
}

int main() {
    int n;
    cin >> n;
    printTable(n, 1);
    return 0;
}
