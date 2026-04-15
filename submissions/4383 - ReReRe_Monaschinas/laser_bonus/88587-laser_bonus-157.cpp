#include <bits/stdc++.h>
#define ll long long
#define int long long
#define rep(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int lcm(int a, int b){
    return (a*b)/__gcd(a,b);
}

int extendedEuclidean(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extendedEuclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int g = extendedEuclidean(a, m, x, y);
    if (g != 1) return -1; 
    return (x % m + m) % m;
}

int chineseRemainderTheorem2(int a1, int m1, int a2, int m2) {
    int x, y;
    int g = extendedEuclidean(m1, m2, x, y);
    
    if ((a2 - a1) % g != 0) return -1; 

    int mod = (m1 / g) * m2; 
   
    int m2_reducido = m2 / g;
    int k = ((a2 - a1) / g) % m2_reducido;
    k = (k * (x % m2_reducido + m2_reducido)) % m2_reducido;
    
    int result = (a1 + k * m1) % mod;
    return (result + mod) % mod;
}

pair<int, int> normalize(int A, int B, int M) {
    int x, y;
    int g = extendedEuclidean(A, M, x, y);

    if (B % g != 0) return {-1, -1};
    int newM = M / g;
    int newB = (B / g) % newM;
    int newA = (A / g) % newM;
    int invA = modInverse(newA, newM);
    int res = (newB * invA) % newM;
    
    return { (res + newM) % newM, newM };
}

void solve(){
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    vector<pair<int,int>> vec(k);
    rep(i,0,k) cin >> vec[i].first >> vec[i].second;
    vector<pair<int,int>> ans;
    ans.push_back({lcm(n,m), 0});
    rep(i,1,k){
        int a1 = ((vec[i].first - vec[0].first) % n + n)% n;
        int a2 = ((vec[i].second - vec[0].second) % m + m) % m;

        pair<int,int> eq1 = normalize(q, a1, n);
        pair<int,int> eq2 = normalize(p, a2, m);
        
        int x = chineseRemainderTheorem2(eq1.first, eq1.second, eq2.first, eq2.second);
            
        if(x != -1 && eq1.second != -1 && eq2.second != -1 && eq1.first != -1 && eq2.first != -1)
            ans.push_back({x, i});
        
    
            
    }

    sort(ans.begin(), ans.end());

    cout << ans[0].second << "\n";

    




}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}