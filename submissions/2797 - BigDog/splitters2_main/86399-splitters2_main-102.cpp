#include<bits/stdc++.h>
using namespace std;

/*
 * Build a factory with N rows and M columns that produces the target rate.
 *
 * P: the target numerator of the fraction P / (2^A * 3^B)
 * A: the exponent of 2 in the denominator
 * B: the exponent of 3 in the denominator
 */
vector<string> solve(long long P, int A, int B) {
    vector<int> t;
    for(int i=0;i<A;i++)t.push_back(2);
    for(int i=0;i<B;i++)t.push_back(3);

    int n=t.size();
    vector<string> g(2*n+1,string(3,'.'));
    g[0][0]='>';
    g[0][1]='v';

    vector<long long> suf(n+1,1);
    for(int i=n-1;i>=0;i--){
        if(suf[i+1]>P)suf[i]=P+1;
        else suf[i]=min(P+1,suf[i+1]*t[i]);
    }

    long long cur=P;
    for(int i=0;i<n;i++){
        int r=2*i+1;
        long long den=suf[i+1];
        long long take=den>cur?0:cur/den;
        long long rem=den>cur?cur:cur%den;

        g[r][1]='S';
        if(t[i]==2){
            g[r][0]=take?'<':'X';
            if(rem)g[r+1][1]='v';
            else g[r][2]='X';
        }else{
            g[r][0]=take>=1?'<':'X';
            g[r][2]=take>=2?'>':'X';
            g[r+1][1]=rem?'v':'X';
        }
        cur=rem;
    }
    return g;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        long long P;
        int A, B;
        cin >> P >> A >> B;
        vector<string> out=solve(P,A,B);
        int N=out.size(),M=out[0].size();
        cout << N << ' ' << M << '\n';
        for(auto &row:out){
            cout << row << '\n';
        }
    }
    return 0;
}
