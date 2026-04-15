#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int maxn = 1e5 + 1;
int T, N;
int a[maxn];
int b[maxn];
int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        int t = 0;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            t += a[i];
        }
        if (N == 3) {
            b[1] = a[1];
            b[3] = a[3];
            int mx = max(a[1], a[3]);
            int mn = min(a[1], a[3]);
            if (a[2] > mx)
                b[2] = mx;
            else if (a[2] < mn)
                b[2] = mn;
            else
                b[2] = a[2];
            cout << b[1] << ' ' << b[2] << ' ' << b[3] << endl;
            continue;
        }
    }
}