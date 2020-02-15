#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool valid(int i, int j) {
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

int dr[8] = {1, 2, 2, -1, 1, -1, -2, -2};
int dc[8] = {2, 1, -1, 2, -2, -2, 1, -1};

bool visited[8][8];

int bfs(int r1, int c1, int r2, int c2) {
    queue<int> rq;
    queue<int> cq;
    rq.push(r1);
    cq.push(c1);
    visited[r1][c1] = true;
    int knight_move = 0;
    int sz = 1;
    int no_next_level = 0;
    while (!rq.empty()) {
        int r = rq.front();
        rq.pop();
        int c = cq.front();
        cq.pop();
        sz--;
        if (r == r2 && c == c2) {
            break;
        }
        for (int i = 0; i < 8; i++) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if (!visited[rr][cc] && valid(rr, cc)) {
                rq.push(rr);
                cq.push(cc);
                visited[rr][cc] = true;
                no_next_level++;
            }

        }
        if(sz == 0){
            sz = no_next_level;
            no_next_level = 0;
            knight_move++;
        }

    }
    return knight_move;
}

int main() {

    string a, b;
    while (cin >> a >> b) {
        memset(visited, 0, sizeof visited);
        int c1 = a[0] - 'a';
        int r1 = a[1] - '1';
        int c2 = b[0] - 'a';
        int r2 = b[1] - '1';
        cout << "To get from " << a << " to " << b << " takes " << bfs(r1, c1, r2, c2)
             << " knight moves." << endl;
    }


}
