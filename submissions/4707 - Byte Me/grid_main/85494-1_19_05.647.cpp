#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
   vector<long long> vec;
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      long long temp;
      cin >> temp;
      vec.push_back(temp);
   }

   double sum = 0;
   for (int i = 0; i < n; i++) {
      sum += vec[i];
   }

   sum = round(sum / n);


   for (int i = 0; i < n; i++) {
      cout << sum << " ";
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