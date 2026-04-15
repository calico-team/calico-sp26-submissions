#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--){  
        string A, B;
        cin >> A >> B;
        int Bind = 0;
        for(int i = 0; i < A.size(); i++){
            if(Bind < B.size() && A[i] == B[Bind]){
                Bind++;
                cout << A[i];
            }
            else cout << "#";
        }
        cout << "\n";
    }
    
}