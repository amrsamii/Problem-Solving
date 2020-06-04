#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int OO = 1e7;

struct Point {
    ll x;
    ll y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    while (cin >> n && n) {
        vector<Point> points(n);

        for (int i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;

            points[i].x = a;
            points[i].y = b;
        }
        Point halfPoint = points[n / 2];
        int s = 0, o = 0;

        for (auto point : points) {
            ll dx = point.x - halfPoint.x;
            ll dy = point.y - halfPoint.y;

            // point lies on either vertical or horizontal line
            if (dx == 0 || dy == 0)
                continue;

            // point is in Top Right or Bottom Left
            if (dx * dy > 0)
                s++;
                // point is in Top Left or Bottom Right
            else
                o++;
        }

        cout << s << " " << o << endl;

    }
    return 0;
}
