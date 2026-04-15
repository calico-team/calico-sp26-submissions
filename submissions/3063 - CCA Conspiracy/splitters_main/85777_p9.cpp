#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define endl "\n"
#define mp make_pair
void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin); 
		freopen((name+".out").c_str(), "w", stdout);
	}
}

pi add_frac(pi a, pi b){
    int num = a.first * b.second + b.first * a.second;
    int den = a.second * b.second;
    int g = __gcd(num, den);
    return mp(num/g, den/g);
}

int main(){
    setIO("");
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        string grid[n];
        for (int i = 0; i < n; i++) cin>>grid[i];

        queue<pair<pi, pi>> q;
        pi dest = mp(0,1);
        q.push(mp(mp(0,0), mp(1,1)));
        
        while (!q.empty()){
            auto [p, cur] = q.front();
            q.pop();
            auto [r, c] = p;
            auto [num, den] = cur;
            if (grid[r][c] == 'X'){
                dest = add_frac(dest, cur);
            }
            else if (grid[r][c]=='S'){
                int valid = 0;
                if (r + 1 < n && (grid[r+1][c]!= '.' && grid[r+1][c] != '^')){
                    valid++;
                }
                if (r - 1 >= 0 && (grid[r-1][c]!= '.' && grid[r-1][c] != 'v')){
                    valid++;
                }
                if (c + 1 < m && (grid[r][c+1]!= '.' && grid[r][c+1] != '<')){
                    valid++;
                }
                if (c - 1 >= 0 && (grid[r][c-1]!= '.' && grid[r][c-1] != '>')){
                    valid++;
                }





                if (r + 1 < n && (grid[r+1][c]!= '.' && grid[r+1][c] != '^')){
                    q.push(mp(mp(r+1, c), mp(num, den*valid)));
                }
                if (r - 1 >= 0 && (grid[r-1][c]!= '.' && grid[r-1][c] != 'v')){
                    q.push(mp(mp(r-1, c), mp(num, den*valid)));
                }
                if (c + 1 < m && (grid[r][c+1]!= '.' && grid[r][c+1] != '<')){
                    q.push(mp(mp(r, c+1), mp(num, den*valid)));
                }
                if (c - 1 >= 0 && (grid[r][c-1]!= '.' && grid[r][c-1] != '>')){
                    q.push(mp(mp(r, c-1), mp(num, den*valid)));
                }
            }
            else if (grid[r][c] == '>'){
                if (c + 1 < m && grid[r][c+1] != '.'){
                    q.push(mp(mp(r, c+1), cur));
                } 
                
            }
            else if (grid[r][c] == '<'){
                if (c - 1 >= 0 && grid[r][c-1] != '.'){
                    q.push(mp(mp(r, c-1), cur));
                }
                
            }
            else if (grid[r][c] == '^'){
                if (r - 1 >= 0 && grid[r-1][c] != '.'){
                    q.push(mp(mp(r-1, c), cur));
                }
                
            }
            else if (grid[r][c] == 'v'){
                if (r + 1 < n && grid[r+1][c] != '.'){
                    q.push(mp(mp(r+1, c), cur));
                }
                
            }
        }
        pi ans = add_frac(dest, mp(-1,1));
        cout<<abs(ans.first)<<" "<<abs(ans.second)<<endl;
    }

}
