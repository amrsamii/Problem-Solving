#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m;
bool valid(ll x, ll y){
    return x>=1 && x<=n && y>=1 && y<=m;
}
int main() {

    // little faster reading, no c apis
    ios_base::sync_with_stdio(false);

    ll  xc, yc, k;
    ll ans = 0;
    cin >> n >> m >> xc >> yc >> k;

    while (k--) {
        ll x, y;
        cin >> x >> y;
// this case will not happen as x+y >= 1
        if (x == 0 && y == 0)
            continue;
        ll start = 0, end = 1e10,mid;
        while(start<end){
            mid = start + (end-start+1)/2;
            if(valid(xc+mid*x,yc+mid*y)){
                start = mid;
            } else
                end = mid-1;
        }
        ans += start;
        xc += start*x;
        yc+= start*y;



    }
    cout << ans;

}
