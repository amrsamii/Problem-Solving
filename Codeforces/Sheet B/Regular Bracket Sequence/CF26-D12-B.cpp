#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

    // little faster reading, no c apis
    ios_base::sync_with_stdio(false);

    string s;
    cin>>s;
    stack<char> st;
    for(char i : s){
        if(i == '(')
            st.push(i);
        else{
            if(!st.empty()&&st.top() == '(')
                st.pop();
            else
                st.push(i);
        }
    }
    cout<<s.length()-st.size();



}
