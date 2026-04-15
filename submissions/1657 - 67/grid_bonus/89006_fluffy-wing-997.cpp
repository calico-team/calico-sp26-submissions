#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 1) {
            int x;
            cin >> x;
            cout << x << endl;
        }
        if(n == 2) {
            int x, y;
            cin >> x >> y;
            cout << (x+y)/2 << " " << (x+y)/2 << endl;
        }
        if(n == 3) {
            int x, y, z;
            cin >> x >> y >> z;
            vector<int> b = {x, y, z};
            sort(b.begin(), b.end());
            cout << b[1] << " " << b[1] << " " << b[1] << endl;
        }
        else {
            vector<int> b (n);
            for(int i = 0; i < n; i++) {
                cin >> b[i];
            }
            for(int i = 0; i < n; i++) {
                cout << 1 << ' ';
            }
            cout << endl;
        }
    }
}
