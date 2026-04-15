#include <iostream>
#include <string>
using namespace std;

void solve() {
   int N, M;
   cin >> N >> M;
   for (int i = 0; i < N; i++) {
      string s = "";
      for (int j = i*2; j < M + i*2; j++) {
         s += to_string(j % 5);
         s += " ";
      }
      cout << s << endl;
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