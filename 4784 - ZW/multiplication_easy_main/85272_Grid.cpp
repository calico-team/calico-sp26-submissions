#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct E
{
    ll r,c,v,w,id;
    double f;
};
ll n,m,d;
ll a[4005];
E e[2000005];
vector<int> res;
bool cmp(E x,E y)
{
    return x.f > y.f;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>d;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].r>>e[i].c>>e[i].v>>e[i].w;
        e[i].id=i;
        e[i].f = 1.0*e[i].w/e[i].v;
    }
    for(int i=1;i<=n;i++) a[i]=1;
    sort(e+1,e+m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m&&cnt<d;i++)
    {
        res.push_back(e[i].id);
        cnt++;
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    cout<<res.size();
    for(int x:res) cout<<" "<<x;
    cout<<"\n";
    return 0;
}
