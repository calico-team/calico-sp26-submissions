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
    string A,B;
    while (t--) {
        cin >> A >> B;
        string ans = "";
        ll curr = 0;
        for (int i = 0; i<A.size(); i++) {
            if (curr < B.size() && B[curr] == A[i]) {
                curr++;
                ans += A[i];
            }
            else {
                ans += '#';
            }
        }
        cout << ans << "\n";
    }

}