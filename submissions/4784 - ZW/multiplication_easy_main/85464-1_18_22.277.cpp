#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct E
{
    ll r,c,v,w,id;
    double val;
};

ll n,m,d;
ll a[4005];
E e[2000005];
vector<int> res;

bool cmp(E x,E y)
{
    return x.val>y.val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m>>d;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].r>>e[i].c>>e[i].v>>e[i].w;
        e[i].id=i;
        ll diff=abs(1-e[i].v);
        e[i].val=1.0*e[i].w*diff/e[i].v;
    }

    for(int i=1;i<=n;i++) a[i]=1;
    sort(e+1,e+m+1,cmp);

    int cnt=0;
    for(int i=1;i<=m&&cnt<d;i++)
    {
        res.push_back(e[i].id);
        cnt++;
    }

    for(int i=1;i<=n;i++)
    {
        if(i>1) cout<<" ";
        cout<<a[i];
    }
    cout<<endl;

    cout<<res.size();
    for(int x:res) cout<<" "<<x;
    cout<<endl;

    return 0;
}
