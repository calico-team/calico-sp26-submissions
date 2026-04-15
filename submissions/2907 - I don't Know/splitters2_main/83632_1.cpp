#include <iostream>

using namespace std;

void solve() {
    long long N, P, R, K;
    cin >> N >> P >> R >> K;
    
    bool ok = true;
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        long long E; 
        cin >> E;
        
        if (!ok) continue; 
        
        P -= E;
        
        if (P < 0) {
            ok = false;
        } else {
            count++;
            if (count == K) {
                P += R;
                count = 0;
            }
        }
    }
    
    if (ok) {
        cout << "nah i'd win\n";
    } else {
        cout << "nah i'd lose\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}