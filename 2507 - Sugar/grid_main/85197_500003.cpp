#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        
        vector<long long> the_two_tower_heights = A; 
        
      
        bool changed;
        do {
            changed = false;
            for (int i = 1; i < N - 1; ++i) {
                long long arr[3] = {A[i], the_two_tower_heights[i-1], the_two_tower_heights[i+1]};
                sort(arr, arr + 3);
                long long new_val = arr[1];
                if (new_val != the_two_tower_heights[i]) {
                    the_two_tower_heights[i] = new_val;
                    changed = true;
                }
            }
        } while (changed);
        
        for (int i = 0; i < N; ++i) {
            cout << the_two_tower_heights[i] << " \n"[i == N-1];
        }
    }
    return 0;
}