#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int arr[105];

int main() {

    int n;
    int rep=0,maxx=0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if(n==1)
        return cout<<"YES",0;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i] == arr[i+1]){
            rep++;
            while(arr[i] == arr[i+1])
                rep++,i++;
            if(rep>maxx)
                maxx = rep;
            rep=0;
        }
    }
    if(n>=2*maxx-1)
        cout<<"YES";
    else
        cout<<"NO";

}

// use simplification and observation thechniques: observation will tell you that you can shuffle the array in anyway using the swap operation
// using simplification you get that you can make the array distinct IFF n>=2*C-1 where C is the biggest repetition of numbers because if it is C
// you need at least C-1 numbers to make array distinct
