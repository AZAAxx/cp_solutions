//Observations:
//1. If there are 2 consecutive equal numbers, they MUST be merged
//2. 
//1 1 3 2 -> 1 3 2 -> 3 3 2 -> 5 + 1

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("../../in.txt", "r", stdin);
    //freopen("../../out.txt", "w", stdout);

    int t, n, a;
    cin >> t;
    for(int k=0; k<t; k++){

        cin >> n;
        deque<int> q;
        int maX = 0;
        for(int i=0; i<n; i++){
            cin >> a;
            q.push_back(a);
            maX = max(maX, a);
        }

        long long sum = 0;
        int curr, prev = q.back();
        while(!q.empty()){
            curr = q.front();
            q.pop_front();
            sum += max(prev, curr);
            prev = curr;
        }
        cout << sum-maX << "\n";

    }
}
