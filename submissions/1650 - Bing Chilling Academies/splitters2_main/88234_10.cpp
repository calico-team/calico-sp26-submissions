#include<bits/stdc++.h>//I love Ogura Yui forever!
using namespace std;//Yui chan is so cute!

using ll=long long;


const int n=5,m=400;

ll p;
int a,b;

char mp[6][401];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                mp[i][j]='.';
            }
        }
        scanf("%lld%d%d",&p,&a,&b);

        mp[1][1]='v';
        mp[2][1]='v';
        mp[3][1]='>';
        mp[3][2]='>';

        int curcol=3;
        int fir5=-1,fir1=-1;
        for(int i=1;i<=a;i++)
        {
            //2^(a-i) 3^b
            ll prod=1;
            for(int j=1;j<=a-i;j++)
            {
                prod*=2;
                if(prod>p)break;
            }
            for(int j=1;j<=b;j++)
            {
                prod*=3;
                if(prod>p)break;
            }
            int cnt=p/prod;
            p=p%prod;

            if(cnt)
            {
                mp[3][curcol]='S';
                mp[4][curcol]='v';
                if(fir5==-1)fir5=curcol;
            }
            else
            {
                mp[3][curcol]='S';
                mp[4][curcol]='X';
            }
            mp[3][++curcol]='>';
            curcol++;
        }
        for(int i=1;i<=b;i++)
        {
            // 3^(b-i)
            ll prod=1;
            for(int j=1;j<=b-i;j++)
            {
                prod*=3;
                if(prod>p)break;
            }
            int cnt=p/prod;
            p=p%prod;

            if(cnt==2)
            {
                mp[2][curcol]='^';
                mp[3][curcol]='S';
                mp[4][curcol]='v';
                if(fir1==-1)fir1=curcol;
                if(fir5==-1)fir5=curcol;
            }
            else if(cnt==1)
            {
                mp[2][curcol]='X';
                mp[3][curcol]='S';
                mp[4][curcol]='v';
                if(fir5==-1)fir5=curcol;
            }
            else
            {
                mp[2][curcol]='X';
                mp[3][curcol]='S';
                mp[4][curcol]='X';
            }
            mp[3][++curcol]='>';
            curcol++;
        }
        mp[3][curcol]='X';
        if(fir1!=-1)
        {
            for(int j=fir1;j<m;j++)
            {
                mp[1][j]='>';
            }
            mp[1][m]='v';
            mp[2][m]='v';
            mp[3][m]='v';
            mp[4][m]='v';
        }
        if(fir5!=-1)
        {
            for(int j=fir5;j<=m;j++)
            {
                mp[5][j]='>';
            }
        }
        else assert(false);
        printf("%d %d\n",n,m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                putchar(mp[i][j]);
            }
            puts("");
        }
        
    }
    return 0;
}