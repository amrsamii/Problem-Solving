#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {

    // little faster reading, no c apis
    ios_base::sync_with_stdio(false);

    ll n, m, xc, yc, k;
    ll ans = 0;
    cin >> n >> m >> xc >> yc >> k;

    while (k--) {
        ll x, y;
        cin >> x >> y;
        if (x == 0 && y == 0)
            continue;
        ll steps_x = (x == 0) ? 1e15 : (x > 0) ? (n - xc) / x : (1 - xc) / x;
        ll steps_y = (y == 0) ? 1e15 : (y > 0) ? (m - yc) / y : (1 - yc) / y;
        ll steps = min(steps_x, steps_y);
        ans += steps;
        if (x != 0)
            xc += steps * x;
        if (y != 0)
            yc += steps * y;

    }
    cout << ans;

}
