#include <iostream>
#include <vector>
using namespace std;

string solve()
{
    int n, k;
    long long p, r;
    cin>>n>>p>>r>>k;
    int e[10005];
    for(int i=0; i < n; i++)cin>>e[i];
    long long cnt=0, kill=0;        
    for(int i=0; i < n; i++)
    {
        while(p<e[i]&&cnt>0)
        {
            p+=r;
            cnt--;
        }
        p -= e[i];
        if(p < 0) return "nah i'd lose";
        kill++;
        if(kill%k==0)cnt++;
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