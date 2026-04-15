#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string> a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        long long mx=0,mn=0;
        for(int z=0;z<n;z++){
            int cx=0,cy=0;
            for(int x=0;x<n;x++)if(a[z][x]=='#')cx++;
            for(int y=0;y<n;y++)if(b[z][y]=='#')cy++;
            mx+=1LL*cx*cy;
            mn+=max(cx,cy);
        }
        cout<<mx<<" "<<mn<<endl;
    }
    return 0;
}