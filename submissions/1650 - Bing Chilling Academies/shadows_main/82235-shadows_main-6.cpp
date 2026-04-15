#include<bits/stdc++.h>
using namespace std;
int n;
char s[1005][1005],t[1005][1005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int ma=0,mi=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s[i]+1);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%s",t[i]+1);
        }

        for(int i=1;i<=n;i++)
        {
            int u=0,v=0;
            for(int j=1;j<=n;j++)
            {
                if(s[i][j]=='#')u++;
            }
            for(int j=1;j<=n;j++)
            {
                if(t[i][j]=='#')v++;
            }
            ma+=u*v;
            mi+=max(u,v);
        }
        printf("%d %d\n",ma,mi);
    }
    return 0;
}