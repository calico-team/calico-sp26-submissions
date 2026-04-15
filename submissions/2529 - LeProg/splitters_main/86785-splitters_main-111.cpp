#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<pair<ll,ll>>> total;
ll n,m;
vector<string> s;
vector<ll> xm = {0,1,0,-1};
vector<ll> ym = {1,0,-1,0};
pair<ll,ll> output = {0,1};
pair<ll,ll> point(ll r, ll c){
    if(s[r][c] == '<'){
        if(c-1<0) return {-1,-1};
        return {r,c-1};
    }
    if(s[r][c] == '>'){
        if(c+1>=m) return {-1,-1};
        return {r,c+1};
    }
    if(s[r][c] == 'v'){
        if(r+1>=n) return {-1,-1};
        return {r+1,c};
    }
    if(s[r][c] == '^'){
        if(r-1<0) return {-1,-1};
        return {r-1,c};
    }
    return {r,c};
}
void fracaddd(pair<ll,ll> &f1, pair<ll,ll> &f2){
    f1 = {f1.first*f2.second+f1.second*f2.first,f1.second*f2.second};
}

void traverse(ll r, ll c,ll pc, ll pr,pair<ll,ll> add){
    // cout << add.first << " " << add.second << "\n";
    // for(ll i = 0; i<n; i++){
    //         for(ll j = 0; j<m; j++){
    //             cout << total[i][j].first << "/" << total[i][j].second << "  ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n\n";
    if(s[r][c] == '.') return;
        if(s[r][c] == 'X') return;
    pair<ll,ll> dest = point(r,c);
    if(dest.first == -1){
        fracaddd(output, add);
        return;
    }
    if(s[r][c] == 'S'){
        vector<pair<ll,ll>> targets;
        for(ll i = 0; i<4; i++){
            ll nr = r+xm[i], nc = c+ym[i];
            if(nr<0 || nc<0 || nr>=n || nc >= m){
                continue;
            }
            if(s[nr][nc] == '.' || point(nr,nc) == pair<ll,ll>{r,c}){
                continue;
            }
            if(nr == pr && nc == pc) continue;
            targets.push_back({nr,nc});
        }
        pair<ll,ll> P = {add.first,add.second*targets.size()};
        for(auto i:targets){
            fracaddd(total[i.first][i.second], P);
        }
        for(auto i:targets){
            traverse(i.first,i.second,c,r,P);
        }
    }
    
    else if(point(r,c) != pair<ll,ll>{r,c}){
        
        // cout << r << ", " << c << " --> " << dest.first << ", " << dest.second << "\n";
        fracaddd(total[dest.first][dest.second],add);
        traverse(dest.first,dest.second,c,r,add);
    }
}
int main(){
    ll t; cin >> t;
    for(ll ii = 0; ii<t; ii++){
         cin >> n >> m;
        s=vector<string>(n);
        for(ll i = 0; i<n; i++){
            cin >> s[i];
        }
        total = vector<vector<pair<ll,ll>>>(n, vector<pair<ll,ll>>(m,{0,1}));
        total[0][0] = {1,1};
        s.clear();
        output = {0,1};
        traverse(0,0,-1,-1,{1,1});
        // for(ll i = 0; i<n; i++){
        //     for(ll j = 0; j<m; j++){
        //         cout << total[i][j].first << "/" << total[i][j].second << "  ";
        //     }
        //     cout << "\n";
        if(output.first != 0){
            ll g = __gcd(output.first,output.second);
            output.first /= g;
            output.second /= g;
            cout << output.first << " " << output.second << "\n";
        }
        else{
            cout << "0 1\n";
        }
    }
}
/*
2
6 10
v.........
v.........
v.......
S>........
v.........
S.........
3 3
vX.
>SX
.X.

*/