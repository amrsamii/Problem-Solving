#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {

    // little faster reading, no c apis
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    set<int> numbers;
    bool can = true;
    for (int i = 0; i < n; i++) {
        int g = -1, s = -1;
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == 'G')
                g = j;
            else if (ch == 'S') {
                if (g == -1)
                    can = false;
                else
                    s = j;

            }

        }
        numbers.insert(s - g);
    }
    if (!can)
        cout << -1;
    else {
        cout << numbers.size();
    }
}

// we have 1 2 3 4 5 numbers, to count the number of steps to make all numbers = 0, it is simply 5 because we first make 1 => 0 and then 2 and so on
// if we have 2 2 3 4 5, it is 4 not 5 because 2 is repeated so it will be 0 in one step, no repeating means set
// push our numbers in set and the ans is size of set
