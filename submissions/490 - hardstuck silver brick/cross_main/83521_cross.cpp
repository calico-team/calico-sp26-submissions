#include <bits/stdc++.h>
using namespace std;
//  *
// ***
//  *

/*
x,y in the middle
(x,y-1),(x-1,y),(x,y),(x+1,y),(x,y+1), mod 5
ax+by
(ax+by-b)%5
(ax-a+by)%5
(ax+by)%5
(ax+a+by)%5
(ax+by+b)%5

-b%5
-a%5
+a%5
+b%5
=1,2,3,4
a=1
b=2
*/

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)cout<<(j+2*i)%5<<" ";
            cout<<endl;
        }
    }
}
