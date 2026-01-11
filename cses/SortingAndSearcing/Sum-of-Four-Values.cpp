#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    int n, x, a;
    cin >> n >> x;

    vector<int> v;

    for(int i=0; i<n; i++){
        cin >> a;
        v.push_back(a);
    }

    map<int, vector<pair<int,int>>> mp;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int sum = v[i] + v[j];
            mp[sum].push_back({i+1, j+1});
        }
    }
    
    
    for(auto it = mp.begin(); it != mp.end(); it++){
        int goal = x - it->first;
        auto it2 = mp.find(goal);
        if(it2 == mp.end()) continue;
        

        
        for(auto [a,b] : it->second){
            for(auto [a2, b2] : it2->second){
                if(a != a2 && a != b2 && b != a2 && b != b2){
                    cout << a << " " << b << " " << a2 << " " << b2;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";

    
}
