#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    int t, n, p;
    cin >> t;

    for(int k=0; k<t; k++){
        
        //every test case
        cin >> n;
        int minimum = n+5;
        deque<int> dq;
        for(int i=0; i<n; i++){
            cin >> p;
            if(p < minimum){
                dq.push_front(p);
                minimum = p;
            }
            else dq.push_back(p);
        }

        while(!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << "\n";
    }

    
}
