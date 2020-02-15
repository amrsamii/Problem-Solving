#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool valid(int i, int j) {
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

int dr[8] = {1, 2, 2, -1, 1, -1, -2, -2};
int dc[8] = {2, 1, -1, 2, -2, -2, 1, -1};

int d[8][8];

int bfs(int r1, int c1, int r2, int c2) {
    queue<int> rq;
    queue<int> cq;
    rq.push(r1);
    cq.push(c1);
    memset(d,-1,sizeof d);
    d[r1][c1] = 0;
    while (!rq.empty()) {
        int r = rq.front();
        rq.pop();
        int c = cq.front();
        cq.pop();
        if (r == r2 && c == c2) {
            return d[r][c];
        }
        for (int i = 0; i < 8; i++) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if (valid(rr, cc)) {
                if(d[rr][cc] == -1) {
                    rq.push(rr);
                    cq.push(cc);
                    d[rr][cc] = d[r][c] + 1;
                }
            }

        }


    }
    return -1;
}

int main() {

    string a, b;
    while (cin >> a >> b) {
        int c1 = a[0] - 'a';
        int r1 = a[1] - '1';
        int c2 = b[0] - 'a';
        int r2 = b[1] - '1';
        cout << "To get from " << a << " to " << b << " takes " << bfs(r1, c1, r2, c2)
             << " knight moves." << endl;
    }


}
