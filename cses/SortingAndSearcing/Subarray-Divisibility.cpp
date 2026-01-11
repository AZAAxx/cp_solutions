#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
    //freopen("../../out.txt", "w", stdout);

    int n, a;
    cin >> n;

    vector<int> pref; //prefix array mod n
    int prefix = 0;
    
    for(int i=0; i<n; i++){
        cin >> a;
        prefix = ((prefix + a)%n + n)%n;
        pref.push_back(prefix);
    }

    map<int, int> freq; //frequency map
    freq[0] = 1;
    ll count = 0;
    for(int i=0; i<n; i++){
        prefix = pref[i];
        auto it = freq.find(prefix);
        if(it != freq.end()) {
            count += (ll)it->second;
            it->second++;
        }
        else freq[prefix] = 1;
    }
    cout << count << endl;

}
