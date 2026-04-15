# include <bits/stdc++.h>
using namespace std;

vector<string> gr;
vector<pair<long long, long long> > d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;

pair<long long, long long> sm(pair<long long, long long> a, pair<long long, long long> b){
    if(a.second == b.second){
        return make_pair(a.first + b.first, a.second);
    }
    return make_pair(a.first * b.second + b.first * a.second, a.second * b.second);
}

pair<long long, long long> calc(pair<long long, long long> i, pair<long long, long long> c){
    pair<long long, long long> prv = c;
    while(true){
        if(c.first == -1 || c.second == -1 || c.first == n || c.second == m){
            return i;
        }
        if(gr[c.first][c.second] == 'X'){
            return make_pair(0, 1);
        }
        if(gr[c.first][c.second] == 'S'){
            int p = 0;
            for(int x = 0; x < 4; x++){
                pair<long long, long long> tst = make_pair(c.first + d[x].first, c.second + d[x].second);
                if(tst.first >= 0 && tst.first < n && tst.second >= 0 && tst.second < m && gr[tst.first][tst.second] != '.' && tst != prv){
                    ++p;
                }
            }
            pair<long long, long long> tot = make_pair(0, 1);
            for(int x = 0; x < 4; x++){
                pair<long long, long long> tst = make_pair(c.first + d[x].first, c.second + d[x].second);
                if(tst.first >= 0 && tst.first < n && tst.second >= 0 && tst.second < m && gr[tst.first][tst.second] != '.' && tst != prv){
                    pair<long long, long long> cr = calc(make_pair(i.first, i.second * p), tst);
                    pair<long long, long long> ret = sm(tot, cr);
                    tot = ret;
                }
            }
            return tot;
        }
        prv = c;
        if(gr[c.first][c.second] == '^'){
            --c.first;
        }
        else if(gr[c.first][c.second] == '>'){
            ++c.second;
        }
        else if(gr[c.first][c.second] == '<'){
            --c.second;
        }
        else if(gr[c.first][c.second] == 'v'){
            ++c.first;
        }
    }
}

int main() { 
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int tc;
    cin >> tc;
    for(int tc_ = 0; tc_ < tc; tc_++){
        cin >> n >> m;
        gr.resize(n);
        gr.shrink_to_fit();
        for(int x = 0; x < n; x++){
            cin >> gr[x];
        }
        pair<long long, long long> ans = calc(make_pair(1, 1), make_pair(0, 0));
        while(ans.first % 2 == 0 && ans.second % 2 == 0){
            ans.first /= 2;
            ans.second /= 2;
        }
        while(ans.first % 3 == 0 && ans.second % 3 == 0){
            ans.first /= 3;
            ans.second /= 3;
        }
        cout << ans.first << ' ' << ans.second << endl;
    }
}