#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N,P,R,K;
int P_left,K_left;
bool boo = true;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i = 0;i < T;i++){
        cin >> N >> P >> R >> K;
        int a[10005];
        for(int i = 0;i < N;i++){
            cin >> a[i];
        }
        P_left = P;
        K_left = K;
        for(int i = 0;i < N;i++){
            P_left -= a[i];
            if(P_left < 0){
                cout << "nah i'd lose"<<'\n';
                boo = false;
                break;
            }else{
                K_left--;
                if(K_left == 0){
                    P_left += R;
                    K_left = K;
                }
                
            }
        }
        if(boo){
            cout << "nah i'd win"<<'\n';
        }
        boo = true;
    }
    return 0;
}