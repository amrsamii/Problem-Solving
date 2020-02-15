#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



ll factn_primepower(ll n, ll p) {

    ll power = 0;
    for (ll i = p; i <= n; i *= p)
        power += n / i;
    return power;
}




map<ll,ll> factorizationM(ll n) {

    map<ll,ll> primes;

    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0)
            primes[i]++, n /= i;
    }

    if (n > 1)
        primes[n]++;

    return primes;
}

int main() {

    ll n, m;
    map<ll,ll> primePowerM;
    while (scanf("%lld %lld", &n, &m) == 2) {

        bool flag = false;



        primePowerM = factorizationM(m);

        for(auto i : primePowerM){

            ll powerN = factn_primepower(n,i.first);
            if(powerN < i.second) {
                printf("%lld does not divide %lld!\n", m, n);
                flag  =true;
                break;
            }

        }

        if(!flag)
            printf("%lld divides %lld!\n",m,n);

    }


    return 0;
}