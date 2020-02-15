#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main() {

    int p, q, l, r;
    int v[1005]={0};
    cin >> p >> q >> l >> r;
    vector<pair<int, int>> z(p), x(q);
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        z[i] = {a, b};
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        x[i] = {a, b};
    }
    int ans = 0;
    for (auto cur_x : x) {
        for (auto cur_z : z) {
            int t_min = cur_z.first - cur_x.second;
            int t_max =cur_z.second - cur_x.first;
// if max < l, also min < l, so no numbers inside range, and so for min>r => continue the loop 
            if(t_max<l || t_min>r)
                continue;
// if min = -2 max = 2 but l = 1, we must start from min = 1 not -2, so we take max of min and l, and so for max and r we take min to not to go out of range
            for(int i=max(t_min,l) ;i<= min(r,t_max);i++){
                if(!v[i]){
                    ans++;
                    v[i] = 1;
                }
            }
        }
    }
    cout << ans;


}
