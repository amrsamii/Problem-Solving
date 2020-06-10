#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 1000000
#define MOD 1073741824

void sieve(ll x, bool prime[]) {

    // fill(prime, prime + MAXN, true);
    // memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= x; i++) {
        if (prime[i]) {
            for (int j = i * 2; j <= x; j += i)
                prime[j] = false;
        }
    }
}

vector<ll> range(ll l, ll u, ll x, bool primes[]) {

    vector<ll> divisors(u - l + 2);
    vector<int> v;
    for (ll i = 2; i <= x; i++) {
        if (primes[i]) v.push_back(i);
    }
    ll sz = v.size();

    for (ll i = l; i <= u; i++) {

        ll j = 0;
        ll total = 1;

        ll temp = i;
        for (ll k = v[j]; k * k <= temp && j < sz; k = v[++j]) {
            int count = 0;

            while (temp % k == 0)
                count++, temp /= k;

            total *= (1 + count);

        }

        if (temp > 1)
            total *= 2;


        divisors[i] = total;
    }

    return divisors;
}


int main() {

    ll x = sqrt(MAXN) + 1;
    bool primes[x];
    memset(primes, true, sizeof primes);
    sieve(x, primes);
    vector<ll> divisors = range(1, MAXN, x, primes);

    int a, b, c;
    cin >> a >> b >> c;

    ll sum = 0;

    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= c; k++)
                sum = (sum + divisors[i * j * k]) % MOD;

    cout << sum;

    return 0;
}
