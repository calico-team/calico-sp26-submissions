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
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cout << arr[0] << " ";
        if(arr[1] >= arr[0] && arr[1] <= arr[2] || arr[1] <= arr[0] && arr[1] >= arr[2]) cout << arr[1] << " ";
        else cout << arr[0] << " ";
        cout << arr[2] << "\n";



    }
}