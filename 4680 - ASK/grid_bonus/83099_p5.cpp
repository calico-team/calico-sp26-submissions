#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin>> T;

    while (T--) {
        int numF;cin>>numF;

        vector<ll> top(numF), left(numF), right(numF), bot(numF);
        for (ll &height: top) cin >> height;

        right[0] = top[0];
        left[0] = right[0];

        for (int f = 1;f < numF; f++) {
            if (top[f] < left[f-1]) {
                left[f] = top[f];
                right[f] = left[f-1];
            } else if (top[f] > right[f-1]) {
                left[f] = right[f-1];
                right[f] = top[f];
            } else {
                right[f] = top[f];
                left[f] = right[f];
            }
        }

        bot[numF-1] = left[numF-1];
        for (int f =numF-2; f >= 0;f--) {
            ll next_height = bot[f+1];
            if (next_height <left[f]) {
                bot[f] = left[f];
            }else if (next_height > right[f]) {
                bot[f] = right[f];
            } else {
                bot[f] = next_height;
            }
        }
        
        for (int f=0; f < numF; ++f) {
            if (f) cout << ' ';
            cout << bot[f];
        }

        cout << '\n';
    }
}
