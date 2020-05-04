#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

    // little faster reading, no c apis
    ios_base::sync_with_stdio(false);

    int n, m;
    int a, b, c;
    ll ans = 0;
    cin >> n >> m;
    vector<int> money(n, 0);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--, b--;
        money[a] -= c;
        money[b] += c;
    }

    for (int i : money) {
        if (i < 0)
            ans += -i;
    }

    cout << ans;
    return 0;
}