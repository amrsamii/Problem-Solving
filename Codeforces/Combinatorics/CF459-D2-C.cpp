#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ans[1005][1005];
int main() {


    int n, k, d;
    cin >> n >> k >> d;
    bool check = false;
    ll temp = 1;
    for(int i=0;i<d;i++){
        temp *=k;
        if(temp>=n){
            check = true;
            break;
        }

    }
    if(!check)
        return cout<<-1,0;

    for(int i=0; i<n; i++)
    {
        int p=i,j=0;
        while(p>0)
        {
            ans[j++][i]=p%k;
            p/=k;
        }
    }

    for(int i=0;i<d;i++,cout<<endl)
        for(int j=0;j<n;j++)
            cout<<ans[i][j]+1<<" ";

    return 0;
}