#include <bits/stdc++.h>
using namespace std;

int C1[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        
        unsigned long long min_area = 0;
        unsigned long long max_area = 0;
    
        for (int i = 0; i < N; i++) {
            C1[i] = 0;
            for (int j = 0; j < N; j++) {
                char C;
                cin >> C;
                C1[i] += (C == '#');
            }
        }
        for (int i = 0; i < N; i++) {
            int s = 0;
            for (int j = 0; j < N; j++) {
                char C;
                cin >> C;
                s += (C == '#');
            }
            
            min_area += max(s, C1[i]);
            max_area += s * C1[i];
        }
        
        cout << max_area << ' ' << min_area << '\n';
    }
    
    return 0;
}