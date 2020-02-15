#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ed ;


void rec(int x, int no, int &ans, int idx = 1) {
    if (idx == ed) {
        if (no + 1 == x || no - 1 == x)
            ans++;
        return;
    }
    rec(x, no + 1, ans, idx + 1);
    rec(x, no - 1, ans, idx + 1);
}

int power(int b,int p){
    if(p == 0)
        return 1;
    int val = power(b,p/2);
     val = val*val;
    if(p % 2)
        val *= b;
    return val;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int no_plus_s1 = count(s1.begin(), s1.end(), '+');
    int no_minus_s1 = (int) s1.length() - no_plus_s1;
    int corr = no_plus_s1 - no_minus_s1;

    int no_plus_s2 = count(s2.begin(), s2.end(), '+');
    int no_minus_s2 = count(s2.begin(), s2.end(), '-');
    int no_unrec = (int) s2.length() - no_plus_s2 - no_minus_s2;
    int no_s2 = no_plus_s2 - no_minus_s2;

    if (no_unrec == 0) {
        if (corr == no_s2)
            cout << fixed << setprecision(9) << 1.0;
        else
            cout << fixed << setprecision(9) << 0.0;

    } else {
        int want = corr - no_s2;
        int count_corr = 0;
        ed = no_unrec;
        rec(want, 0, count_corr);
        cout << fixed << setprecision(9) << (double)count_corr/power(2,no_unrec);

    }




}
