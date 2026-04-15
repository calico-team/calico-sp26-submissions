#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (b); --i)
#define scan(x) cin >> x
#define scann(x) int x; cin >> x
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define local freopen("zDAT.txt", "r", stdin);
#define scanArr(arr, n)  FR(i, n) scan(arr[i])
#define scanArr2D(arr, n, m) FR(i, n) FR(j, m) scan(arr[i][j])
#define SZ(v) ((int) (v).size())

void solve() {
  string A;
  string B;

  cin >> A >> B;

  string temp = A;
  /*
  int ctr_A = 0;
  int ctr_B = 0;

  while(ctr_B < B.length()) {
    char char_B = B[ctr_B];
    if(A[ctr_B] == B[ctr_B]) {
      ctr_B++;
      ctr_A++;
    } else {
      A[ctr_A] = '#';
      ctr_A++;
    }
  }
  */

  int ctr = 0;

  for(int i = 0; i < A.length(); i++) {
    if (ctr < B.size() && A[i] == B[ctr]) {
      ctr++;
    } else {
      A[i] = '#';
    }
  }

  cout << A << "\n";
}

int main() {
  fast

  scann(T);

  FR(i, T) {
    solve();
  };

  return 0;
}