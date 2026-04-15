//~ #pragma GCC optimize("O3,unroll-loops")
//~ #pragma GCC target("avx2,popcnt,lzcnt,bmi,bmi2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
#define for1(i, n) for(int i=1; i<=n; i++)
#define for0(i, n) for(int i=0; i<n; i++)
#define mnto(a, b) a = min(a, (__typeof__(a))b)
#define mxto(a, b) a = max(a, (__typeof__(a))b)
#define sz(a) (int)a.size();
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define arint vector<int>
#define arll vector<ll>
#define arpii vector<pii>
#define arpll vector<pll>
#define arpil vector<pil>
#define arpli vector<pli>
#define arbool vector<bool>
#define archar vector<char>
#define matint vector<arint>
#define matll vector<arll>
#define matpii vector<arpii>
#define matpll vector<arpll>
#define matpil vector<arpil>
#define matpli vector<arpli>
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define FAST_IO cin.tie(0), ios_base::sync_with_stdio(0);
#define INF 1000000001
#define MAXN 200005
#define MOD 1000000007
//~ #define int ll

//VARIABLES FOR DSA------------------------------------------
int n;

int binlog(int a){
	int ans = 0;
	while(a/=2) ans++;
	return ans;
}

//CODED DS HERE
struct segtree{ //RANGE QUERY 0-INDEX [l, r)
	int h = 0; //HEIGHT OF SEGTREE
    arll t; //SEGTREE
	arll d; //DELAYTREE
	
	//COMBINE FUNCTION--------------------------------------------------
	ll comupd(ll a, ll b){ //CHANGE
		return a + b;
	}
	
	ll comque(ll a, ll b){ //CHANGE
		return max(a, b);
	}
	
	//INITIALIZE--------------------------------------------------------
    void buildseg(arll ar){
		t.resize(n*2); d.resize(n);
		for(int x=n; x>0; x>>=1) h++;
		for(int i=0; i<n; ++i) 
			t[n+i] = ar[i+1]; //1-INDEX ar
        for(int i = n-1; i>0; i--) 
			t[i] = comque(t[i<<1], t[i<<1|1]); 
    }
	
	//NORMAL------------------------------------------------------------
    //~ void update(int pos, pii val) { //POINT ASSIGNMENT
        //~ for(t[pos+=n]=val; pos>>=1; ) 
			//~ t[pos] = comupd(t[pos<<1], t[pos<<1|1]);
    //~ }
	
    //~ ll query(int l, int r){ //INTERVAL [l, r)
		//~ pii resl = -INF, resr = resl; //INIT
		//~ for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
			//~ if(l&1) resl = comque(resl, t[l++]);
			//~ if(r&1) resr = comque(resr, t[--r]);
		//~ }
		//~ return comque(resl, resr);
    //~ }
    
    //LAZY--------------------------------------------------------------
    void apply(int p, ll val){
		t[p] = comupd(t[p], val);
		if(p<n) 
			d[p] = comupd(d[p], val);
	}

	void build_up(int p){
		while(p>1){
			p >>= 1, 
			t[p] = comque(t[p<<1], t[p<<1|1]);
			t[p] = comupd(t[p], d[p]);
		}
	}

	void push(int p){
		for(int s=h; s>0; --s){
			int i = p >> s;
			if(d[i] != 0){
				apply(i<<1, d[i]);
				apply(i<<1|1, d[i]);
				d[i] = 0;
			}
		}
	}

	void upd(int l, int r, ll val){
		int l0 = l+n, r0 = r+n;
		for (; l0 < r0; l0 >>= 1, r0 >>= 1){
			if (l0&1) apply(l0++, val);
			if (r0&1) apply(--r0, val);
		}
		build_up(l+n);
		build_up(r-1+n);
	}

	ll query(int l, int r){
		int l0 = l+n, r0 = r+n;
		push(l0);
		push(r0 - 1);
		ll resl = -INF, resr = resl; //CHANGE
		for(; l0<r0; l0>>=1, r0>>=1) {
			if(l0&1) resl = comque(resl, t[l0++]);
			if(r0&1) resr = comque(resr, t[--r0]);
		}
		return comque(resl, resr);
	}
};

struct tgraph{
	matint al, par; //INPUT UNDIRECTED EDGES
	arint dep;
	int h;

	void init(){
		al.resize(n+5); //1-INDEX
		dep.resize(n+5);
	}
	
