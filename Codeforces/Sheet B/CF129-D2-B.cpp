#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


int main() {

    int n, m, a, b;
    cin >> n >> m;
    vector<pair<int, int>> ties;
    vector<int> tied(n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        tied[a]++, tied[b]++;
        ties.emplace_back(a, b);
        ties.emplace_back(b, a);

    }
    int ans = 0;
    while (find(tied.begin(), tied.end(), 1) != tied.end()) {

        map<int, int> index_to_be_dec;


        for (int i = 1; i <= n; i++) {
            if (tied[i] == 1) {
                tied[i]--;

                for (auto it = ties.begin(); it != ties.end(); it++) {
                    if (it->first == i) {
                        index_to_be_dec[it->second]++;
                        pair<int, int> sec = {it->second, it->first};
                        ties.erase(it);
                        auto itt = find(ties.begin(), ties.end(), sec);
                        if (itt != ties.end())
                            ties.erase(itt);
                        break;
                    }
                }
            }
        }
        for (auto i: index_to_be_dec)
            tied[i.first] -= i.second;
        ans++;
    }
    cout << ans;

    return 0;
}

