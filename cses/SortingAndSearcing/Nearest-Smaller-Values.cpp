#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("../in.txt", "r", stdin);
	//freopen("../out.txt", "w", stdout);

    int n, a;
    cin >> n;

    stack<pair<int,int>> st;

    for(int i=1; i<=n; i++){
        cin >> a;
        while(!st.empty() && st.top().first >= a) st.pop();

        int index = (st.empty() ? 0 : st.top().second);
        cout << index << " ";

        st.push(make_pair(a, i));
    }
    cout << endl;
}
