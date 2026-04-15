#include <bits/stdc++.h>
using namespace std;
using ll=long long;
static inline ll manhattan(ll x1, ll y1, ll x2, ll y2) {
    return llabs(x1-x2)+llabs(y1-y2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        ll xg, yg, xm, ym;
        cin>>xg>>yg>>xm>>ym;
        ll D=manhattan(xg, yg, xm, ym);
        ll R=(2*D-1)/5;
        ll ans=0;
        for(ll dx=-R; dx<=R; dx++) {
            ll rem=R-llabs(dx);
            for(ll dy=-rem; dy<=rem; dy++) {
                ll x=xm+dx;
                ll y=ym+dy;
                ll dM=llabs(dx)+llabs(dy);
                ll dG=manhattan(x, y, xg, yg);
                if(7*dM<2*dG)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}