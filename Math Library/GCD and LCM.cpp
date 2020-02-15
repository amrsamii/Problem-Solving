ll gcd(ll a, ll b) {

    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll gcd(vector<ll> arr) {
    ll ans = arr[0];

    for (int i = 1; i < (int) arr.size(); i++)
        ans = gcd(ans, arr[i]);
    //if ans == 1 break and return
    return ans;
}

ll lcm(ll a, ll b) {

    return (a / gcd(a, b)) * b;
}

ll lcm(vector<ll> arr) {

    ll ans = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        ans = lcm(ans, arr[i]);
    }
    return ans;
}



// inclusion exclusion for division

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

// Arithmeric series

ll series(ll n) {
    ll x = n;
    ll y = n + 1;

 // divide first then take mod
    if (x % 2 == 0)
        x /= 2;
    else
        y /= 2;

    x %= mod;
    y %= mod;

    return (x * y) % mod;
}


//Fibonacci in efficient way

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

// 2D prefix sum
ll sum_range(int i, int j, int k, int l, int a[1005][1005]) {
    return a[k][l] - a[i - 1][l] - a[k][j - 1] + a[i - 1][j - 1];
}

bool sortPairs(const pair<ll, ll> &a, const pair<ll, ll> &b) {

    return min(a.second - a.first, a.first) > min(b.second - b.first, b.first);
}




// Max GCD of array for sum k numbers
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
    for (int i = high; i >= 1; i--) {
        // If this divisor can divide at least k
        // numbers, it is a GCD of at least one
        // sub sequence of size k
        // because if we have k=4, we can choose k =3 of them and have max gcd and number of
        // possible subsequences are c(4,3)
        if (divisors[i] >= k)
            return i;
    }
}


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



ll read1Float() {
    ll x, y;
    scanf("%lld.%lld", &x, &y);
    return x * 10 + y;
}

ll extended_eculid(ll a, ll b, ll c, ll &x, ll &y, ll &z) {
    ll w, e, f;
    ll g = extended_eculid(a, gcd(b, c), x, e);
    extended_eculid(b, c, f, w);
    y = e * f;
    z = e * w;
    return g;
}


// Recursive function to return gcd of a and b
double gcd(double a, double b) {
    if (a < b)
        return gcd(b, a);

    // base case
    if (fabs(b) < 0.001)
        return a;

    else
        return (gcd(b, a - floor(a / b) * b));
}

