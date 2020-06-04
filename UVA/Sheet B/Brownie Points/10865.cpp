#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int OO = 1e7;

struct Point {
    int x;
    int y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    while (cin >> n && n) {
        vector<Point> points(n);

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            points[i].x = a;
            points[i].y = b;
        }
        Point halfPoint = points[n / 2];
        int s = 0, o = 0;

        for (auto point : points) {
            if ((point.x > halfPoint.x && point.y > halfPoint.y) || (point.x < halfPoint.x && point.y < halfPoint.y))
                s++;
            else if ((point.x > halfPoint.x && point.y < halfPoint.y) ||
                     (point.x < halfPoint.x && point.y > halfPoint.y))
                o++;
        }

        cout << s << " " << o << endl;

    }
    return 0;
}
