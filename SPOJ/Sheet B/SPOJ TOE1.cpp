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

string BFS(const string &dest) {
    string src = ".........";
//1- how to store player's turn => in the queue, use pair
    queue<pair<string,bool>> q;
    q.push({src,true});
    while (!q.empty()) {
        string cur = q.front().first;
        bool x_turn = q.front().second;
        q.pop();
        if (cur == dest)
            return "yes";
//2- when to check that player wins, after popping from queue
        if(is_win(cur))
            continue;
        for (int i = 0; i < 9; i++) {
            if (cur[i] == '.') {
                cur[i] = x_turn ? 'X' : 'O';
//3- after making the change, if cur[i] == dest[i], push in queue, otherwise, do not waste time!
                if(cur[i] == dest[i])
                    q.push({cur,!x_turn});
                cur[i] = '.';
            }

        }

    }
    return "no";
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        string grid, x;
        for (int i = 0; i < 3; i++) {
            cin >> x;
            grid += x;
        }
        cout << BFS(grid) << endl;

    }
}
//4- BFS to reach your destination in shortest path
