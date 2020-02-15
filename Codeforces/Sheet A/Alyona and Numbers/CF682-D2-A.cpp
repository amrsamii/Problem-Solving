#include <bits/stdc++.h>

typedef long long ll;
using namespace std;



int main() {

   int n,m;
   ll ans = 0;
   cin>>n>>m;
   int minn = min(n,m);
   int maxx = max(n,m);
   for(int i=1;i<=minn;i++){
       int low = i + 1;
       int high = i+ maxx;
       ans += high/5 - (low-1)/5;
   }

   cout<<ans;
    return 0;
}


هنا ب loop على الرقم الصغير وبشوف الجمع بتاعه والرقم الكبير ال max بتاعه ايه وال min بتاعه ايه
ال min هيكون 1 + الرقم لان اقل رقم فى الكبير هو 1
ال max هيكون الكبير + الصغير الحالى

بعد كدا هعمل inc-exc بانى هعد فى كام رقم يقبل القسمة على 5 فى ال range دا
ف high/5 هيجبلى كل اللى بيقبل القسمة من 1 ل high
و (low-1)/5 هيجبلى كل اللى بيقبل القسمة من 1 ل low -1
وطرحت 1 عشان لما اطرح مشيلش ال low لانه معايا وبعد كدا هزود ال ans باللى هيطلع وهطبع ال ans
