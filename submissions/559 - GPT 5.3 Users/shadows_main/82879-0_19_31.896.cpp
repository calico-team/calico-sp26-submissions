using namespace std;
#include <bits/stdc++.h>
 
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
 
#define ll long long
#define read(arr) for (auto &x: arr) cin >> x;
#define print_vec(arr) for (auto arr_val: arr) { cout << arr_val << " "; } cout << endl
 
// https://codeforces.com/blog/entry/70327, written 5 years ago
ll mod_pow(ll a, ll b, ll m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}

// https://usaco.guide/gold/hashing?lang=cpp
long long rng() {
	static std::mt19937 gen(
	    std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> a(n); read(a);
        vector<string> b(n); read(b);

        ll min = 0;
        ll maxi = 0;
        for (int i = 0; i < n; i++) {
            min += max(count(a[i].begin(), a[i].end(), '#'), count(b[i].begin(), b[i].end(), '#'));
            maxi += count(a[i].begin(), a[i].end(), '#') * count(b[i].begin(), b[i].end(), '#');
        }

        cout << maxi << " " << min << "\n";
    }
}
