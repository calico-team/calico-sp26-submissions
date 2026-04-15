#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0;i < t;i++){
        int n, p, r, k;
        int e[10000] = {0};
        cin >> n >> p >> r >> k;
        for(int j = 0;j < n;j++){
            cin >> e[j];
        }
        bool win = 1;
        int progress_k = 0;
        for(int j = 0;j < n;j++){
            if(p < 0){
                win = 0;
                break;
            }
            p -= e[j];
            if(progress_k == k){
                p += r;
                progress_k = 0;
            }
            progress_k++;
        }
        if(p < 0){
            win = 0;
        }
        if(win == 1){
            cout << "nah i'd win" << endl;
        }
        else{
            cout << "nah i'd lose" << endl;
        }
    }
    return 0;
}