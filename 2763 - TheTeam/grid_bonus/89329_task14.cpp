
using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#define mii map<int, int>
#define si set<int>
#define sll set<long long>
#define sc set<char>
#define ss set<string>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f(i,s,e) for(int i = s; i < e; i++)
#define cf(i,s,e) for(int i = s; i <= e; i++)
#define rf(i,e,s) for(int i = e-1; i >= s; i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb embrace_back
#define mp make_pair
#define fi first
#define se first
#define ub upper_bound
#define lb lower_bound
#define sz(x) (int)(x).size()
#define afastio ios::sync_with_stdio(0); cin.tie(0); freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define read(x) cin >> x
#define print(x) cout << x << "\n"
#define debug(x) cerr << #x << " = " << x << "\n"
int gcd(int a,int b) { if (b==0) return a; return gcd(b, a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
ll gcd_ll(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm_ll(ll a,ll b) { return a/gcd_ll(a,b)*b; }
bool prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
bool prime_ll(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
#define MOD 1000000007
#define inf 1e9  // Use for int (e.g., distance)
#define inf_ll 1e18  // Use for long long
#define eps 1e-9  // Precision for floating-point comparison


struct BIT {  
    int n; vi tree;
    BIT(int size): n(size), tree(size + 1, 0) {}
    

    void update(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    int query(int i) {
        ll sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};
	class DisjointSets {
  private:
	

  public:
  vector<int> parents;
	vector<int> sizes;
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	/** @return the "representative" node in x's component */
	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};



void solve()
{
    int N; cin >> N;
    
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++) cin >> arr[i];

    vector<int> vals;
    for (int i = 1; i <= N; i++) vals.pb(arr[i]);

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    int M = vals.size();

    ll dp[M]; ll dpNew[M]; ll reconstruct[N + 1][M + 1];
    
    //dp is min cost 
    for (int k = 0; k < M; k++)
    {
        dp[k] = llabs(vals[k] - arr[1]);
    }
    for (int i = 2; i <= N; i++)
    {
        vector<ll> pref_val(M); vector<ll> pref_idx(M);

        pref_val[0] = dp[0] - vals[0];
        pref_idx[0] = 0;

        for (int j = 1; j < M; j++)
        {
            ll d = dp[j] - vals[j];
            if (d < pref_val[j - 1])
            {
                pref_val[j] = d;
                pref_idx[j] = j;
            }
            else 
            {
                pref_val[j] = pref_val[j - 1];
                pref_idx[j] = pref_idx[j - 1];
            }
        }
        vector<ll> suffix_val(M); vector<ll> suffix_idx(M);
        suffix_val[M - 1] = dp[M - 1] + vals[M - 1];
        suffix_idx[M - 1] = M - 1;
        for (int j = M -2; j >= 0; j--)
        {
            ll d = dp[j] + vals[j];
            if (d < suffix_val[j + 1])
            {
                suffix_val[j] = d;
                suffix_idx[j] = j;
            }
            else 
            {
                suffix_val[j] = suffix_val[j + 1];
                suffix_idx[j] = suffix_idx[j + 1];
            }
        }
        for (int j = 0; j < M; j++)
        {
            ll left = pref_val[j] + vals[j];
            ll right = suffix_val[j] - vals[j];

            if (left <= right)
            {
                dpNew[j] = llabs(vals[j] - arr[i]) + left;
                reconstruct[i][j] = pref_idx[j];
            }
            else
            {
                dpNew[j] = llabs(vals[j] - arr[i]) + right;
                reconstruct[i][j] = suffix_idx[j];
            }
        }
        memcpy(dp, dpNew, sizeof(dp));
    }
    ll mi = dpNew[0];
    ll mi_idx = 0;
    for (int i = 1; i < M; i++)
    {
        if (dpNew[i] < mi)
        {
            mi = min(mi, dpNew[i]);
            mi_idx = i;
        }
    }
    vector<ll> ans(N + 1);
    ll curr = mi_idx;
    for (int i = N; i >= 1; i--)
    {
        ans[i] = vals[curr];
        if (i > 1) curr = reconstruct[i][curr];
    }
    string delim = "";
    for (int i = 1; i <= N; i++)
    {
        cout << delim << ans[i];
        delim = " ";
    }
    cout << "\n";



}

int main()
{
    //afastio
    int T; cin >> T;
    while (T--) solve();
}