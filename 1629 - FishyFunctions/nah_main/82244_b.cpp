#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
while(t--) {
    int n, p, r, k;
    cin >> n >> p >> r >> k;
    vector<int> m = vector<int> (n);
    for(int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    sort(m.begin(), m.end());
    bool win = true;
    for(int i = 0; i < n; ++i) {
        p -= m[i];
        if(p < 0) {
            win = false;
            break;
        }
        if((i+1) % k == 0) p += r;
    }
    if(win) {
        cout << "nah i'd win\n";
    }
    else {
        cout << "nah i'd lose\n";
    }
    
}
}