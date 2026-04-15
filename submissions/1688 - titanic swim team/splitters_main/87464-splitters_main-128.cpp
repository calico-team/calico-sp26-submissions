#include <bits/stdc++.h>
#define f first
#define s second
using ll=long long;
using ull=unsigned long long;
using namespace std;
pair<ll, ll> add(pair<ll, ll> x, pair<ll, ll> y) {
    ll num=x.f*y.s+y.f*x.s, den=x.s*y.s;
    ll g=__gcd(num, den);
    return {num/g, den/g};
}
struct squ {
    ll x, y;
    pair<ll, ll> val;
};
int main() {
    ll t; cin >> t;
    while(t--) {
        ll n, m; cin >> n >> m;
        vector<string> v(n);
        for(ll i=0; i<n; i++) cin >> v[i];
        vector<vector<pair<ll, ll>>> a(n, vector<pair<ll, ll>>(m, {0, 1}));
        stack<squ> st;
        st.push({0, 0, {1, 1}});
        a[0][0]={1, 1};
        while(!st.empty()) {
            squ p=st.top(); st.pop();
            if(v[p.x][p.y]=='X') continue;
            else if(v[p.x][p.y]=='S') {
                ll cnt=0;
                vector<pair<ll, ll>> pos;
                if(p.x-1>=0) {
                    if(v[p.x-1][p.y]!='.' && v[p.x-1][p.y]!='v') {
                        cnt++;
                        pos.push_back({p.x-1, p.y});
                    }
                }
                if(p.x+1<n) {
                    if(v[p.x+1][p.y]!='.' && v[p.x+1][p.y]!='^') {
                        cnt++;
                        pos.push_back({p.x+1, p.y});
                    }
                }
                if(p.y-1>=0) {
                    if(v[p.x][p.y-1]!='.' && v[p.x][p.y-1]!='>') {
                        cnt++;
                        pos.push_back({p.x, p.y-1});
                    }
                }
                if(p.y+1<m) {
                    if(v[p.x][p.y+1]!='.' && v[p.x][p.y+1]!='<') {
                        cnt++;
                        pos.push_back({p.x, p.y+1});
                    }
                }
                if(cnt==0) continue;
                for(auto z:pos) {
                    if(v[z.f][z.s]=='X') continue;
                    st.push({z.f, z.s, {p.val.f, p.val.s*cnt}});
                    a[z.f][z.s] = add({p.val.f, p.val.s * cnt}, a[z.f][z.s]);
                }
            } else if(v[p.x][p.y]=='^') {
                if(p.x-1>=0) {
                    st.push({p.x-1, p.y, p.val});
                    a[p.x-1][p.y]=add(p.val, a[p.x-1][p.y]);
                } else {}
            } else if(v[p.x][p.y]=='v') {
                if(p.x+1<n) {
                    st.push({p.x+1, p.y, p.val});
                    a[p.x+1][p.y]=add(p.val, a[p.x+1][p.y]);
                }
            } else if(v[p.x][p.y]=='<') {
                if(p.y-1>=0) {
                    st.push({p.x, p.y-1, p.val});
                    a[p.x][p.y-1]=add(p.val, a[p.x][p.y-1]);
                }
            } else if(v[p.x][p.y]=='>') {
                if(p.y+1<m) {
                    st.push({p.x, p.y+1, p.val});
                    a[p.x][p.y+1]=add(p.val, a[p.x][p.y+1]);
                }
            }
        }
        pair<ll, ll> tot={0, 1};
        for(ll i=0; i<n; i++) {
            if(v[i][0]=='<') tot=add(tot, a[i][0]);
            if(v[i][m-1]=='>') tot=add(tot, a[i][m-1]);
        }
        for(ll i=0; i<m; i++) {
            if(v[0][i]=='^') tot=add(tot, a[0][i]);
            if(v[n-1][i]=='v') tot=add(tot, a[n-1][i]);
        }
        cout << tot.f << " " << tot.s << "\n";
    }
}