#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool grid[25][25];
int n,m;
bool isValid(int i,int j){ return i>0 && i<=n && j>0 && j<=m;}
int rr[] = {1,0,0,-1};
int cc[] = {0,1,-1,0};

int d[25][25];
int BFS(int rs,int cs,int& dr,int& dc){
    memset(d,-1,sizeof d);
    d[rs][cs] = 0;
    queue<pair<int,int>> q;
    q.push({rs,cs});
    int dep =0,sz=1;
    for(;!q.empty();dep++,sz = q.size()){
        while (sz--){
            int cur_row = q.front().first;
            int cur_col = q.front().second;
            q.pop();
            if(grid[cur_row][cur_col]) {
                dr = cur_row;
                dc = cur_col;
                return d[dr][dc];
            }
            for(int i=0;i<4;i++){
                int new_row = cur_row + rr[i];
                int new_col = cur_col + cc[i];
                if(isValid(new_row,new_col) && d[new_row][new_col] == -1){
                    q.push({new_row,new_col});
                    d[new_row][new_col] = dep+1;
                }
            }
        }
    }
    return 0;
}

int main() {

    // little faster reading, no c apis
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--){
        memset(grid,0,sizeof grid);
        cin>>n>>m;
        int sr,sc,k;
        cin>>sr>>sc>>k;
        int fr = sr,fc = sc;
        int ans = 0;
        for(int i=0;i<k;i++){
            int a,b;
            cin>>a>>b;
           grid[a][b] = true;
        }
        int dr,dc;
        for(int i=0;i<k;i++){
            ans += BFS(sr,sc,dr,dc);
            grid[dr][dc] = false;

            sr = dr,sc = dc;
        }
        grid[fr][fc] = true;
        ans += BFS(sr,sc,fr,fc);
        cout<<"The shortest path has length "<<ans<<endl;

    }

}


