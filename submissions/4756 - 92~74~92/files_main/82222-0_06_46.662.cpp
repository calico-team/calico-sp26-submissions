#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e18;

void docase(){
    string a, b;
    cin >> a >> b;
    string out = "";
    int j = 0;
    for (int i = 0; i < a.size(); i++) {
        if (j >= b.size()) {
            out.push_back('#');
        }
        else if (a[i] == b[j]){
            out.push_back(a[i]);
            j++;
        }
        else {
            out.push_back('#');
        }
    }
    cout << out << '\n';
}

signed main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int i = 0 ; i < tt; i++){
        docase();
    }
    return 0;
}