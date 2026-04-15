#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int main() {
   int T;
    if (!(cin >> T)) return 0;
    string dummy;
    getline(cin, dummy);
    while (T--) {
        int L,W,R,E;
        cin>>L>>W>>R>>E;
        int perimeter=(L+W)*2;
        double LAP;
        LAP=E/R * perimeter;
        int result = std::ceil(LAP);
        cout<<result<<endl;
    }
    return 0;
}
