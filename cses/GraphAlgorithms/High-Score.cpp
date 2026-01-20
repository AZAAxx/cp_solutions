#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LONG_LONG_MAX
#define vi vector<int>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	freopen("../../in.txt", "r", stdin);
	freopen("../../out.txt", "w", stdout);

    ll n, m;
    cin >> n >> m;
    ll a, b, x;

    vector<tuple<ll,ll,ll>> edges;
    ll* dist = (ll*) malloc((n+2) * sizeof(ll));
    vi* rev_adj = (vi*) malloc((n+2) * sizeof(vi));

    for(int i=0; i<=n; i++) dist[i] = -INF;
    dist[1] = 0;

    cout << "done" << endl;


    for(int i=0; i<m; i++){
        cin >> a >> b >> x;
        edges.push_back({a,b,x});
        rev_adj[b].push_back(a);
    }
    cout << "done" << endl;

    //calculate distances
    bool positive_cycle = false;
    for(int i=1; i<n; i++){ //for n times
        for(auto edge : edges){ //for every edge
            tie(a, b, x) = edge;
            if(-INF < dist[a] && dist[a] < INF){ //if not infinitely away
                if(dist[a] + x > dist[b]){
                    dist[b] = dist[a] + x;
                    cout << b << " " << dist[b] << endl;
                }
            }
        }
    }
    int distance = dist[n];

    //mark the nodes in positive cycle, the changing nodes in nth iteration
    set<int> s;
    for(auto edge : edges){ //for every edge
        tie(a, b, x) = edge;
        if(-INF < dist[a] && dist[a] < INF){ //if not infinitely away
            if(dist[a] + x > dist[b]){
                s.insert(b);
                dist[b] = dist[a] + x;
                cout << b << " " << dist[b] << endl;
            }
        }
    }
    
    for(auto it = s.begin(); it != s.end(); it++) cout << *it << " ";

    //check if cycle affects dist[n] 
    // if any element of s is reachable from n
    if(positive_cycle){
        queue<int> q;
        bool* visited = (bool*) malloc((n+2) * sizeof(bool));
        for(int i=0; i<=n; i++) visited[i] = false;

        q.push(n);
        while(!q.empty()){
            b = q.front(); q.pop();
            if(s.find(b) != s.end()){
                //positive cycle including n
                cout << -1 << endl;
                return 0;
            }
            visited[b] = true;

            for(auto a : rev_adj[b]){
                if(!visited[a]) q.push(a);
            }
        }
    }
    cout << distance << endl; 
}