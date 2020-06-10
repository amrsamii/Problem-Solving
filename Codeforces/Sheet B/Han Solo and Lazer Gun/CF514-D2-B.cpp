#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int OO = 1e7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, gunx, guny;
    set<double> linesCnt;
    cin >> n >> gunx >> guny;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x - gunx == 0)
            linesCnt.insert(OO);
        else {
            double slope = (double)(y - guny) / (x - gunx);
            linesCnt.insert(slope);
        }
    }
    cout << linesCnt.size();
    return 0;
}
