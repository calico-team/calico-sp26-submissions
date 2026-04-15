#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Point {
   int x, y;
};

void solve() {
   int K, N, M, P, Q;
   cin >> K >> N >> M >> P >> Q;
   vector<Point> vec;
   Point ls;

   int temp = gcd(P, Q);
   P /= temp;
   Q /= temp;


   for (int i = 0; i < K; i++) {
      int x, y;
      cin >> x >> y;
      Point temp;
      temp.x = x;
      temp.y = y;
      vec.push_back(temp);
   }

   ls.x = vec[0].x;
   ls.y = vec[0].y;

   while (1) {
      ls.x += Q;
      ls.y += P;
      if (ls.x >= N) {
         ls.x = ls.x - N;
      }
      else if (ls.x < 0) {
         ls.x = N + ls.x;
      }
      if (ls.y >= M) {
         ls.y = ls.y - M;
      }
      else if (ls.y < 0) {
         ls.y = M + ls.y;
      }

      for (int i = 0; i < K; i++) {
         if (ls.x == vec[i].x && ls.y == vec[i].y) {
            cout << i << endl;
            return;
         }
      }
   }
}

int main() {
   int t;
   cin >> t;

   while (t--) {
      solve();
   }

   return 0;
}