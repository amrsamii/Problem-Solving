#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {


    int n, m, c;

    while (cin >> n >> m >> c && n) {
        n -= 7, m -= 7;
        cout<<(n*m+c)/2<<endl;
    }

    return 0;
}