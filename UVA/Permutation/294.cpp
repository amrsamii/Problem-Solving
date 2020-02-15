#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 1000000000


void sieve(ll x, bool prime[]) {

    // fill(prime, prime + MAXN, true);
   // memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= x; i++)  {
        if (prime[i]) {
            for (int j = i * 2; j <= x; j += i)
                prime[j] = false;
        }
    }
}

pair<ll,ll> range(ll l,ll u,ll x, bool primes[]){

    ll a=-1,b=-1;
    vector<int>v;
    for(ll i =2 ; i<= x;i++) {
        if(primes[i])   v.push_back(i);
    }
    ll sz = v.size();

    for(ll i = l; i<= u;i++){

        ll j = 0;
        ll total = 1;

        ll temp = i;
        for(ll k = v[j] ;k*k <=temp && j<sz;k=v[++j]){
            int count = 0;

            while(temp % k == 0)
                count++ , temp /= k;

            total *=(1+count);

        }

        if(temp > 1)
            total *= 2;

        if(total>a)
            a = total , b = i;
    }

    return make_pair(a,b);

}


int main() {

    pair<ll,ll> ans;
    int t;
    ll l,u;
    ll x = sqrt(MAXN)+1;
    bool primes[x];
    memset(primes,true,sizeof primes);
    sieve(x,primes);
    cin>>t;
    while(t--){
        cin>>l>>u;
       ll y = sqrt(u)+1;
        ans = range(l,u,y,primes);
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,u,ans.second,ans.first);
    }
    return 0;
}