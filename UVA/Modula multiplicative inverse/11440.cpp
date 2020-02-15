#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ll> vll;

#define all(v) ((v).begin()),((v).end())

#define MOD 100000007


ll bigmod(ll b, ll p, ll m) {

    if (p == 0)
        return 1;

    ll value = bigmod(b,p/2,m);
    value = (value*value) % m;
    if(p%2)
        value = (value * b%m)%m;
    return value;
}

ll modInversep(ll a, ll p){
    return bigmod(a,p-2,p);
}

const int maxn = 1e7;
int isPrime[maxn+5];
ll phi_fact[maxn+5];
ll fact[maxn+5];

void sieve() {

    fill(isPrime, isPrime + maxn, true);
    //memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= maxn; j += i)
                isPrime[j] = false;
        }
    }
}

void factorial(){
    fact[0] = fact[1] = 1;

    for(int i=2;i<=maxn;i++){
        fact[i] = (fact[i-1] * i)%MOD;
    }
}

void phi(){

    memset(phi_fact,0,sizeof phi_fact);
    phi_fact[1] = phi_fact[2] = 1;

    for(int i=3;i<=maxn;i++){
        if(isPrime[i])
            phi_fact[i] = ((i-1) * phi_fact[i-1]) % MOD;
        else
            phi_fact[i] = (i * phi_fact[i-1]) % MOD;

    }
}
int main() {

    //freopen("input/input.txt", "r", stdin);
    //freopen("output/output.txt", "w", stdout);

    sieve();
    phi();
    factorial();
    ll n,m,inv;
    ll ans = 0;
    while(cin>>n>>m && n){

        ans = phi_fact[m];
        /*
        for(ll i = n;i>m;i--){
            ans = (ans * i) % MOD;
        }
*/
        inv = bigmod(fact[m],MOD-2,MOD);
        ans = ((ans * fact[n])%MOD * inv)%MOD;
        cout<<ans-1<<endl;
    }




    return 0;
}


940534866