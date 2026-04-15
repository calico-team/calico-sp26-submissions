#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (b); --i)
#define scan(x) cin >> x
#define scann(x) int x; cin >> x
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define local freopen("zDAT.txt", "r", stdin);
#define scanArr(arr, n)  FR(i, n) scan(arr[i])
#define scanArr2D(arr, n, m) FR(i, n) FR(j, m) scan(arr[i][j])
#define SZ(v) ((int) (v).size())

const int MX = 1e8 + 1;

void solve() {
  int K, N, M, P, Q;
  cin >> K >> N >> M >> P >> Q;

  vector<vector<int>> grid(N, vector<int>(M, 0));
  bool hit = false;
  bool first = true;
  int ctrX = 0;
  int ctrY = 0;

  FR(i, K) {
    int x, y;
    cin >> x >> y;
    grid[x][y] = i;

    if(i == 0) {
      ctrX = x;
      ctrY = y;
    }
  }

  int origX = ctrX;
  int origY = ctrY;

  while(!hit) {
    if(grid[ctrX][ctrY] && !first) {
      hit = true;
    } else if(ctrX == origX && ctrY == origY && !first) {
      hit = true;
    }

    first = false;

    if(!hit) {
      ctrX = (ctrX + Q) % (N);
      ctrY = (ctrY + P) % (M);
    }
  }

  cout << grid[ctrX][ctrY] << "\n"; 
}

int main() {
  fast

  scann(T);

  FR(i, T) {
    solve();
  };

  return 0;
}