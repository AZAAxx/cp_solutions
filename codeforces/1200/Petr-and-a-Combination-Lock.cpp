#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("../../in", "r", stdin);
	//freopen("../../out", "w", stdout);

    int a[15];
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    int k = (1<<n) - 1;

    int angle = 0;
    for(int i=0; i<k; i++){ //for every combination

        angle = 0;
        for(int j=0; j<n; j++){ //for every number
            if(i & (1<<j)) angle += a[j];
            else angle -= a[j];
        }
        if(angle % 360 == 0){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
