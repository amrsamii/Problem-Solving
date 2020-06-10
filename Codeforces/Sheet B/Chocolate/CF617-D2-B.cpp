#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int OO = 1e7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int bar[n];

    int one = -1;
    // long long to prevent overflow
    ll ans = 1;

    for (int i = 0; i < n; i++) {
        cin >> bar[i];
        if (bar[i] == 1 && one == -1)
            one = i;
    }

    if (one == -1)
        return cout << 0, 0;

    for (int i = one + 1; i < n; i++) {
        if (bar[i] == 1)
            ans *= i - one, one = i;
    }
    cout << ans;
    return 0;
}
