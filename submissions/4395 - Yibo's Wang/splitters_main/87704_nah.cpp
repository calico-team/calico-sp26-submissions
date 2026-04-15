#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#include <cassert>
#include<algorithm>
#include<queue>
#include <array>
#include<queue>
#include <bitset>
#include<numeric>
using namespace std;
#define int long long
#define pii pair<int,int>
int INF = 1e18;
int k, n, m;
//  ^ > v <

struct fract{
    int num, deno;
    void simp(){
        int g = gcd(num, deno);
        num /= g;
        deno /= g;
    }
};
fract add(fract a, fract b){
    fract ret = (fract){(a.num * b.deno + a.deno * b.num), (b.deno * a.deno)};
    ret.simp();
    return ret;
}
fract mult(fract a, fract b){
    fract lol = {a.num * b.num, (a.deno * b.deno)};
    lol.simp();
    return lol;
}



void solve(){
    cin >> n >> m;

    int dx[4] = {-m, 0, m, 0};
    int dy[4] = {0, 1, 0, -1};
    int drix[4] = {-1, 0, 1, 0};
    int driy[4] = {0, 1, 0, -1};
    map<char, int> dir;
    dir['^'] = 0;
    dir['>'] = 1;
    dir['v'] = 2;
    dir['<'] = 3;


    auto valid = [&](int x, int y){
        return x >= 0 && y >= 0 && x < n && y < m;
        };
    auto toH = [&](int x, int y){
        return x * m + y;
        };

    vector<string>v(n + 1);
    vector<vector<int>>adj(n * m + 1);
    int special = -1;


    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(v[i][j] == '.' || v[i][j] == 'X')continue;
            int node = i * m + j;
            if(dir.count(v[i][j])){
                int a = i + drix[dir[v[i][j]]];
                int b = j + driy[dir[v[i][j]]];

                if(!valid(a, b)){
                    //thsi is specail
                    assert(special == -1);
                    special = node;

                } else{
                    adj[node].push_back(toH(a, b));
                }

            } else{
                //can only be a split node

                assert(v[i][j] == 'S');
                for(int k = 0; k < 4; ++k){
                    int a = i + drix[k];
                    int b = j + driy[k];




                    if(v[a][b] == '.' || !valid(a, b))continue;
                    if(v[a][b] == 'X'){
                        adj[node].push_back(toH(a, b));
                        continue;
                    }




                    assert(v[a][b] != 'S');
                    if(toH(a, b) + dx[dir[v[a][b]]] + dy[dir[v[a][b]]] == node){
                        continue;
                    }
                    adj[node].push_back(toH(a, b));
                }
            }
        }
    }
    if(special == -1){
        cout << "0 1\n";
        return;
    }

    vector<int>in(n * m);
    for(int i = 0; i < n * m; ++i){
        for(int j : adj[i]){
            in[j]++;
        }
    }
    vector<fract>f(n * m);
    for(int i = 0; i < n * m; ++i){
        f[i] = {0, 1};
    }
    f[0] = {1, 1};



    assert(in[0] == 0);
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int sz = adj[cur].size();
        fract mul = {1, sz};
        for(int j : adj[cur]){
            f[j] = add(f[j], mult(f[cur], mul));
            in[j]--;
            if(in[j] == 0){
                q.push(j);
            }
        }
    }

    cout << f[special].num << " " << f[special].deno << "\n";
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while(T--){
        solve();
    }
}