#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

    // little faster reading, no c apis
    ios_base::sync_with_stdio(false);

    double vp,vd,t,f,c;
    cin>>vp>>vd>>t>>f>>c;
    if(vp>= vd)
        return cout<<0,0;
    double curr = vp*t;
    int count = 0;
    double diff = vd-vp;
    while(1){
        double y = curr/diff;
        curr += vp*y;
        if(curr >= c)
            break;
        count++;
        double ti = curr/vd + f;
        curr += ti*vp;
    }
    cout<<count;


}

// VIP,my mistake was i used int not double, equations are easy to deduce
