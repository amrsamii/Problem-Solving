#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ll> vll;

#define all(v) ((v).begin()),((v).end())


ll extended_eculid(ll a, ll b, ll &x, ll &y){
    if(a<0)
        a = -a;
    if(b<0)
        b = -b;
    if(b == 0){
        x=1,y=0;
        return a;
    }
    ll g = extended_eculid(b,a%b,y,x);
    y -= (a/b)*x;
    return g;
}


int main() {

    //freopen("input/input.txt", "r", stdin);
    //freopen("output/output.txt", "w", stdout);

    ll a,b;
    ll x,y,gcd;
    while (cin>>a>>b){
      gcd =  extended_eculid(a,b,x,y);
        cout<<x<<" "<<y<<" "<<gcd<<endl;

    }


    return 0;
}