#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int OO = 1e7;

int n;
int x[10000];
int y[10000];
int r[10000];
bool solve(int x1, int y1) {
    for (int i=0;i<n;i++) {
        if ((((x1 - x[i]) * (x1 - x[i])) + ((y1 - y[i]) * (y1 - y[i]))) <=
            (r[i] * r[i])) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;


    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    int ans = 0;

    for (int i = min(xa, xb); i <= max(xa, xb); i++) {
        ans += !solve(i, ya);
        ans += !solve(i, yb);
    }

    for (int i = min(ya, yb) + 1; i < max(ya, yb); i++) {
        ans += !solve(xa, i);
        ans += !solve(xb, i);
    }

    cout << ans;
    return 0;
}
