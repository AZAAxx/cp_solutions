#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    set<int> s;
    int n, x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        s.insert(x);
    } 
    cout << s.size();
}
