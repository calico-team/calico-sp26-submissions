#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve()
{
    long long n;
    cin>>n;
    vector<string> a(n),b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a [i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    long long mx=0,mn=0;
    for(int i=0;i<n; ++i)
    {
        long long x=0, y=0;
        for(int j=0; j<n;++j)
        {
            if(a[i] [j]=='#')
            {
                x++;
            }
            if(b[i] [j]=='#')
            {
                y++;
            }
        }
        mx+= x*y;
        mn+=max(x,y);
    }
    cout<<mx<<" "<<mn<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}