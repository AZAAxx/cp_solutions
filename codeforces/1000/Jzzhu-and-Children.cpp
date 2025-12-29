#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("../../in.txt" , "r", stdin);
    //freopen("../../out.txt", "w", stdout);

    int n, m, a;
    pair<int, int> p;
    cin >> n >> m;

    queue<pair<int, int>> q;
    for(int i=1; i<=n; i++){
        cin >> a;
        q.push(make_pair(a, i));
    }

    while(q.size() > 1){
        p = q.front();
        p.first -= m;
        if(p.first > 0) q.push(p);
        q.pop();
    }
    cout << q.front().second << endl;
}