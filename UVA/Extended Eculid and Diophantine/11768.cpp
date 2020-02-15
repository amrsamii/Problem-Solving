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
        if(c % a)
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

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    return (rx - lx) / abs(b) + 1;
}

ll read1Float() {
    ll x, y;
    scanf("%lld.%lld", &x, &y);
    return x * 10 + y;
}

int main() {

    //freopen("input/input.txt", "r", stdin);
    //freopen("output/output.txt", "w", stdout);

    int n;
    ll x1, y1, x2, y2, a, b, c;
    ll minx, maxx, miny, maxy;


    cin >> n;
    while (n--) {
        x1 = read1Float();
        y1 = read1Float();
        x2 = read1Float();
        y2 = read1Float();
        minx = ceil(min(x1, x2) / 10.0);
        maxx = floor(max(x1, x2) / 10.0);
        miny = ceil(min(y1, y2) / 10.0);
        maxy = floor(max(y1, y2) / 10.0);
        a = y2 - y1;
        b = x1 - x2;
        c = a * x1 + b * y1;
        a *= 10, b *= 10;
        cout << find_all_solutions(a, b, c, minx, maxx, miny, maxy) << endl;
    }


    return 0;
}