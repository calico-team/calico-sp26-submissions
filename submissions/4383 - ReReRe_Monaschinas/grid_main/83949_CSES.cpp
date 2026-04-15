#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int f(int x, vector<int> &vec, int n){
    int ans = 0;
    rep(i,1,n-1) ans += abs(vec[i]-x);
    return ans;
}

int ternary(int l, int r, vector<int> &vec, int n){
    while(l<=r){
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;

        int f1 = f(mid1, vec, n) + abs(vec[0]-mid1) + abs(vec[n-1]-mid1);
        int f2 = f(mid2, vec, n) + abs(vec[0]-mid2) + abs(vec[n-1]-mid2);
        
        
        
        if(f1 <= f2) r = mid2-1;
        else l = mid1+1;
    }

    return l;
}

void solve(){
    int n; cin >> n;
    vector<int> vec(n);
    rep(i,0,n) cin >> vec[i];

    if(n<=2){
        rep(i,0,n) cout << vec[i] << " ";
        cout << "\n";
        return;
    }

    int ans = ternary(0, 1e9, vec, n);
    cout << vec[0] << ' ';
    rep(i,1,n-1) cout << ans << ' ';
    cout << vec[n-1] << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}