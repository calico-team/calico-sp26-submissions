#include<bits/stdc++.h>
using namespace std;

char mp[2005][2005];
const int S=1000;

using pii=pair<int,int>;

vector<pii>vecR,vecP,tmp;

int cnt;

void expandR()
{
    tmp.clear();
    for(pii x:vecR)
    {
        int u=x.first,v=x.second;
        if(mp[u-1][v]=='.')
        {
            mp[u-1][v]='R';
            tmp.push_back({u-1,v});
        }
        if(mp[u+1][v]=='.')
        {
            mp[u+1][v]='R';
            tmp.push_back({u+1,v});
        }
        if(mp[u][v-1]=='.')
        {
            mp[u][v-1]='R';
            tmp.push_back({u,v-1});
        }
        if(mp[u][v+1]=='.')
        {
            mp[u][v+1]='R';
            tmp.push_back({u,v+1});
        }
    }
    swap(vecR,tmp);
}

bool expandP()
{
    tmp.clear();
    for(pii x:vecP)
    {
        int u=x.first,v=x.second;
        if(mp[u-1][v]=='.')
        {
            mp[u-1][v]='P';
            tmp.push_back({u-1,v});
        }
        if(mp[u+1][v]=='.')
        {
            mp[u+1][v]='P';
            tmp.push_back({u+1,v});
        }
        if(mp[u][v-1]=='.')
        {
            mp[u][v-1]='P';
            tmp.push_back({u,v-1});
        }
        if(mp[u][v+1]=='.')
        {
            mp[u][v+1]='P';
            tmp.push_back({u,v+1});
        }
    }
    bool flag=false;
    if(tmp.size())flag=true;
    cnt+=tmp.size();
    swap(vecP,tmp);
    return flag;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<=2000;i++)
        {
            for(int j=0;j<=2000;j++)
            {
                mp[i][j]='.';
            }
        }
        int Rx,Ry,Px,Py;
        scanf("%d%d%d%d",&Rx,&Ry,&Px,&Py);
        vecR.clear();
        vecP.clear();
        vecR.push_back({Rx+S,Ry+S});
        vecP.push_back({Px+S,Py+S});
        mp[Rx+S][Ry+S]='R';
        mp[Px+S][Py+S]='P';
        cnt=1;
        for(int i=1;;i++)
        {
            if(i%2==0)
            {
                expandR();
            }
            if(i%7==0)
            {
                if(!expandP())break;
            }

            // for(int u=-10;u<=10;u++)
            // {
            //     for(int v=-10;v<=10;v++)
            //     {
            //         printf("%c",mp[u+S][v+S]);
            //     }
            //     puts("");
            // }
            //     puts("");
        }
        printf("%d\n",cnt);
    }
    return 0;
}