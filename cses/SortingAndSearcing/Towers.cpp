#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    int n, k;
    cin >> n;
    multiset<int> ms;

    for(int i=0; i<n; i++){
        cin >> k;
        auto it = ms.upper_bound(k); //first element greater than k
        if(it == ms.end()) ms.insert(k);
        else{
            ms.erase(it);
            ms.insert(k);
        }
    }
    cout << ms.size();
    
}
