#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main() {

   int book,cover,start,end;
   cin>>book>>cover>>start>>end;
   int ans = 0;
   if(start == end)
       return cout<<book,0;
   if(abs(start-end)>1){
       ans += (abs(start-end)-1)*(book+2*cover);
   }
   if(start>end){
       ans += 2*book + 2*cover;
   }else{
       ans += 2*cover;
   }
   cout<<ans;


}
