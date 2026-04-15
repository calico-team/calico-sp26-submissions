#include <iostream>

using namespace std;

void solve() {
    long long n, p, r, k, e;
    cin >> n >> p >> r >> k;

    long long count = 0;
    bool win = true;

    while (n--) {
        cin >> e;
        if (win && p >= e) {
            p -= e;
            if (++count == k) {
                p += r;
                count = 0;
            }
        } else {
            win = false;
        }
    }
    
    cout << (win ? "nah i'd win\n" : "nah i'd lose\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}