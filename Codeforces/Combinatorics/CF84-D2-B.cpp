#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {


    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ll ans = n;
    for(int i=0;i<n-1;i++){
        ll count =1;

        while(arr[i] == arr[i+1])
            count ++, i++;
        if(count != 1)
            ans += (count * (count-1))/2;
    }
    cout<<ans;

    return 0;
}