#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e18;
vector<vector<char>> out;
int P, A, B;
int cp2() {
    int o = 1;
    for (int i = 0; i < A-1; i++) {
        if (o > P) return 0;
        o *= 2ll;
    }
    for (int i = 0; i < B; i++) {
        if (o > P) return 0;
        o *= 3ll;
    }
    if (P >= o) return 1;
    else return 0;
}
int cp3() {
    int o = 1;
    for (int i = 0; i < A; i++) {
        if (o > P) return 0;
        o *= 2ll;
    }
    for (int i = 0; i < B-1; i++) {
        if (o > P) return 0;
        o *= 3ll;
    }
    if (P >= o * 2ll) return 2;
    if (P >= o) return 1;
    else return 0;
}
int gen() {
    int o = 1;
    for (int i = 0; i < A; i++) o *= 2ll;
    for (int i = 0; i< B; i++) o *= 3ll;
    return o;
}
const int db = 1500;
void docase(){
    cin >> P >> A >> B;
    out = vector<vector<char>>(3, vector<char> (db, '.'));
    out[0][0] = '>';
    out[1][0] = 'v';
    int cur = 1;
    while (A > 0) {
        int x = cp2();
        out[1][cur] = 'S';
        if (x == 0) {
            out[0][cur] = 'X';
            out[2][cur] = '<';
        }
        else {
            out[0][cur] = '<';
            out[2][cur] = '<';
        }
        out[1][cur+1] = 'v';
        cur += 2;
        A--;
        if (x == 1){
            P -= gen();
        }
    }
    while (B > 0) {
        int x = cp3();
        out[1][cur] = 'S';
        if (x == 0) {
            out[0][cur] = 'X';
            out[2][cur] = 'X';
            out[1][cur+1] = 'v';
        cur += 2;
        B--;
        }
        else if (x == 1){
            out[0][cur] = '<';
            out[2][cur] = 'X';
            out[1][cur+1] = 'v';
        cur += 2;
        B--;
        P -= gen();
        }
        else {
            out[0][cur] = '<';
            out[2][cur] = '>';
            out[1][cur+1] = 'v';
        cur += 2;
        B--;
        P -= gen();
        P -= gen();
        }
    }
    if (P == 0) out[1][cur] = 'X';
    else out[1][cur] = '<', out[0][cur] = '<';
    cout << "1500 3\n";
    for (int i = 0; i < db; i++) {
        cout << out[0][i] << ' ' << out[1][i] << ' ' << out[2][i] << '\n';
    }
}

signed main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int i = 0 ; i < tt; i++){
        docase();
    }
    return 0;
}