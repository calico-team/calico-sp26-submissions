#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        
        vector<string> grid(N);
        for (int i = 0; i < N; i++) cin >> grid[i];
        
        // Compute aura loss for each seat
        // aura[r][c] = min(#occupied left of c in row r, #occupied right of c in row r)
        vector<vector<int>> aura(N, vector<int>(M, 0));
        for (int r = 0; r < N; r++) {
            // prefix count of '#'
            vector<int> pre(M + 1, 0);
            for (int c = 0; c < M; c++)
                pre[c+1] = pre[c] + (grid[r][c] == '#' ? 1 : 0);
            for (int c = 0; c < M; c++) {
                if (grid[r][c] == '-') {
                    int left = pre[c];
                    int right = pre[M] - pre[c+1];
                    aura[r][c] = min(left, right);
                }
            }
        }
        
        // Collect available seats with their u=r+c, v=r-c
        struct Seat {
            int u, v, r, c, aur;
        };
        vector<Seat> seats;
        for (int r = 0; r < N; r++)
            for (int c = 0; c < M; c++)
                if (grid[r][c] == '-')
                    seats.push_back({r+c, r-c, r, c, aura[r][c]});
        
        int S = seats.size();
        
        // Sort by u
        sort(seats.begin(), seats.end(), [](const Seat& a, const Seat& b){
            return a.u < b.u;
        });
        
        // Binary search on D
        // For a given D, check if there exist K seats with max u diff <= D and max v diff <= D
        // Use two pointer on u, and for each u-window, check if any v-window of size D has >= K seats
        
        // For check: seats in u-window [l..r] (two pointer), 
        // sort by v and slide v window of size D
        // We need to do this efficiently.
        
        // Since we need to actually find the best window (for bonus), let's just
        // for each candidate D, find the best window.
        
        // For the check function: O(S log S) per check using sliding window on v after sorting.
        // We'll precompute seats sorted by u. For two-pointer on u, maintain a multiset of v values.
        // Then for each right endpoint (by u), find the number of v values in [v_min, v_min+D].
        // But "best v window" = max count - use sliding window on sorted v values within the u-window.
        
        // This is O(S^2) in worst case with naive approach.
        // Better: two pointer on u, sorted v multiset, then sliding window on v.
        // For each u-window, sort v values, use two pointer on v window of size D.
        // But maintaining sorted v as u-window changes is O(S log S) total if we use multiset.
        
        // Let's do: for each possible u-window [ul, ul+D] (two pointer), 
        // we have a set of v values. We want the max count of v's in any window [vl, vl+D].
        // If we keep a sorted vector and scan, that's O(S) per step = O(S^2) total.
        
        // Given S <= 10^6 and log factor, O(S log S) binary search might TLE.
        // But let's try: S <= NM <= 10^6, log(2000) ~ 11. O(S log S * log(2000)) ~ 10^6 * 20 * 11 = 2*10^8. Risky.
        
        // Alternative: since the answer D is between 0 and N+M-2,
        // and we just need to find the optimal window, let's think differently.
        
        // For small grids this is fine. Let's implement and hope it passes.
        
        // For the check + find best window for a given D:
        // Two pointer on u (sorted seats), maintain sorted multiset of v's.
        // For counting in v-window: use a sorted vector + binary search.
        // When we want best count in v-window of size D: 
        //   sort v values in current u-window, two pointer on v.
        
        // Since we need both check AND find the window, let's do:
        // binary search on D, for each D do a sweep.
        
        auto countAndFind = [&](int D) -> pair<int, pair<int,int>> {
            // Returns {max_count, {ul, vl}} for best window
            // Two pointer on u
            int best = 0;
            int best_ul = 0, best_vl = 0;
            
            // Use two pointer: right pointer r, left pointer l on seats (sorted by u)
            // Maintain sorted list of v's in window
            multiset<int> vs;
            int l = 0;
            for (int r = 0; r < S; r++) {
                vs.insert(seats[r].v);
                while (seats[r].u - seats[l].u > D) {
                    vs.erase(vs.find(seats[l].v));
                    l++;
                }
                // Now count max in v-window of size D
                // Iterate through v's in sorted order, two pointer
                vector<int> sv(vs.begin(), vs.end());
                int cnt = 0, lv = 0;
                for (int rv = 0; rv < (int)sv.size(); rv++) {
                    while (sv[rv] - sv[lv] > D) lv++;
                    cnt = max(cnt, rv - lv + 1);
                    if (rv - lv + 1 > best) {
                        best = rv - lv + 1;
                        best_ul = seats[l].u; // u lower bound
                        best_vl = sv[lv];
                    }
                }
            }
            return {best, {best_ul, best_vl}};
        };
        
        // This is O(S^2) due to copying multiset to vector each time. Too slow.
        // 
        // Better approach: separate the two dimensions.
        // Sort all seats by u. Two pointer on u.
        // Within u-window, we want max seats in v-range of D.
        // Key insight: when we add/remove seats from u-window (as we slide right pointer),
        // we can maintain a sorted structure for v.
        // For finding the best v-window: iterate through all v's in sorted order with two pointer.
        // But we only need to check O(window_size) v-windows.
        // 
        // Total work: sum over all right pointers of (window_size) = O(S^2) worst case.
        // 
        // For N=M=1000, S can be up to 10^6. This is too slow.
        //
        // Smarter: For a fixed D, the best window answer:
        // Sort seats by u. Two pointer [l,r] on u.
        // For each such window, we want max # seats in v-interval of length D.
        // This is a 1D problem: given a set of points, find interval of length D with most points.
        // If we maintain a sorted multiset of v, and slide a v-window:
        // We can use a BIT indexed by compressed v values!
        // 
        // v ranges from -(M-1) to (N-1), so range is about 2000. We can use a BIT of size 2*(N+M).
        // Then for each right pointer r, after updating BIT:
        //   For each v in multiset, query BIT[v .. v+D]. O(S log(N+M)) per call.
        // Still O(S^2 log) if naive.
        //
        // The real trick: we only need to check v-windows starting at one of the actual v values.
        // For each u-window [l,r], the best v-window starts at some seat's v.
        // If we do a sweep line on v while also sliding u... this is 2D.
        //
        // Given time constraints of a competition, let me just implement the O(S * sqrt(S)) or
        // accept that with the given constraints (sum NM <= 10^6), 
        // the total seats S <= 10^6, but after binary search log(2000)*S*log(S) ~ 2*10^8 might be okay
        // if we avoid the inner copy to vector.
        //
        // Let me redo: keep v values in a sorted vector (BIT approach).
        
        // REVISED APPROACH:
        // v values range: r-c, r in [0,N-1], c in [0,M-1]. Range: [-(M-1), N-1].
        // Offset by (M-1) to make non-negative. Max value = N+M-2.
        // Use BIT of size N+M.
        
        int V_OFFSET = M - 1;
        int V_SIZE = N + M; // 0 to N+M-2
        
        auto solve = [&](int D) -> tuple<bool, int, int> {
            // Returns {feasible, best_ul, best_vl}
            vector<int> bit(V_SIZE + 1, 0);
            auto update = [&](int i, int val) {
                i++; // 1-indexed
                for (; i <= V_SIZE; i += i & (-i)) bit[i] += val;
            };
            auto query = [&](int i) {
                i++; // 1-indexed
                int s = 0;
                for (; i > 0; i -= i & (-i)) s += bit[i];
                return s;
            };
            auto queryRange = [&](int l, int r) -> int {
                if (l > r) return 0;
                r = min(r, V_SIZE - 1);
                if (l < 0) l = 0;
                return query(r) - (l > 0 ? query(l-1) : 0);
            };
            
            int best = 0, best_ul = 0, best_vl = 0;
            int l = 0;
            
            for (int r = 0; r < S; r++) {
                int vi = seats[r].v + V_OFFSET;
                update(vi, 1);
                while (seats[r].u - seats[l].u > D) {
                    update(seats[l].v + V_OFFSET, -1);
                    l++;
                }
                // Find best v-window of size D
                // Check all v-values of seats in current window
                // This is O(window_size) per right pointer = O(S^2) total
                // Use BIT to query: for each seat in window, check [v_i, v_i+D]
                // But that's still O(window_size * log) per step
                // 
                // Let's just query for each seat currently entering (seats[r])
                // and also check the optimal starting at seats[r].v - D (ending at seats[r].v)
                // Actually we should check starting at each v in the window... 
                // 
                // Optimization: only check v-windows starting at actual seat v values.
                // For the current window [l..r], check v-window starting at each seats[i].v for i in [l..r].
                // = O(window_size) queries each O(log) = O(S^2 log / S) = O(S log) amortized? No.
                //
                // But: we only need to check when seats[r] is added (new element).
                // The best window might start at seats[r].v or end at seats[r].v.
                // Check both: [seats[r].v, seats[r].v+D] and [seats[r].v-D, seats[r].v].
                
                // Actually the optimal v-window must start at some seat's v value.
                // When we add seats[r], we should check windows starting at seats[r].v.
                // But existing windows might now be better too...
                // 
                // For a correct but potentially slow solution, let's check the window
                // starting at each of the O(window) v values. In practice for competition
                // grids this might be fast enough.
                // 
                // For now, just check starting at seats[r].v and seats[r].v - D:
                for (int delta = 0; delta <= 1; delta++) {
                    int vl = (delta == 0) ? seats[r].v : seats[r].v - D;
                    int cnt = queryRange(vl + V_OFFSET, vl + D + V_OFFSET);
                    if (cnt > best) {
                        best = cnt;
                        best_ul = seats[l].u;
                        best_vl = vl;
                    }
                }
            }
            return {best >= K, best_ul, best_vl};
        };
        
        // Hmm the above "check only 2 windows per step" is incorrect.
        // Let me think again...
        //
        // CORRECT efficient approach:
        // For each right u-pointer r, the u-window is [seats[l].u, seats[r].u].
        // As r increases, the set of v values grows. The best v-window can only improve.
        // We want the v-window [vl, vl+D] with most points.
        // This is a classic "max points in window" problem solvable with sliding window on sorted v.
        // But we can't maintain sorted v incrementally easily for this.
        //
        // SIMPLIFICATION: The answer is just the minimum D.
        // Let's enumerate: for each pair of seats (anchor, anchor), compute the bounding box.
        // But O(S^2) is too slow.
        //
        // CORRECT EFFICIENT approach using the rotation trick:
        // Binary search on D. For check:
        //   Sort seats by u. Two pointer on u gives us the valid u-range.
        //   Within that, we need >= K seats in a v-interval of length D.
        //   This equals: can we find K seats in a K-th window?
        //   Use sliding window on sorted-by-v with TWO pointers simultaneously.
        //
        // The key: we DON'T iterate over all pairs. We iterate over all right endpoints r (by u).
        // For each r, we have a set of v values (the u-window). We want max in v-window of D.
        // 
        // If we maintain v-values in a sorted array and use two-pointer ON THAT array:
        // But as r increases, l might increase too, and we need to insert/delete from sorted array.
        //
        // ACCEPTED APPROACH for competition: 
        // Since V_SIZE = N+M <= 2000, use a BIT.
        // For each u-window, we don't find the BEST v-window by checking all O(S) starting points.
        // Instead, maintain a "v-count" array and use prefix sums.
        // But prefix sum query for "best window of size D" is O(V_SIZE) per update.
        // Total: O(S * V_SIZE) = O(10^6 * 2000) = too slow.
        //
        // GIVEN CONSTRAINTS: N,M <= 1000, so V_SIZE = N+M <= 2000.
        // S = number of available seats <= N*M <= 10^6.
        // But sum of N*M <= 10^6, so for a single test case, S <= 10^6.
        //
        // WORKABLE APPROACH:
        // Sort seats by u. Two pointer on u-window.
        // Maintain array cnt[v] = number of seats with that v value in current u-window.
        // Maintain sliding window sum for v-window of size D using a prefix sum array.
        // When we add/remove a seat, update cnt[v] in O(1).
        // Then recompute prefix sums in O(V_SIZE) and find best v-window in O(V_SIZE).
        // Total: O(S * V_SIZE) per binary search step. With S = 10^6, V_SIZE = 2000, log = 11:
        //   10^6 * 2000 * 11 = 2.2 * 10^10. WAY too slow.
        //
        // BETTER: When a seat is added/removed, update prefix sums lazily and query in O(1).
        // Use a BIT on v-values (size V_SIZE = 2000).
        // For each right pointer r:
        //   Add seat to BIT in O(log V_SIZE).
        //   Remove expired seats from BIT in O(log V_SIZE).
        //   Now find v-window of size D with most seats.
        //   This requires querying O(V_SIZE) windows or using a smarter structure.
        //
        // To find max in sliding v-window: maintain a sliding window max structure.
        // But as u-window changes, v-values change non-monotonically.
        //
        // FINAL INSIGHT: We can do this in O(S log S) total:
        // Sort seats by v as secondary sort.
        // Use a two-pointer approach on BOTH dimensions simultaneously.
        // This is the "4D" bounding box minimization, which is actually hard.
        //
        // PRACTICAL APPROACH for this competition problem:
        // Since N,M <= 1000, V_SIZE = N+M <= 2000.
        // Binary search on D.
        // For each D, use a 2D sliding window:
        //   - Sweep through u values from 0 to N+M-2.
        //   - Maintain a BIT on v (size 2000).
        //   - Use two pointers for u-window.
        //   - For v-window: for each v-start, query BIT. O(V_SIZE) per u-step.
        //   - Total per binary search: O(V_SIZE^2) = O(4*10^6).
        //   - With binary search: O(V_SIZE^2 * log(V_SIZE)) = O(4*10^7). Acceptable!
        //
        // Wait but this doesn't account for the seats correctly. Let me restate:
        // 
        // For each D:
        //   Create a 2D array count[u][v] (but u,v range up to 2000, so 2000x2000 = 4M entries).
        //   Fill it: for each available seat (r,c), count[r+c][r-c+M-1]++.
        //   Now find a rectangle [u0,u0+D] x [v0,v0+D] with max sum.
        //   This is the 2D sliding window max problem, solvable in O(V_SIZE^2).
        //
        // TOTAL: O(V_SIZE^2 * log(N+M)) = O(4*10^6 * 11) = 4.4*10^7. 
        // Memory: 2000*2000 = 4M integers. Fine.
        //
        // This is the correct efficient approach! Let's implement it.
        
        int U_SIZE = N + M; // u = r+c ranges 0 to N+M-2
        // V_OFFSET = M-1, V_SIZE = N+M, v+V_OFFSET ranges 0 to N+M-2
        
        // Build 2D grid in (u,v) space
        // count2d[u][v+V_OFFSET] = 1 if seat at (r,c) with r+c=u, r-c=v is available
        // But we also need aura for bonus.
        // Let's store count and aura_sum separately.
        
        vector<vector<int>> cnt2d(U_SIZE, vector<int>(V_SIZE, 0));
        vector<vector<int>> aura2d(U_SIZE, vector<int>(V_SIZE, 0));
        
        for (int r = 0; r < N; r++)
            for (int c = 0; c < M; c++)
                if (grid[r][c] == '-') {
                    int u = r + c;
                    int v = r - c + V_OFFSET;
                    cnt2d[u][v]++;
                    aura2d[u][v] += aura[r][c];
                }
        
        // For a given D, find the best rectangle [u0,u0+D] x [v0,v0+D]:
        // Use 2D prefix sums, then slide.
        // But 2D prefix sums with D varying = O(V_SIZE^2) per D during binary search.
        
        // Step 1: Compute prefix sums for count2d and aura2d.
        // psum[u][v] = sum of cnt2d[0..u][0..v]
        vector<vector<int>> psum(U_SIZE + 1, vector<int>(V_SIZE + 1, 0));
        vector<vector<long long>> paura(U_SIZE + 1, vector<long long>(V_SIZE + 1, 0));
        
        for (int u = 0; u < U_SIZE; u++)
            for (int v = 0; v < V_SIZE; v++) {
                psum[u+1][v+1] = cnt2d[u][v] + psum[u][v+1] + psum[u+1][v] - psum[u][v];
                paura[u+1][v+1] = aura2d[u][v] + paura[u][v+1] + paura[u+1][v] - paura[u][v];
            }
        
        auto queryRect = [&](int u0, int v0, int u1, int v1) -> int {
            u0 = max(u0, 0); v0 = max(v0, 0);
            u1 = min(u1, U_SIZE-1); v1 = min(v1, V_SIZE-1);
            if (u0 > u1 || v0 > v1) return 0;
            return psum[u1+1][v1+1] - psum[u0][v1+1] - psum[u1+1][v0] + psum[u0][v0];
        };
        
        auto queryAura = [&](int u0, int v0, int u1, int v1) -> long long {
            u0 = max(u0, 0); v0 = max(v0, 0);
            u1 = min(u1, U_SIZE-1); v1 = min(v1, V_SIZE-1);
            if (u0 > u1 || v0 > v1) return 0;
            return paura[u1+1][v1+1] - paura[u0][v1+1] - paura[u1+1][v0] + paura[u0][v0];
        };
        
        // Binary search on D
        int lo = 0, hi = N + M - 2;
        
        auto check = [&](int D) -> bool {
            for (int u0 = 0; u0 < U_SIZE; u0++)
                for (int v0 = 0; v0 < V_SIZE; v0++)
                    if (queryRect(u0, v0, u0+D, v0+D) >= K)
                        return true;
            return false;
        };
        
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) hi = mid;
            else lo = mid + 1;
        }
        
        int bestD = lo;
        
        // Find best window for bestD (minimizing aura for bonus)
        int best_u0 = 0, best_v0 = 0;
        long long best_aura = LLONG_MAX;
        
        for (int u0 = 0; u0 < U_SIZE; u0++)
            for (int v0 = 0; v0 < V_SIZE; v0++)
                if (queryRect(u0, v0, u0+bestD, v0+bestD) >= K) {
                    long long a = queryAura(u0, v0, u0+bestD, v0+bestD);
                    if (a < best_aura) {
                        best_aura = a;
                        best_u0 = u0;
                        best_v0 = v0;
                    }
                }
        
        // Collect all available seats in the best window and pick K with min aura
        vector<pair<int,pair<int,int>>> candidates; // {aura, {r,c}}
        for (int r = 0; r < N; r++)
            for (int c = 0; c < M; c++) {
                if (grid[r][c] != '-') continue;
                int u = r + c;
                int v = r - c + V_OFFSET;
                if (u >= best_u0 && u <= best_u0 + bestD && v >= best_v0 && v <= best_v0 + bestD)
                    candidates.push_back({aura[r][c], {r,c}});
            }
        
        sort(candidates.begin(), candidates.end());
        
        for (int i = 0; i < K; i++)
            cout << candidates[i].second.first << " " << candidates[i].second.second << "\n";
    }
    
    return 0;
}