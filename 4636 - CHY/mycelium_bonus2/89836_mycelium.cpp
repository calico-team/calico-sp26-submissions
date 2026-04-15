#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int shift = 3100;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    vector<vector<char>> land(6200, vector<char>(6200, 'B'));
    int xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;
    xg += shift;
    yg += shift;
    xm += shift;
    ym += shift;
    long long tick = 1;
    queue<pair<int, int>> g, m;
    land[xg][yg] = 'G';
    land[xm][ym] = 'M';
    g.push({xg, yg});
    m.push({xm, ym});
    long long ans = 1;
    while (!m.empty()) {
      if (tick % 2 == 0) {
        int size = g.size();
        for (int i = 0; i < size; i++) {
          auto [x, y] = g.front();
          g.pop();
          for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (land[nx][ny] == 'B') {
              land[nx][ny] = 'G';
              g.push({nx, ny});
            }
          }
        }
      }
      if (tick % 7 == 0) {
        int size = m.size();
        for (int i = 0; i < size; i++) {
          auto [x, y] = m.front();
          m.pop();
          for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (land[nx][ny] == 'B') {
              land[nx][ny] = 'M';
              ans++;
              m.push({nx, ny});
            }
          }
        }
      }
      tick++;
    }
    cout << ans << endl;
  }
}