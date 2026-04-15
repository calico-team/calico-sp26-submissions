# include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tc;
    cin >> tc;
    for(int tc_ = 0; tc_ < tc; tc_++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << c / ((2 * a + 2 * b) * d) << endl;
    }
}