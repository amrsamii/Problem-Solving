#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



ll n,c;
vector<ll> stalls;
bool F(ll x){

    ll placed_cows = 1, last_pos = stalls[0];
    for(ll i=1;i<n;i++){
        if(stalls[i]- last_pos >= x){
            last_pos = stalls[i];
            if(++placed_cows == c)
                return true;
        }
    }
    return false;

}

ll BS() {
    ll min = 0, max = stalls[n-1] - stalls[0];
    while (min < max) {
        ll mid = min + (max - min+1) / 2;
        ll can = F(mid);
        if (can)
            min = mid;
        else
            max = mid-1;

    }
    return min;
}

int main() {

   ll t;
   cin>>t;
   while(t--){
       cin>>n>>c;
       stalls = vector<ll>(n);
       for(int i=0;i<n;i++)
           cin>>stalls[i];
       sort(stalls.begin(),stalls.end());
        cout<<BS()<<endl;
   }

}
