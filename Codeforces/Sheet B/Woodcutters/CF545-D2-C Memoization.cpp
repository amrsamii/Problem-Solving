#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int OO = 1e6;

int n;
vector<pair<int, int>> trees;
int mem[100000][4];

/*
 * stateOfPreviousTree
 * 3, no previous tree
 * 0, didn't fall
 * 1, fell right
 * 2, fell left
 */
int maxFallenTrees(int i, int stateOfPreviousTree) {
    if (i == n)
        return 0;

    int &ret = mem[i][stateOfPreviousTree];

    if (ret != -1)
        return ret;

    // if previous tree has not fallen to the right, i.e. it might fall to left or not fall at all
    if (stateOfPreviousTree != 1) {
        // Try fall left if you could, the previous tree point is its x
        if (i == 0 || trees[i].first - trees[i].second > trees[i - 1].first)
            ret = max(ret, 1 + maxFallenTrees(i + 1, 2));
    } else { // if previous tree has fallen to the right
        // Try fall left if you could, the previous tree point is its x + h
        if (trees[i].first - trees[i].second > trees[i - 1].first + trees[i - 1].second)
            ret = max(ret, 1 + maxFallenTrees(i + 1, 2));
    }

    // Try fall Right if you could, it has nothing to do with the previous tree state, only check if the next one
    // is valid to fall right
    if (i == n - 1 || trees[i].first + trees[i].second < trees[i + 1].first)
        ret = max(ret, 1 + maxFallenTrees(i + 1, 1));

    // Try not to fall
    ret = max(ret, maxFallenTrees(i + 1, 0));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    trees = vector<pair<int, int>>(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        trees[i] = {a, b};
    }
    memset(mem, -1, sizeof mem);

    cout << maxFallenTrees(0, 3);
    return 0;
}
