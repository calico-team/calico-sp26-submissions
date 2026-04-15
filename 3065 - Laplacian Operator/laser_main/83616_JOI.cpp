//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2") // Improves vectorization
//#pragma GCC optimize("unroll-loops") // Speeds up loops

#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using si = set<int>;
using sll = set<ll>;

const streamsize ss = cout.precision(); // The original precision.
const double pi = 3.141592653589793238;
const int inf = 1073741823; // A number greater than 10^9 and doesn't overflow when *2.
const ll infll = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";

#define rep(i, n) for (int i = 0; i < (int) n; ++i) // Still put {}, only for int's. Only from 0 to n - 1.
#define REP(i, n) for (int i = 1; i <= (int) n; ++i) // Still put {}, only for int's. Only from 1 to n.
#define rep1(i, x, n) for (int i = x; i <= (int) n; ++i) // Still put {}, only for int's. Only from x to n.
#define all(vec) vec.begin(), vec.end() // All elements in a vector
#define nl "\n" //Use instead of endl
#define deciplace(n) cout << fixed << setprecision((int) n)
#define reset cout << fixed << setprecision(ss)
#define elif else if
//#define Yes cout << "Yes" << nl // Outputs "Yes"
//#define No cout << "No" << nl // Outputs "No"
//#define YES cout << "Yes" << nl // Outputs "YES"
//#define NO cout << "No" << nl // Outputs "NO"

// Changes the max value(a) into b if b is greater
// Returns true if changed
template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

// Changes the min value(a) into b if b is smaller
// Returns true if changed
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

//---------------------------------------------------------



int main() {
  int t; cin >> t;
  while (t--) {
    int k, n, m, p, q; cin >> k >> n >> m >> p >> q;
    vector<pair<int, int>> points(k);
    for (int i = 0; i < k; i++) cin >> points.at(i).first >> points.at(i).second;
    vector<pair<int, int>> inorder = points;
    sort(inorder.begin(), inorder.end());
    int temp = gcd(p, q);
    p /= temp;
    q /= temp;
    pair<int, int> cur = points.at(0);
    cur.first += q;
    cur.first %= n;
    cur.second += p;
    cur.second %= m;
    while (!binary_search(inorder.begin(), inorder.end(), cur)) {
      cur.first += q;
      cur.first %= n;
      cur.second += p;
      cur.second %= m;
    }
    for (int i = 0; i < k; i++) {
      if (points.at(i) == cur) {
        cout << i << nl;
        break;
      }
    }
  }
}