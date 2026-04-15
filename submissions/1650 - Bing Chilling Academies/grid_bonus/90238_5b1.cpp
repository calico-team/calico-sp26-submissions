#include<bits/stdc++.h>//I love Ogura Yui forever!
using namespace std;//Yui chan is so cute!

int n;


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int x;
        scanf("%d",&x);
        int l=x,r=x;
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&x);
            if(x<l)
            {
                printf("%d ",l);
                r=l,l=x;
            }
            else if(x>r)
            {
                printf("%d ",r);
                l=r,r=x;
            }
            else
            {
                printf("%d ",x);
                l=r=x;
            }
        }
        printf("%d\n",l);
    }
    return 0;
}