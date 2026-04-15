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
        string a,b;
        cin >> a >> b;
        int i=0;
        string ans="";
        for (char ch : a) {
            if (i<b.size() && ch==b[i]) {
                ans+=ch;
                i++;
            }
            else ans+='#';
        }
        cout << ans << '\n';
    }
}