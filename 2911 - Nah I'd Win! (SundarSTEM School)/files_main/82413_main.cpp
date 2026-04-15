#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define ll long long



void solve() {
    string a, b; cin >> a >> b;
    int j = 0;
    for (int i = 0; i < a.size(); i++) {
        if (j >= b.size()) {
            cout<<'#';
        } else {
            if (a[i] == b[j]) {
                cout<<a[i];
                j++;
            }else{
                cout<<'#';
            }
        }
    }
    cout<<endl;
}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) solve();
    return 0;
}
