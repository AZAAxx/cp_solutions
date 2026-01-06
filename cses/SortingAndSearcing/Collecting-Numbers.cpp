#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    int n, x;
    cin >> n;

    set<pair<int,int>> mp;

    for(int i=0; i<n; i++){
        cin >> x;
        mp.insert(make_pair(x,i));
    }

    int round = 1;
    set<pair<int,int>>::iterator it = mp.begin();
    int prev = it->second;

    for(it++; it != mp.end(); it++){
        if(prev > it->second) round++;
        prev = it->second;
    }

    cout << round;
}
