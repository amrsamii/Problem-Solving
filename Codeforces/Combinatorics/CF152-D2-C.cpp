#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000007

char numbers[105][105];

int main() {

    int n, m;
    ll ans =1;
    bool alphabet[26];
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> numbers[i][j];


    for (int j = 0; j < m; j++) {
        memset(alphabet,0,sizeof alphabet);
        ll count = 0;
        for (int i = 0; i < n; i++) {
            if(!alphabet[numbers[i][j] -65])
                count ++, alphabet[numbers[i][j] -65] = true;
        }
        ans = (ans % MOD * count % MOD)%MOD;
    }
    cout<<ans;


    return 0;
}