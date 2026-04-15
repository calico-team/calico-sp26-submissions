#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            int cur=0;
            if(i%5==0)cur=2;
            if(i%5==1)cur=0;
            if(i%5==2)cur=3;
            if(i%5==3)cur=1;
            if(i%5==4)cur=4;
            for(int j=1;j<=m;j++)
            {
                printf("%d ",cur);
                cur=(cur+1)%5;
            }
            puts("");
        }
    }
    return 0;
}