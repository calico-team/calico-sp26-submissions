#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

typedef long long ll;
void solve(const vector<string>& v1, const vector<string>& v2) {
  long long mi = 0, ma = 0;
  int n = v1.size();
  for (int i = 0; i < n; i++) {
    int count1 = 0, count2 = 0;
    for (int j = 0; j < n; j++) {
      if (v1[i][j] == '#') count1++;
      if (v2[i][j] == '#') count2++;
    }
    ma += count1 * count2;
    mi += max(count1, count2);
  }
  cout << ma << " " << mi << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    vector<string> v1;
    vector<string> v2;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      v1.push_back(s);
    }
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      v2.push_back(s);
    }
    solve(v1, v2);
  }
}
