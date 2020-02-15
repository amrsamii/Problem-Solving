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




int main() {

    //freopen("input/input.txt", "r", stdin);
    //freopen("output/output.txt", "w", stdout);

    ll x,m,n;
    bool first;
    while(cin>>x && x){
        first = true;
        for(int k=9;k>=0;k--){
            if((x-k) % 9 == 0){
                m = (x-k)/9;
                n = 10*m + k;
                if(first){
                    first = false;
                    cout<<n;
                }
                else
                    cout<<" "<<n;
            }
        }
        cout<<'\n';
    }


/*

 ull x, n, m, k;
    while (cin >> x && x) {

        if (x % 9 == 0) {
            n = 10 * x / 9;
            cout << n - 1 << " " << n << endl;
        } else {
            k = x % 9;
            m = (x - k) / 9;
            cout << 10 * m + k << endl;
        }

    }

*/






    return 0;
}
