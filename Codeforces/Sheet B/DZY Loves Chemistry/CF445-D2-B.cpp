#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int OO = 1e7;
const int neg_OO = -1e7;

#define lp(i, n) for(int i=0;i<n;i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))

vector<vector<int>> graph;
bool vis[50];
ll cnt = 1;

void dfs(int node) {
    vis[node] = true;

    for (auto child : graph[node]) {
        if (!vis[child]) {
            cnt *= 2;
            dfs(child);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    graph = vector<vector<int>>(n);

    while (m--) {
        int a, b;
        cin >> a >> b;

        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    lp(i, n) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    cout << cnt;
    return 0;
}