	void bfs(){
		queue<pair<pii, int>> q;
		q.push({{1, 1}, 0});
		while(!q.empty()){
			int p = q.front().f.f, node = q.front().f.s;
			dep[node] = q.front().s;
			q.pop();
			par[0][node] = p;
			for(int i:al[node]){
				if(i == p) continue;
				q.push({{node, i}, dep[node]+1});
			}
		}
	}
	
	void build2dec(){
		h = binlog(n);
		par.resize(h+1, arint(n+5, 0));
		bfs();
		//~ cerr<<"[par] = [\n0: ";
		//~ for1(i, n) cerr<<par[0][i]<<", ";
		//~ cerr<<"]\n";
		for1(i, h){
			//~ cerr<<i<<": [";
			for1(j, n){
				par[i][j] = par[i-1][par[i-1][j]];
				//~ cerr<<par[i][j]<<", ";
			}
			//~ cerr<<"]\n";
		}	
	}
	
	int kpar(int node, int k){
		//~ cerr<<"[node, k] = ["<<node<<", "<<k<<"]\n";
		for0(i, h+1){
			if(k>>i & 1){
				node = par[i][node];
			}
		}
		//~ cerr<<"[after jump] = ["<<node<<"]\n";
		return node;
	}

	int lca(int u, int v){
		if(dep[u] < dep[v]) swap(u, v);
		//~ cerr<<"[u, v, dep[u], dep[v]] = ["<<u<<", "<<v<<", "<<dep[u]<<", "<<dep[v]<<"]\n";
		u = kpar(u, dep[u]-dep[v]);
		if(u == v) return u;
		for(int i=h; i>=0; i--)
			if(par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
		
		return par[0][u];
	}
};

struct dsunion{
	arint par, sz, rk;
	
	void resize(int l){
		par.resize(l);
		sz.resize(l);
		rk.resize(l);
	}
	
	void make(int v){
	    par[v] = v;
		//~ sz[v] = 1; //BY SIZE
		rk[v] = 0; //BY RANK
	}
	
	int find(int v){
	    if (v == par[v])
	        return v;
	    return par[v] = find(par[v]);
	}

	bool merge(int a, int b){
	    a = find(a);
	    b = find(b);
	    if (a != b){
			//BY SIZE
			//~ if(sz[a] < sz[b]) swap(a, b);
			//~ sz[a] += sz[b];
			//BY RANK
			if(rk[a] < rk[b]) swap(a, b);
			if(rk[a] == rk[b]) rk[a]++;
			par[b] = a;
			return true;
	    }
	    return false;
	}
};

struct line{ //STRUCT FOR LICHAO TREE
    ll m, c;
    line(){
        m = 0, c = -2e18;
    }
    line(ll _m, ll _c){
        m = _m, c = _c;
    }
    ll operator () (int x) {return (ll) m * x + c;}
    bool operator == (line nl) {return m == nl.m && c == nl.c;}
};
 
struct lcnode{ //LICHAO TREE ( SEGTREE [l, r) ) USING LINES) TO FIND MAX Y
    int s, e, m;
    line ln;
    lcnode *l = nullptr, *r = nullptr;
    lcnode(int _s, int _e){
        s = _s, e = _e, m = (s + e) >> 1;
    }
    
    void mc(){
        if(l != nullptr || s + 1 == e)return;
        l = new lcnode(s, m);
        r = new lcnode(m, e);
    }
    
    ll query(int x){
        if(s + 1 == e || l == nullptr) return ln(x);
        else if(x < m) return max(ln(x), l->query(x));
        else return max(ln(x), r->query(x));
    }
    
    void insert(line nl){
        if(s + 1 == e){
            if(ln(s) < nl(s))swap(ln, nl);
            return;
        }
        bool lf = ln(s) > nl(s), mid = ln(m) < nl(m), rgt = ln(e) > nl(e);
        if(mid) swap(ln, nl);
        if(nl == line() || lf == rgt) return;
        mc();
        if(lf != mid) r->insert(nl);
        else l->insert(nl);
    }
};

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;

//CODED ALGO HERE--------------------------------------------

arint dijkstra(matpii al, ll st){ //SINGLE SOURCE SHORTEST PATH (POSITIVE)
	arint d(n+5, -1);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, st});
	while(!pq.empty()){
		int weight = pq.top().f, node = pq.top().s;
		
		pq.pop();
		if(d[node] == -1)
			d[node] = weight;
		else if(d[node] < weight) continue;
		
		for(auto [v, w]:al[node]){
			if(d[v] == -1 || d[v] > weight + w){
				d[v] = weight + w;
				pq.push({d[v], v});
			}
		}
	}
	for1(i, n) if(d[i] == -1) d[i] = INF;
	return d; //DIST FROM ST TO OTHER NODES
}

