#include<bits/stdc++.h>
using namespace std;

//WRONG ANSWER

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    int n, k;
    cin >> n;
    set<pair<int,int>> s;

    for(int i=0; i<n; i++){
        cin >> k;
        s.insert(make_pair(k,i));
    }
    //sorted by increasing size
    //k, .., .., l can be in the same tower iff k.i > l.i
    //decreasing sequences in it->second can make a tower
    //find min number of decr. sequences
    //this becomes the collecting numbers problem

    set<pair<int,int>> s2;
    int i = 1;
    for(auto p : s){
        s2.insert(make_pair(p.second, i));
        i++;
    }

    int round = 1;
    set<pair<int,int>>::iterator it = s2.begin();
    int prev = it->second;

    for(it++; it != s2.end(); it++){
        if(prev < it->second) round++;
        prev = it->second;
    }

    cout << round; 
}
