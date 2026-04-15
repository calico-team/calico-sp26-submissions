#include <iostream>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    for(int ii=0; ii<t; ii++)
    {
        int n;
        cin >> n;
        string s1[n],s2[n];
        long long mn=0,mx=0,n1[n],n2[n];
        for(int i=0;i<n;i++) n1[i]=0,n2[i]=0;
        for(int i=0; i<n; i++)
        {
            cin >> s1[i];
            for(int j=0;j<n;j++) if(s1[i][j]=='#') n1[i]++;
        }
        for(int i=0; i<n; i++)
        {
            cin >> s2[i];
            for(int j=0;j<n;j++) if(s2[i][j]=='#') n2[i]++;
        }
        for(int i=0;i<n;i++) mn+=max(n1[i],n2[i]),mx+=n1[i]*n2[i];
        cout << mx << " "<< mn << '\n';
    }
}
