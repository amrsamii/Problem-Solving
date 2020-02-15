#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll n, l;
vector<double> lanterns;

bool F(double d) {

    for (ll i = 0; i < n; i++) {
        if (i == 0) {
            if (lanterns[0] != 0 ) {
                if (lanterns[0] >d)
                    return false;
            }else{
                if (lanterns[1] - lanterns[0] > 2 * d)
                    return false;
            }
        } else if (i == n-1){
            if(lanterns[i] != l){
                if(lanterns[i]+d < l)
                    return false;
            }
        }
        else {
            if(lanterns[i + 1] - lanterns[i] > 2 * d)
                return false;
        }
    }


    return true;

}

double BS() {
    double min = 0, max = 1e9;
    for (ll i = 0; i < 1000; i++) {
        double mid = min + (max - min) / 2;
        bool can = F(mid);
        if (can)
            max = mid;
        else
            min = mid;

    }
    return min;
}

int main() {

    cin >> n >> l;
    lanterns = vector<double>(n);
    for (ll i = 0; i < n; i++)
        cin >> lanterns[i];
    sort(lanterns.begin(), lanterns.end());
    if(lanterns.size() == 1)
        return cout<<fixed << setprecision(9)<<max(l-lanterns[0],lanterns[0]-0),0;
    cout << fixed << setprecision(9) << BS();
}

