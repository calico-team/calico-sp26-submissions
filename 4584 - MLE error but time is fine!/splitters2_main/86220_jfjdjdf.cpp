#include <bits/stdc++.h>
using namespace std;

struct Step{
    int k,d;
};

long long getVal(int a,int b,long long cap){
    long long x=1;
    for(int i=0;i<a;i++){
        if(x>cap/2)return cap+1;
        x*=2;
    }
    for(int i=0;i<b;i++){
        if(x>cap/3)return cap+1;
        x*=3;
    }
    return x;
}

/*
 * Build a factory with N rows and M columns that produces the target rate.
 *
 * P: the target numerator of the fraction P / (2^A * 3^B)
 * A: the exponent of 2 in the denominator
 * B: the exponent of 3 in the denominator
 */
vector<string> solve(int P, int A, int B) {
    long long cur=P;
    vector<Step> ops;
    int a=A,b=B;

    while(cur!=0&&getVal(a,b,cur)!=cur){
        if(a>0){
            long long nd=getVal(a-1,b,cur);
            int take=0;
            if(nd<=cur)take=cur/nd;
            long long rem=cur-1LL*take*nd;
            ops.push_back({2,take});
            cur=rem;
            a--;
        }else{
            long long nd=getVal(a,b-1,cur);
            int take=0;
            if(nd<=cur)take=cur/nd;
            long long rem=cur-1LL*take*nd;
            ops.push_back({3,take});
            cur=rem;
            b--;
        }
    }

    bool good=(cur!=0&&getVal(a,b,cur)==cur);

    if(ops.empty()){
        return {string(1,good?'>':'X')};
    }

    int N=2*(int)ops.size()+1;
    int M=5;
    vector<string> g(N,string(M,'.'));

    g[0][0]='>';
    g[0][1]='>';
    g[0][2]='v';

    for(int i=0;i<(int)ops.size();i++){
        int r=2*i+1;
        g[r][2]='S';

        if(i+1<(int)ops.size())g[r+1][2]='v';
        else g[r+1][2]=good?'v':'X';

        if(ops[i].k==2){
            g[r][1]='<';
            g[r][0]=ops[i].d?'<':'X';
        }else{
            g[r][1]='<';
            g[r][3]='>';
            g[r][0]=ops[i].d>=1?'<':'X';
            g[r][4]=ops[i].d==2?'>':'X';
        }
    }

    return g;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int P, A, B;
        cin >> P >> A >> B;
        vector<string> factory = solve(P, A, B);
        int N = (int) factory.size();
        int M = (int) factory[0].size();
        cout << N << ' ' << M << '\n';
        for (const string& row : factory) {
            cout << row << '\n';
        }
    }
    return 0;
}
