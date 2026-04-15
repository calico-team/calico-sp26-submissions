#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
    int nums[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums[i][j]=(i*2+j)%5;
                cout<<nums[i][j]<<" ";
            }cout<<endl;
        }
    }

    return 0;
}