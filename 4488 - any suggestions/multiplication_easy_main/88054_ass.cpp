#include <bits/stdc++.h>
using namespace std;

struct con{
    int r, c, v, w, idx;
    con(int r, int c, int v, int w, int idx) : r(r), c(c), v(v), w(w), idx(idx) {}
};
vector<con> cons;
int A[4003];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, d; cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        int r, c, v, w; cin >> r >> c >> v >> w;
        cons.push_back({r, c, v, w, i+1});
    }
    sort(cons.begin(), cons.end(), [](con a, con b){
        return (double)a.w / a.v > (double)b.w / b.v; 
    });
    for (int i = 0; i < m; i++){
        int r = cons[i].r, c = cons[i].c, v = cons[i].v;
        int x = sqrt(v);
        if (A[r] == 0 && A[c] == 0){
            A[r] = x;
            A[c] = v / x;
        } else if (A[r] != 0){
            if (A[c] != 0) A[c] = v / A[r];
        } else if (A[c] != 0){
            if (A[r] != 0) A[r] = v / A[c];
        }
    }
    sort(cons.begin(), cons.end(), [](con a, con b){
         int x = a.w * llabs(A[a.r] * A[a.c] - a.v) / double(a.v);
         int y = b.w * llabs(A[b.r] * A[b.c] - b.v) / double(b.v);
         return x > y;
    });
    for (int i = 1; i <= n; i++){
        cout << (A[i]==0?1:A[i]) << " \n"[i == n];
    }
    cout << d << " ";
    for (int i = 0; i < d; i++){
        cout << cons[i].idx << " \n"[i == d-1];
    }
}