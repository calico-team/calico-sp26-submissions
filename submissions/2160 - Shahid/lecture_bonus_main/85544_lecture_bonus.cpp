#include <bits/stdc++.h>
using namespace std;

struct Seat { int u,v,r,c,aura; };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--){
        int N,M,K; cin>>N>>M>>K;
        vector<string> grid(N);
        for(int i=0;i<N;i++) cin>>grid[i];

        vector<Seat> seats;
        for(int r=0;r<N;r++){
            int cnt=0;
            vector<int> L(M),R(M);
            for(int c=0;c<M;c++){ L[c]=cnt; if(grid[r][c]=='#') cnt++; }
            cnt=0;
            for(int c=M-1;c>=0;c--){ R[c]=cnt; if(grid[r][c]=='#') cnt++; }
            for(int c=0;c<M;c++)
                if(grid[r][c]=='-')
                    seats.push_back({r+c, r-c, r, c, min(L[c],R[c])});
        }
        int S=seats.size();

        if(K==1){
            auto it=min_element(seats.begin(),seats.end(),[](auto&a,auto&b){return a.aura<b.aura;});
            cout<<it->r<<" "<<it->c<<"\n"; continue;
        }

        // Sort by (v, aura) for later use
        // But first sort by u for sliding window
        sort(seats.begin(),seats.end(),[](auto&a,auto&b){ return a.u<b.u||(a.u==b.u&&a.v<b.v); });

        // For a given D, check feasibility and find min aura K-subset
        // Use policy: first binary search D for feasibility only (fast),
        // then at optimal D, do one pass to find best aura subset
        auto feasible=[&](int D)->bool{
            int j=0;
            vector<int> vs; // sorted v values in u-window
            for(int i=0;i<S;i++){
                // insert v_i
                auto it=lower_bound(vs.begin(),vs.end(),seats[i].v);
                vs.insert(it,seats[i].v);
                while(seats[j].u<seats[i].u-D){
                    auto it2=lower_bound(vs.begin(),vs.end(),seats[j].v);
                    vs.erase(it2);
                    j++;
                }
                if((int)vs.size()>=K){
                    for(int p=0;p<=(int)vs.size()-K;p++)
                        if(vs[p+K-1]-vs[p]<=D) return true;
                }
            }
            return false;
        };

        int lo=0, hi=N+M-2, optD=hi;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(feasible(mid)){ optD=mid; hi=mid-1; } else lo=mid+1;
        }

        // Now find best aura subset at optD
        // Maintain window sorted by v; for each feasible v-sub-window, pick K smallest aura
        int bestSum=INT_MAX;
        vector<int> bestIdx;
        {
            int j=0;
            // win: indices into seats[], sorted by v
            vector<int> win;
            for(int i=0;i<S;i++){
                auto cmp=[&](int a,int b){ return seats[a].v<seats[b].v||(seats[a].v==seats[b].v&&a<b); };
                auto it=lower_bound(win.begin(),win.end(),i,cmp);
                win.insert(it,i);
                while(seats[j].u<seats[i].u-optD){
                    for(int q=0;q<(int)win.size();q++){
                        if(win[q]==j){ win.erase(win.begin()+q); break; }
                    }
                    j++;
                }
                int W=win.size();
                if(W<K) continue;
                for(int p=0;p<=W-K;p++){
                    if(seats[win[p+K-1]].v-seats[win[p]].v>optD) continue;
                    // find rightmost q with v range <= optD
                    int rr=p+K-1;
                    { int a=p+K-1,b=W-1;
                      while(a<=b){ int m=(a+b)/2; if(seats[win[m]].v-seats[win[p]].v<=optD){rr=m;a=m+1;}else b=m-1; }
                    }
                    int cnt=rr-p+1;
                    if(cnt==K){
                        int s=0; vector<int> ch;
                        for(int q=p;q<=rr;q++){ s+=seats[win[q]].aura; ch.push_back(win[q]); }
                        if(s<bestSum){ bestSum=s; bestIdx=ch; }
                    } else {
                        vector<pair<int,int>> av;
                        for(int q=p;q<=rr;q++) av.push_back({seats[win[q]].aura, win[q]});
                        sort(av.begin(),av.end());
                        int s=0; vector<int> ch;
                        for(int q=0;q<K;q++){ s+=av[q].first; ch.push_back(av[q].second); }
                        if(s<bestSum){ bestSum=s; bestIdx=ch; }
                    }
                }
            }
        }
        for(int i:bestIdx) cout<<seats[i].r<<" "<<seats[i].c<<"\n";
    }
}
