#include <bits/stdc++.h>
using namespace std;

/**
 * Simulate the factory and return the final output as the fraction P / Q.
 *
 * N: number of rows in the factory grid
 * M: number of columns in the factory grid
 * factory: vector of N strings of length M, each character one of '^<>vSX.'
 */
 
#define ll long long

ll lcm(ll a, ll b){
	return a*b/__gcd(a, b);
}

char move_lwn[] = {'<', '>', 'v', '^'};
char move_c[] = {'>', '<', '^', 'v'};
ll move_X[] = {1, -1, 0, 0};
ll move_Y[] = {0, 0, -1, 1};
 
 
pair<long long, long long> solve(ll N, ll M, vector<string>& factory) {
    // YOUR CODE HERE
	/*
		a = start
		e = end
		X = dead
		S = split
	*/

	ll par[N+2][M+2];
	ll ch[N+2][M+2];
	ll idx_cur = 2;
	memset(ch, 0, sizeof(ch));
	memset(par, 0, sizeof(par));
	map<ll,char> tipe;
	vector<ll> adj[N*M+7], radj[N*M+7];
	
	tipe[1] = 'a';
	{
		
		stack<tuple<ll,ll,ll>> q;
		q.push({0, 0, 1});
		while(!q.empty()){
			auto [y, x, prev] = q.top();
			q.pop();
			
			if(ch[y][x] == 1){
				//connect ama yang udah kelar
				int tmp = par[y][x];
				if(par[y][x] == 0)assert(0);
//				cout<<prev<<" -> "<<tmp<<"\n";
				adj[prev].push_back(tmp);
				radj[tmp].push_back(prev);
				continue;
			}	
			ch[y][x] = 1;
			par[y][x] = idx_cur;
//			cout<<">>>>>"<<y<<" "<<x<<" "<<prev<<"\n";
			if(factory[y][x] == 'S'){
				adj[prev].push_back(idx_cur);
				radj[idx_cur].push_back(prev);
				tipe[idx_cur] = 'S';
//				cout<<prev<<" -> "<<idx_cur<<"\n";
				prev = idx_cur;
				idx_cur++;
				
				
				for(ll i=0; i<4; i++){
					ll move_y = y+move_Y[i];
					ll move_x = x+move_X[i];
					
					if(move_y < 0 || move_x < 0 || N <= move_y || M <= move_x){
						adj[prev].push_back(idx_cur);
						radj[idx_cur].push_back(prev);
						idx_cur++;
						continue;
					}
					if(factory[move_y][move_x] == '.')continue;
					if(factory[move_y][move_x] == move_lwn[i])continue;
					
					q.push({move_y, move_x, prev});
				}
				
				continue;
			}else if(factory[y][x] == 'X'){
				adj[prev].push_back(idx_cur);
				radj[idx_cur].push_back(prev);
				tipe[idx_cur] = 'X';
//				cout<<prev<<" -> "<<idx_cur<<"\n";
				idx_cur++;
				
				continue;
			}else{
				for(ll i=0; i<4; i++){
					if(factory[y][x] != move_c[i])continue;
					ll move_y = y+move_Y[i];
					ll move_x = x+move_X[i];
					
					
					if(move_y < 0 || move_x < 0 || N <= move_y || M <= move_x){
						adj[prev].push_back(idx_cur);
						radj[idx_cur].push_back(prev);
						tipe[idx_cur] = 'e';
//						cout<<prev<<" -> "<<idx_cur<<"\n";
						idx_cur++;
						continue;
					}
					
					q.push({move_y, move_x, prev});
					break;
				}
			}
			
		}	
	}
    
//    for(int i=0; i<N; i++){
//    	for(int j=0; j<M; j++){
//    		cout<<par[i][j];
//		}
//		cout<<"\n";
//	}
    
    vector<ll> atas(N*M+7), bawah(N*M+7, 1);
    atas[1] = bawah[1] = 1;
    vector<ll> ct(N*M+7);
    queue<ll> q;
    q.push(1);
    
    while(!q.empty()){
    	auto tp = q.front();
    	q.pop();
    	
    	ct[tp]++;
    	
    	if(ct[tp] < radj[tp].size())continue;
    	if(tipe[tp] == 'X' || tipe[tp] == 'e')continue;
		ll dead = 0;
		
		if(tipe[tp] == 'S'){
			bawah[tp] *= adj[tp].size();
		}
//    	cout<<tp<<" "<<tipe[tp]<<" "<<atas[tp]<<" "<<bawah[tp]<<"\n";
		
		for(auto k : adj[tp]){
			ll LCM = lcm(bawah[k], bawah[tp]);
			{
				ll tmp = LCM/bawah[k];
				atas[k] *= tmp;
				bawah[k] *= tmp;
			}
			{
				ll tmp = LCM/bawah[tp];
				atas[tp] *= tmp;
				bawah[tp] *= tmp;
			}
			
			atas[k] += atas[tp];
			{
				ll tmp = __gcd(atas[k], bawah[k]);
				atas[k] /= tmp;
				bawah[k] /= tmp;
			}
			q.push(k);	
		}
	}
    
    ll atas_ans = 0, bawah_ans = 1;
    for(auto [k, type] : tipe){
    	if(type != 'e')continue;
		ll LCM = lcm(bawah[k], bawah_ans);
		{
			ll tmp = LCM/bawah[k];
			atas[k] *= tmp;
			bawah[k] *= tmp;
		}
		{
			ll tmp = LCM/bawah_ans;
			atas_ans *= tmp;
			bawah_ans *= tmp;
		}
		
		atas_ans += atas[k];
		{
			ll tmp = __gcd(atas_ans, bawah_ans);
			atas_ans /= tmp;
			bawah_ans /= tmp;
		}  	
	}
    
    
    
    return {atas_ans, bawah_ans};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin >> T;
    while (T--) {
        ll N, M;
        cin >> N >> M;
        vector<string> factory(N);
        for (ll i = 0; i < N; i++) cin >> factory[i];
        auto [P, Q] = solve(N, M, factory);
        cout << P << " " << Q << "\n";
    }
    return 0;
}
