typedef long double ld;

// that is the max
ld c[1000][1000] = {0};

void build_nCk() {
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            c[i][j] = (j == 0) ? 1 : ((i == 0) ? 0 : c[i - 1][j - 1] + c[i - 1][j]);
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


// c(n,k) efficient one
#define lp(i, n)        for(ull i=0;i<(ull)(n);++i)
typedef vector<ld> vll;

ld nck(ld n, ld k) {
    if (k > n)return 0;
    if (n - k < k) k = n - k;
    vll nom(k), d(k);
    ld s = k;
    lp(i, s) {
        d[i] = k;
        nom[i] = n;
        n--;
        k--;
    }
    lp(i, s) {
        lp(j, s) {
            ll g = gcd(nom[i], d[j]);
            nom[i] /= g;
            d[j] /= g;
        }
    }
    ld ans = 1;
    lp(i, s)ans *= nom[i];
    lp(i, s)ans /= d[i];
    return ans;
}

