#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(vector<long long>& A) {
    int n = A.size();
    if (n == 1) return {A[0]};
    priority_queue<long long>L;                                       
    priority_queue<long long, vector<long long>, greater<long long>> R;
    vector<long long> lo(n), hi(n);
    for (int i =0; i< n;i++) {
        long long a= A[i];
        L.push(a);
        R.push(a);
        if (L.top() >R.top()) {
            long long lv= L.top(); L.pop();
            long long rv =R.top(); R.pop();
            L.push(rv);
            R.push(lv);
        }
        lo[i]= L.top();
        hi[i] = R.top();
        if (i <n- 1) {
            long long best_l = L.top();while (!L.empty()) L.pop(); L.push(best_l);
            long long best_r= R.top(); while (!R.empty()) R.pop(); R.push(best_r);
        }
    }
    vector<long long> b(n);
    b[n-1] = lo[n-1];
    for (int i = n -2;i >= 0; i--)
        b[i]= max(lo[i], min(hi[i],b[i+ 1]));
    return b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >>T;
    while (T--){
        int n; cin>> n;
        vector<long long>A(n);
        for (auto& x : A)cin>> x;
        auto b = solve(A);
        for (int i= 0; i <n;i++) { cout<< b[i];if(i <n -1) cout <<' '; }
        cout <<'\n';
    }
    return 0;
}