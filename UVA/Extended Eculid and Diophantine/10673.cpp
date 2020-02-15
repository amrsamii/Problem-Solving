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

ll extended_eculid(ll a, ll b, ll &x, ll &y){
    if(a<0){
        ll r = extended_eculid(-a,b,x,y);
        x *= -1;
        return r;
    }
    if(b<0){
        ll r = extended_eculid(a,-b,x,y);
        y *= -1;
        return r;
    }
    if(b == 0){
        x=1,y=0;
        return a;
    }
    ll g = extended_eculid(b,a%b,y,x);
    y -= (a/b)*x;
    return g;
}

ll ldioph(ll a, ll b, ll c, ll &x, ll &y, bool &found){
    ll g = extended_eculid(a,b,x,y);
    if((found = c % g == 0))
        x *= c/g, y *= c/g;
    return g;
}

int main() {

    // freopen("input/input.txt", "r", stdin);
    //freopen("output/output.txt", "w", stdout);

   ll x,y,n,m;
   bool found;

   int t;
   cin>>t;
   while(t--){
       cin>>n>>m;
       ldioph(n/m,(n+m-1)/m,n,x,y,found);
       cout<<x<<" "<<y<<endl;
   }


    return 0;
}