#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

// a [b c d] e
// a^b^c^d ^ a = b^c^d (a^a = 0)

int main(){
    int n, q;
    cin >> n >> q;

    int arr[N], arrXor[N];
    for(int i=0; i<n; i++) cin >> arr[i];

    arrXor[0] = arr[0];
    for(int i=1; i<n; i++) arrXor[i] = arrXor[i-1] ^ arr[i];

    int a, b, ans;
    for(int i=0; i<q; i++){
        cin >> a >> b;
        if(a==1) ans = arrXor[b-1];
        else ans = arrXor[b-1] ^ arrXor[a-2];
        cout << ans << endl;
    }
}