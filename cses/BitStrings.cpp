#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main(){
    //find 2^n % M
    int n, ans = 1;
    cin >> n;
    for(int i=0; i<n; i++){
        ans = (ans << 1) % M;
    }
    cout << ans;
}