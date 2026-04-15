#include <bits/stdc++.h>
using namespace std;
void INORI()
{
    int n;
    cin>>n;



    vector<vector<char>> S1(n+1,vector<char>(n+1,0));
    vector<vector<char>> S2(n+1,vector<char>(n+1,0));

    vector<int> AR(n+1);
    vector<int> BR(n+1);

    for(int x=0;x<n;x++)
    {
        string I1;
        cin>>I1;
        for(int y=0;y<n;y++)
        {
            S1[x][y]=I1[y];
        }
    }

    for(int x=0;x<n;x++)
    {

        string I1;
        cin>>I1;
        for(int y=0;y<n;y++)
        {
            S2[x][y]=I1[y];
        }
    }

    for(int x=0;x<n;x++)
    {
        int tot=0;
        for(int y=0;y<n;y++)
        {
            if(S1[x][y]=='#') tot++;
        }

        AR[x]=tot;
    }

     for(int x=0;x<n;x++)
    {
        int tot=0;
        for(int y=0;y<n;y++)
        {
            if(S2[x][y]=='#') tot++;
        }

        BR[x]=tot;
    }
    int Max=0,Min=0;
    for(int i=0;i<n;i++)
    {
        Max+=AR[i]*BR[i];
        Min+=max(AR[i],BR[i]);
        
    }


    cout<<Max<<" "<<Min<<endl;
    



}

int main()
{
    int t;
    cin>>t;
    while(t--)  INORI();
}