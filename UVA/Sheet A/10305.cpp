#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool visited[105];
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
    int n,m;
	// exit when only n = 0, m can be zero
    while(cin>>n>>m && n) {
        memset(visited, 0, sizeof visited);
        topsort.clear();
        grid = vector<vector<int>>(n + 1);
        while(m--) {
            int i, j;
            cin >> i>>j;
            grid[j].push_back(i);
        }

        for(int i=1;i<=n;i++) if(!visited[i])
            dfs(i);

	// solve problem of last space
        for(int i=0,sz = topsort.size();i<sz;i++) {

            cout << topsort[i];
            if(i != sz-1)
                cout<<" ";
        }
        cout<<endl;

    }

}
