#include <iostream>
#include <vector>

using namespace std;

long long N, P, R, K;
vector<int> vec;
int defeatedCount = 0;

void solve() {
   cin >> N >> P >> R >> K;
   vec = {};
   for (int i = 0; i < N; i++) {
      int e;
      cin >> e;
      vec.push_back(e);
   }

   for (int i = 0; i < N; i++) {
      P -= vec[i];
      if (P < 0) {
         cout << "nah, i'd lose" << endl;
         return;
      }

      defeatedCount++;
      if (defeatedCount >= K) {
         P += R;
         defeatedCount = 0;
      }
   }

   cout << "nah, i'd win" << endl;
}
int main() {
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}

