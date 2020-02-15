#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main() {

   int n;
   cin>>n;
   int ans = 0;
   stack<int> s;
   vector<int> buildings(n);
   for(int i=0;i<n;i++){
       int a,b;
       cin>>a>>b;
       buildings[i] = b;
       if(s.empty()){
           ans++;
           s.push(buildings[i]);
       }else{
           while(s.top() > buildings[i]){
               s.pop();
               if(s.empty())
                   break;
           }
           if(s.empty()){
               ans++;
               s.push(buildings[i]);
           }else{
               if(s.top() == buildings[i])
                   continue;
               else{
                   ans++;
                   s.push(buildings[i]);
               }
           }
       }
   }
   cout<<ans;


}

// if height increases, add poster. if height decreases, add poster IFF there is no previous building with same height or there is lower building between the two

// as stack is empty, add poster and push to stack
// if no, check if there are buildings with height larger than current, remove it as it will not help in decision
// after while, if stack is empty, we need to add poster and push to stack
// if not empty, if the top is the same as current i.e we have 2 3 4 5 2, so last 2 does not need poster
// if not, we must add poster and push to stack e.g 1 2 3 1 2 => last 1 will remove 3,2 remain 1 2, so 2 needs poster
