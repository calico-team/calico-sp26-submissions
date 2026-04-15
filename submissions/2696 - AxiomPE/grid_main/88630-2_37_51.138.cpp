#include <bits/stdc++.h>
using namespace std;

void slv() {
    int n;
    cin >> n;
    
    auto f = [&](auto& sf, int k, int sp) -> void{
        if (k == 1) {
            cout << string(sp, ' ') << "calico\n";
            return;
        }
        string s = "calico";
        for (int i = 0; i < 6; i++){
            cout << string(sp + i, ' ') << s[i] << "\n";
        }
        sf(sf, k - 1, sp + 6);
        sf(sf, k - 1, sp + 6);
    };
    
    f(f, n, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (cin >> t){
        while (t--) {
            slv();
        }
    }
    return 0;
}
