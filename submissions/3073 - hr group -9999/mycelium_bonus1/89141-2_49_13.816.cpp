#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;
#define endl "\n"
#define int long long
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<long long, long long> pl;
typedef pair<string, string> ps;
typedef pair<pi, char> pic;
typedef pair<char, pi> pci;
typedef pair<pci, pci> pcii;
typedef pair<char, char> pc;
typedef pair<bool, int> ib;
typedef long long ll;
const int MOD = 1e9 + 7;
const int HASH = 197;
const int MM = 1e5 + 2;
int dir[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
int arr[4000][4000];
void fun() {
    memset(arr, 0, sizeof(arr)); queue<pi> q, q1;
    int r,c, r1, c1; cin >> r >> c >> r1 >> c1; r += 1000; c += 1000; r1 += 1000; c1 += 1000;
    arr[r1][c1] = 2, arr[r][c] = 1;
    if (r == r1 && c == c1) {cout<<"0"<<endl; return;}
    q.push({r, c}); q1.push({r1, c1}); int t = 0;
    while (!q1.empty()) {
        t++;
        if (t % 2 == 0) {
            queue<pi> q2;
            while (!q.empty()) {
                auto [r2, c2] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = r2 + dir[k][0], nc=  c2 + dir[k][1];
                    if (nr < 4000 && nr >= 0 && nc < 4000 && nc > 0 && arr[nr][nc] == 0) {arr[nr][nc] = 1; q2.push({nr, nc});}
                }
            }
            while (!q2.empty()) {
                q.push(q2.front()); q2.pop();
            }
        }
        if (t % 7 == 0) {
            queue<pi> q2;
            while (!q1.empty()) {
                auto [r2, c2] = q1.front(); q1.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = r2 + dir[k][0], nc=  c2 + dir[k][1];
                    if (nr < 4000 && nr >= 0 && nc < 4000 && nc > 0 && arr[nr][nc] == 0) {arr[nr][nc] = 2; q2.push({nr, nc});}
                }
            }
            while (!q2.empty()) {
                q1.push(q2.front()); q2.pop();
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i <= 3999; i++) {
        for (int j = 0; j <= 3999; j++) {
            if (arr[i][j] == 2) cnt++;
        }
    }
    cout<<cnt<<endl;
}
signed main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for(int qwr = 1; qwr <= T; qwr++) {
        fun();
    }
}
//https://www.geeksforgeeks.org/dsa/using-chinese-remainder-theorem-combine-modular-equations/
