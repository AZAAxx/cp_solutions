#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    int n, x, a;
    cin >> n >> x;

    map<int, int> mp;

    for(int i=1; i<=n; i++){
        cin >> a;
        auto it = mp.find(x-a);
        if(it == mp.end()) mp.insert(make_pair(a, i));
        else{
            cout << it->second << " " << i;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}
