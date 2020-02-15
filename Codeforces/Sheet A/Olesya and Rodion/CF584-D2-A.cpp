#include <bits/stdc++.h>

typedef long long ll;
using namespace std;



int main() {

    int n,t;
    cin>>n>>t;
    if(n == 1 && t == 10)
        return cout<<-1,0;

    if(t == 10)
        n-=2;
    else
        n--;
    cout<<t;
    for(int i=0;i<n;i++)
        cout<<0;
    return 0;
}


//Notes
الفكرة هنا ان لو حطيت الرقم نفسه (t) وجنبه شوية zeros هيبقبل القسمة على t
طيب لو n =1 و t = 10 مستحيل يقبل القسمة فاطلع 1
غير كدا فى حل, كل اللى هعمله هطبع الرقم والباقى اصفار, لو الرقم يساوى 10 يبقى  دا خد 2 من ال n فانقص ال n ب 2 ولو ال t غير 10 يبقى هو digit واحد انقص ال n واحد واطبع ال t وبعد كدا loop على n اطبع فيها zeros

