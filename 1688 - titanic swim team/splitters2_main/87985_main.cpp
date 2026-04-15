#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        long long Pll;
        int A, B;
        cin>>Pll>>A>>B;
        vector<pair<int, int>> stages;
        cpp_int num=Pll;
        cpp_int den=1;
        for(int i=0; i<A; i++) den*=2;
        for(int i=0; i<B; i++) den*=3;
        for(int i=0; i<A; i++) {
            cpp_int c=(num*2)/den;
            stages.push_back({2, (int)c});
            num=num*2-c*den;
            den/=2;
        }
        for(int i=0; i<B; i++) {
            cpp_int c=(num*3)/den;
            stages.push_back({3, (int)c});
            num=num*3-c*den;
            den/=3;
        }
        assert(num==0);
        int K=(int)stages.size();
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
        auto put_down_collect[&](int c) {
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