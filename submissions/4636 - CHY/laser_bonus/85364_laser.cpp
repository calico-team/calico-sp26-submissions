#include <algorithm>
#include <iostream>
#include <vector>

struct Laser {
  int x, y;
};
struct Asteroid {
  int x, y;
  bool operator==(const Asteroid &other) const {
    return x == other.x && y == other.y;
  }
};
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    Laser laser;
    vector<Asteroid> asteroids(k);
    for (int i = 0; i < k; i++) {
      cin >> asteroids[i].x >> asteroids[i].y;
    }
    laser.x = asteroids[0].x;
    laser.y = asteroids[0].y;
    while (true) {
      laser.x += q;
      laser.y += p;
      if (laser.x > n - 1) {
        laser.x = laser.x % n;
      }
      if (laser.y > m - 1) {
        laser.y = laser.y % m;
      }
      Asteroid tmp;
      tmp.x = laser.x;
      tmp.y = laser.y;
      if (find(asteroids.begin(), asteroids.end(), tmp) != asteroids.end()) {
        cout << find(asteroids.begin(), asteroids.end(), tmp) -
                    asteroids.begin()
             << endl;
        break;
      }
    }
  }
}