#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
// #define int long long
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
const int N = 1000 + 10;
int n, m;
int a[N][N], num[] = {0, 2, 4, 1, 3};
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        a[i][1] = num[(i - 1) % 5];
        for(int j = 2; j <= m; j ++) {
            a[i][j] = (a[i][j - 1] +1) % 5;
        }
    }
    for(int i = 1; i <= n; i ++, cout <<'\n')
        for(int j = 1; j <= m; j ++)
            cout << a[i][j] << ' ';
    
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1; 
    cin >> T;
    while (T--) work();

    return 0;
}
