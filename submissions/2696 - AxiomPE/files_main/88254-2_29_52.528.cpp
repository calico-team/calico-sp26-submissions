#include <bits/stdc++.h>

using namespace std;

void solve(){
    string a, b;
    cin >> a >> b;
    
    int j = 0;
    for (int i = 0; i < a.length(); i++) {
        if (j < b.length() && a[i] == b[j]) {
            j++;
        } else {
            a[i] = '#';
        }
    }
    
    cout << a << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t){
        while (t--) {
            solve();
        }
    }
    return 0;
}
