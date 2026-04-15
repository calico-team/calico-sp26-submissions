#include <bits/stdc++.h>
using namespace std;

int mino,minn,maxn;
vector<int> inums;
vector<vector<int>> sols;

void collapse(vector<int> nums, int pos){
    for(int i=minn;i<=maxn;i++){
        nums[pos]=i;
        if(pos<nums.size()-1){
            collapse(nums,pos+1);
        }
        else{
            int score=0;
            for(int i=0;i<inums.size();i++){
                score+=abs(inums[i]-nums[i]);
            }
            for(int i=1;i<inums.size();i++){
                score+=abs(nums[i]-nums[i-1]);
            }
            if(score<mino) sols=vector<vector<int>>();
            if(score==mino) sols.push_back(nums);
            mino=min(mino,score);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    minn=2000000000;
    maxn=0;
    inums=vector<int>(n,0);
    for(int i=0;i<n;i++){
        cin >> inums[i];
        minn=min(inums[i],minn);
        maxn=max(inums[i],maxn);
    }
    vector<int> out(n,inums[0]);
    mino=2000000000;
    collapse(out,0);
    ///cout << mino << '\n';
    for(auto i:sols[0]){
        cout << i << ' ';
    }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  //cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}