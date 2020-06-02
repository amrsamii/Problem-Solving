#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> days;
int mem[100][4];

int minRest(int idx, int prevDayActivity) {
    if (idx == n)
        return 0;

    int &ret = mem[idx][prevDayActivity];

    if (ret != -1)
        return ret;

    ret = 1 + minRest(idx + 1, 0); // rest

    if (days[idx] == 0)
        return ret;

    if (prevDayActivity != 1 && days[idx] != 2)
        ret = min(ret, minRest(idx + 1, 1)); // contest

    if (prevDayActivity != 2 && days[idx] != 1)
        ret = min(ret, minRest(idx + 1, 2)); // gym

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    days = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> days[i];

    memset(mem, -1, sizeof mem);

    cout << minRest(0, 3);
    return 0;
}
