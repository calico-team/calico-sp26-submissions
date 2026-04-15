#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std; using ll = long long; using pii = pair<int, int>;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vec<int> shadow1(n), shadow2(n);
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (s[j] == '#') count++;
            }
            shadow1[i] = count;
        }
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (s[j] == '#') count++;
            }
            shadow2[i] = count;
        }
        
        int big = 0, small = 0;
        for (int i = 0; i < n; i++) {
            big += shadow1[i] * shadow2[i];
            small += max(shadow1[i], shadow2[i]);
        }
        cout << big _ small << ln;
    }
}
