#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <list>
#include <cstring>
#include <iomanip>
#include "algorithm"
#include <set>

# define PI         3.141592654 /* pi */
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define all(v) ((v).begin()),((v).end())

ll cntr;

ll gcd(ll a, ll b) {
    cntr++;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll gcd(vector<ll> arr) {
    ll ans = arr[0];

    for (int i = 1; i < (int) arr.size(); i++)
        ans = gcd(ans, arr[i]);

    return ans;
}

ll lcm(ll a, ll b) {

    return (a * b) / gcd(a, b);
}

ll lcm(vector<ll> arr) {

    ll ans = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        ans = lcm(ans, arr[i]);
    }
    return ans;
}

ll lcm(ll a, ll b, ll c, ll d) {

    ll ans = a;

   ans = lcm(ans,b);
   ans = lcm(ans,c);
   ans = lcm(ans,d);
    return ans;
}

ll arr[5];

ll inc_exc(ll n, int idx = 0, ll d = 1, int sign = -1) {
    if (idx == 5) {
        if (d == 1 && sign == -1)
            return 0;
        return sign * n / d;
    }
    return inc_exc(n, idx + 1, d, sign) + inc_exc(n, idx + 1, lcm(d, arr[idx]), sign * -1);

}

ll inc(ll n) {
    ll cnt = 0;
    for (int i1 = 0; i1 < 2; i1++) {
        for (int i2 = 0; i2 < 2; i2++) {
            for (int i3 = 0; i3 < 2; i3++) {
                for (int i4 = 0; i4 < 2; i4++) {
                    for (int i5 = 0; i5 < 2; i5++) {
                        ll elementsCnt = 0;
                        ll d = 1;
                        if (i1) d = lcm(arr[0], d), elementsCnt++;
                        if (i2) d = lcm(arr[1], d), elementsCnt++;
                        if (i3) d = lcm(arr[2], d), elementsCnt++;
                        if (i4) d = lcm(arr[3], d), elementsCnt++;
                        if (i5) d = lcm(arr[4], d), elementsCnt++;

                        if (elementsCnt == 0)
                            continue;
                        int sign = elementsCnt % 2 == 0 ? -1 : 1;
                        cnt += sign * n / d;
                    }
                }
            }
        }
    }
    return cnt;
}

double getAngle_A_abB(double a, double b, double B) {
    return asin(a * sin(B) / b);
}

double getDistance(int x1, int x2, int y1, int y2) {

    return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}

bool isInside(double x_point, double y_point, double top_left_x, double top_left_y, double bottom_right_x,
              double bottom_right_y) {
    return (x_point > top_left_x && x_point < bottom_right_x) && (y_point > bottom_right_y && y_point < top_left_y);
}

struct Point {
    double x;
    double y;
};

bool doOverlap(Point l1, Point r1, Point l2, Point r2) {

    if (l1.x >= r2.x || l2.x >= r1.x)
        return false;

    if (l2.y >= r1.y || l1.y >= r2.y)
        return false;

    return true;
}

pair<Point, Point> getIntersection(Point l1, Point r1, Point l2, Point r2) {

    Point l3, r3;
    l3.x = max(l1.x, l2.x);
    l3.y = max(l1.y, l2.y);
    r3.x = min(r1.x, r2.x);
    r3.y = min(r1.y, r2.y);
    return make_pair(l3, r3);

}

bool pointsEqual(Point p1, Point p2) {

    return (fabs(p1.x - p2.x) < 1e-6) && (fabs(p1.y - p2.y) < 1e-6);
}


map<char, int> values;

char findByValue(int x) {
    for (auto &y : values) {
        if (y.second == x)
            return y.first;
    }
    return '*';
}


ll c[101][101] = {0};

void build_nCk() {
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            c[i][j] = (j == 0) ? 1 : ((i == 0) ? 0 : c[i - 1][j - 1] + c[i - 1][j]);
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

/*
ll series(ll n) {
    ll x = n;
    ll y = n + 1;

    if (x % 2 == 0)
        x /= 2;
    else
        y /= 2;

    x %= mod;
    y %= mod;

    return (x * y) % mod;
}
*/
int mod;


void multiply(ll F[2][2], ll M[2][2]) {

    ll x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    ll y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    ll z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    ll w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x % mod;
    F[0][1] = y % mod;
    F[1][0] = z % mod;
    F[1][1] = w % mod;
}

void power(ll F[2][2], int n) {
    if (n == 0 || n == 1)
        return;
    ll M[2][2] = {{1, 1},
                  {1, 0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}

int fib(int n) {
    if (n == 0)
        return 0;
    ll F[2][2] = {{1 % mod, 1 % mod},
                  {1 % mod, 0 % mod}};
    power(F, n - 1);
    return F[0][0];
}

ll stirling2(ll n, ll k) {
    if (n == k || k == 1)
        return 1;
    return k * stirling2(n - 1, k) + stirling2(n - 1, k - 1);
}

ll bell(ll n) {
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum += stirling2(n, i);
    return sum;
}

vector<ll> factorization(ll n) {
    vector<ll> v;
    ll i;
    for (i = 1; i * i <= n; i++) {
        if (n % i == 0)
            v.push_back(i), v.push_back(n / i);
    }
    if (i * i == n)
        v.push_back(i);
    return v;
}

ll sum_range(int i, int j, int k, int l, int a[1005][1005]) {
    return a[k][l] - a[i - 1][l] - a[k][j - 1] + a[i - 1][j - 1];
}

bool sortPairs(const pair<ll, ll> &a, const pair<ll, ll> &b) {

    return min(a.second - a.first, a.first) > min(b.second - b.first, b.first);
}


int maxGCD(vector<int> numbers, int k) {

    int high = *max_element(all(numbers));
    // high is factor of high like 12 is factor of 12 (not prime factorization)
    // so we want to say divisors[high]++ we can't do so unless divisors size is high+1
    // note that high is the largest divisor in the array
    vector<int> divisors(high + 1, 0);
    int j;
    for (int element : numbers) {
        for (j = 1; j * j < element; j++)
            if (element % j == 0)
                divisors[j]++, divisors[element / j]++;

        if (j * j == element)
            divisors[j]++;
    }

    // traverse from high to low to get the max GCD
    for(int i = high;i>=1;i--){
        // If this divisor can divide at least k
        // numbers, it is a GCD of at least one
        // sub sequence of size k
        // because if we have k=4, we can choose k =3 of them and have max gcd and number of
        // possible subsequences are c(4,3)
        if(divisors[i] >= k)
            return i;
    }
}

int main() {

    //freopen("input/input.txt","r",stdin);
    //freopen("output/output.txt","w",stdout);
    int n,t,table;
    ll coinsLCM,greatest,smallest;
    vector<ll> coins;
    while(cin>>n>>t && n){
        coins.resize(n);
        for(int i=0;i<n;i++)
            cin>>coins[i];
        while(t--){
            greatest = -1, smallest = 1e9;
            cin>>table;
            for(int i1 = 0;i1<n;i1++){
                for(int i2 = i1+1;i2<n;i2++){
                    for(int i3 = i2+1;i3<n;i3++){
                        for(int i4 = i3+1;i4<n;i4++){
                            coinsLCM = lcm(coins[i1],coins[i2],coins[i3],coins[i4]);

                            greatest = max(greatest,coinsLCM * (table/coinsLCM));
                            smallest = min(smallest,coinsLCM * ((table+coinsLCM-1)/coinsLCM));
                        }
                    }
                }
            }


            cout<<greatest<<" "<<smallest<<endl;
        }
    }





    return 0;
}




