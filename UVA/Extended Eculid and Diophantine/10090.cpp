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

    //freopen("input/input.txt", "r", stdin);
    //freopen("output/output.txt", "w", stdout);

    ll x,y,n,n1,n2,c1,c2,gcd,k,k_num,k_den;
    ll x1,x2,y1,y2;
    bool found;
    while(cin>>n && n){
        cin>>c1>>n1>>c2>>n2;
        gcd = ldioph(n1,n2,n,x,y,found);
        if(!found){
            cout<<"failed"<<endl;
            continue;
        }

        if(x<0){
            k_num = gcd * -x;
            k_den = n2;
            k = (k_num+k_den-1)/k_den;
            x += k*n2/gcd;
            y -= n1*k/gcd;
        }

        if(y<0){
            k_num = gcd * -y;
            k_den = n1;
            k = (k_num+k_den-1)/k_den;
            x -= k*n2/gcd;
            y += n1*k/gcd;
        }

        if( x < 0 || y<0){
            cout<<"failed"<<endl;
            continue;
        }

        // minimize x, maximize y
        k_num = x*gcd;
        k_den = n2;
        k = k_num/k_den;
        x -= k*n2/gcd;
        y += k*n1/gcd;
        x1 = x, y1 = y;
        // maximize x, minimize y
        k_num = y*gcd;
        k_den = n1;
        k = k_num/k_den;
        x += k*n2/gcd;
        y -= k*n1/gcd;
        x2 = x, y2 = y;

        if(x1*c1 + y1 * c2 < x2*c1 + y2*c2)
            cout<<x1<<" "<<y1<<endl;
        else
            cout<<x2<<" "<<y2<<endl;

    }


    return 0;
}