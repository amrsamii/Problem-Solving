#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define maxn 31
int prime[maxn+5]; // range + 1 to include last number in range
void sieve() {

    // fill(prime, prime + maxn, true);
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= maxn; i++)  {
        if (prime[i]) {
            for (int j = i * 2; j <= maxn; j += i)
                prime[j] = false;
        }
    }
}

vector<ll> factorization(ll n) {
    vector<ll> factors;
    ll i;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0)
            factors.push_back(i), factors.push_back(n / i);
    }
    if (i * i == n)
        factors.push_back(i);
    return factors;
}

int main() {

    int n;
    sieve();
    while (cin >> n && n) {
        ll x = pow(2, n - 1);
        ll y = pow(2, n) - 1;
        ll relative = x*y;
        vector<ll> x_div = factorization(x);
        vector<ll> y_div = factorization(y);
        set<ll> relative_div;
        for(ll i : x_div){
            for(ll j : y_div){
                relative_div.insert(i*j);
                relative_div.insert(j);
            }
            relative_div.insert(i);
        }

        ll sum = 0;
        for(ll i : relative_div)
            sum += i;

        if(relative == sum - relative){
            printf("Perfect: %lld!\n",relative);
        }else{
            if(prime[n])
                printf("Given number is prime. But, NO perfect number is available.\n");
            else
                printf("Given number is NOT prime! NO perfect number is available.\n");
        }

    }
    return 0;
}