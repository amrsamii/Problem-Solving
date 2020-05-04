#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    // little faster reading, no c apis
    ios_base::sync_with_stdio(false);

    map<int, pair<int, int>> ans;
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    for (int i = 0; i < n; i++) {
        if (ans.count(numbers[i]) == 0)
            // 0 is ans, i is last known index
            ans[numbers[i]] = {0, i};
        else if (ans[numbers[i]].first == 0) {
            ans[numbers[i]] = {i - ans[numbers[i]].second, i};
        } else {
            int lastIdx = ans[numbers[i]].second;
            if (i - lastIdx == ans[numbers[i]].first)
                ans[numbers[i]].second = i;
            else
                ans[numbers[i]].first = -1;
        }
    }

    int sz = 0;
    for( auto i : ans){
        if (i.second.first != -1)
            sz ++;
    }
    cout << sz << endl;
    for (auto i : ans) {
        if (i.second.first != -1)
            cout << i.first << " " << i.second.first << endl;
    }
    return 0;
}