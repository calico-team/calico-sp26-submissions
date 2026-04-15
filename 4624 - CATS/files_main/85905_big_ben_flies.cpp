#include <iostream>
#include <string>
#define FASTIO std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
using namespace std;

int main() { FASTIO;
    int t; // # of test cases
    cin >> t;

    string a;
    string b;
    while (t--) {
        cin >> a >> b;

        int b_idx = 0;
        for (int a_idx = 0; a_idx < a.length(); a_idx++) {
            if (a[a_idx] != b[b_idx]) {
                a[a_idx] = '#';
                continue;
            }
            b_idx++;
            if (b_idx == b.length()) {
                while (a_idx < a.length()) {
                    a_idx++;
                    a[a_idx] = '#';
                }
                break;
            }
        }
        cout << a << endl;
    }
    return 0;
}

/**
sample in
5
ccaalliiccoo
calico
big_bens_bday
bbb
job
jb
include_over_californication
ilovecalico
six_seven_rizzler_sigma_banned_discord_skibidi_toilet
severence
**/