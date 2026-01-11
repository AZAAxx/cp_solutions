#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    int n, x, a;
    cin >> n >> x;

    vector<pair<int, int>> v;

    for(int i=0; i<n; i++){
        cin >> a;
        v.push_back({a, i+1});
    }
    sort(v.begin(), v.end());


    for(int i=0; i<n; i++){
        int goal = x - v[i].first;
        int a = i+1, b = n-1;
        while(a < b){
            int sum = v[a].first + v[b].first;
            if(sum == goal){
                cout << v[i].second << " " << v[a].second << " " << v[b].second;
                return 0;
            }
            else if(sum < goal) a++;
            else b--;
        }
    }
    cout << "IMPOSSIBLE";
    
}
