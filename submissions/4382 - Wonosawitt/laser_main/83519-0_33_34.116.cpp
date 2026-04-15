#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back

int k,n,m,p,q;
int a,b;

void sol(){
    map<pair<int,int>, int> pr;
    cin >> k >> n >> m >> p >> q;

    int x=-1, y=-1;
    for(int i=0;i<k;i++){
        cin >> a >> b;
        if(x==-1){
            x=a; y=b;
        }
        pr[{a,b}]=i;
    }

    x=(x+q)%n; y=(y+p)%m;

    while(pr.count({x,y})==0){
        x=(x+q)%n; y=(y+p)%m;
    }

    cout << pr[{x,y}] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc=1;
    cin >> tc;
    while(tc--) sol();
}