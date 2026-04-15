#include<iostream>
using namespace std;

void solve()
{
    int n, p, r, k, e[10005], cnt=0;
        cin>>n>>p>>r>>k;
        for(int i=1; i<=n; i++)
        {
            cin>>e[i];
        }
        for(int i=1; i<=n; i++)
        {
            p-=e[i];
            cnt++;
            if(cnt>=k&&p>=0)
            {
                p+=r;
            }
            if(p<=0)
            {
                cout<<"nah i’d lose\n";
                return;
            }
        }
    cout<<"nah i’d win\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}