pair<arint, bool> bellman_ford(matpii al, int st){ //SSSP (NEGATIVE), NEGATIVE WEIGHT LOOP
    //SSSP
    arint d(MAXN, INF);
    d[st] = 0;
    for1(i, n-1){
        bool modified = false;
        for1(v, n){
			if(d[v] == INF) continue;
			for(auto node:al[v]){
				if(d[v] + node.s > d[node.f]) continue;
				d[node.f] = d[v] + node.s;
				modified = true;
			}
		}
		
		if(!modified) break;
    }
    //CHECK FOR NEGATIVE LOOP
	bool isNegLoop = false;
    for1(i, n-1){
		if(isNegLoop == true) break;
		for1(v, n){
			if(isNegLoop == true) break;
			for(auto node:al[v]){
				if(d[v] + node.s >= d[node.f]) continue; 
				isNegLoop = true;
				break;
			}
		}
	}
    return {d, isNegLoop};
}

matint floyd_warshall(matpii al){ //ALL PAIRS SHORTEST PATH
	matint ans(n+5, arint(n+5, INF));
	for1(i, n){
		ans[i][i] = 0;
		for(auto [v, w]:al[i]){
			ans[i][v] = min(ans[i][v], w);
		}
	}	
	for1(m, n)
		for1(u, n)
			for1(v, n){
				if(ans[u][m] != INF && ans[m][v] != INF)
					ans[u][v] = min(ans[u][v], ans[u][m] + ans[m][v]);
			}
	return ans;
}

matpii mst_kruskal(vector<pair<int, pii>> edges, int e){ //edges[i] = {weight, {u, v}}
	arbool isV(n+5, false);
	matpii al(n+5, arpii());
	sort(edges.begin()+1, edges.begin()+1+e); //MIN SPANNING TREE
	for1(i, e){
		int w = edges[i].f, u = edges[i].s.f, v = edges[i].s.s;
		if(isV[u] && isV[v]) continue; //DIRECTED
		isV[u] = isV[v] = true;
		al[u].pb({v, w});
	}
	return al;
}

matpii mst_prim(matpii al){ 
	//PRIM
	bool isV[n+5] = {0};
	matpii ans(n+5, arpii());
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq; //MIN SPANNING TREE
	pq.push({0, {0, 1}}); //MIN SPANNING TREE
	while(!pq.empty()){
		int w = pq.top().f, u = pq.top().s.f, v = pq.top().s.s; 
		pq.pop();
		isV[u] = isV[v] = true;
		ans[u].pb({v, w}); //DIRECTED
		for(auto i:al[v]){
			if(isV[v] && isV[i.f]) continue;
			pq.push({i.s, {v, i.f}});
		}
	}
	return ans;
}

bool topodfs(int u, arint &topo, arint &visit, matint al){
	visit[u] = 1;
	for(int i:al[u]){
		if(visit[i] == 1) return 0; // CHANGE TO continue; IF FIND HAMILTON PATH
		if(!visit[i])
			if(!topodfs(i, topo, visit, al)) return 0;
	}
	topo.pb(u);
	visit[u] = 2;
	return 1;
}

arint toposort(matint al){ // TOPOSORT FROM SOURCE TO CHILD
	arint visit(n+1, 0), ans;
	for1(i, n)
		if(!visit[i])
			if(!topodfs(i, ans, visit, al)) return arint(0);
	reverse(all(ans));
	return ans;
}

//VARIABLE HERE----------------------------------------------
int t;
matbool s1, s2;

//CODE-------------------------------------------------------
void solve(){
	cin>>n;
	s1 = *new matbool(n+1, arbool(n+1));
	s2 = *new matbool(n+1, arbool(n+1));
	
	for1(i, n)
		for1(j, n) cin>>s1[i][j];
	
	for1(i, n)
		for1(j, n) cin>>s2[i][j];
	
	int ansmn = 0, ansmx = 0, cnt1, cnt2;
	for1(i, n){
		cnt1 = cnt2 = 0;
		for1(j, n){
			cnt1 += s1[i][j]; cnt2 += s2[i][j];
			ansmx += 3* (s1[i][j] | s2[i][j]);
		}
		ansmn += max(cnt1, cnt2);
	}
	
	cout<<ansmx<<' '<<ansmn<<"\n";
}

int32_t main(){
    FAST_IO
	//~ freopen("INP.txt", "r", stdin);
	//~ freopen("OUT.txt", "w", stdout);
	cin>>t;
	while(t--) solve();
    return 0;
}
