#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pli=pair<ll,int>;
using pil=pair<int,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vc=vector<char>;
using vvc=vector<vc>;
using vb=vector<bool>;
using vvb=vector<vb>;
using vvi=vector<vi>;
using vvll=vector<vll>;
using vpii=vector<pii>;
using vpll=vector<pll>;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int xg,yg,xm,ym;
        cin >> xg >> yg >> xm >> ym;
        set<pii> grass;
        set<pii> m;
        grass.insert({xg,yg});
        m.insert({xm,ym});
        int tick=1;
        while (true) {
            int before=m.size();
            if (tick%2==0) {
                set<pii> newg=grass;
                for (pii p : grass) {
                    for (pii pp : vpii{{0,1},{1,0},{0,-1},{-1,0}}) {
                        int x=p.first+pp.first;
                        int y=p.second+pp.second;
                        if (m.find({x,y})==m.end()) newg.insert({x,y});
                    }
                }
                grass=newg;
            }
            if (tick%7==0) {
                set<pii> newm=m;
                for (pii p : m) {
                    for (pii pp : vpii{{0,1},{1,0},{0,-1},{-1,0}}) {
                        int x=p.first+pp.first;
                        int y=p.second+pp.second;
                        if (grass.find({x,y})==grass.end()) newm.insert({x,y});
                    }
                }
                m=newm;
            }
            if (tick%7==0 && m.size()==before) {
                break;
            }
            tick++;
        }
        cout << m.size() << '\n';
    }
}