// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long P, a, b; cin >> P >> a >> b;
    vector<vector<char>> A(5,vector<char>((a+b)*2+1,'.'));
    A[0][0]='v';
    A[1][0]='v';
    A[2][0]='>';
    for (long long i = 1; i <= (a+b)*2; i++) {if (i&1) {A[2][i]='S';} else {A[2][i]='>';}}
    long long tb = b;
    vector<pair<long long, long long>> r;
    while (P) {
        if (tb) {long long o = P%3; P/=3; tb--; r.push_back({o,3});}
        else {long long o = P%2; P/=2; r.push_back({o,2});}
    }
    reverse(r.begin(),r.end());
    for (long long i = 1; i <= (a+b)*2; i+=2) {
        for (auto o : r) {
            if (o.second==3) {
                A[1][i]='^';
                A[3][i]='v';
                if (o.first==2) {A[0][i]='^'; A[4][i]='v';}
                else if (o.first==1) {A[0][i]='^'; A[4][i]='X';}
                else {A[0][i]='X'; A[4][i]='X';}
                tb--;
            } else {
                A[1][i]='^';
                if (o.first) {A[0][i]='^';}
                else {A[0][i]='X';}
            }
        }
    }
    A[2][(a+b)*2]='X';
    cout << 5 << " " << (a+b)*2+1 << endl;
    for (long long i = 0; i < 5; i++) {
        for (long long j = 0; j <= (a+b)*2; j++) {cout << A[i][j] << (j==((a+b)*2)?"\n":"");}
    }
}

int main() {
	long long T; cin >> T;
    while (T--) {solve();}
}
