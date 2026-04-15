#include <bits/stdc++.h>
using namespace std;

vector<int> solve(const vector<int> &A) {
  int n = A.size();

  vector<int> L(n, 0);
  vector<int> R(n, 0);
  L[0] = A[0];
  R[0] = A[0];
  for (int i = 1; i < n; i++) {
    if (A[i] < L[i - 1]) {
      L[i] = A[i];
      R[i] = L[i - 1];
    } else if (A[i] > R[i - 1]) {
      L[i] = R[i - 1];
      R[i] = A[i];
    } else {
      L[i] = A[i];
      R[i] = A[i];
    }
  }

  vector<int> b(n, 0);
  b[n - 1] = L[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    b[i] = max(L[i], min(R[i], b[i + 1]));
  }

  return b;
}
int T, n, s;
vector<int> A;

int main() {
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s;
      A.push_back(s);
    }
    vector<int> result = solve(A);

    for (int val : result) {
      cout << val << " ";
    }
    cout << '\n';
  }
  return 0;
}
