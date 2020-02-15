#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool visited[1000005];
vector<vector<int>> grid;
vector<int> topsort;

void dfs(int node) {


    visited[node] = true;

    for (int child : grid[node]) {
        if (!visited[child])
            dfs(child);
    }
    topsort.push_back(node);

}

int main() {

    int n, k;
    cin >> n >> k;
    grid = vector<vector<int>>(n + 1);
    for (int i = 1; i <= k; i++) {
        int w, x;
        cin >> w;
        while (w--) {
            cin >> x;
            grid[i].push_back(x);
        }
    }

    memset(visited, 0, sizeof visited);
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);

    int pos = 0;
    vector<int> parent(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        int st = topsort[i];
        parent[st] = pos;
        pos = st;
    }

    for (int i = 1; i <= n; i++)
        cout << parent[i] << endl;
}


//toplogical sort, problem is to know the parent of each node so we loop from last element in topsort and give it position 0 as it will be the boss, then every step we make the new position the current student
