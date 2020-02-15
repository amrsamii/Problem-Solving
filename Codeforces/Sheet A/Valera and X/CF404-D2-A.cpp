#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


char grid[305][305];

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    char x = grid[0][0];
    char o = grid[0][1];
    if(x == o)
        return cout<<"NO",0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(j==i || j == n-i-1){
                if(grid[i][j] != x)
                    return cout<<"NO",0;
            }else{
                if(grid[i][j] != o)
                    return cout<<"NO",0;
            }


        }
    }
    cout<<"YES";


    return 0;
}


check that letter of diagonal does not equal letter of square first => if does print no

check if diagnonal letters are the same of x => if not print no

check if square letters are the same of o => if not print no

else print
