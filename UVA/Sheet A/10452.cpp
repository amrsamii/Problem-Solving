#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char grid[10][10];
bool visited[10][10];
vector<string> ans;
string path = "IEHOVA#";
int n, m;
int dx[3] = {-1, 0, 0};
int dy[3] = {0, -1, 1};
string order[3] = {"forth", "left", "right"};

bool valid(int i, int j) {
    return i >= 0 && i < m && j >= 0 && j < n;
}

void dfs(int i, int j, int index) {
    if (visited[i][j])
        return;
    visited[i][j] = true;

    for (int k = 0; k < 3; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (!visited[x][y] && valid(x, y) && grid[x][y] == path[index]) {
            ans.push_back(order[k]);
            dfs(x, y, index + 1);
        }
    }

}

int main() {

    int t;
    cin >> t;
    while (t--) {
        memset(visited, 0, sizeof visited);
        ans.clear();
        cin >> m >> n;
        for (int i = 0; i < m; i++)
            cin >> grid[i];

        for (int i = 0; i < n; i++)
            if (grid[m - 1][i] == '@')
                dfs(m - 1, i, 0);

        for (int i=0,sz = ans.size();i<sz;i++) {
            cout << ans[i];
            if(i != sz-1)
                cout<<" ";
        }

            cout << endl;
    }


}
