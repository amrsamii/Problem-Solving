
const int maxn = 1e7; // max number
int prime[maxn + 5]; // range + 1 to include last number in range

void sieve() {

    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (prime[i]) {
            for (int j = i * 2; j <= maxn; j += i)
                prime[j] = false;
        }
    }
}


// Prime Factorization
vector<ll> factorization(ll n) {
    vector<ll> primes;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0)
            primes.push_back(i), n /= i;
    }
    if (n>1)
        primes.push_back(n);
    return primes;
}








// Least prime factorization
int spf[MAXN+5]; // range + 1 to include last number in range
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

// Factorize in efficient way
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}


bool isPrime(int n) {

    if (n == 2)
        return true;
    if (n % 2 == 0 || n < 2)
        return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}



// Handles all the cases
// function to find all sub-arrays divisible by k
// modified to handle negative numbers as well
ll subCount(vector<int> &ar, int k) {

    int Mod[k];
    memset(Mod, 0, sizeof Mod);

    int cum_sum = 0;
    for (int x : ar) {
        cum_sum += x;
        Mod[(cum_sum % k + k) % k]++;
    }
    int result = 0;

    for (int x : Mod) {

        if (x > 1)
            result += (x * (x - 1) / 2);
    }

    // add the elements which are divisible by k itself
    // i.e., the elements whose sum%k = 0
    result += Mod[0];

    return result;

}



// count number of divisors for range from l to u
// x is sqrt of max of range
// store primes till x as primes after sqrt of max is reduntant

pair<ll, ll> range(ll l, ll u, ll x, bool primes[]) {

    ll a = -1, b = -1;
    vector<int> v;
    for (ll i = 2; i <= x; i++) {
        if (primes[i]) v.push_back(i);
    }
    ll sz = v.size();

    for (ll i = l; i <= u; i++) {

        ll j = 0;
        ll total = 1;

        ll temp = i;
        for (ll k = v[j]; k * k <= temp && j < sz; k = v[++j]) {
            int count = 0;

            while (temp % k == 0)
                count++, temp /= k;

            total *= (1 + count);

        }

        if (temp > 1)
            total *= 2;

        if (total > a)
            a = total, b = i;
    }

    return make_pair(a, b);

}