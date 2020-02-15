#include <bits/stdc++.h>

typedef long long ll;
using namespace std;



int main() {

    int n,k;
    cin>>n>>k;
    vector<int> pts(2*n+2);
    for(int i=1;i<=2*n+1;i++)
        cin>>pts[i];

    for(int i=2;i<=2*n+1 && k;i+=2){
            if(pts[i]>pts[i-1]+1 && pts[i] > pts[i+1]+1)
                pts[i]--,k--;
    }
    for(int i=1;i<=2*n+1;i++)
        cout<<pts[i]<<" ";
    return 0;
}



// 
هنا بمشى على ال even فقط عشان هما عندهم ان اللى قبلهم وبعدهم اصغر منهم يعنى هما peak فبمشى عليهم وبتأكد ان ال k مش 0 عشان اقدر انقص فبشوف لو ال even دا اعلى من اللى حوله ب 2 على الاقل يبقى اقدر انقص وهيفضل peak لانه مختار peaks يلعب فيهم, لو ال loop خلصت ومفيش حاجة اقدر اغيرها مفيش مشكلة ال k مش هتنقص, بعد كدا هطبع ال pts
n peaks -> 2*n segments -> 2*n+1 pts
