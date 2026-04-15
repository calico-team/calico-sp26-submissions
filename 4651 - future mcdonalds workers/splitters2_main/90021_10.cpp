#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; 
    if(!(cin>>T)) return 0;
    while(T--){
        long long P; int A,B;
        cin>>P>>A>>B;

        vector<int> factors;
        for(int i=0;i<A;i++) factors.push_back(2);
        for(int i=0;i<B;i++) factors.push_back(3);

        long long D = 1;
        for(int d: factors) D *= d;

        int W = 5;
        int maxH = 5 * (A+B+5);
        vector<string> g(maxH, string(W, '.'));

        int r = 0;

        // entry path
        g[r][0] = '>';
        g[r][1] = '>';
        
        int cur_r = r;

        for(int idx=0; idx<(int)factors.size(); idx++){
            int d = factors[idx];

            int sr = cur_r;
            int sc = 2;

            g[sr][sc] = 'S';

            long long k = (P * d) / D;
            P = P * d - k * D;

            // directions: left (col2->1), right (3->4->5), down

            bool use_left = false, use_right = false, use_down = false;

            if(k == 0){
                use_left = use_right = use_down = false;
            } else if(k == 1){
                use_left = true;
            } else if(k == 2){
                use_left = true;
                use_right = true;
            } else if(k == 3){
                use_left = use_right = use_down = true;
            }

            // LEFT
            if(use_left){
                g[sr][sc-1] = '<';
                g[sr][0] = '<';
            } else {
                // route to merger
                g[sr][sc-1] = '<';
                g[sr+1][sc-1] = 'v';
                g[sr+1][sc] = '>';
            }

            // RIGHT
            if(use_right){
                g[sr][sc+1] = '>';
                g[sr][sc+2] = '>';
            } else {
                g[sr][sc+1] = '>';
                g[sr+1][sc+1] = 'v';
                g[sr+1][sc] = '<';
            }

            // DOWN
            if(use_down){
                g[sr+1][sc] = 'v';
            } else {
                // continue path
                g[sr+1][sc] = 'v';
            }

            cur_r += 2;

            if(idx + 1 < (int)factors.size()){
                g[cur_r-1][sc] = 'v';
            }
        }

        int H = cur_r + 3;

        cout << H << " " << W << "\n";
        for(int i=0;i<H;i++){
            cout << g[i] << "\n";
        }
    }
    return 0;
}
