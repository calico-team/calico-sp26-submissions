#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
   vector<long long> vec;
   vector<long long> ans;
   long long n;
   cin >> n;
   for (long long i = 0; i < n; i++) {
      long long temp;
      cin >> temp;
      vec.push_back(temp);
   }

   if (n == 1) {
      cout << vec[0] << " " << endl;
      return;
   }
   
   ans.push_back(vec[0]);
   for (long long i = 1; i < n - 1; i++) {
      long long a = ans[i - 1];
      long long b = vec[i];
      if (vec[i + 1] >= a && vec[i + 1] >= b) ans.push_back(max(a, b));
      else if (vec[i + 1] <= a && vec[i + 1] <= b) ans.push_back(min(a, b));
      else ans.push_back(vec[i + 1]);
   }
   ans.push_back(vec.back());

   for (long long i = 0; i < n; i++) {
      cout << ans[i] << " ";
   }
   cout << endl;
}
int main() {
   long long t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}