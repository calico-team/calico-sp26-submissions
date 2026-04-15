#include<bits/stdc++.h>//I love Ogura Yui forever!
#define ll long long
using namespace std;//Yui chan is so cute!
int n;
int a[100005];
const ll inf=1e18;

ll calc(int i,int j)
{
    if(i==0||j==0||i==n+1||j==n+1)return inf;
    return abs(a[i]-a[j]);
}
ll f[100005][3];
using pii=pair<int,int>;
int from[100005][3];

int b[100005];

int Ans[100005];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            b[i]=a[i];
        }
        f[1][0]=inf;
        f[1][1]=0;
        f[1][2]=calc(1,2);
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=2;j++)
            {
                f[i][j]=inf;
                for(int k=0;k<=2;k++)
                {
                    ll now=f[i-1][k]+calc(i-1+k-1,i+j-1)+calc(i+j-1,i);
                    if(now<f[i][j])
                    {
                        f[i][j]=now;
                        from[i][j]=k;
                    }
                }
            }
        }
        int ans=0;
        if(f[n][1]<f[n][ans])ans=1;
        if(f[n][2]<f[n][ans])ans=2;
        for(int i=n;i>=1;i--)
        {
            Ans[i]=a[i+ans-1];
            ans=from[i][ans];
        }
        for(int i=1;i<=n;i++)printf("%d ",Ans[i]);
        puts("");
    }
    return 0;
}