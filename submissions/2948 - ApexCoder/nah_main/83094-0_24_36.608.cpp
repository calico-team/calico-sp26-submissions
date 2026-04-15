#include <bits/stdc++.h>

void solve() {
  int n,p,r,k;std::cin >> n >> p >> r >> k;
  //std::cout << n << " " << p << " " << r << " " << k << " " << std::endl;

  bool lost = false;
  int arr[n];
  for(int i = 0; i < n; i++) std::cin >> arr[i];
  for(int i = 0; i < n; i++) {
    int e = arr[i];
    
    p -= e;
    
    if( p < 0 ) {
      lost = true;
      std::cout << "nah i'd lose" << std::endl;
      break;
    }
    
    if((i + 1) % k == 0) {
      p += r;
    }
  }
  if(!lost) std::cout << "nah i'd win" << std::endl;
}

int main() {
  int t;std::cin >> t;while(t--) solve();
}