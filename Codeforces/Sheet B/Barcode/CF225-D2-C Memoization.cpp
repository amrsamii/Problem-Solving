#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int OO = 1e7;

int n, m, x, y;
// n - cols[i] = # of hashes
// cols[i] = # of dots
vector<int> cols;

/*
 * blackOrWhite
 * 0 -> white
 * 1 -> black
 * 2 -> nothing before (first column)
 */
int mem[1000][1000][3];

int minPaint(int col, int width, int blackOrWhite) {
    if (col == m) {
        // done and correct
        if (width >= x && width <= y)
            return 0;
        // invalid case, return INF to make sure min() will not take the ans of this invalid path, i.e. invalidate invalid state
        return OO;
    }
    int &ret = mem[col][width][blackOrWhite];
    if (ret != -1)
        return ret;

    ret = OO;

    // Try to change all to white
    // nothing before or old block is valid or bigger block is allowed
    if (!col || (blackOrWhite && width >= x && width <= y) || (!blackOrWhite && width < y))
        ret = min(ret, n - cols[col] + minPaint(col + 1, blackOrWhite ? 1 : width + 1, 0));

    // Try to change all to black
    // nothing before or bigger block is allowed or old block is valid
    if (!col || (blackOrWhite && width < y) || (!blackOrWhite && width >= x && width <= y))
        ret = min(ret, cols[col] + minPaint(col + 1, blackOrWhite ? width + 1 : 1, 1));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> x >> y;
    // store dots count
    cols = vector<int>(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            if (a == '.')
                cols[j]++;
        }
    }
    memset(mem, -1, sizeof mem);
    cout << minPaint(0, 0, 2);
    return 0;
}
