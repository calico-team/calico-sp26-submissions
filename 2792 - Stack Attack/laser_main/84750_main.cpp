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
    ll n, k, m, p, q;
    vector<pll> astroids;
    while (t--) {
        cin >> k >> n >> m >> p >> q;
        astroids.resize(k);
        for (int i = 0; i<k; i++) {
            cin >> astroids[i].first >> astroids[i].second;
        }
        map<pll,ll> ast;
        for (int i = 0; i<k; i++) {
            ast[astroids[i]] = i;
        }

        ll currx = astroids[0].first;
        ll curry = astroids[0].second;

        while (true) {
            currx = (currx  + q)%n;
            curry = (curry + p)%m;
            if (ast.contains({currx,curry})) {
                cout << ast[{currx,curry}] << "\n";
                break;
            }

        }
    }


}