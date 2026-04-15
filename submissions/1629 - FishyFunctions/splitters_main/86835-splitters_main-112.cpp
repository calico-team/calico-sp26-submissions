#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int gox[4] = {0, 1, 0, -1};
int goy[4] = {-1, 0, 1, 0};

struct frac {
    int n, d;
    frac(int n_, int d_) : n(n_), d(d_) {};
};

int gcd(int a, int b) {
    if(a == 0 || b == 0) return 1;
    while(a != b) {
        if(a > b) {
            a %= b;
        }
        else if(b > a) {
            b %= a;
        }
    }
    
    return a;
    
}

frac fadd(frac a, frac b) {
    frac ans = frac(a.n*b.d+b.n*a.d, a.d*b.d);
    int curgcd = gcd(ans.n, ans.d);
    ans.n /= curgcd;
    ans.d /= curgcd;
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
while(t--) {
    int n, m;
    cin >> n >> m;
    vector<string> grid (n);
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    vector<vector<frac> > ans (n, vector<frac> (m, frac(0, 1)));
    vector<vector<int> > ins (n, vector<int> (m, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == '.') continue;
            for(int k = 0; k < 4; ++k) {
                int newx = i + gox[k];
                int newy = j + goy[k];
                if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
                if(k == 0 && grid[newx][newy] == '>') ins[i][j]++;
                if(k == 1 && grid[newx][newy] == '^') ins[i][j]++;
                if(k == 2 && grid[newx][newy] == '<') ins[i][j]++;
                if(k == 3 && grid[newx][newy] == 'v') ins[i][j]++;
                if(k == 0 && grid[newx][newy] == 'S' && grid[i][j] != '<') ins[i][j]++;
                if(k == 1 && grid[newx][newy] == 'S' && grid[i][j] != 'v') ins[i][j]++;
                if(k == 2 && grid[newx][newy] == 'S' && grid[i][j] != '>') ins[i][j]++;
                if(k == 3 && grid[newx][newy] == 'S' && grid[i][j] != '^') ins[i][j]++;
            }
        }
    }
    vector<vector<int> > outs (n, vector<int> (m, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] != 'S') continue;
            int gotos = 0;
            for(int k = 0; k < 4; ++k) {
                int newx = i + gox[k];
                int newy = j + goy[k];
                if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
                if(grid[newx][newy] == '.') continue;
                gotos++;
            }
            outs[i][j] = gotos-ins[i][j];
        }
    }

    // cout << "\n\n THIS IS INS: \n";
    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < m; ++j) {
    //         cout << ins[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << "\n\n THIS IS OUTS: \n";
    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < m; ++j) {
    //         cout << outs[i][j];
    //     }
    //     cout << '\n';
    // }

    queue<pair<int, int> > process;
    process.push(make_pair(0, 0));
    ans[0][0] = frac(1, 1);
    pair<int, int> anspos;
    bool ansposFound = false;
    while(!process.empty()) {
        auto cur = process.front();
        process.pop();
        int curx = cur.first;
        int cury = cur.second;
        //cout << "processing " << curx << ' ' << cury << endl;
        if(grid[curx][cury] == 'S') {
            //currently, ans[curx][cury] is the total input we are getting, now we gotta distribute it
            for(int i = 0; i < 4; ++i) {
                int newx = curx + gox[i];
                int newy = cury + goy[i];
                if(newx < 0 || newx >= n) continue;
                if(newy < 0 || newy >= m) continue;
                if(grid[newx][newy] == '.') continue;
                if(i == 0 && grid[newx][newy] == '>') continue;
                if(i == 1 && grid[newx][newy] == '^') continue;
                if(i == 2 && grid[newx][newy] == '<') continue;
                if(i == 3 && grid[newx][newy] == 'v') continue;
                ans[newx][newy] = fadd(ans[newx][newy], frac(ans[curx][cury].n, ans[curx][cury].d * outs[curx][cury])); //split the things
                ins[newx][newy]--;
                if(ins[newx][newy] == 0) process.push(make_pair(newx, newy));
            }
            
            
        }
        else if(grid[curx][cury] == 'X') { //yay we can just delete it lol
            ans[curx][cury] = frac(0, 1);
        }
        else { //push it to the next section if its also a conveyor
            int newx = curx, newy = cury;
            if(grid[curx][cury] == '<') {
                newy -= 1;
            }
            if(grid[curx][cury] == '>') {
                newy += 1;
            }
            if(grid[curx][cury] == '^') {
                newx -= 1;
            }
            if(grid[curx][cury] == 'v') {
                newx += 1;
            }
            if(newx < 0 || newy < 0 || newx >= n || newy >= m) {
                anspos = make_pair(curx, cury);
                ansposFound = true;
                continue;
            }
            if(grid[newx][newy] == '.') continue;
            ans[newx][newy] = fadd(ans[newx][newy], ans[curx][cury]);

            ins[newx][newy]--;
            if(ins[newx][newy] == 0) process.push(make_pair(newx, newy));
            
        
        }
    }
    if(ansposFound) cout << ans[anspos.first][anspos.second].n << ' ' << ans[anspos.first][anspos.second].d << '\n';
    else {
        cout << "0 1\n";
    }

    // cout << "\n\nTHESE ARE THE fracs" << '\n';
    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < m; ++j) {
    //         cout << ans[i][j].n << '/' << ans[i][j].d << ' ';
    //     }
    //     cout << '\n';
    // }
}
}