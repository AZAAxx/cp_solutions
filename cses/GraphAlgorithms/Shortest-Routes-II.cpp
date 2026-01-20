#include<bits/stdc++.h>
using namespace std;
#define N 505
#define INF LONG_LONG_MAX
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    //floyd-warshall
    ll n, m, q;
    cin >> n >> m >> q;
    
    vector<vector<ll>> dist (n+1, vector<ll> (n+1, INF));
    for(int i=1; i<=n; i++) dist[i][i] = 0;

    ll a,b,c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }

    for(int j=1; j<=n; j++){
        for(int i=1; i<=n; i++){ //j is the intermediate value
            for(int k=1; k<=n; k++){
                if(i == j || i == k || j == k) continue;
                if(dist[i][j] < INF && dist[j][k] < INF){
                    dist[i][k] = min(dist[i][k], dist[i][j] + dist[j][k]);
                }
            }
        }
    }

    for(int i=0; i<q; i++){
        cin >> a >> b;
        if(dist[a][b] == INF) cout << "-1\n";
        else cout << dist[a][b] << "\n";
    }
}
