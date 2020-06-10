#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi ;

const int OO = INT_MAX;
const int neg_OO = INT_MIN;

#define lp(i, n) for(int i=0;i<n;i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);

    lp(i, n) cin >> arr[i];

    sort(all(arr));

    int ans = OO;

    lp(i, n) {
        int removed = i + (arr.end() - upper_bound(all(arr), arr[i] * 2));

        ans = min(ans, removed);
    }
    cout << ans;

    return 0;
}
