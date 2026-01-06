#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    set<ll> s;
    ll N;
    cin >> N;
    
    for(ll a=2; a<=sqrt(N); a++){
        ll p = a*a;
        while(p <= N){
            s.insert(p);
            p *= a;
        }
    }
    cout << N-s.size();
}
