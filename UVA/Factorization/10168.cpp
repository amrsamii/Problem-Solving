
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 10000000

bool primes[MAXN+5];

void sieve(){

    memset(primes,true,sizeof primes);
    primes[0] = primes[1] = false;

    for(ll i =2;i*i<= MAXN;i++){

        if(primes[i]){
            for(ll j = i*i;j<=MAXN;j += i)
                primes[j] = false;
        }
    }

}

void num(ll x, ll &a, ll &b){

    for(ll i=2;2*i<=x;i++){
        if(primes[i] && primes[x-i]){
            a = i;
            b = x-i;
            return;
        }
    }

}

void generateNumbers(ll n){

    ll a,b;
    if( n % 2){
        num(n-5,a,b);
        printf("2 3 %lld %lld\n",a,b);

    }else{
        num(n-4,a,b);
        printf("2 2 %lld %lld\n",a,b);
    }
}



int main() {

    sieve();
    ll n;
    while(scanf("%lld",&n)==1){
       if(n<8){
           printf("Impossible.\n");
           continue;
       }
       generateNumbers(n);

    }


    return 0;
}

