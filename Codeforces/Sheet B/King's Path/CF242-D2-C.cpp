#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int drow[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dcol[8] = {0, 0, 1, -1, -1, 1, -1, 1};
//use set to remove reduntant nodes
set<pair<int,int>> pts;


int BFS(int sc, int sr, int dr, int dc) {
// 2 queues get MLE, use one queue and use for loop for depth
    map<pair<int, int>,int> len;
    queue<pair<int,int>> q;
    q.push({sr,sc});
    int dep = 0,sz=1;
    for(;!q.empty();dep++,sz = q.size()){
    while (sz--) {
        int curr_row = q.front().first;
        int curr_col = q.front().second;
        q.pop();

        if (curr_col == dc && curr_row == dr)
            return len[{dr,dc}];

        for (int i = 0; i < 8; i++) {
            int new_row = curr_row + drow[i];
            int new_col = curr_col + dcol[i];
            pair<int,int> new_pt = {new_row,new_col};
// check if the new pt is inside the graph (no need for is_valid because this handles it), also check if len =0, i.e we did not visit it before
            if (pts.count(new_pt) != 0 && len.count(new_pt) == 0) {
                q.push(new_pt);
                len[new_pt] = dep+1;
            }
        }
    }

    }
    return -1;
}


int main() {

    // little faster reading, no c apis
    ios_base::sync_with_stdio(false);
    int n, sr, sc, dr, dc;
    cin >> sr >> sc >> dr >> dc >> n;
    while (n--) {
        int r, a, b;
        cin >> r >> a >> b;
        // graph generation
        for (int i = a; i <= b; i++)
            pts.insert({r,i});
    }
    cout << BFS(sc, sr, dr, dc);

}
