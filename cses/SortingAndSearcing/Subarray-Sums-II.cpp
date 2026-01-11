#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    ll n, x, a;
    cin >> n >> x;

    //a frequency map to store past prefix sums
    map<ll, ll> freq;
    freq[0] = 1;
    ll count = 0;

    ll prefix = 0;
    for(int i=0; i<n; i++){
        cin >> a;
        prefix += a;

        auto it = freq.find(prefix-x);
        if(it != freq.end()) count += it->second;

        it = freq.find(prefix);
        if(it == freq.end()) freq[prefix] = 1;
        else freq[prefix]++;
    }
    cout << count;
}
