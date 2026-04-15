#include <bits/stdc++.h>
#define int long long
using namespace std;

int lcm(int a, int b) {
    return __gcd(a, b) ? (a / __gcd(a, b) * b) : 0;
}

struct frac{
    int numerator, denominator;

    frac(int a, int b){
        numerator = a, denominator = b;
    }

    frac simplify(frac f){
        int g = __gcd(f.numerator, f.denominator);
        return frac(f.numerator / g, f.denominator / g);
    }

    frac add(frac f){
        int l = lcm(denominator, f.denominator);
        numerator *= (l / denominator);
        numerator += f.numerator * (l / f.denominator);

        return simplify(frac(numerator, l));
    }

    frac multiply(frac f) {
      int g1 = __gcd(abs(numerator), f.denominator);
      int g2 = __gcd(abs(f.numerator), denominator);
      int n = (numerator / g1) * (f.numerator / g2);
      int d = (denominator / g2) * (f.denominator / g1);
      return simplify(frac(n, d));
    }

    bool operator<(frac o) const{
      return numerator * o.denominator < o.numerator * denominator;
    }
    void print(){
        if (denominator != 1)
            printf("%d %d\n", numerator, denominator);
        else
            printf("%d\n", numerator);
    }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for(int i=0; i<n; ++i) cin >> grid[i];

  vector<vector<bool>> vis(n, vector<bool>(m, false));
  vector<vector<frac>> memo(n, vector<frac>(m, frac(0, 1)));

  auto isconveyor = [&](char c) -> bool {
    return c == '<' || c == '>' || c == '^' || c == 'v';
  };

  auto isvalid = [&](int r, int c, char avoid) -> bool {
    if(r <0 || r >= n || c < 0 || c>= m) return false;
    if(grid[r][c] == 'x' || grid[r][c] == 'X') return true;
    if(isconveyor(grid[r][c]) && grid[r][c] != avoid) return true;
    return false;
  };

  function<frac(int, int)> dfs = [&](int r, int c) -> frac{
    if(r < 0 || r >= n || c < 0 || c >= m) return frac(1, 1);
    if(vis[r][c]) return memo[r][c];
    vis[r][c] = true;

    if(grid[r][c] == 'x' || grid[r][c] == 'X') return memo[r][c] = frac(0, 1);
    
    if(grid[r][c] == '^') return memo[r][c] = dfs(r-1, c);
    if(grid[r][c] == 'v') return memo[r][c] = dfs(r+1, c);
    if(grid[r][c] == '<') return memo[r][c] = dfs(r, c-1);
    if(grid[r][c] == '>') return memo[r][c] = dfs(r, c+1);

    if(grid[r][c] == 'S' || grid[r][c] == 's') {
      multiset<frac> ms;
      if(isvalid(r-1, c, 'v')) ms.insert(dfs(r-1, c));
      if(isvalid(r+1, c, '^')) ms.insert(dfs(r+1, c));
      if(isvalid(r, c-1, '>')) ms.insert(dfs(r, c-1));
      if(isvalid(r, c+1, '<')) ms.insert(dfs(r, c+1));
      
      frac sum(0, 1);
      for(frac f : ms) sum = sum.add(f);
      if((int)ms.size()) sum = sum.multiply(frac(1, (int)ms.size()));
      return memo[r][c] = sum;
    }
    return memo[r][c] = frac(0, 1);
  };

  frac ans = dfs(0, 0);
  cout << ans.numerator << ' ' << ans.denominator << '\n';
  // ans.print();
}
  
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t-->0)  solve();
} 