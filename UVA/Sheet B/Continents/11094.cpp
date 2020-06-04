#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int OO = 1e7;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int m, n;

bool valid(int r, int c) {
    return r >= 0 && r < m && c >= 0 && c < n;
}

vector<vector<char>> grid;
vector<vector<bool>> vis;
int cnt;

void connectedComponents(int sr, int sc, char land) {
    vis[sr][sc] = true;
    cnt++;

    for (int k = 0; k < 4; k++) {
        int nr = sr + dr[k];
        int nc = sc + dc[k];
        // wrap from end to start
        if (nc == n)
            nc = 0;
        // wrap from start to end
        else if (nc == -1)
            nc = n - 1;

        if (valid(nr, nc) && grid[nr][nc] == land && !vis[nr][nc]) {
            connectedComponents(nr, nc, land);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (cin >> m >> n) {
        grid = vector<vector<char>>(m, vector<char>(n));
        vis = vector<vector<bool>>(m, vector<bool>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];

        int x, y;
        cin >> x >> y;
        char land = grid[x][y];

        cnt = 0;
        // mark the continent of the king
        connectedComponents(x, y, land);

        // try all other possible continent and print the max one
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == land && !vis[i][j]) {
                    cnt = 0;
                    connectedComponents(i, j, land);
                    ans = max(ans, cnt);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
