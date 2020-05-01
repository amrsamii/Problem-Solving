#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool predicate(const pair<int,double>& a, const pair<int,double>& b){
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
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(heights[i].second < heights[j].second){
                pair<int,double> p = heights[i];
                heights[i] = heights[j];
                heights[j] = p;
            }else if (fabs(heights[i].second-heights[j].second)<1e10){
                if(heights[i].first > heights[j].first){
                    pair<int,double> p = heights[i];
                    heights[i] = heights[j];
                    heights[j] = p;
                }
            }
        }
    }

    for(auto it : heights){
        cout<<it.first<<" "<<fixed<<setprecision(2)<<it.second<<endl;
    }



}
