#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[105];
int main() {

    int n;
    bool flag = false;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        if(arr[i] == 1)
            flag = true;
    }

    if(!flag)
        return cout<<0,0;

    ll ans = 1;
    for(int i=0;i<n;i++){
        if(arr[i] == 1) {
            for(int j = i+1;j<n;j++){
                if(arr[j] == 1) {
                    ans *= (j - i);
                    break;
                }
            }
        }
    }

    cout<<ans;


    return 0;
}