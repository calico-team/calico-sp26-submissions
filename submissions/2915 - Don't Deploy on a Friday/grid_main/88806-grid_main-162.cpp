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

const int MX = 1e8 + 1;

void solve() {
  int N;
  cin >> N;

  int arr[N];
  //vector<int> freq(MX, 0);
  int sum = 0;
  int avg = 0;
  int mx = -1;

  FR(i, N) {
    int x;

    cin >> x;
    arr[i] = x;

    sum += x;
    //freq[x]++;

    mx = max(mx, x);
  }
  
  int freq_max = -1;
  int freq_max_idx = -1;

  /*for(int i = 0; i <= mx; i++) {
    if(freq_max < freq[i]) {
      freq_max = freq[i];
      freq_max_idx = i;
    }
  }*/

  /*for(int i = 0; i < N; i++) {
    cout << freq_max_idx << " ";
  }*/

  /*for(int i = 0; i < N; i++) {
    cout << arr[freq_max_idx] << " ";
  }*/

  for(int i = 0; i < N; i++) {
    cout << 1 << " ";
  }

  cout << "\n";
}

int main() {
  fast

  scann(T);

  FR(i, T) {
    solve();
  };

  return 0;
}