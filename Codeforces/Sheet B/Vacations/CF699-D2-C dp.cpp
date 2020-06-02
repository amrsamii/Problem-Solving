#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int OO = 1e6;

int dp[101][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> days(n);
    for (int i = 0; i < n; i++)
        cin >> days[i];

    // 0 is rest, 1 is contest, 2 is gym
    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for (int i = 1; i <= n; i++) {
        // Since you rested, you can get min of rest, contest, or gym of the day before
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1; // rest
        dp[i][1] = OO; // Initialize contest with infinity so if it isn't changed, it will never be min, so no two consecutive days will be the same
        dp[i][2] = OO;

        // Contest is valid, only get min of rest or gym of the day before
        if (days[i - 1] == 1 || days[i - 1] == 3) dp[i][1] = min({dp[i - 1][0], dp[i - 1][2]});

        // Gym is valid, only get min of rest or contest the day before
        if (days[i - 1] == 2 || days[i - 1] == 3) dp[i][2] = min({dp[i - 1][0], dp[i - 1][1]});
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]});
    return 0;
}
