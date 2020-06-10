#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int OO = 1e7;

#define MAX 1000005
#define MOD 1073741824

ll factors[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i <= MAX; i++)
        for (int j = i; j <= MAX; j += i)
            factors[j]++;


    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= c; k++)
                ans = (ans % MOD + factors[i * j * k] % MOD) % MOD;

    cout << ans;
    return 0;
}
