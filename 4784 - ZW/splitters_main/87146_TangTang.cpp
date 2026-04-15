#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
    while(b){ll t=b;b=a%b;a=t;}
    return a;
}

struct Frac{
    ll a,b;
    Frac(ll x=0,ll y=1){
        ll g=gcd(abs(x),abs(y));
        a=x/g; b=y/g;
        if(b<0){a=-a;b=-b;}
    }
    Frac operator+(const Frac& t)const{
        return Frac(a*t.b + t.a*b, b*t.b);
    }
    Frac operator*(const Frac& t)const{
        return Frac(a*t.a, b*t.b);
    }
};

int n,m;
string g[105];
Frac dp[105][105];
bool vis[105][105];
bool ins[105][105];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

Frac dfs(int x,int y){
    // ���� = �ɹ�
    if(x<0||x>=n||y<0||y>=m) return Frac(1,1);
    // �ϰ�/�յ� = ʧ��
    if(g[x][y]=='X'||g[x][y]=='.') return Frac(0,1);
    // ? �ؼ��޸�1���ȶ����仯��������֮ǰ˳���ˣ�
    if(vis[x][y]) return dp[x][y];
    // ��· = ʧ��
    if(ins[x][y]) return Frac(0,1);

    ins[x][y]=1;
    Frac res;
    char c=g[x][y];

    // ���ʹ�
    if(c=='^')res=dfs(x-1,y);
    else if(c=='v')res=dfs(x+1,y);
    else if(c=='<')res=dfs(x,y-1);
    else if(c=='>')res=dfs(x,y+1);

    // ������ S
    else if(c=='S'){
        int tot=0;
        for(int d=0;d<4;d++){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=0&&nx<n&&ny>=0&&ny<m)tot++;
        }
        Frac p(1,tot);
        res=Frac(0,1);
        for(int d=0;d<4;d++){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=0&&nx<n&&ny>=0&&ny<m){
                res=res+p*dfs(nx,ny);
            }
        }
    }

    ins[x][y]=0;
    vis[x][y]=1;
    dp[x][y]=res;
    return res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>g[i];
        memset(vis,0,sizeof(vis));
        memset(ins,0,sizeof(ins));
        Frac ans=dfs(0,0);
        cout<<ans.a<<" "<<ans.b<<"\n";
    }
    return 0;
}
