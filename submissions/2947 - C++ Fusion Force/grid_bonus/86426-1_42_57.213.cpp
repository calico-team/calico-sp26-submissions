#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(int N, vector<int>& A) {
    vector<ll> lft(N), rgt(N);

    priority_queue<ll> L;
    priority_queue<ll, vector<ll>, greater<ll>> R;

    auto addAbs = [&](ll a) {
        L.push(a);
        R.push(a);
        if (L.top() > R.top()){
            ll lv = L.top(), rv = R.top();
            L.pop(); R.pop();
            L.push(rv); R.push(lv);
        }
    };

    addAbs(A[0]);
    lft[0] = L.top();
    rgt[0] = R.top();

    for (int i =1; i < N; i++) {
        ll lt = L.top(), rt = R.top();
        while (!L.empty()) L.pop();
        while (!R.empty()) R.pop();
        L.push(lt); 
        R.push(rt);
        addAbs(A[i]);
        lft[i] = L.top();
        rgt[i] = R.top();
    }

    // Reconstruct path backwards
    vector<int> B(N);
    B[N-1] = (int)lft[N-1];
    for (int i = N-2; i >= 0; i--) {
        ll v = B[i+1];
        B[i] = (int)max(lft[i], min(rgt[i], v));
    }
    return B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        vector<int> result = solve(N, A);
        for (int i = 0; i < N; i++) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}