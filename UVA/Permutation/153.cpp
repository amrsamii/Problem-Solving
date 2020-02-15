#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll gcd(ll a, ll b) {

    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll getIndex(string s) {
    int n = s.size();
    ll ans = 0;
    int cnt[26] = {0};
    for (char c : s) {
        cnt[c - 'a']++;
    }
    int i, j, k, l,a;
    for ( i=0;i<n;i++) {
        for (j = 0; j < s[i] - 'a'; j++) {
            if (cnt[j] == 0) continue;
            cnt[j]--;
            int set[40];
            for(k=2;k<n-i;k++)
                set[k] = k;
            for(k = 0; k<26;k++){
                for(l = 2; l <= cnt[k];l++){
                    int temp = l;
                    for(a=2;a<n-i;a++){
                        int g = gcd(set[a],temp);
                        temp /= g;
                        set[a] /= g;
                    }
                }
            }

            ll temp = 1;
            for(k = 2;k<n-i;k++)
                temp *= set[k];
            ans += temp;
            cnt[j]++;

        }
        cnt[s[i]-'a']--;

    }
    return ans;
}

int main() {
    string s;
    ll ans;
    while(cin>>s && s!="#"){
        ans = getIndex(s);
        printf("%10lld\n",ans+1);
    }

    return 0;
}