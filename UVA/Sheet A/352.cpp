#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char grid[30][30];
bool visited[30][30];
int n;
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,-1,1};
bool valid(int i,int j){
    return i>=0 && i<n && j>=0 && j<n;
}

void dfs(int i, int j){
    if(visited[i][j] || !valid(i,j) || grid[i][j] != '1')
        return ;    
    visited[i][j] = true;

    for(int k=0;k<8;k++)
        dfs(i+dx[k],j+dy[k]);

}
int main() {

  int t = 1;
  while(cin>>n){
      memset(visited,0,sizeof visited);
      int ans = 0;
      for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
              cin>>grid[i][j];
      for(int i=0;i<n;i++)
          for(int j=0;j<n;j++){
              if(grid[i][j] == '1' && !visited[i][j]){
                  dfs(i,j);
                  ans++;
              }
          }

      cout<<"Image number "<<t++<<" contains "<<ans<<" war eagles."<<endl;
  }


}
