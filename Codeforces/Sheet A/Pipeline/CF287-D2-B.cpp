#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sum_p(ll p, ll k) {

    return k * (k + 1) / 2 - p * (p - 1) / 2;
}

ll BS(ll n, ll k) {
    ll min = 1, max = k;
    while (min <= max) {
        ll mid = min + (max - min) / 2;
        ll sum = sum_p(mid, k);
        if (sum > n)
            min = mid + 1;
        else if (sum < n)
            max = mid;
        else
            return  k - mid + 1;
    }
    return k-min+2;
}

int main() {

    ll n, k;
    cin >> n >> k;
    if (n == 1)
        return cout << 0, 0;
    n--, k--;
    if (k * (k + 1) / 2 < n)
        return cout << -1, 0;
    if (n <= k)
        return cout << 1, 0;
    cout << BS(n, k);

}
