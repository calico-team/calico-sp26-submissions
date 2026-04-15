#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;
#define endl "\n"
#define int long long
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<long long, long long> pl;
typedef pair<string, string> ps;
typedef pair<pi, char> pic;
typedef pair<char, pi> pci;
typedef pair<pci, pci> pcii;
typedef pair<char, char> pc;
typedef pair<bool, int> ib;
typedef long long ll;
const int MOD = 1e9 + 7;
const int HASH = 197;
const int MM = 1e5 + 2;
unordered_map<int, int> dp; vector<pi> candy;
void fun() {
    int N,P,R,K; cin >> N >> P >> R >> K; int arr[N + 1];
    for (int i= 1; i<= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) {
        P -= arr[i];
        if (P < 0) {
            cout<<"nah i'd lose"<<endl; return;
        }
        if (i % K == 0) {
            P += R;
        }
        //cout<<P<<endl;
    }
    cout<<"nah i'd win"<<endl; return;
}
signed main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for(int qwr = 1; qwr <= T; qwr++) {
        fun();
    }
}