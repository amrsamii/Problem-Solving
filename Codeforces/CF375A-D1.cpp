#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    string m = "";
    string k = "1689";
    string z = "";
    int flag[4] = {0};

    int zeros = 0, ans = 0;
    cin >> s;
    for (char i : s) {

        if (i == '0')
            zeros++;
        else if (i == '1' && !flag[0])
            flag[0] = 1;
        else if (i == '6' && !flag[1])
            flag[1] = 1;
        else if (i == '8' && !flag[2])
            flag[2] = 1;
        else if (i == '9' && !flag[3])
            flag[3] = 1;
        else
            m += i, ans *= 10, ans += i - '0', ans %= 7;
    }
    ans *= 10000;
    ans %= 7;

    for (int i = 0; i < zeros; i++)
        z += '0';

    string arr[7];
    do {
        arr[stoi(k) % 7] = k;

    } while (next_permutation(k.begin(), k.end()));
    m += arr[(7 - ans)%7];

    cout << m << z;

    return 0;
}