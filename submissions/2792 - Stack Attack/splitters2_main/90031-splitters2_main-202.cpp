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






ll power(ll x, ll y) {

    if (y == 1) {
        return x;
    }
    if (y == 0) {
        return 1;
    }
    if (y%2 == 1) {
        ll temp = power(x,y-1);
        return temp * x;
    }
    else {
        ll temp = power(x,y/2);
        if (temp > 1e6) {
            temp = 1e6;
        }
        return temp*temp;
    }
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    vector<string> board;
    ll p, a, b;
    while (t--) {
        cin  >> p >> a >> b;
        cout << 1 + (a+b) * 2 << ' ' << 3 << "\n";
        cout << ">v.\n";
        for (int i = 0; i<a; i++) {
            if (power(2,a-i-1) <= p && power(3,b) <= p && p>=power(2,a-i-1)*power(3,b)) {
                cout << ".S>\n";
                p -= power(2,a-i-1)*power(3,b);
            }
            else {
                cout << ".SX\n";
            }
            if (b == 0 && i == a-1 && p == 0) {
                cout << ".X.\n";
            }
            else {
                cout << ".v.\n";
            }
        }
        for (int i = 0; i<b; i++) {
            if (p>=2*power(3,b-i-1)) {
                cout << "<S>\n";
                p -= 2*power(3,b-i-1);
            }
            else if (p>=power(3,b-i-1)) {
                cout << "XS>\n";
                p -= power(3,b-i-1);
            }
            else {
                cout << "XSX\n";
            }
            if (i == b-1 && p == 0) {
                cout << ".X.\n";
            }
            else {
                cout << ".v.\n";
            }
        }



    }


}