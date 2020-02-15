#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char grid[105][105];
bool visited[105][105];
int n;
int dx[4] = {-1, 0, 0,1};
int dy[4] = {0, -1, 1,0};

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

void dfs(int i, int j) {
    if (visited[i][j])
        return;
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (!visited[x][y] && valid(x, y) && (grid[x][y] == 'x' || grid[x][y]=='@')) {
            dfs(x, y);
        }
    }

}

int main() {

    int t;
    cin >> t;
    for(int k=1;k<=t;k++) {
        int ans=0;
        memset(visited, 0, sizeof visited);
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> grid[i];

        for (int i = 0; i < n; i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == 'x' && !visited[i][j]){
                    ans++;
                    dfs(i,j);
                }

        cout<<"Case "<<k<<": "<<ans<<endl;
    }


}
