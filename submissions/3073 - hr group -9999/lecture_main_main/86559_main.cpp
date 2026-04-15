#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t,n,m,k;
const int MAXS = 4010;
int grid[MAXS][MAXS], psa[MAXS][MAXS];

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> t;
    while(t--){
        cin >> n >> m >> k;

        memset(grid,0,sizeof(grid));
        memset(psa,0,sizeof(psa));

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                char c; cin >> c;
                if(c == '-')
                    grid[i+j][i-j+m] = psa[i+j][i-j+m] = 1;
            }
        }

        for(int i=1; i<=2*(n+m); ++i)
            for(int j=1; j<=2*(n+m); ++j)
                psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];

        int lo = 1, hi = n+m+1, ans = hi, ansi = 1, ansj = 1;
        while(lo < hi){
            int mid = (lo + hi) / 2;

            bool good = 0;
            int resi = 1, resj = 1;
            for(int i=1; i<=n+m; ++i){
                for(int j=1; j<=n+m; ++j){
                    if(psa[i+mid-1][j+mid-1] - psa[i+mid-1][j-1] - psa[i-1][j+mid-1] + psa[i-1][j-1] >= k){
                        good = 1;
                        resi = i;
                        resj = j;
                        break;
                    }
                }

                if(good) break;
            }

            if(good){
                if(mid < ans){
                    ans = mid;
                    ansi = resi;
                    ansj = resj;
                }
                hi = mid;
            } else {
                lo = mid+1;
            }
        }

        for(int i=0; i<ans; ++i){
            for(int j=0; j<ans; ++j){
                if(grid[ansi+i][ansj+j] == 1){
                    int x = ansi+i, y = ansj+j;
                    cout << (x+y-m)/2-1 << " " << (x-y+m)/2-1 << "\n";
                    --k;
                    if(k == 0) break;
                }
            }

            if(k == 0) break;
        }
    }
}
