
#include <iostream>
#include <vector>

using namespace std;



string read_your_input() {
    string s;
    getline(cin, s);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a;
    cin >> a;
    while (a--) {
        int b, c, d, e;
        cin >> b >> c >> d >> e;
        vector<int> f(b);
        for (int i = 0; i < b; ++i) cin >> f[i];
        
        long long g = c;
        bool h = true;
        for (int i = 0; i < b; ++i) {
            g -= f[i];
            if (g < 0) {
                h = false;
                break;
            }
            if ((i + 1) % e == 0) g += d;
        }
        cout << (h ? "nah i'd win\n" : "nah i'd lose\n");
    }
    return 0;
}