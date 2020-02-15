#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


int main() {

    ll n, a, m;
    cin >> n >> m >> a;

    cout << ((n + a - 1) / a) * ((m + a - 1) / a);


    return 0;
}



take care of overflow of multiplication
طالما مقالش mod حاجة يبقى اكيد الضرب هيكون فى حدود ال long long لان a ب 10^9 فاكيد الضرب هيعدى ال int فنخليهم كلهم long long عشان الضرب يطلع long long
