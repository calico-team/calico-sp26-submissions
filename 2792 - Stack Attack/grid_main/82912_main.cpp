#include <iostream>
#include <vector>
#include<string>
#include <string>
#include <algorithm>
#include<utility>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <deque>
#include <math.h>
#include<random>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll MOD = 1e9 + 7;




int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    ll n;
    vll A;
    while (t--) {
        cin >> n;
        A.resize(n);
        for (int i = 0; i<n; i++) {
            cin >> A[i];
        }
        if (n<3) {
            for (auto& a : A) {
                cout << a << ' ';
            }
        }
        else {
            if (A[0] < A[1] && A[2] < A[1]) {
                A[1] = max(A[0], A[2]);
            }
            else if (A[0] > A[1] && A[2] > A[1]) {
                A[1] = min(A[0], A[2]);
            }
            for (auto& a : A) {
                cout << a << ' ';
            }

        }
        cout << "\n";
    }


}