

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int n, p ,r,k;
        cin >> n >> p >> r >> k;
        vector<int> curse(n);
        for(int i=0; i<n; i++){
            cin >> curse[i];
        }
        bool win = true;
        int count = 0;
        for(int i=0; i<n; i++){
            
            if(count == k){
              p+=r;
              count=0;
            }
            p-=curse[i];
           
            if(p<0){
                win=false;
                
                break;
            }
            count++;
            

        }

        if(win){
            cout << "nah i'd win" << endl;
        }
        else{
            cout << "nah i'd lose" << endl;
        }
    }
}
