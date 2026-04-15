// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <numeric>
using namespace std;

long long n, m;
pair<long long, long long> dp[15][15];
long long dx[4] = {1, -1, 0, 0};
long long dy[4] = {0, 0, -1, 1};
char factory[15][15];
bool outOfFactory(long long x, long long y){
    return !(x >= 0 && x < n && y >= 0 && y < m);
}
pair<long long, long long> solve(long long x, long long y){
    if(outOfFactory(x, y)) return {1, 1};
    if(dp[x][y] != make_pair(-1LL, -1LL)) return dp[x][y];
    if(factory[x][y] == 'X') dp[x][y] = {0, 1};
    else if(factory[x][y] == '>') dp[x][y] = solve(x, y+1);
    else if(factory[x][y] == '<') dp[x][y] = solve(x, y-1);
    else if(factory[x][y] == '^') dp[x][y] = solve(x-1, y);
    else if(factory[x][y] == 'v') dp[x][y] = solve(x+1, y);
    if(factory[x][y] != 'S') return dp[x][y];
    long long i;
    vector<pair<long long, long long>>possible;
    for(i = 0; i < 4; ++i){
        long long nx = x+dx[i];
        long long ny = y+dy[i];
        if(!outOfFactory(nx, ny)){
            if((factory[nx][ny] == '>' && dy[i] == -1) || 
            (factory[nx][ny] == '<' && dy[i] == 1) ||
            (factory[nx][ny] == '^' && dx[i] == 1) ||
            (factory[nx][ny] == 'v' && dx[i] == -1) || factory[nx][ny] == '.'){
                continue;
            }
            possible.push_back({nx, ny});
        }
    }
    vector<long long>num;
    vector<long long>den;
    long long finalDen = 1;
    for(i = 0; i < possible.size(); ++i){
        long long nx = possible[i].first;
        long long ny = possible[i].second;
        pair<long long, long long>res = solve(nx, ny);
        num.push_back(res.first);
        den.push_back(res.second*possible.size());
        finalDen = lcm(finalDen, den[i]);
    }
    // cout << x << " " << y << endl;
    // for(i = 0; i < possible.size(); ++i){
    //     cout << num[i] << " " << den[i] << endl;
    // }
    // cout << "BREAK" << endl;
    long long finalNum = 0;
    for(i = 0; i < possible.size(); ++i){
        finalNum += (finalDen/den[i])*num[i];
    }
    long long simplify = gcd(finalNum, finalDen);
    dp[x][y] = {finalNum/simplify, finalDen/simplify};
    return dp[x][y];
}

int main() {
	long long t;
    cin >> t;
    while(t--){
        long long i, j;
        cin >> n >> m;
        factory[n][m];
        for(i = 0; i < n; ++i){
            for(j = 0; j < m; ++j){
                cin >> factory[i][j];
                dp[i][j] = {-1LL, -1LL};
            }
        }
        dp[0][0] = solve(0, 0);
        cout << dp[0][0].first << " " << dp[0][0].second << endl;
        // for(i = 0; i < n; ++i){
        //     for(j = 0; j < m; ++j){
        //         cout << "(" << dp[i][j].first << "/" << dp[i][j].second << ")" << " ";
        //     }
        //     cout << endl;
        // }
    }
}
