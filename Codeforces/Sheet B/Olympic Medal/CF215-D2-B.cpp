#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main() {

    double n,m,z,max_r1=-1,max_p1=-1,min_p2=1e6,a,b;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(x>max_r1)
            max_r1 = x;
    }
    cin>>m;
    while(m--){
        int x;
        cin>>x;
        if(x>max_p1)
            max_p1 = x;
    }
    cin>>z;
    while(z--){
        int x;
        cin>>x;
        if(x<min_p2)
            min_p2 = x;
    }
    cin>>a>>b;

    cout<<fixed<<setprecision(12)<<max_r1/sqrt((a*min_p2/b/max_p1)+1);

}
