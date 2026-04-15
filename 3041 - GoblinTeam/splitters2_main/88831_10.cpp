#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll p;
        int a,b;
        cin>>p>>a>>b;
        ll tot=1;
        for(int i=0;i<a;i++)tot*=2;
        for(int i=0;i<b;i++)tot*=3;
        int n=3;
        int m=2+2*b+2*a;
        vector<string>g(n,string(m,'.'));
        int r=1,c=0;
        g[r][c]='>';
        c++;
        ll rem=p;
        for(int i=0;i<b;i++){
            tot/=3;
            ll k=rem/tot;
            rem%=tot;
            g[r][c]='S';
            if(k>=1)g[r-1][c]='^';
            if(k==2){
                g[r+1][c]='v';
                g[r+2][c]='^';
            }else if(k==0){
                g[r+1][c]='v';
                g[r+2][c]='X';
            }
            c++;
            if(i<b-1||a>0)g[r][c]='>';
            c++;
        }
        for(int i=0;i<a;i++){
            tot/=2;
            ll k=rem/tot;
            rem%=tot;
            g[r][c]='S';
            if(k)g[r-1][c]='^';
            g[r+1][c]='^';
            c++;
            if(i<a-1)g[r][c]='>';
            c++;
        }
        int fm=c;
        if(fm>m)fm=m;
        for(int i=0;i<n;i++)g[i].resize(fm);
        cout<<n<<" "<<fm<<endl;
        for(auto&s:g)cout<<s<<endl;
    }
    return 0;
}
