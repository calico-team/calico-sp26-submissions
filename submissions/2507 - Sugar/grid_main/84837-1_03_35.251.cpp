#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;





long long compute_cost(const vector<long long>& A, const vector<long long>& b) {
    int n = A.size();
    long long cost = 0;
    
    for (int i = 0; i < n; ++i) {
        cost += abs(A[i] - b[i]);
    }
  
    for (int i = 0; i < n - 1; ++i) {
        cost += abs(b[i] - b[i+1]);
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    cin >> a;
    while (a--) {
        int b;
        cin >> b;
        vector<long long> c(b); 
        for (int d = 0; d < b; ++d) {
            cin >> c[d];
        }

        
        vector<long long> d = c;
        bool e;
        do {
            e = false;
            for (int f = 0; f < b; ++f) {
                long long g;
                if (b == 1) {
                    g = c[0];
                } else if (f == 0) {
                    g = (c[0] + d[1]) / 2; 
                } else if (f == b - 1) {
                    g = (c[b-1] + d[b-2]) / 2;
                } else {
                    long long h[3] = {c[f], d[f-1], d[f+1]};
                    sort(h, h + 3);
                    g = h[1];
                }
                if (g != d[f]) {
                    e = true;
                    d[f] = g;
                }
            }
        } while (e);

       
        if (compute_cost(c, c) == compute_cost(c, d)) {
            d = c;
        }

        for (int f = 0; f < b; ++f) {
            cout << d[f] << " \n"[f == b - 1];
        }
    }
    return 0;
}