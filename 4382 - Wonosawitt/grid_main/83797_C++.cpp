#include<bits/stdc++.h>
using namespace std;

void FREOPEN(const string &prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

#define debug(c) cout << #c << " = " << c << endl
#define debugc() cout << "PASS" << endl

#define nl "\n"
#define fl flush
#define int long long

#define ll long long
#define str string
#define ld long double

#define Pb push_back
#define pB pop_back
#define ub upper_bound
#define lb lower_bound
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define ft first
#define sc second

struct Seg {
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<int>> R;
    int l, r;

    Seg(int x, int idx) {
        L.push(x); R.push(x);
        l = r = idx;
    }

    int med() {return L.top();}

    void add(int x) {
        L.push(x); R.push(x);
        if (L.top() > R.top()) {
            int a = L.top(), b = R.top(); 
            L.pop(); R.pop();
            L.push(b); R.push(a);
        }
    }

    void merge(Seg &y) {
        for (; !y.L.empty(); y.L.pop()) add(y.L.top());
        for (; !y.R.empty(); y.R.pop()) add(y.R.top());
        r = y.r;
    }
};

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<Seg> st;
    for (int i=0;i<n;i++) {
        st.Pb({a[i], i});
        while (st.size() >= 2) {
            int m = st.size();
            if (st[m-2].med() > st[m-1].med()) {
                auto lst = st.back(); st.pB();
                st.back().merge(lst);
            } else break;
        }
    }

    vector<int> b(n);
    for(auto &seg : st) {
        int v = seg.med();
        for(int i=seg.l;i<=seg.r;i++) b[i] = v;
    }

    for (auto x : b) cout << x << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0); 
    // FREOPEN("");
    
    int T = 1; cin >> T;
    while(T--) solve();
}