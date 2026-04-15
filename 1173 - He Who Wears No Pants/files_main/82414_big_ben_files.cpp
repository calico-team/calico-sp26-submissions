#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

void solve(string& s1, string& s2) {
    int j = 0;
    for (int i = 0; i < (int)s2.size(); i++) {
        while (s1[j] != s2[i]) {
            cout << "#";
            j++;
        }
        cout << s1[j++];
    }
    cout << ln;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        string s1, s2;
        cin >> s1 >> s2;
        solve(s1, s2);
    }
}
