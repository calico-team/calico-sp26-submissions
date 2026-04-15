#include <bits/stdc++.h>
using namespace std;

int main( ) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--){
        long long P;int A,B;
        cin>> P>>A >>B;
        vector<string>g;
        vector<int> cols ={0};
        int width= 1;
        for(int i= 0;i <A;i++){
            int n=cols.size();
            vector<int> nxt;
            string row(width *2+ 5, '.');
            int ptr =0;
            for(int c:cols){
                int base =ptr;
                row[base]= 'S';
                row[base+1]= '>';
                nxt.push_back(base+2);
                row[base+ 3]= '>';
                nxt.push_back(base+4);
                ptr +=6;
            }
            width =ptr;
            cols =nxt;
            g.push_back(row);
        }
        for(int i =0;i < B;i++){
            int n= cols.size();
            vector <int> nxt;
            string row(width*3 +5,'.');
            int ptr=0;
            for(int c : cols){
                int base = ptr;
                row[base]='S';
                for(int k=0;k<3;k++){
                    row[base+1+2*k]='>';
                    nxt.push_back(base+2+2*k);
                }
                ptr += 8;
            }
            width=ptr;
            cols = nxt;
            g.push_back(row);
        }
        string last(width+5,'.');
        for(int i=0;i<(int)cols.size();i++){
            if(i<P) last[cols[i]] = '^';
            else last[cols[i]]= 'X';
        }
        g.push_back(last);
        int N=g.size();
        int M =0;
        for(auto &r:g) M=max(M, (int)r.size());
        for(auto &r : g){
            while((int)r.size()<M) r.push_back('.');
        }
        cout<<N<<" " <<M <<"\n";
        for(auto &r:g) cout<<r<<"\n";
    }
}