#include <iostream>
#include <vector>
using namespace std;

string solve()
{
    int n, k;
    long long p, r;
    cin>>n>>p>>r>>k;
    vector<long long> e(n);
    for(int i=0; i<n; i++)
    {
        cin>>e[i];
    }
    int flag=0;
    bool is=false;
    for(int i=0; i<n; i++)
    {
        if(is&&p-e[i]<0)
        {
            p+=r;
            is=false;
            flag=0;
        }
        p-=e[i];
        if(p<0)return "nah i'd lose";
        if(!is)
        {
            flag++;
            if(flag >= k)
            {
                is=true;
            }
        }
    }
    return "nah i'd win";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<'\n';
    }
    return 0;
}
