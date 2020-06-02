#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int OO = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> trees(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        trees[i] = {a, b};
    }
    int dp[n + 1][3];
    /*
     * stateOfPreviousTree
     * 0, didn't fall
     * 1, fell right
     * 2, fell left
     */
    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for (int i = 1; i <= n; i++) {
        // Try not to fall
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = -1;
        dp[i][2] = -1;

        // Try fall left if you could
        if (i - 1 == 0) {
            dp[i][2] = 1;
        } else {
            // check if you can fall tree left in case of the previous tree has fallen either left or didn't fall(take only
            // dp[i-1][0] and dp[i-1][2])
            if (trees[i - 1].first - trees[i - 1].second > trees[i - 2].first)
                dp[i][2] = max(dp[i][2], 1 + max(dp[i - 1][0], dp[i - 1][2]));

            // check if you can fall tree left in case of the previous tree has fallen right(take only dp[i-1][1]
            if (trees[i - 1].first - trees[i - 1].second > trees[i - 2].first + trees[i - 2].second)
                dp[i][2] = max(dp[i][2], 1 + dp[i - 1][1]);
        }

        // Try fall Right if you could
        if (i - 1 == n - 1 || trees[i - 1].first + trees[i - 1].second < trees[i].first)
            dp[i][1] = 1 + dp[i][0];
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]});
    return 0;
}
