#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ll> vll;

#define all(v) ((v).begin()),((v).end())








int main() {

    // freopen("input/input.txt", "r", stdin);
    //freopen("output/output.txt", "w", stdout);



    int t;
    int c1, c2;
    map<string, int> months;
    months["January"] = 1;
    months["February"] = 2;
    months["March"] = 3;
    months["April"] = 4;
    months["May"] = 5;
    months["June"] = 6;
    months["July"] = 7;
    months["August"] = 8;
    months["September"] = 9;
    months["October"] = 10;
    months["November"] = 11;
    months["December"] = 12;
    string m1, m2;
    int d1, d2;
    string d11, d22;
    int y1, y2;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> m1 >> d11 >> y1;
        cin >> m2 >> d22 >> y2;
        d11[d11.size() - 1] = '\0';
        d22[d22.size() - 1] = '\0';
        d1 = stoi(d11);
        d2 = stoi(d22);

        if (months[m1] < 2 || (months[m1] == 2 && d1 <= 29))
            c1 = (y1-1) / 4 - (y1 -1)/ 100 + (y1 -1)/ 400;

        else
            c1 = y1 / 4 - y1 / 100 + y1 / 400;

        if(months[m2] > 2 || (months[m2] == 2 && d2== 29))
            c2 = y2 / 4 - y2 / 100 + y2 / 400;
        else
            c2 = (y2-1) / 4 - (y2 -1)/ 100 + (y2 -1)/ 400;




        cout << "Case " << i << ": " << c2-c1 << endl;

    }

    return 0;
}