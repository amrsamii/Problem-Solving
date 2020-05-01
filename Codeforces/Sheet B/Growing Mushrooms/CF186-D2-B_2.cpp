#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool predicate(const pair<int,double>& a, const pair<int,double>& b){
    if(a.second==b.second)
        return a.first < b.first;
    return b.second < a.second;
}
int main() {

    // little faster reading, no c apis
    ios_base::sync_with_stdio(false);

    int n,t1,t2,k;
    cin>>n>>t1>>t2>>k;
    vector<pair<int,double>> heights;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        double res1 = a*t1*(1-.01*k)+b*t2;
        double res2 = b*t1*(1-0.01*k)+a*t2;
        if(res1>res2){
            heights.emplace_back(i,res1);
        }else{
            heights.emplace_back(i,res2);
        }
    }
    sort(heights.begin(),heights.end(),predicate);

    for(auto it : heights){
        cout<<it.first<<" "<<fixed<<setprecision(2)<<it.second<<endl;
    }



}
