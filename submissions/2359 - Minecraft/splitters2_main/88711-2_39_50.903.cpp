#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long p;
    int a,b;
    cin>>p>>a>>b;

    if(a==0&&b==0){
        cout<<"1 1\n^\n";
        return;
    }

    vector<int>fac;
    for(int i=0;i<a;++i)fac.push_back(2);
    for(int i=0;i<b;++i)fac.push_back(3);

    int cnt=a+b;
    vector<int>rem(cnt);
    long long cur=p;

    for(int i=cnt-1;i>=0;--i){
        rem[i]=cur%fac[i];
        cur/=fac[i];
    }

    int col=2*cnt+3;
    vector<string>g(5,string(col,'.'));

    g[0][0]='v';
    g[1][0]='v';
    g[2][0]='>';
    g[2][1]='>';

    for(int i=0;i<cnt;++i){
        int c=2+2*i;
        g[2][c]='S';
        g[2][c+1]='>';

        int f=fac[i];
        int r=rem[i];

        if(f==2){
            if(r==1){
                g[1][c]='^';
                g[0][c]='^';
            }else{
                g[1][c]='X';
            }
        }else if(f==3){
            if(r==2){
                g[1][c]='^';g[0][c]='^';
                g[3][c]='v';g[4][c]='v';
            }else if(r==1){
                g[1][c]='^';g[0][c]='^';
                g[3][c]='X';
            }else{
                g[1][c]='X';
                g[3][c]='X';
            }
        }
    }

    g[2][col-1]='X';
    cout<<5<<" "<<col<<"\n";
    for(int i=0;i<5;++i)cout<<g[i]<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if(cin>>t)while(t--)solve();
    return 0;
}
