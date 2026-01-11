#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    map<string, int> mp;
    int n;
    cin >> n;

    string s;
    int count, max_count = 1;
    for(int i=0; i<n; i++){
        cin >> s;
        auto it = mp.find(s);
        if(it == mp.end()) mp[s] = 1;
        else {
            count = ++mp[s];
            max_count = max(count, max_count);
        }
    } 
    cout << max_count;
}
