#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

typedef long long ll;

void get_vector(int n, vector<int>& v) {
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    v.push_back(d);
  }
}

void solve(const vector<int>& v) {
  cout << v[0] << " " <<  (v[0] + v[2]) / 2  << " " << v[2] << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    vector<int> v;
    get_vector(n, v);
    solve(v);
  }
}
