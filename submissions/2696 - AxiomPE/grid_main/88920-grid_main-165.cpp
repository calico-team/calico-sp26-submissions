#include <bits/stdc++.h>
using namespace std;

void slv() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    
    for (int j = 0; j < m; j++){
        int bot = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (g[i][j] == 'o') {
                bot = i - 1;
            } else if (g[i][j] == '*'){
                swap(g[i][j], g[bot][j]);
                bot--;
            }
        }
    }
    
    for (int i = 0; i < n; i++) cout << g[i] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    if (cin >> t){
        while (t--) slv();
    }
    return 0;
}
