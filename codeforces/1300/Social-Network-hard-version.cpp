#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    map<int, int> mp;
    deque<int> dq;
    int n, k, id;
    cin  >> n >> k;

    int removed_id;
    for(int i=0; i<n; i++){
        cin >> id;
        if(mp.find(id) == mp.end()){ //not on the list
            mp.insert({id, id});
            dq.push_back(id);

            if(dq.size() > k){
                removed_id = dq.front();
                mp.erase(removed_id);
                dq.pop_front();
            }
        }
    }
    cout << dq.size() << endl;
    while(!dq.empty()){
        cout << dq.back() << " ";
        dq.pop_back();
    }
}
