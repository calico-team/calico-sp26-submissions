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
int dir[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
int arr[2000][2000];
int med(int x, int y, int z) {
    vector<int> v = {x, y, z};
    sort(v.begin(), v.end());
    return v[1];
}
void fun() {
    int N; cin >> N; int arr[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    if (N == 1) {
        cout<<arr[1]<<endl;
        return;
    }
    if (N == 2) {
        cout<<arr[1]<<" "<<arr[2]<<endl;
        return;
    }
    cout<<arr[1]<<" ";
    for (int i = 2; i < N; i++) {
        cout<<med(arr[i-1], arr[i], arr[i + 1])<<" ";
    }
    cout<<arr[N]<<endl;
}
signed main(){
    int T; cin >> T;
    for (int qwr = 0; qwr < T; qwr++) {
        fun();
    }
}
//https://www.geeksforgeeks.org/dsa/using-chinese-remainder-theorem-combine-modular-equations/
