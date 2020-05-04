#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    int sum = 0, mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (k > 0 && numbers[i] < 0) {
            numbers[i] = -numbers[i];
            k--;
        }
        mini = min(mini, numbers[i]);
        sum += numbers[i];
    }

    if (k % 2) {
        sum -= 2 * mini;
    }

    cout << sum;

    return 0;
}