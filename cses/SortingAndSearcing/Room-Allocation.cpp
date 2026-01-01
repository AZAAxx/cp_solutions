#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    int n, a, b; 
    cin >> n;

    //{arrival, departure, order}
    priority_queue<tuple<int,int,int>, 
                   vector<tuple<int,int,int>>, 
                   greater<tuple<int,int,int>>> customers;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        customers.push(make_tuple(a, b, i));
    }

    //rooms holds {time room i is freed, room number} for every room
    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> rooms;

    //v[i] holds {order, room} for every customer
    vector<pair<int,int>> v;

    for(int i=0; i<n; i++){
        tuple<int,int,int> t = customers.top();

        int arrival = get<0>(t);
        int departure = get<1>(t);
        int order = get<2>(t);
        int room;

        if(!rooms.empty() && rooms.top().first < arrival) { //no extra room needed, update arrays
            room = rooms.top().second; //room number
            rooms.pop(); 
            rooms.push(make_pair(departure, room));
        }
        else{
            room = rooms.size();
            rooms.push(make_pair(departure, room)); //create new room
        }
            
        v.push_back(make_pair(order, room));
        customers.pop();
    }

    cout << rooms.size() << endl;
    sort(v.begin(), v.end());

    for(auto p : v) cout << p.second+1 << " ";
    cout << endl;

}
