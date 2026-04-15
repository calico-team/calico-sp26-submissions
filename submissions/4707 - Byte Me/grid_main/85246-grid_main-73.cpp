#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

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
   long long ans = 0;
   for (int i = 1; i < n; i++) {
      ans += abs(vec[i] - vec[i - 1]);
   }

   long long smallest = INT_MAX;
   long long in;
   for (long long i = 0; i < *max_element(vec.begin(), vec.end()); i++) {
      long long sum = 0;
      for (int j = 0; j < n; j++) {
         sum += abs(vec[j] - i);
      }
      if (sum < smallest) {smallest = sum; in = i;}
   }

   for (int i = 0; i < n; i++) {
      cout << in << " ";
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