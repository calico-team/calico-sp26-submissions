#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

struct Seat {
    int r,c;
    int u,v;
    int a;
};

int rect_sum(const vector<vector<int>>& pref, int r1, int c1, int r2, int c2) {
    if(r1>r2||c1>c2)return 0;
    return pref[r2+1][c2+1]-pref[r1][c2+1]-pref[r2+1][c1]+pref[r1][c1];
}

/*
 * M: number of rows in the lecture hall
 * N: number of columns in the lecture hall
 * K: number of friends who need seats
 * GRID: vector of M strings of length N; '#' is a blocked seat, '-' is an empty seat
 *
 * Return a vector of K (row, col) pairs for the chosen seats.
 */
vector<pair<int, int>> solve(int M, int N, int K, vector<string>& GRID) {
    vector<Seat> seats;
    int sh=N-1;
    int U=M+N-1,V=M+N-1;

    vector<vector<int>> ok(U, vector<int>(V, 0));
    vector<vector<int>> aura(U, vector<int>(V, 0));

    for(int r=0;r<M;r++){
        vector<int> pref(N+1,0);
        for(int c=0;c<N;c++){
            pref[c+1]=pref[c]+(GRID[r][c]=='#');
        }
        int tot=pref[N];

        for(int c=0;c<N;c++){
            if(GRID[r][c]!='-')continue;

            int left=pref[c],right=tot-pref[c+1];
            int cur=min(left,right);
            int u=r+c,v=r-c+sh;

            seats.push_back({r, c, u, v, cur});
            ok[u][v]=1;
            aura[u][v]=cur;
        }
    }

    vector<vector<int>> cnt(U+1,vector<int>(V+1,0));
    vector<vector<int>> val(U+1,vector<int>(V+1,0));
    for(int u=0;u<U;u++){
        for(int v=0;v<V;v++){
            cnt[u+1][v+1]=cnt[u][v+1]+cnt[u+1][v]-cnt[u][v]+ok[u][v];
            val[u+1][v+1]=val[u][v+1]+val[u+1][v]-val[u][v]+aura[u][v];
        }
    }

    auto can = [&](int dist) {
        for(int u0=0;u0<U;u0++){
            int u1=min(U-1,u0+dist);
            for(int v0=0;v0<V;v0++){
                int v1=min(V-1,v0+dist);
                if(rect_sum(cnt,u0,v0,u1,v1)>=K){
                    return true;
                }
            }
        }
        return false;
    };

    int low=0,high=U-1;
    while(low < high){
        int mid=(low+high)/2;
        if(can(mid)){
            high=mid;
        } else {
            low=mid+1;
        }
    }
    int best=low;

    const int LIM = 32;
    priority_queue<array<long long, 4>> pq;

    for(int u0=0;u0<U;u0++){
        int u1=min(U-1,u0+best);
        for(int v0=0;v0<V;v0++){
            int v1=min(V-1,v0+best);
            int c=rect_sum(cnt,u0,v0,u1,v1);
            if(c<K)continue;

            long long sum=rect_sum(val,u0,v0,u1,v1);
            array<long long, 4> cur={sum,c,u0,v0};

            if((int)pq.size() < LIM){
                pq.push(cur);
            } else if(cur<pq.top()){
                pq.pop();
                pq.push(cur);
            }
        }
    }

    vector<array<long long, 4>> shortlist;
    while(!pq.empty()){
        shortlist.push_back(pq.top());
        pq.pop();
    }
    sort(shortlist.begin(), shortlist.end());

    long long best_a=(1LL<<60);
    vector<pair<int, int>> ans;

    for(auto [_,__,u0_ll,v0_ll]:shortlist){
        int u0=(int)u0_ll,v0=(int)v0_ll;
        int u1=min(U-1,u0+best),v1=min(V-1,v0+best);

        vector<pair<int, int>> inside;
        inside.reserve(rect_sum(cnt,u0,v0,u1,v1));

        for(int i=0;i<(int)seats.size();i++){
            const Seat& s=seats[i];
            if(u0<=s.u&&s.u<=u1&&v0<=s.v&&s.v<=v1){
                inside.push_back({s.a, i});
            }
        }

        if((int)inside.size()<K)continue;

        if((int)inside.size() > K){
            nth_element(inside.begin(),inside.begin()+K,inside.end());
        }
        long long sum=0;
        vector<pair<int, int>> chosen;
        chosen.reserve(K);
        for(int i=0;i<K;i++){
            sum+=inside[i].first;
            const Seat& s=seats[inside[i].second];
            chosen.push_back({s.r, s.c});
        }

        if(sum<best_a){
            best_a=sum;
            ans=chosen;
        }
    }

    if(!ans.empty()){
        return ans;
    }

    for(int u0=0;u0<U;u0++){
        int u1=min(U-1,u0+best);
        for(int v0=0;v0<V;v0++){
            int v1=min(V-1,v0+best);
            if(rect_sum(cnt,u0,v0,u1,v1)<K)continue;

            vector<pair<int, int>> inside;
            for(int i=0;i<(int)seats.size();i++){
                const Seat& s=seats[i];
                if(u0<=s.u&&s.u<=u1&&v0<=s.v&&s.v<=v1){
                    inside.push_back({s.a, i});
                }
            }

            if((int)inside.size() > K){
                nth_element(inside.begin(),inside.begin()+K,inside.end());
            }
            vector<pair<int, int>> chosen;
            chosen.reserve(K);
            for(int i=0;i<K;i++){
                const Seat& s=seats[inside[i].second];
                chosen.push_back({s.r, s.c});
            }
            return chosen;
        }
    }

    return vector<pair<int, int>>(K, {0, 0});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;
        vector<string> GRID(M);
        for (int i = 0; i < M; i++) {
            cin >> GRID[i];
        }
        vector<pair<int, int>> result = solve(M, N, K, GRID);
        for (auto& p : result) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}
