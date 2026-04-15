#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        long long maxi = 0;
        long long mini = 0;
        //to find maximum just know how many are in each row, then multiply it by how many are in that row in the next one
        //ok this one works, now I just need to figure out how to find minimum

        // for minimum its whatever the largest number is in that row
        char x;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            int cur = 0;
            for(int j = 0; j < N; j++){
                cin >> x;
                if(x == '#') cur++;
            }
            arr[i] = cur;
        }

        for(int i = 0; i < N; i++){
            int cur = 0;
            for(int j = 0; j < N; j++){
                cin >> x;
                if(x == '#') cur++;
            }
            maxi += arr[i]*cur;
            mini += max(arr[i], cur);
        }
        cout << maxi << " " << mini << "\n";
    }
    
}