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
        int n;
        cin >> n;
        vi v(n);
        for (auto &item : v) cin >> item;
        vi b(n,-1);
        for (int i=0; i<=n-3; ++i) {
            if (v[i+1]>v[i] && v[i+1]>v[i+2]) {
                b[i]=max(v[i],v[i+2]);
                b[i+1]=max(v[i],v[i+2]);
                b[i+2]=max(v[i],v[i+2]);
            }
            else if (v[i+1]<v[i] && v[i+1]<v[i+2]) {
                b[i]=min(v[i],v[i+2]);
                b[i+1]=min(v[i],v[i+2]);
                b[i+2]=min(v[i],v[i+2]);
            }
            else {
                b[i+2]=v[i+2];
                if (b[i+1]==-1) b[i+1]=v[i+1];
                if (b[i]==-1) b[i]=v[i];
            }
        }
        for (int i=0; i<n; ++i) {
            cout << b[i];
            if (i!=n-1) cout << ' ';
        }
        cout << endl;
    }
}