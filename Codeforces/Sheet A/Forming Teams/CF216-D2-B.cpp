#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool visited[105];
vector<vector<int>> grid;
typedef enum {
    CYCLE, PATH
} status;

status dfs(int cur_node, int par_node, int &nodes_cnt) {

    if (visited[cur_node])
        return CYCLE;

    visited[cur_node] = true;

    for (int child : grid[cur_node]) {
        if (child != par_node) {
            nodes_cnt++;
            if (dfs(child, cur_node, nodes_cnt) == CYCLE)
                return CYCLE;
        }
    }
    return PATH;

}

int main() {

    int n, m;
    int to_remove = 0;
    cin >> n >> m;
    grid = vector<vector<int>>(n);
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        grid[a - 1].push_back(b - 1);
        grid[b-1].push_back(a-1);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int nodes_cnt = 0;
            if (dfs(i, -1, nodes_cnt) == CYCLE) {
                if (nodes_cnt % 2 == 1)
                    to_remove++;
            }
        }
    }
    if ((n - to_remove) % 2 == 1)
        to_remove++;
    cout << to_remove;


}
