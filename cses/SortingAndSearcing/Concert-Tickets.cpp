#include<bits/stdc++.h>
using namespace std;

//use lower_bound(), which returns the first element >= comp
//returns an iterator
//use negatieve values to get <=

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    multiset<int> tickets;
    int n, m, h, t;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> h;
        tickets.insert(-h);
    }

    int price;
    for(int i=0; i<m; i++){
        cin >> t;
        multiset<int>::iterator it = tickets.lower_bound(-t);
        if(it == tickets.end()) price = -1;
        else {
            price = -*it;
            tickets.erase(it);
        }
        cout << price << "\n";
    }
}
