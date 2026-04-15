#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gg(i, m, n) for(i = m; i < n; i++)
#define pb push_back
#define sz(x) (int)x.size()
#define all(v) (v).begin(), (v).end()

const int nm = 1e3 + 5;

char tab[nm][nm];

void pre_build() {

    for(int i = 0; i < nm; i++) {
        for(int j = 0; j < nm; j++) {
            tab[i][j] = '-';
        }
    }

    // El centro es arbitrario
    /* Cruz base:
       | |0| |
       |1|2|3|
       | |4| |
    Forma de expansion:
    1. Un movimiento en una direccion cualquiera
    2. Giro a la izquierda y mover dos casillas
    */
    
    int dx[] = {-1, +1, -2, +2};
    int dy[] = {-2, +2, +1, -1};
    
    queue<pair<int, int>> q;
    int x = 20, y = 20;
    
    tab[x - 1][y] = '0';
    tab[x][y - 1] = '1';
    tab[x][y]     = '2';
    tab[x][y + 1] = '3';
    tab[x + 1][y] = '4';
    
    q.push({x, y});
    q.push({x - 1, y});
    q.push({x + 1, y});
    q.push({x, y - 1});
    q.push({x, y + 1});
    
    while(sz(q)) {
        x = q.front().first; y = q.front().second; q.pop();
        int i; gg(i, 0, 4) {
            int xi = x + dx[i];
            int yi = y + dy[i];
            if(xi < 0 or yi < 0 or xi >= nm or yi >= nm) continue;
            if(tab[xi][yi] != '-') continue;
            tab[xi][yi] = tab[x][y];
            q.push({xi, yi});
        }
    }
}

void go() {
    int n, m; cin >> n >> m;
    int i, j;
    gg(i, 0, n) {
        gg(j, 0, m) {
            cout << tab[i][j];
        } cout << "\n";
    }
    // cout << "-------------\n";
}

int main() {
    // ifstream cin("input.txt"); ofstream cout("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    pre_build();
    int tc; cin >> tc;
    while(tc--) go();

    return 0;
}