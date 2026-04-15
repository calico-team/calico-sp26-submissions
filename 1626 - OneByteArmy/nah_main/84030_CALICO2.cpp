#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, p , r, k;
        cin >> n >> p >> r >> k;
        vector<int> e(n+1);
        for(int i = 1; i <= n; i++){
            cin >> e[i];
        }
        int curses_defeated = 0;
        bool canwin = true;
        for(int i = 1; i <=n ; i++){
            if(p < e[i] && curses_defeated >= k){
                p += r;
                curses_defeated = 0;
            }
            if(p >= e[i]){
                p -= e[i];
                curses_defeated++;
            }else{
                canwin = false;
                break;
            }
        }
        if(canwin){
            cout << "nah i'd win" << endl;
        }else{
            cout << "nah i'd lose" << endl;
        }
    }
}