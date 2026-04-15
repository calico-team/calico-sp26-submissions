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
  int mi = 1000000000;
  int ba = -1, bb = -1, bc = -1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        int t = abs(v[0] - v[1]) + abs(v[1] - v[2]);
        t += abs(v[i] - v[j]) + abs(v[j] - v[k]);
        t += abs(v[0] - v[i]) + abs(v[1] - v[j]) + abs(v[2] - v[k]);
        if (t < mi) {
          mi = t;
          ba = v[i];
          bb = v[j];
          bc = v[k];
        }
      }
    }
  }
  cout << ba << " " << bb << " " << bc << endl;

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
