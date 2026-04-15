#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7;

int dp[N][N], lst[N][N], n, m, t;

string A, B;

int main(){

    cin >> t;

    while(t --){

        cin >> A >> B;
        n = A.size(), m = B.size();
        A = " " + A, B = " " + B;

        memset(dp, 0, sizeof(dp));
        memset(lst, 0, sizeof(lst));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i ++){
            dp[i][0] = 1;
            for(int j = 1; j <= m; j ++){
                dp[i][j] = dp[i - 1][j];
                if(dp[i - 1][j]) lst[i][j] = 1;
                if(A[i] == B[j]){
                    dp[i][j] |= dp[i - 1][j - 1];
                    if(dp[i - 1][j - 1]) lst[i][j] = 2;
                }
            }
        }
        
        for(int i = n, j = m; i >= 1; i --){
            // cout << i << ' ' << j << " / ";
            if(lst[i][j] == 2) j --;
            else A[i] = '#';
        }

        for(int i = 1; i <= n; i ++)
            cout << A[i];
        cout << '\n';

    }



    return 0;
}

