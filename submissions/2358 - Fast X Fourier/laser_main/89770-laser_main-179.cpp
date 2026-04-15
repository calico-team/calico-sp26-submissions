#include <bits/stdc++.h>
#define pb push_back
#define All(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define f first
#define s second
#define INF (int)(1e18)
#define MOD (int)(1e9+7)
#define MAXN 500005
#define enl '\n'
#define DB(CODE) cout<<'\t'<<CODE<<'\n';
#define SP <<' '<<
#define int long long
typedef long long ll;
using namespace std;
void testcase(){
    int q,n,m,a,b;
    cin >> q >> n >> m >> b >> a;
    pii pos[q];
    for(int i=0; i<q; i++) cin >> pos[i].f >> pos[i].s;
    for(int i=1; i<q; i++) pos[i].f=(pos[i].f-pos[0].f+n)%n,pos[i].s=(pos[i].s-pos[0].s+m)%m;
    pos[0]={0,0};
    //
    vector<int> valn,valm;
    valn.pb(0);
    while((valn.back()+a)%n) valn.pb((valn.back()+a)%n);
    int szn=(int)valn.size();
    //
    int stepm=b*szn%m;
    valm.pb(0);
    while((valm.back()+stepm)%m) valm.pb((valm.back()+stepm)%m);
    int szm=(int)valm.size();
    //for(auto x: valn) DB(x) DB(' ')
    //for(auto x: valm) DB(x)
    //
    int ordn[n],ordm[m];
    memset(ordn,-1,sizeof(ordn));
    memset(ordm,-1,sizeof(ordm));
    for(int i=0; i<szn; i++) ordn[valn[i]]=i;
    for(int i=0; i<szm; i++) ordm[valm[i]]=i;
    //
    pii ans={szn*szm,0};
    for(int i=1; i<q; i++){
        int on=ordn[pos[i].f];
        if(on==-1) continue;
        int om=ordm[(pos[i].s-on*b%m+m)%m];
        if(om==-1) continue; //DB(i SP on SP om)
        ans=min(ans,{om*szn+on,i});
    }
    cout << ans.s << enl;
}
signed main(){
    //cin.tie(0)->sync_with_stdio(false);
    int t=1;
    cin >> t;
    while(t--){
        testcase();
    }
    return 0;
}

/*

4
3 10 10 1 1
0 0
2 2
9 9
3 6 8 2 1
1 1
1 5
5 1
3 6 8 2 1
1 1
2 3
4 4
3 5 5 2 3
2 2
0 0
1 4

*/
