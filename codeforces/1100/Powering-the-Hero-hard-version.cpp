#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    int t; 
    cin >> t;
    for(int k=0; k<t; k++){

        //every test case
        int n, s; 
        cin>> n;
        long long sum = 0;
        priority_queue<int> pq;

        for(int i=0; i<n; i++){
            cin >> s;
            if(s == 0 && !pq.empty()){
                sum += pq.top();
                pq.pop();
            }
            else if(s > 0) pq.push(s);
        }

        cout << sum << "\n";
    }
}