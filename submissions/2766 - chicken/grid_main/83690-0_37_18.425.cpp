#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >>n;
    vector<ll> a (n),l(n),r(n),res(n);
    for(int i=0;i<n;i++)
    {
        cin >>a[i];
    }
    l[0]=r[0]=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<l[i-1])
        {
            l [i]=a[i];
            r[i]=l[i-1];
        }
        else if(a[i]>r[i-1])
        {
            l[i]=r[i-1];
            r [i]=a[i];
        }
        else
        {
            l[i]=r[i]=a[i];
        }
    }
    res[n-1] =l[n-1];
    for(int i=n-2; i>=0;i--)
    {
        res[i] =max(l[i],min(r[i],res[i+1]));
    }
    
    for(int i=0;i<n;i++)
    {
        cout<< res[i]<<(i == n-1?"":" ");
    }
    cout<<"\n";
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