#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long LL;

const LL MAX_TILES = 3656158440062976; // 6^20

void solve() {
  int N, M;
  cin >> N >> M;
  vector<string> grid (N);
  for (int i = 0; i < N; i++) {
    cin >> grid[i];
  }

  vector<vector<LL> > tiles (N, vector<LL> (M, 0));
  tiles[0][0] = MAX_TILES;

  LL thrown_away = 0;

  for (int time = 0; time <= N * M + 2; time++) {

    // cout << "printing tiles " << endl;
    // for (int i = 0; i < N; i++) {
    //   for (int j = 0; j < N; j++) {
    //     cout << tiles[i][j] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << "prinitng done" << endl << endl;

    vector<vector<LL> > new_tiles (N, vector<LL> (M, 0));

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        
        if (tiles[i][j] == 0) {
          continue;
        }
        if (grid[i][j] == '.') {
          continue;
        }
        if (grid[i][j] == 'X') {
          thrown_away += tiles[i][j];
          continue;
        }

        

        if (grid[i][j] == 'v' && i != N - 1) {
          new_tiles[i + 1][j] += tiles[i][j];
        }
        if (grid[i][j] == '^' && i != 0) {
          new_tiles[i - 1][j] += tiles[i][j];
        }
        if (grid[i][j] == '>' && j != M - 1) {
          new_tiles[i][j + 1] += tiles[i][j];
        }
        if (grid[i][j] == '<' && j != 0) {
          new_tiles[i][j - 1] += tiles[i][j];
        }

        if (grid[i][j] == 'S') {
          int valid = 4;
          if (i == 0 || grid[i - 1][j] == 'v' || grid[i - 1][j] == '.') {
            valid--;
          }
          if (i == N - 1 || grid[i + 1][j] == '^' || grid[i + 1][j] == '.') {
            valid--;
          }
          if (j == 0 || grid[i][j - 1] == '>' || grid[i][j - 1] == '.') {
            valid--;
          }
          if (j == M - 1 || grid[i][j + 1] == '<' || grid[i][j + 1] == '.') {
            valid--;
          }


          if (!(i == 0 || grid[i - 1][j] == 'v' || grid[i - 1][j] == '.')) {
            new_tiles[i - 1][j] += tiles[i][j] / valid;
          }
          if (!(i == N - 1 || grid[i + 1][j] == '^' || grid[i + 1][j] == '.')) {
            new_tiles[i + 1][j] += tiles[i][j] / valid;
          }
          if (!(j == 0 || grid[i][j - 1] == '>' || grid[i][j - 1] == '.')) {
            new_tiles[i][j - 1] += tiles[i][j] / valid;
          }
          if (!(j == M - 1 || grid[i][j + 1] == '<' || grid[i][j + 1] == '.')) {
            new_tiles[i][j + 1] += tiles[i][j] / valid;
          }
        }
      }
    }

    tiles = new_tiles;
  }

  LL Q = MAX_TILES;
  LL P = MAX_TILES - thrown_away;

  while(Q % 2 == 0 && P % 2 == 0) {
    Q /= 2;
    P /= 2;
  }
  while(Q % 3 == 0 && P % 3 == 0) {
    Q /= 3;
    P /= 3;
  }
  cout << P << ' ' << Q << '\n';
}

int main() {
  fastio;
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}