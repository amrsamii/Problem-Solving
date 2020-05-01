#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {

    // little faster reading, no c apis
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> numbers(n);
    bool can = true;
    for (int i = 0; i < n; i++) {
        int g = -1, s = -1;
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == 'G')
                g = j;
            else if (ch == 'S') {
                if (g == -1)
                    can = false;
                else
                    s = j;

            }

        }
        numbers[i] = s - g;
    }
    if (!can)
        cout << -1;
    else {
        int ans = 0;
        sort(numbers.begin(), numbers.end());
        while (!numbers.empty()) {
            ans++;
            int minus = numbers[0];
            for (int &number : numbers) {
                number -= minus;
            }
            numbers.erase(remove(numbers.begin(), numbers.end(), 0), numbers.end());
        }
        cout << ans;
    }
}
