#include <bits/stdc++.h>
#define int long long
using namespace std;

pair<int,int> simplify(pair<int,int> p){
  if(p.first == 0) return {0, 1};
  int g = gcd(p.first, p.second);
  return {p.first / g, p.second / g};
}

pair<long long, long long> solve(int N, int M, vector<string>& factory, int sx, int sy) {
  if(sx<0 || sy<0 || sx>=M || sy>=N){
    return {1,1};
  }
  char c = factory[sy][sx];
  //cout << sx << " " << sy << " " << c << " " << endl;
  if(c=='^'){
    return solve(N,M,factory,sx,sy-1);
  }
  if(c=='v'){
    return solve(N,M,factory,sx,sy+1);
  }
  if(c=='<'){
    return solve(N,M,factory,sx-1,sy);
  }
  if(c=='>'){
    return solve(N,M,factory,sx+1,sy);
  }
  if(c=='X'){
    return {0,1};
  }
  if(c=='S'){
    pair<int,int> frac = {0,1};
    int valid_count = 0;
    if(sy > 0 && factory[sy-1][sx] != 'v' && factory[sy-1][sx] != '.'){
      pair<int,int> a = solve(N, M, factory, sx, sy-1);
      frac.first = frac.first * a.second + a.first * frac.second;
      frac.second *= a.second;
      frac = simplify(frac);
      valid_count++;
    }
    if(sy < N-1 && factory[sy+1][sx] != '^' && factory[sy+1][sx] != '.'){
      pair<int,int> a = solve(N, M, factory, sx, sy+1);
      frac.first = frac.first * a.second + a.first * frac.second;
      frac.second *= a.second;
      frac = simplify(frac);
      valid_count++;
    }
    if(sx > 0 && factory[sy][sx-1] != '>' && factory[sy][sx-1] != '.'){
      pair<int,int> a = solve(N, M, factory, sx-1, sy);
      frac.first = frac.first * a.second + a.first * frac.second;
      frac.second *= a.second;
      frac = simplify(frac);
      valid_count++;
    }
    if(sx < M-1 && factory[sy][sx+1] != '<' && factory[sy][sx+1] != '.'){
      pair<int,int> a = solve(N, M, factory, sx+1, sy);
      frac.first = frac.first * a.second + a.first * frac.second;
      frac.second *= a.second;
      frac = simplify(frac);
      valid_count++;
    }
    frac.second *= valid_count;
    return simplify(frac);
  }
  return {0,1};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<string> factory(N);
        for (int i = 0; i < N; i++) cin >> factory[i];
        auto [P, Q] = simplify(solve(N, M, factory, 0, 0));
        cout << P << " " << Q << "\n";
    }
    return 0;
}
