#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


vector<ll> factorization(ll n) {
    vector<ll> primes;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0)
            primes.push_back(i), n /= i;
    }
    if (n>1)
        primes.push_back(n);

    sort(primes.begin(),primes.end());
    return primes;
}


int main() {

    ll n;
    vector<ll> primes;
    while(cin>>n && n){
        primes = factorization(abs(n));
        printf("%lld = ",n);
        if(n < 0)
            printf("-1 x ");

        for(int i=0,sz = primes.size();i<sz;i++){
            printf("%lld",primes[i]);
            if(i == sz-1)
                printf("\n");
            else
                printf(" x ");
        }


    }

    return 0;
}