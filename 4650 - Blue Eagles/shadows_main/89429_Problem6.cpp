#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void solve() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    cin >> t;
    vector<std::string> out;
    for (int _ = 0; _ < t; ++_) {
        int n;
        cin >> n;
        vector<std::string> s1(n), s2(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> s1[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> s2[i];
        }
        int max_vol = 0, min_vol = 0;
        for (int i = 0; i < n; ++i) {
            int a = 0, b = 0;
            for (char c : s1[i]) {
                if (c == '#') ++a;
            }
            for (char c : s2[i]) {
                if (c == '#') ++b;
            }
            max_vol += a * b;
            min_vol += (a > b) ? a : b;
        }
        out.push_back(to_string(max_vol) + " " + to_string(min_vol));
    }
    for (const auto& line : out) {
        std::cout << line << endl;
    }
}

int main() {
    solve();
    return 0;
}