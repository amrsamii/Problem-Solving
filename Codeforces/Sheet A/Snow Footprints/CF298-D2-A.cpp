#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {

    int n;
    cin >> n;
    string r;
    int s = 0, t = 0;
    cin >> r;
    for (int i = 0; i < n; i++) {
        if (r[i] == 'R') {
            s = i + 1;
            while (r[i] == 'R') {
                i++;
            }
            if (r[i] == 'L')
                t = i;
            else
                t = i + 1;
            break;
        }
        else if(r[i] == 'L'){
            t= i;
            while(r[i] == 'L')
                i++;
            if(r[i] == 'R')
                s=i+1;
            else
                s = i;
            break;
        }
    }
    cout << s << " " << t;

}






// use simplification technique to discover that there are only three patterns in the problem: ..RRRR.. ...LLLLL...   ...RRRRRLLLL....
