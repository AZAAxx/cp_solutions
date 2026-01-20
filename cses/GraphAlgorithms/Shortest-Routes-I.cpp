#include<bits/stdc++.h>
using namespace std;
#define INF LONG_LONG_MAX
#define ll long long

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    //dijkstra
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj (n+2);
    vector<ll> dist (n+2, INF);
    dist[1] = 0;

    ll a, b, c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<bool> processed (n+2, false);
    priority_queue<pair<ll, ll>> pq; //pq.top() gives the node closest to s, {weight, node}
    pq.push({0, 1});
    int count = 0;
    ll v, w, vn;

    while(!pq.empty() && count < n){
        v = pq.top().second; pq.pop();
        if(processed[v]) continue;
        processed[v] = true;
        count++;
        for(auto p : adj[v]){
            tie(vn, w) = p;
            if(!processed[vn]) {
                dist[vn] = min(dist[vn], dist[v] + w);
                pq.push({-dist[vn], vn});
            }
        }
    }

    for(int i=1; i<=n; i++) cout << dist[i] << " ";
    cout << endl;
}