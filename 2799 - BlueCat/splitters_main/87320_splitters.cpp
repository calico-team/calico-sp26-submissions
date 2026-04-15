#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, M;

vector<vector<ll>> arr(16, vector<ll>(16));
long long ansp = 0;
long long ansq = 1;

void addUp(ll p, ll q){
    p *= ansq;
    ansq *= q;
    ansp *= q;
    ansp += p;
    ll divides = gcd(ansp, ansq);
    ansp /= divides;
    ansq /= divides;
}

void recurse(ll i, ll j, ll p, ll q){
    if(i < 0 || i >= N || j < 0 || j >= M){
        addUp(p, q);
        return;
    }
    ll cur = arr[i][j];
    if(arr[i][j] == -1){
        return;
    }
    else if(arr[i][j] == 10){
        ll count = 0;
        if(i > 0 && (arr[i-1][j] == -1 || arr[i-1][j] == 1 || arr[i-1][j] == 3 || arr[i-1][j] == 4)) count++;
        if(i < N-1 && (arr[i+1][j] == -1 || arr[i+1][j] == 2|| arr[i+1][j] == 3 || arr[i+1][j] == 4)) count++;
        if(j > 0 && (arr[i][j-1] == -1 || arr[i][j-1] == 1 || arr[i][j-1] == 2 || arr[i][j-1] == 3)) count++;
        if(j < M-1 && (arr[i][j+1] == -1 || arr[i][j+1] == 1 || arr[i][j+1] == 2 || arr[i][j+1] == 4)) count++;

        if(i > 0 && (arr[i-1][j] == -1 || arr[i-1][j] == 1 || arr[i-1][j] == 3 || arr[i-1][j] == 4)){
            recurse(i-1, j, p, q*count);
        }
        if(i < N-1 && (arr[i+1][j] == -1 || arr[i+1][j] == 2|| arr[i+1][j] == 3 || arr[i+1][j] == 4)){
            recurse(i+1, j, p, q*count);
        }
        if(j > 0 && (arr[i][j-1] == -1 || arr[i][j-1] == 1 || arr[i][j-1] == 2 || arr[i][j-1] == 3)){
            recurse(i, j-1, p, q*count);
        }
        if(j < M-1 && (arr[i][j+1] == -1 || arr[i][j+1] == 1 || arr[i][j+1] == 2 || arr[i][j+1] == 4)){
            recurse(i, j+1, p, q*count);
        }

    }
    else{
        if(cur == 1) recurse(i-1, j, p, q);
        else if(cur == 2) recurse(i+1, j, p, q);
        else if(cur == 3) recurse(i, j-1, p, q);
        else recurse (i, j+1, p, q);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        cin >> N >> M;
        ansp = 0;
        ansq = 1;
        char x;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> x;
                if(x == '.') arr[i][j] = 0;
                else if(x == 'X') arr[i][j] = -1;
                else if(x == 'S') arr[i][j] = 10;
                else if(x == '^') arr[i][j] = 1; // up down left right
                else if(x == '<') arr[i][j] = 3;
                else if(x == 'v') arr[i][j] = 2;
                else arr[i][j] = 4;
            }
        }

        recurse(0, 0, 1, 1);
        

        cout << ansp << " " << ansq << "\n";
    }
}