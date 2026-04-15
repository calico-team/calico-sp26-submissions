#include <bits/stdc++.h>
using namespace std;



void solve(){
    long long p,a,b;
    cin >> p >> a >> b;
    __int128 s2=p%((__int128)1<<a);
    __int128 s3=p/((__int128)1<<a);
    vector<int> bs2;
    vector<int> bs3;
    while(s2>0){
        bs2.push_back(s2%2);
        s2/=2;
    }
    while(bs2.size()<a) bs2.push_back(0);
    while(s3>0){
        bs3.push_back(s3%3);
        s3/=3;
    }
    while(bs3.size()<b) bs3.push_back(0);
    reverse(bs2.begin(),bs2.end());
    reverse(bs3.begin(),bs3.end());
    vector<vector<char>> out;
    out.push_back({'>','v','.'});
    for(int i:bs3){
        if(i==0) out.push_back({'X','S','X'});
        else if(i==1) out.push_back({'X','S','>'});
        else out.push_back({'<','S','>'});
        out.push_back({'.','v','.'});
    }
    for(int i:bs2){
        if(i==0) out.push_back({'.','S','X'});
        else out.push_back({'.','S','>'});
        out.push_back({'.','v','.'});
    }
    out[out.size()-1][1]='X';
    cout << out.size() << ' ' << out[0].size() << '\n';
    for(auto i:out){
        for(auto o:i) cout << o;
        cout << '\n';
    }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}