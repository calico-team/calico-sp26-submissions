#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Minimize F(b) = sum_{i=0}^{N-2}|b[i]-b[i+1]| + sum_{i=0}^{N-1}|b[i]-A[i]|
//
// SLOPE TRICK (correct version using multisets):
//
// f_i(x) = min_{b[0]..b[i-1]} cost with b[i]=x
// f_0(x) = |x - A[0]|
// f_i(x) = |x - A[i]| + min_y{ f_{i-1}(y) + |y-x| }
//
// We represent f_i by:
//   L = multiset of left breakpoints (sorted ascending)
//       L.max() = left boundary of flat region
//       slope to the left = -|L|
//   R = multiset of right breakpoints (sorted ascending)
//       R.min() = right boundary of flat region
//       slope to the right = +|R|
//
// INFIMAL CONVOLUTION with |t| clips slopes to [-1,+1]:
//   Flat region boundaries stay UNCHANGED. Only slope magnitudes reduce.
//   If |L| >= 2: erase L.min() (keeps flat boundary L.max intact)
//   If |R| >= 2: erase R.max() (keeps flat boundary R.min intact)
//
// ADD |x - a|: insert a into both L and R, fix if L.max > R.min.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<ll> A(N);
        for(auto& x : A) cin >> x;

        multiset<ll> L, R;
        ll cost = 0;
        vector<ll> fl(N), fr(N);

        for(int i = 0; i < N; i++){
            if(i > 0){
                if(L.size() >= 2) L.erase(L.begin());
                if(R.size() >= 2) R.erase(prev(R.end()));
            }

            ll a = A[i];
            L.insert(a);
            R.insert(a);

            ll lmax = *L.rbegin();
            ll rmin = *R.begin();
            if(lmax > rmin){
                cost += lmax - rmin;
                L.erase(L.find(lmax));
                R.erase(R.find(rmin));
                L.insert(rmin);
                R.insert(lmax);
            }

            fl[i] = *L.rbegin();
            fr[i] = *R.begin();
        }

        vector<ll> the_two_tower_heights(N);
        the_two_tower_heights[N-1] = max(fl[N-1], min(fr[N-1], A[N-1]));
        the_two_tower_heights[N-1] = max(1LL, min(2000000000LL, the_two_tower_heights[N-1]));

        for(int i = N-2; i >= 0; i--){
            ll nxt = the_two_tower_heights[i+1];
            ll val = max(fl[i], min(fr[i], nxt));
            the_two_tower_heights[i] = max(1LL, min(2000000000LL, val));
        }

        for(int i = 0; i < N; i++){
            cout << the_two_tower_heights[i];
            if(i < N-1) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}

void read_your_input(){
    // T test cases
    // Each: N, then N integers A[0..N-1]
}