#include <bits/stdc++.h>
using namespace std;

// max: find the intersection and fill the whole thing

int num_filled(string s){
    int ret = 0;
    for(int i = 0; i < s.length(); i++)
        if(s[i]=='#') ret++;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<string> shadow1(N);
        vector<string> shadow2(N);
        for(auto &x: shadow1)
            cin >> x;
        for(auto &x: shadow2)
            cin >> x;

        int max_fill = 0;
        int min_fill = 0;
        for(int i = 0; i < N; i++){
            max_fill += (num_filled(shadow1[i])*num_filled(shadow2[i]));
            min_fill += max(num_filled(shadow1[i]),num_filled(shadow2[i]));
        }

        cout << max_fill << " " << min_fill << "\n";
    }

    return 0;
}
