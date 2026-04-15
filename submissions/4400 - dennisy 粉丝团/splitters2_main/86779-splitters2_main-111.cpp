#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long LL;

int floor (LL P, int A, int B) {
  for (int i = 0; i < A; i++) {
    P /= 2;
  }
  for (int i = 0; i < B; i++) {
    P /= 3;
  }
  return P;
}

LL get_num(int A, int B) {
  LL ret = 1;
  for (int i = 0; i < A; i++) {
    ret *= 2;
  }
  for (int i = 0; i < B; i++) {
    ret *= 3;
  }

  return ret;
}

void solve() {
  LL P;
  int A, B;
  cin >> P >> A >> B;
  cout << ">v." << '\n';
  while (A > 0) {
    int take = floor(P, A - 1, B);
    if (take == 0) {
      cout << "xS." << '\n';
    }
    else {
      cout << "<S." << '\n';
    }
    cout << ".v." << '\n';

    if (take != 0) {
      P -= get_num(A - 1, B);
    }
    A--;
  }
  while (B > 0) {
    int take = floor(P, A, B - 1);
    if (take == 0) {
      cout << "xSx" << '\n';
    }
    else if (take == 1) {
      cout << "<Sx" << '\n';
    }
    else {
      cout << "<S>" << '\n';
    }
    cout << ".v." << '\n';
    
    if (take != 0) {
      P -= take * get_num(A, B - 1);
    }
    B--;
  }

  if (P == 0) {
    cout << ".x." << '\n';
  }
  else {
    cout << ".v." << '\n';
  }
}

int main() {
  fastio;
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}