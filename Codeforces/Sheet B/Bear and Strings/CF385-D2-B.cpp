#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {

    string input;
    cin>>input;
    ll ans = 0;

    int sz = input.length();
    for(int i=0;i<sz;i++){
        int b_index = input.find("bear",i);
        if( b_index != string::npos){
            ans += sz - (b_index+3);
        }
    }
    cout<<ans;

    return 0;
}