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

ll extended_eculid(ll a, ll b, ll &x, ll &y) {
    if (a < 0) {
        ll r = extended_eculid(-a, b, x, y);
        x *= -1;
        return r;
    }
    if (b < 0) {
        ll r = extended_eculid(a, -b, x, y);
        y *= -1;
        return r;
    }
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll g = extended_eculid(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}

ll ldioph(ll a, ll b, ll c, ll &x, ll &y, bool &found) {
    ll g = extended_eculid(a, b, x, y);
    if ((found = c % g == 0))
        x *= c / g, y *= c / g;
    return g;
}

void shift_solution(ll &x, ll &y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    if (!a && b) {
        if (c % b)
            return 0;
        return maxx - minx + 1;
    } else if (!b && a) {
        if (c % a)
            return 0;
        return maxy - miny + 1;
    } else if (!a && !b)
        return 0;
    ll x, y, g;
    bool found;
    g = ldioph(a, b, c, x, y, found);
    if (!found)
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    //minimize x
    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    //maximize x
    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    //minimize y
    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    //maximize y
    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    // +1 because [lx,rx] include rx
    // divide by b as x is moving +- b
    return (rx - lx) / abs(b) + 1;
}


ull bigmod(ull b, ull p, ull m) {

    if (p == 0)
        return 1;

    if (p % 2 == 0) {
        ull value = bigmod(b, p / 2, m);
        return (value * value) % m;
    } else if (p % 2 == 1) {
        ull x, y;
        x = b % m;
        y = bigmod(b, p - 1, m);
        return (x * y) % m;
    }

}

bool isLeap(int y) {

    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main() {

    // freopen("input/input.txt", "r", stdin);
    //freopen("output/output.txt", "w", stdout);



    int N, F, A, B, E;
    bool reachables[100][100];
    bool A_reachables[100];
    bool B_reachables[100];
    int X[100], Y[100];
    cin >> N;
    while (N--) {

        cin >> F >> E >> A >> B;
        for (int i = 0; i < E; i++)
            cin >> X[i] >> Y[i];


        for (int i = 0; i < E; i++) {
            A_reachables[i] = A >= Y[i] && !((A - Y[i]) % X[i]);
            B_reachables[i] = B >= Y[i] && !((B - Y[i]) % X[i]);
        }

        for (int i = 0; i < E - 1; i++)
            for (int j = i + 1; j < E; j++)
                reachables[i][j] = reachables[j][i] =
                        find_all_solutions(X[i], -X[j], Y[j] - Y[i], 0, (F - 1 - Y[i]) / X[i], 0,
                                           (F - 1 - Y[j]) / X[j]) > 0;


        for(int k=0;k<E;k++)
            for(int i =0;i<E;i++)
                for(int j=0;j<E;j++)
                    reachables[i][j] |= reachables[i][k] && reachables[k][j];

        bool possible = false;

        for (int i = 0; i < E && !possible; i++) {
            if (A_reachables[i]) {
                for (int j = 0; j < E && !possible; j++) {
                    if (B_reachables[j] && reachables[i][j])
                        possible = true;
                }
            }
        }

        if(possible)
            cout<<"It is possible to move the furniture."<<endl;
        else
            cout<<"The furniture cannot be moved."<<endl;


    }
    return 0;
}