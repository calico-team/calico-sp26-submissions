/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int solve() {
    int K, N, M, P, Q;
    cin >> K >> N >> M >> P >> Q;
    
    vector<int> X(K), Y(K);
    for (int i = 0; i < K; i++) {
        cin >> X[i] >> Y[i];
    }
    
    int x0 = X[0], y0 = Y[0];
    
    map<pair<int, int>, int> pos;
    for (int i = 1; i < K; i++) {
        int dx = (X[i] - x0 + N) % N;
        int dy = (Y[i] - y0 + M) % M;
        if (pos.count({dx, dy}) == 0) {
            pos[{dx, dy}] = i;
        }
    }
    
    int ans = -1;
    long long min_step = 1e18;
    
    int x = 0, y = 0;
    int steps = 0;
    
    do {
        if (x == 0 && y == 0 && steps > 0) break;
        
        if (pos.count({x, y})) {
            int idx = pos[{x, y}];
            if (ans == -1 || steps < min_step) {
                ans = idx;
                min_step = steps;
            }
        }
        
        x = (x + Q) % N;
        y = (y + P) % M;
        steps++;
        
    } while (!(x == 0 && y == 0));
    
    return ans;
}

int main() {
    
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << "\n";
    }
    
    return 0;
}