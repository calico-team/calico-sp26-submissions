#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N, M, K;
        cin >> N >> M >> K;
        vector<string> grid(N);
        for(int i = 0; i < N; i++) cin >> grid[i];

        // Precompute aura loss for each available seat
        // aura_loss = min(# occupied to left, # occupied to right)
        struct Seat {
            int u, v, r, c, aura;
        };
        vector<Seat> seats;

        for(int r = 0; r < N; r++){
            // prefix count of '#' from left
            vector<int> left_occ(M, 0);
            for(int c = 0; c < M; c++){
                left_occ[c] = (c > 0 ? left_occ[c-1] : 0) + (grid[r][c] == '#' ? 1 : 0);
            }
            // prefix count of '#' from right
            vector<int> right_occ(M, 0);
            for(int c = M-1; c >= 0; c--){
                right_occ[c] = (c < M-1 ? right_occ[c+1] : 0) + (grid[r][c] == '#' ? 1 : 0);
            }
            for(int c = 0; c < M; c++){
                if(grid[r][c] == '-'){
                    int lo = (c > 0 ? left_occ[c-1] : 0);
                    int ro = (c < M-1 ? right_occ[c+1] : 0);
                    int aura = min(lo, ro);
                    seats.push_back({r+c, r-c, r, c, aura});
                }
            }
        }

        int S = (int)seats.size();

        if(K == 1){
            // pick seat with min aura
            int best = 0;
            for(int i = 1; i < S; i++){
                if(seats[i].aura < seats[best].aura) best = i;
            }
            cout << seats[best].r << " " << seats[best].c << "\n";
            continue;
        }

        // Sort by u
        sort(seats.begin(), seats.end(), [](const Seat& a, const Seat& b){
            return a.u < b.u;
        });

        // Binary search on D
        // check(D): find K points in Chebyshev box of size D, minimize aura sum
        // Sliding window on u, within window sort v, slide on v to find K with v-range <= D
        // Among those K, pick the K with smallest aura

        auto check = [&](int D) -> pair<bool, vector<int>> {
            // Sliding window on u
            // Within the u-window, we have points. We need to find subset where v-range <= D and size >= K.
            // Sort those by v, slide window of K on v.
            // For each feasible v-window, pick K seats with smallest aura.

            int best_aura_sum = INT_MAX;
            vector<int> best_indices;

            int j = 0;
            // Store indices into seats[] that are in current u-window, sorted by v
            vector<int> win; // indices sorted by v

            for(int i = 0; i < S; i++){
                // Insert seats[i] into win (sorted by v)
                {
                    int pos = (int)(lower_bound(win.begin(), win.end(), i, [&](int a, int b){
                        return seats[a].v < seats[b].v || (seats[a].v == seats[b].v && a < b);
                    }) - win.begin());
                    win.insert(win.begin() + pos, i);
                }

                // Remove seats with u < seats[i].u - D
                while(seats[j].u < seats[i].u - D){
                    // Remove j from win
                    for(int q = 0; q < (int)win.size(); q++){
                        if(win[q] == j){ win.erase(win.begin()+q); break; }
                    }
                    j++;
                }

                if((int)win.size() >= K){
                    // Slide window of size K on win (sorted by v)
                    for(int p = 0; p <= (int)win.size() - K; p++){
                        if(seats[win[p+K-1]].v - seats[win[p]].v <= D){
                            // Feasible! Pick K with smallest aura from win[p..p+K-1]
                            // Actually we must pick exactly K from this sub-window
                            // Collect auras, sort, pick smallest K
                            vector<pair<int,int>> aura_idx;
                            for(int q = p; q < p+K; q++){
                                aura_idx.push_back({seats[win[q]].aura, win[q]});
                            }
                            // All K are needed (exactly K in window of K)
                            int s = 0;
                            vector<int> chosen;
                            for(auto& [a, idx] : aura_idx){
                                s += a;
                                chosen.push_back(idx);
                            }
                            if(s < best_aura_sum){
                                best_aura_sum = s;
                                best_indices = chosen;
                            }
                        }
                    }
                    // Also check larger sub-windows where we can pick best K
                    for(int p = 0; p <= (int)win.size() - K; p++){
                        // find max q such that v-range <= D
                        // binary search for rightmost q
                        int lo2 = p + K - 1, hi2 = (int)win.size() - 1, best_q = -1;
                        while(lo2 <= hi2){
                            int mid = (lo2+hi2)/2;
                            if(seats[win[mid]].v - seats[win[p]].v <= D){
                                best_q = mid;
                                lo2 = mid+1;
                            } else {
                                hi2 = mid-1;
                            }
                        }
                        if(best_q < p + K - 1) continue;
                        // From win[p..best_q], pick K with smallest aura
                        int cnt = best_q - p + 1;
                        if(cnt == K) continue; // already handled
                        vector<pair<int,int>> aura_idx;
                        for(int q = p; q <= best_q; q++){
                            aura_idx.push_back({seats[win[q]].aura, win[q]});
                        }
                        sort(aura_idx.begin(), aura_idx.end());
                        int s = 0;
                        vector<int> chosen;
                        for(int q = 0; q < K; q++){
                            s += aura_idx[q].first;
                            chosen.push_back(aura_idx[q].second);
                        }
                        if(s < best_aura_sum){
                            best_aura_sum = s;
                            best_indices = chosen;
                        }
                    }
                }
            }
            return {!best_indices.empty(), best_indices};
        };

        int lo = 0, hi = N + M - 2;
        int opt_D = hi;
        vector<int> ans_indices;

        // First find optimal D
        while(lo <= hi){
            int mid = (lo+hi)/2;
            auto [ok, idx] = check(mid);
            if(ok){
                opt_D = mid;
                ans_indices = idx;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // Re-run check at opt_D to get best aura
        auto [ok2, final_idx] = check(opt_D);
        for(int i : final_idx){
            cout << seats[i].r << " " << seats[i].c << "\n";
        }
    }
    return 0;
}
