#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {

    int m, x, y;
    cin >> m;
    vector<int> numbers(m);
    for (int i = 0; i < m; i++)
        cin >> numbers[i];

    cin >> x >> y;
    for (int ans = 1; ans <= m; ans++) {
        int small = accumulate(numbers.begin(), numbers.begin() + ans - 1, 0);
        int large = accumulate(numbers.begin() + ans - 1, numbers.end(), 0);
        if (small >= x && small <= y && large >= x && large <= y)
            return printf("%d", ans), 0;
    }

    printf("0");
    return 0;
}