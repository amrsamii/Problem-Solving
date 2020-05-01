#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {

    // little faster reading, no c apis
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    set<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.insert(x);
    }

    int sz = arr.size();
    if (sz < 3)
        cout << "YES";
    else if (sz > 3)
        cout << "NO";
    else {
        if(*(--arr.end()) - *(++arr.begin()) == *(++arr.begin()) - *arr.begin())
            cout<<"YES";
        else
            cout<<"NO";
    }
}
