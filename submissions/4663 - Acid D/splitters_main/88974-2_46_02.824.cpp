#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
struct pr
{
    long long p,a,b;
};
pr operator+(pr x, pr y)
{
    long long maxa=max(x.a,y.a),maxb=max(x.b,y.b);
    long long prob=x.p*(1ll<<(maxa-x.a))*pow(3,maxb-x.b)+y.p*(1ll<<(maxa-y.a))*pow(3,maxb-y.b);
    while(prob%2==0) prob/=2,maxa--;
    while(prob%3==0) prob/=3,maxb--;
    pr px = {prob,maxa,maxb};
    return px;
}
signed main()
{
    long long t;
    cin >> t;
    for(long long ii=0; ii<t; ii++)
    {
        pr ans= {0,0,0};
        long long n,m;
        cin >> n >> m;
        string s[n];
        long long mx[n][m],e[n][m];
        pr a[n][m];
        for(long long i=0; i<n; i++) cin >> s[i];
        for(long long i=0; i<n; i++)
        {
            for(long long j=0; j<m; j++)
            {
                a[i][j].p=0,a[i][j].a=0,a[i][j].b=0;
                if(s[i][j]=='S') mx[i][j]=(s[i+1][j]!='^'&&s[i+1][j]!='.')+(s[i-1][j]!='v'&&s[i-1][j]!='.')+(s[i][j+1]!='<'&&s[i][j+1]!='.')+(s[i][j-1]!='>'&&s[i][j-1]!='.');
                e[i][j]=(i!=n-1&&(s[i+1][j]=='^'||(s[i+1][j]=='S'&&s[i][j]!='v')))+(i!=0&&(s[i-1][j]=='v'||(s[i-1][j]=='S'&&s[i][j]!='^')))+(j!=0&&(s[i][j-1]=='>'||(s[i][j]!='<'&&s[i][j-1]=='S')))+(j!=m-1&&(s[i][j+1]=='<'||(s[i][j]!='>'&&s[i][j+1]=='S')));
            }
        }
        queue<pair<long long,long long>>q;
        a[0][0] = {1,0,0};
        q.push(make_pair(0,0));
        while(!q.empty())
        {
            long long x=q.front().first,y=q.front().second;
            pr p=a[x][y];
            //cout << x << " "<< y << " "<< p.p << " "<< p.a << " " << p.b << endl;
            q.pop();
            if(s[x][y]=='v')
            {
                if(x==n-1)
                {
                    ans=ans+p;
                    continue;
                }
                e[x+1][y]--;
                if(e[x+1][y]==0) q.push(make_pair(x+1,y));
                a[x+1][y]=a[x+1][y]+p;
            }
            else if(s[x][y]=='^')
            {
                if(x==0)
                {
                    ans=ans+p;
                    continue;
                }
                e[x-1][y]--;
                if(e[x-1][y]==0) q.push(make_pair(x-1,y));
                a[x-1][y]=a[x-1][y]+p;
            }
            else if(s[x][y]=='>')
            {
                if(y==m-1)
                {
                    ans=ans+p;
                    continue;
                }
                e[x][y+1]--;
                if(e[x][y+1]==0) q.push(make_pair(x,y+1));
                a[x][y+1]=a[x][y+1]+p;
            }
            else if(s[x][y]=='<')
            {
                if(y==0)
                {
                    ans=ans+p;
                    continue;
                }
                e[x][y-1]--;
                if(e[x][y-1]==0) q.push(make_pair(x,y-1));
                a[x][y-1]=a[x][y-1]+p;
            }
            else if(s[x][y]=='S')
            {
                pr kira = {p.p,p.a+(mx[x][y]==2),p.b+(mx[x][y]==3)};
                if(s[x+1][y]!='^'&&s[x+1][y]!='.')
                {
                    e[x+1][y]--;
                    if(e[x+1][y]==0) q.push(make_pair(x+1,y));
                    a[x+1][y]=a[x+1][y]+kira;
                }
                if(s[x-1][y]!='v'&&s[x-1][y]!='.')
                {
                    e[x-1][y]--;
                    if(e[x-1][y]==0) q.push(make_pair(x-1,y));
                    a[x-1][y]=a[x-1][y]+kira;
                }
                if(s[x][y+1]!='<'&&s[x][y+1]!='.')
                {
                    e[x][y+1]--;
                    if(e[x][y+1]==0) q.push(make_pair(x,y+1));
                    a[x][y+1]=a[x][y+1]+kira;
                }
                if(s[x][y-1]!='>'&&s[x][y-1]!='.')
                {
                    e[x][y-1]--;
                    cout << "nsdfsnfe\n";
                    if(e[x][y-1]==0) q.push(make_pair(x,y-1));
                    a[x][y-1]=a[x][y-1]+kira;
                }
            }
        }
        cout << ans.p << " "<< (1ll<<ans.a)*pow(3,ans.b) << '\n';
    }
}
