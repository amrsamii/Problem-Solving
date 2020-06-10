#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int OO = 1e7;
const int neg_OO = -1e7;

#define lp(i, n) for(int i=0;i<n;i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))

bool vis[100000];

int bfs(int s, int d) {
    queue<int> q;
    q.push(s);

    int dp = 0;
    int sz = 1;
    for (; !q.empty(); sz = q.size(), dp++) {
        while (sz--) {
            int current_node = q.front();
            q.pop();
            if (current_node == d)
                return dp;

            vis[current_node] = true;

            if (current_node - 1 > 0 && !vis[current_node - 1])
                q.push(current_node - 1);

            if (current_node < d && !vis[current_node * 2])
                q.push(current_node * 2);
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;

    cin >> n >> m;

    cout << bfs(n, m);
    return 0;
}
