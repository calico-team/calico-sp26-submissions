#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void solve() {
   string a, b;
   getline(cin, a);
   getline(cin, b);

   int j = 0;
   for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[j]) a[i] = '#';
      else j++;
   }

   cout << a << endl;
}

int main() {

   int t;
   cin >> t;
   cin.ignore();
   while (t--) {
      solve();
   }

   return 0;
}