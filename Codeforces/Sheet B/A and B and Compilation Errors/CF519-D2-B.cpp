#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {

    int n,e1=-1,e2=-1;
    cin>>n;
    vector<int> lines(n);
    vector<int> error_one(n-1);
    vector<int> error_two(n-2);

    for(int i=0;i<n;i++)
        cin >> lines[i];

    sort(lines.begin(),lines.end());

    for(int i=0;i<n-1;i++)
        cin>>error_one[i];

    sort(error_one.begin(),error_one.end());

    for(int i = 0;i<n-2;i++)
        cin>>error_two[i];

    sort(error_two.begin(),error_two.end());

    for(int i=0;i<n-1;i++){
        if(lines[i] != error_one[i]){
            e1 = lines[i];
            break;
        }
    }
    if(e1 == -1)
        e1 = lines[n-1];

    for(int i=0;i<n-2;i++){
        if(error_two[i] != error_one[i]){
            e2 = error_one[i];
            break;
        }
    }
    if(e2 == -1)
        e2 = error_one[n-2];

    printf("%d\n%d",e1,e2);

    return 0;
}