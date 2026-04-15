#include<bits/stdc++.h>
using namespace std;

struct Seat {
    int r, c;
    int u, v;
    int a;
};

int rect_sum(const vector<vector<int>>& pref, int r1, int c1, int r2, int c2) {
    if(r1>r2||c1>c2)return 0;
    return pref[r2+1][c2+1]-pref[r1][c2+1]-pref[r2+1][c1]+pref[r1][c1];
}

struct Fenwick {
    int n;
    vector<int> bit;

    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, int val) {
        for(int i=idx;i<=n;i+=i&-i)bit[i]+=val;
    }

    void range_add(int l, int r, int val) {
        if(l>r)return;
        add(l,val);
        if(r+1<=n)add(r+1,-val);
    }

    int point_query(int idx) const {
        int s=0;
        for(int i=idx;i>0;i-=i&-i)s+=bit[i];
        return s;
    }
};

struct Event {
    int l,r,d;
};

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

    for(int r=0;r<M;r++){
        vector<int> prefRow(N+1,0);
        for(int c=0;c<N;c++){
            prefRow[c+1]=prefRow[c]+(GRID[r][c]=='#');
        }

        int tot=prefRow[N];
        for(int c=0;c<N;c++){
            if(GRID[r][c]!='-')continue;

            int left=prefRow[c];
            int right=tot-prefRow[c+1];
            int a=min(left,right);
            int u=r+c;
            int v=r-c+sh;

            seats.push_back({r,c,u,v,a});
            ok[u][v]=1;
        }
    }

    if(K==1){
        pair<int,int> best={seats[0].r,seats[0].c};
        int bestA=seats[0].a;
        for(auto &s:seats){
            if(s.a<bestA){
                bestA=s.a;
                best={s.r,s.c};
            }
        }
        return {best};
    }

    vector<vector<int>> pref(U + 1, vector<int>(V + 1, 0));
    for(int u=0;u<U;u++){
        for(int v=0;v<V;v++){
            pref[u+1][v+1]=pref[u][v+1]+pref[u+1][v]-pref[u][v]+ok[u][v];
        }
    }

    auto can = [&](int dist) {
        int rows=max(1,U-dist);
        int cols=max(1,V-dist);

        for(int u0=0;u0<rows;u0++){
            int u1=u0+dist;
            for(int v0=0;v0<cols;v0++){
                int v1=v0+dist;
                if(rect_sum(pref,u0,v0,u1,v1)>=K){
                    return true;
                }
            }
        }
        return false;
    };

    int low=0,high=U-1;
    while(low<high){
        int mid=(low+high)/2;
        if(can(mid)){
            high=mid;
        } else {
            low=mid+1;
        }
    }
    int d=low;

    int rows=max(1,U-d);
    int cols=max(1,V-d);

    vector<vector<int>> good(cols?rows:0),need(rows),cost(rows);
    int alive=0;

    for(int u0=0;u0<rows;u0++){
        int u1=u0+d;
        for(int v0=0;v0<cols;v0++){
            int v1=v0+d;
            if(rect_sum(pref,u0,v0,u1,v1)>=K){
                good[u0].push_back(v0);
                need[u0].push_back(K);
                cost[u0].push_back(0);
                alive++;
            }
        }
    }

    int mxA=0;
    for(auto &s:seats)mxA=max(mxA,s.a);

    vector<vector<int>> by(mxA+1);
    for(int i=0;i<(int)seats.size();i++){
        by[seats[i].a].push_back(i);
    }

    for(int a=0;a<=mxA&&alive>0;a++){
        vector<vector<Event>> ev(rows+1);

        for(int id:by[a]){
            auto &s=seats[id];
            int rl=max(0,s.u-d);
            int rr=min(s.u,rows-1);
            int cl=max(0,s.v-d);
            int cr=min(s.v,cols-1);

            ev[rl].push_back({cl,cr,1});
            if(rr+1<rows){
                ev[rr+1].push_back({cl,cr,-1});
            }
        }

        Fenwick fw(cols+1);

        for(int r=0;r<rows;r++){
            for(auto &e:ev[r]){
                fw.range_add(e.l+1,e.r+1,e.d);
            }

            for(int i=0;i<(int)good[r].size();i++){
                if(need[r][i]==0)continue;

                int cnt=fw.point_query(good[r][i]+1);
                if(cnt==0)continue;

                int take=min(need[r][i],cnt);
                cost[r][i]+=take*a;
                need[r][i]-=take;
                if(need[r][i]==0){
                    alive--;
                }
            }
        }
    }

    int bestCost=numeric_limits<int>::max();
    int bu=-1,bv=-1;

    for(int r=0;r<rows;r++){
        for(int i=0;i<(int)good[r].size();i++){
            if(need[r][i]==0&&cost[r][i]<bestCost){
                bestCost=cost[r][i];
                bu=r;
                bv=good[r][i];
            }
        }
    }

    int eu=bu+d,ev=bv+d;
    vector<vector<pair<int,int>>> pick(mxA+1);

    for(auto &s:seats){
        if(bu<=s.u&&s.u<=eu&&bv<=s.v&&s.v<=ev){
            pick[s.a].push_back({s.r,s.c});
        }
    }

    vector<pair<int, int>> answer;
    answer.reserve(K);
    for(int a=0;a<=mxA&&(int)answer.size()<K;a++){
        for(auto &p:pick[a]){
            answer.push_back(p);
            if((int)answer.size()==K)break;
        }
    }

    return answer;
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
