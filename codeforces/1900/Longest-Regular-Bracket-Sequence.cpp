#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("../../in.txt", "r", stdin);
	//freopen("../../out.txt", "w", stdout);

    string str;
    cin >> str;

    stack<pair<char, int>> st;

    for(int i=0; i<str.size(); i++){
        if(!st.empty() && st.top().first == '(' && str[i] == ')') st.pop();
        else st.push(make_pair(str[i], i));
    }
    
    int count = 0, longest = 0;
    int prev = str.size();
    while(!st.empty()){
        int diff = prev - st.top().second - 1;
        if(diff == longest) count++;
        else if(diff > longest){
            longest = diff;
            count = 1;
        }
        prev = st.top().second;
        st.pop();
    }
    if(prev == longest) count++;
    else if(prev > longest){
        longest = prev;
        count = 1;
    }

    if(longest == 0) count = 1;
    cout << longest << " " << count << endl;
}
