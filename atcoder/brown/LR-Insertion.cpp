#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    deque<int> dq; //sequence A

    for(int i=n; i>=0; i--){
        if(s[i] == 'R') dq.push_front(i);
        else dq.push_back(i);
    }
    

    while(!dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }
}
