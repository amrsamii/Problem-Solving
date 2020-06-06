#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int OO = 1e7;

vector<int> wantedSeq;
int m;
int bad = false;

int Hanoi(int n, int from, int to, int use) {
    if (n == 0)
        return 0;
    // the biggest disk is still in the start peg, only try to move all disks above it to the auxiliary peg till
    // you find the wanted sequence
    if (wantedSeq[n - 1] == from)
        return Hanoi(n - 1, from, use, to);

        // the biggest disk is in the dest peg, add half of moves and move only the disks from the auxiliary peg to
        // des peg
    else if (wantedSeq[n - 1] == to)
        return (1 << (n - 1)) + Hanoi(n - 1, use, to, from);

    // invalid sequence
    return bad = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m;
    wantedSeq = vector<int>(m);

    for (int i = 0; i < m; i++)
        cin >> wantedSeq[i];

    int res = Hanoi(m, 1, 2, 3);

    cout << (bad ? -1 : res);

    return 0;
}
