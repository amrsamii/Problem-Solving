#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_win(const string &grid) {
    bool horiz = (grid[0] != '.' && grid[1] != '.' && grid[2] != '.' && grid[0] == grid[1] && grid[1] == grid[2]) ||
                 (grid[3] != '.' && grid[4] != '.' && grid[5] != '.' && grid[3] == grid[4] && grid[4] == grid[5]) ||
                 (grid[6] != '.' && grid[7] != '.' && grid[8] != '.' && grid[6] == grid[7] && grid[7] == grid[8]);

    bool ver = (grid[0] != '.' && grid[3] != '.' && grid[6] != '.' && grid[0] == grid[3] && grid[3] == grid[6]) ||
               (grid[1] != '.' && grid[4] != '.' && grid[7] != '.' && grid[1] == grid[4] && grid[4] == grid[7]) ||
               (grid[2] != '.' && grid[5] != '.' && grid[8] != '.' && grid[2] == grid[5] && grid[5] == grid[8]);

    bool diag = (grid[0] != '.' && grid[4] != '.' && grid[8] != '.' && grid[0] == grid[4] && grid[4] == grid[8])||
                (grid[2] != '.' && grid[4] != '.' && grid[6] != '.' && grid[2] == grid[4] && grid[4] == grid[6]);

    return horiz || ver || diag;
}
bool ended(string grid){
    return count(grid.begin(), grid.end(), '.') == 0;
}

string BFS(const string &dest) {
    string src = ".........";
    queue<pair<string,bool>> q;
    q.push({src,true});
    while (!q.empty()) {
        string cur = q.front().first;
        bool x_turn = q.front().second;
        q.pop();
        bool win = is_win(cur);
        if (cur == dest && (win|| ended(cur)))
            return "valid";

        if(win)
            continue;
        for (int i = 0; i < 9; i++) {
            if (cur[i] == '.') {
                cur[i] = x_turn ? 'X' : 'O';
                if(cur[i] == dest[i])
                    q.push({cur,!x_turn});
                cur[i] = '.';
            }

        }

    }
    return "invalid";
}

int main() {

    string s;
    while(cin>>s && s!= "end"){
        cout<<BFS(s)<<endl;
    }
}
