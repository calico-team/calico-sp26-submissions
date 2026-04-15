#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<int> results;
    cin >> n;
    while(n--){
        int L, W, E, R;
        cin >> L >> W >> E >> R;
        int eLap = ((L * 2) + (W * 2)) * R;
        if(E % eLap == 0){
            results.push_back(E/eLap);
        }
        else{
            results.push_back((E/eLap) + 1);
        }
    }
    for(int i : results){
        cout << i << endl;
    }
    
}