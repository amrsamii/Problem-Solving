#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {

    // little faster reading, no c apis
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    int sz = arr.size();
    if (sz < 3)
        cout << "YES";
    else if (sz > 3)
        cout << "NO";
    else {
        if(arr[1] - arr[0] == arr[2] - arr[1])
            cout<<"YES";
        else
            cout<<"NO";
    }
}

//Let Final value for every element in array = y, so every element in array must be in form of [y, y-x, y+x] otherwise they must be duplicate
// so if we have more than 3 distinct elments in the array, we can not make all elements equal
// if we have less than 2 distinct elements, ans is yes
// if we have exaclty 3 elements, difference between them must be equal, otherwise ans is no
