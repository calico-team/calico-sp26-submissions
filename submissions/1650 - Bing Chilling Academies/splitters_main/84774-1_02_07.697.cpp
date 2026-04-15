#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
using ll=long long;

int n,m;
char s[20][20];

int q;
int id[20][20];

struct frac
{
    ll u,v;
}cnt[250];

ll gcd(ll x,ll y)
{
    return y?gcd(y,x%y):x;
}

frac operator+(frac x,frac y)
{
    x.u*=y.v;
    y.u*=x.v;
    x.u+=y.u;
    x.v*=y.v;
    ll g=gcd(x.u,x.v);
    x.u/=g;
    x.v/=g;
    return x;
}

frac div(frac x,int y)
{
    if(y==1)return x;
    if(y==2)
    {
        if(x.u%2==0)return {x.u/2,x.v};
        return {x.u,x.v*2};
    }
    if(x.u%3==0)return {x.u/3,x.v};
    return {x.u,x.v*3};
}

int deg[250];
int indeg[250];

vector<int>vec[250];

void addedge(int u,int v)
{
    vec[u].push_back(v);
    indeg[v]++;
}

bool conv(char c)
{
    return c=='<'||c=='>'||c=='^'||c=='v';
}

queue<int>que;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s[i]+1);
        }
        q=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                id[i][j]=++q;
            }
        }
        int out=++q;
        for(int i=1;i<=q;i++)
        {
            vec[i].clear();
            indeg[i]=deg[i]=0;
            cnt[i]={0,1};
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int I=id[i][j];
                if(s[i][j]=='S')
                {
                    deg[I]=0;
                    if(s[i-1][j]!='v'&&conv(s[i-1][j]))
                    {
                        deg[I]++;
                        addedge(I,id[i-1][j]);
                    }
                    if(s[i-1][j]=='X')deg[I]++;
                    if(s[i+1][j]!='^'&&conv(s[i+1][j]))
                    {
                        deg[I]++;
                        addedge(I,id[i+1][j]);
                    }
                    if(s[i+1][j]=='X')deg[I]++;
                    if(s[i][j-1]!='>'&&conv(s[i][j-1]))
                    {
                        deg[I]++;
                        addedge(I,id[i][j-1]);
                    }
                    if(s[i][j-1]=='X')deg[I]++;
                    if(s[i][j+1]!='<'&&conv(s[i][j+1]))
                    {
                        deg[I]++;
                        addedge(I,id[i][j+1]);
                    }
                    if(s[i][j+1]=='X')deg[I]++;
                }
                else if(s[i][j]=='^')
                {
                    deg[I]=1;
                    if(i==1)
                    {
                        addedge(I,out);
                    }
                    else addedge(I,id[i-1][j]);
                }
                else if(s[i][j]=='v')
                {
                    deg[I]=1;
                    if(i==n)
                    {
                        addedge(I,out);
                    }
                    else addedge(I,id[i+1][j]);
                }
                else if(s[i][j]=='<')
                {
                    deg[I]=1;
                    if(j==1)
                    {
                        addedge(I,out);
                    }
                    else addedge(I,id[i][j-1]);
                }
                else if(s[i][j]=='>')
                {
                    deg[I]=1;
                    if(j==m)
                    {
                        addedge(I,out);
                    }
                    else addedge(I,id[i][j+1]);
                }
                else deg[I]=1;
            }
        }
        deg[out]=1;
        que.push(id[1][1]);
        cnt[id[1][1]]={1,1};
        while(!que.empty())
        {
            int x=que.front();
            que.pop();
            cnt[x]=div(cnt[x],deg[x]);
            for(int y:vec[x])
            {
                cnt[y]=cnt[y]+cnt[x];
                indeg[y]--;
                if(indeg[y]==0)que.push(y);
            }
        }
        printf("%lld %lld\n",cnt[out].u,cnt[out].v);
    }
    return 0;
}