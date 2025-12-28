#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("../../in", "r", stdin);
	//freopen("../../out", "w", stdout);

    int n, l, r, x;
    cin >> n >> l >> r >> x;

    int q[16];
    for(int i=0; i<n; i++) cin >> q[i];

    int count = 0;
    for(int k=0; k<(1<<n); k++){ //for every combination
        
        int sum = 0, biggestQ = 0, smallestQ = 1e6;
        for(int i=0; i<n; i++){ //for every question

            if(k & (1<<i)){ //include in the problemset
                sum += q[i];
                if(biggestQ < q[i]) biggestQ = q[i];
                if(q[i] < smallestQ) smallestQ = q[i];
            }
        }
        if (biggestQ - smallestQ >= x & l <= sum & sum <= r) count++;
    }
    cout << count << endl;

}