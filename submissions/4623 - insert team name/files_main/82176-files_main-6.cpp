# include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tc;
    cin >> tc;
    for(int tc_ = 0; tc_ < tc; tc_++){
        string a, b;
        cin >> a >> b;
        int pt = 0;
        for(int x = 0; x < a.length(); x++){
            if(pt == b.length()){
                cout << '#';
            }
            else{
                if(a[x] == b[pt]){
                    cout << b[pt];
                    ++pt;
                }
                else{
                    cout << '#';
                }
            }
        }
        cout << endl;
    }
}