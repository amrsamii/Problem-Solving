#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int v, e;
vector<vector<int>> graph;
vector<vector<int>> graph2;
vector<int> days;
bool vis[600];



int BFS1(int node) {

    int tot = 0;
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while (!q.empty()) {
        int cur_node = q.front();
        q.pop();
        for (auto child : graph[cur_node]) {
            if (!vis[child]) {
                vis[child] = true;
                q.push(child);
                tot += days[child];
            }
        }
    }
    return tot;
}

int BFS2(int node) {

    int tot = 0;
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while (!q.empty()) {
        int cur_node = q.front();
        q.pop();
        for (auto child : graph2[cur_node]) {
            if (!vis[child]) {
                vis[child] = true;
                q.push(child);
            }
        }
    }
    for(int i=0;i<v;i++){
        if(!vis[i])
            tot += days[i];
    }
    return tot;
}

int main() {


    int q, t = 1;
    while (scanf("%d %d",&v,&e) == 2 && v) {
        days = vector<int>(v);
        graph = vector<vector<int>>(v);
        graph2 = vector<vector<int>>(v);
        for (int i = 0; i < v; i++)
            scanf("%d",&days[i]);
        for (int i = 0; i < e; i++) {
            int a, b;
            scanf("%d %d",&a,&b);
            a--, b--;
            graph[a].push_back(b);
            graph2[b].push_back(a);
        }

        scanf("%d",&q);
        printf("Case #%d:\n",t++);
        while (q--) {
            int x;
            cin >> x;
            x--;

            memset(vis,false,sizeof vis);
            int minn = BFS1(x);
            memset(vis,false,sizeof vis);
            int maxx = BFS2(x);
            printf("%d\n",maxx-minn);
        }
        printf("\n");
    }

}
