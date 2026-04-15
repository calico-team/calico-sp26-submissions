#include <bits/stdc++.h>
using namespace std;
static long long cap_mul(long long a, long long b, long long cap) {
    if(a>cap/b) return cap;
    return min(cap, a*b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    string dummy;
    getline(cin, dummy);
    while(T--) {
        string line;
        getline(cin, line);
        while(line.empty()) getline(cin, line);
        long long P;
        int A, B;
        {
            stringstream ss(line);
            vector<string> tok;
            string x;
            while(ss>>x) tok.push_back(x);
            if((int)tok.size()==3) {
                P=stoll(tok[0]);
                A=stoll(tok[1]);
                B=stoll(tok[2]);
            } else {
                string s=tok[0];
                P=s[0]-'0';
                A=s[1]-'0';
                B=s[2]-'0';
            }
        }
        vector<int> fac;
        for(int i=0; i<A; i++) fac.push_back(2);
        for(int i=0; i<B; i++) fac.push_back(3);
        int K=(int)fac.size();
        long long CAP=P+1;
        vector<long long> suf(K+1, 1);
        for(int i=K-1; i>=0; i--) {
            suf[i]=cap_mul(suf[i+1], fac[i], CAP);
        }
        vector<pair<int, int>> stages;
        long long num=P;
        for(int i=0; i<K; i++) {
            int m=fac[i];
            long long nextDen=suf[i+1];
            long long c=num/nextDen;
            stages.push_back({m, (int)c});
            num-=c*nextDen;
        }
        int N=5;
        int M=2*K+1;
        vector<string> g(N, string(M, '.'));
        g[0][0]='v';
        g[1][0]='v';
        g[2][0]='>';
        auto put_up_collect=[&](int c) {
            g[1][c]='^';
            g[0][c]='^';
        };
        auto put_down_collect=[&](int c) {
            g[3][c]='v';
            g[4][c]='v';
        };
        for(int i=0; i<K; i++) {
            int col=1+2*i;
            int m=stages[i].first;
            int c=stages[i].second;
            bool last=(i==K-1);
            g[2][col]='S';
            if(m==2) {
                if(!last) {
                    g[2][col+1]='>';
                    if(c==0) {
                        g[3][col]='X';
                    } else {
                        put_up_collect(col);
                    }
                } else {
                    g[2][col+1]='X';
                    if(c==0) {
                        g[3][col]='X';
                    } else {
                        put_up_collect(col);
                    }
                }
            } else {
                if(!last) {
                    g[2][col+1]='>';
                    if(c==0) {
                        g[1][col]='X';
                        g[3][col]='X';
                    } else if(c==1) {
                        put_up_collect(col);
                        g[3][col]='X';
                    } else {
                        put_up_collect(col);
                        put_down_collect(col);
                    }
                } else {
                    g[2][col+1]='X';
                    if(c==0) {
                        g[1][col]='X';
                        g[3][col]='X';
                    } else if(c==1) {
                        put_up_collect(col);
                        g[3][col]='X';
                    } else {
                        put_up_collect(col);
                        put_down_collect(col);
                    }
                }
            }
        }
        cout<<N<<' '<<M<<'\n';
        for(auto &row:g) cout<<row<<'\n';
    }
    return 0;
}