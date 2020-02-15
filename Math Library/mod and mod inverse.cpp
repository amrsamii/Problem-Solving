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

// this is better
ll bigmod(ll b, ll p, ll m) {

    if (p == 0)
        return 1;

    ll value = bigmod(b, p / 2, m);
    value = (value * value) % m;
    if (p % 2)
        value = (value * b % m) % m;
    return value;
}


bool isLeap(int y) {

    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}


ll modInversep(ll a, ll p) {
    if (__gcd(a, p) > 1)
        return -1;
    return bigmod(a, p - 2, p);
}


// solve the equation ax = b (mod n)
vector<ll> modularEquation(ll a, ll b, ll n) {
    vector<ll> sols;

    ll x, y, g;
    g = extended_eculid(a, n, x, y);
    if (b % g != 0)
        return sols; // no solutions


    x = ((x * b / g) % n + n) % n;  // from LDE, +ve mod

    for (int i = 0; i < g; i++)
        sols.push_back((x + i * n / g) % n);

    sort(sols.begin(), sols.end());

    return sols;

}



// ax == 1 % m IFF a,m coprimes
// return -1 means no answer
// handle case x may be -ve
ll modInversek(ll a, ll m) {
    ll x, y;
    ll g = extended_eculid(a, m, x, y);
    if (g != 1)
        return -1;

    return (x + m) % m;
}




// phi[n]

const int MAX = 1000000;

int phi[MAX];

void phi_generator() {


    char primes[MAX];
    memset(primes, 1, sizeof primes);

    for (int &k : phi)
        k = 1;

    for (int i = 2; i <= MAX; i++) {
        if (primes[i]) {
            phi[i] = i - 1;
            for (int j = i * 2; j <= MAX; j += i) {
                primes[j] = 0;
                int n = j, pow = 1;
                while (!(n % i))
                    pow *= i, n /= i;
                phi[j] *= (pow / i) * (i - 1);
            }
        }
    }
}


//phi(n!)

ll phi_factn(int n) {
    ll ret = 1;
    for (int i = 2; i <= n; i++)
        ret = ret * (isPrime(i) ? i - 1 : i);

    return ret;
}



// phi[n!] range
const int maxn = 1e7;

ll phi_fact[maxn + 5];
int prime[maxn + 5]; // range + 1 to include last number in range

void phi_fact_range() {

    memset(phi_fact, 0, sizeof phi_fact);
    phi_fact[1] = phi_fact[2] = 1;

    for (int i = 3; i <= maxn; i++) {
        if (prime[i])
            phi_fact[i] = ((i - 1) * phi_fact[i - 1]); //% MOD;
        else
            phi_fact[i] = (i * phi_fact[i - 1]);// % MOD;

    }
}



ll a_to_x(ll a, ll x, ll n) {

    map<ll, ll> factors = factorization(a);
    ll ans = 1;
    ll g = 0, t;
    ll p_to_x;
    for (auto &factor : factors) {
        t = n;
        g = 0;
        while (t % factor.first == 0) {
            g++;
            t /= factor.first;
        }
        p_to_x = ((ll) pow(factor.first, g) % n * bigmod(factor.first, (x - g) % phi[t], n) % n) % n;
        ans = (ans * bigmod((p_to_x % n), factor.second, n)) % n;
    }

    return ans;
}


void factorial() {
    fact[0] = fact[1] = 1;

    for (int i = 2; i <= maxn; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}


ll powerTower(vector<ll> & numbers, ll mod, int idx = 0){
    if(idx == numbers.size()-1){
        return (numbers[idx] % mod);
    }
  //  if(gcd(numbers[idx],mod) == 1) {
        ll phi = phi_n(mod);
        ll power = powerTower(numbers, phi, idx + 1) + phi;
        return bigmod(numbers[idx],power,mod);
}





// phi(n)
ll phi_n(ll n){

    ll p_to_k,relative_primes = 1;
    for(ll i=2,d=1;i*i<=n;i+=d,d=2){
        if(!(n%i)){
            p_to_k =1 ;
            while(!(n%i))
                p_to_k *=i,n/=i;
            relative_primes *=(p_to_k/i)*(i-1);
        }
    }
    if(n>1)
        relative_primes *=(n-1);
    return relative_primes;
}


// -------------power tower problem---------------------------------------------------------------//

ll newmod(ll a, ll b) {
    return a <= b ? a : b + a % b;
}

ll poww(ll a, ll b, ll cap) {
    if (b == 0) return 1;
    if (b&1) return newmod(poww(a, b - 1, cap) * a, cap);
    return newmod(poww(a, b / 2, cap) * poww(a, b / 2, cap), cap);
}

ll len(ll curr, ll n) {
    ll l = 0;
    for (ll i = 1; i <= 100000000; i *= 10) {
        if (curr >= i - (i % 10)) l++;
        else break;
    }
    return n - l;
}

ll solve2(ll base, ll iter, ll mod) {
    if (iter == 0) return 1;
    ll a2 = solve2(base, iter - 1, phi(mod));
    return poww(base, a2, mod);
}

ll solve(ll base, ll iter, ll n) {
    ll cap = 1;
    for (int i = 1; i <= n; i++) {
        cap *= 10;
    }
    return solve2(base, iter, 10000000LL) % cap;
}

ll curr = solve(b, i, n);
        int l = len(curr, n);
        for (int i = 1; i <= l; i++) {
            cout << 0;
        }






// LCM problem
ll phi[n + 2], ans[n + 2]; 
  
// Euler totient Function 
void ETF() 
{ 
    for (int i = 1; i <= n; i++) { 
        phi[i] = i; 
    } 
  
    for (int i = 2; i <= n; i++) { 
        if (phi[i] == i) { 
            phi[i] = i - 1; 
            for (int j = 2 * i; j <= n; j += i) { 
                phi[j] = (phi[j] * (i - 1)) / i; 
            } 
        } 
    } 
} 
  
// Function to return the required LCM sum 
ll LcmSum(int m) 
{ 
    ETF(); 
  
    for (int i = 1; i <= n; i++) { 
  
        // Summation of d * ETF(d) where 
        // d belongs to set of divisors of n 
        for (int j = i; j <= n; j += i) { 
            ans[j] += (i * phi[i]); 
        } 
    } 
  
    ll answer = ans[m]; 
    answer = (answer + 1) * m; 
    answer = answer / 2; 
    return answer; 
} 







// GCD problem

 
#define MAX 100001 
  
// phi[i] stores euler totient function for i 
// result[j] stores result for value j 
long long phi[MAX], result[MAX]; 
  
// Precomputation of phi[] numbers. Refer below link 
// for details : https://goo.gl/LUqdtY 
void computeTotient() 
{ 
    // Refer https://goo.gl/LUqdtY 
    phi[1] = 1; 
    for (int i=2; i<MAX; i++) 
    { 
        if (!phi[i]) 
        { 
            phi[i] = i-1; 
            for (int j = (i<<1); j<MAX; j+=i) 
            { 
                if (!phi[j]) 
                    phi[j] = j; 
  
                phi[j] = (phi[j]/i)*(i-1); 
            } 
        } 
    } 
} 
  
// Precomputes result for all numbers till MAX 
void sumOfGcdPairs() 
{ 
    // Precompute all phi value 
    computeTotient(); 
  
    for (int i=1; i<MAX; ++i) 
    { 
        // Iterate throght all the divisors 
        // of i. 
        for (int j=2; i*j<MAX; ++j) 
            result[i*j] += i*phi[j]; 
    } 
  
    // Add summation of previous calculated sum 
    for (int i=2; i<MAX; i++) 
        result[i] += result[i-1]; 
} 