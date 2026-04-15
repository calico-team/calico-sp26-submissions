#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--){
        int N,M,K; cin>>N>>M>>K;
        vector<string> grid(N);
        for(int i=0;i<N;i++) cin>>grid[i];

        // Collect available seats with aura
        struct Seat { int u,v,r,c,aura; };
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
        int S=(int)seats.size();

        if(K==1){
            int bi=0;
            for(int i=1;i<S;i++) if(seats[i].aura<seats[bi].aura) bi=i;
            cout<<seats[bi].r<<" "<<seats[bi].c<<"\n";
            continue;
        }

        // Sort by v (primary), then u (secondary)
        sort(seats.begin(),seats.end(),[](const Seat&a,const Seat&b){
            return a.v<b.v||(a.v==b.v&&a.u<b.u);
        });

        // Feasibility check for distance D:
        // Slide window [l..r] on v-sorted seats with v-range <= D.
        // Within window, find K seats with u-range <= D.
        // Sort window by u, slide K consecutive by u.
        // O(S log S) per check.
        
        // But we need something faster for the inner part.
        // Approach: for a v-window [l..?], all seats with v in [seats[l].v, seats[l].v+D].
        // Within those, sort by u, slide window of K on u checking u-range <= D.
        // Two pointer on l: as l advances, r advances. 
        // We maintain a sorted structure (by u) for elements in [l,r].
        // For each l, after updating, scan K consecutive by u.
        // Use a policy-based tree or BIT? No — use a simpler approach.
        //
        // Key insight: sort by v. Two pointer l,r on v with v[r]-v[l]<=D.
        // Within [l,r], we need K elements with min u-range.
        // That's the min of (u[i+K-1] - u[i]) over the u-sorted subsequence of [l,r].
        // Maintain a multiset of u-values. When we add/remove, update.
        // To find min K-consecutive u-range in a multiset: 
        //   keep sorted vector, check us[i+K-1]-us[i] for all i.
        // That's O(window_size) per step — still too slow worst case.
        //
        // Better: maintain sorted order by u using a Fenwick/BIT on coordinate-compressed u values.
        // For each v-window, find the K-th smallest u minus (K-th from some offset).
        // Actually: compress u values. Use a BIT to count. 
        // To find min range of K consecutive: we need the positions where
        // the i-th element and (i+K-1)-th element in u-sorted order minimize their difference.
        // Walk through all occupied u-positions using two iterators that maintain K elements between them.
        
        // Let's do: coordinate-compress u. Maintain BIT for count.
        // Use two "iterators" on u-axis: lo_ptr and hi_ptr with exactly K elements in [lo_ptr, hi_ptr].
        // Slide lo_ptr up, adjust hi_ptr.
        // This gives O(S * (u_range / step)) which could be bad.
        //
        // Simplest efficient approach: 
        // Sort seats by v. Two-pointer [l,r] with v-range<=D.
        // Maintain the u-values in a sorted order using a Fenwick tree on compressed u.
        // For feasibility: just need to know if any K consecutive u-values have range <= D.
        // Use two pointers on the BIT: maintain lo_u, hi_u with K elements between them.
        // When adding element to BIT, update hi_u/lo_u pointers.
        // When removing, update similarly.
        // This is complex. Let's just do the simpler O(S log S * log(N+M)) approach:
        
        // For each binary search step:
        //   Sort by v. Two pointer [l,r] with v_r - v_l <= D.
        //   When the window changes, maintain sorted list of u-values (vector + insort).
        //   Each element is inserted/removed once → total O(S log S) for insort.
        //   For each window state after adding r, check if min K-consecutive u-range <= D.
        //   Key: we don't re-check everything. We only check near the newly inserted element.
        //   Actually, min K-consecutive can only decrease or change near insertion point.
        //   Hmm, that's tricky. Let's just keep a running minimum.
        //
        // Actually: total insertions + deletions = O(S). Each insert into sorted vector = O(S) worst case 
        // due to shifting. That's O(S^2) total. For S=10^6, too slow.
        //
        // Final approach: EVENT-BASED.
        // Sort all seats by v. Group by unique v. 
        // Two pointer on v-groups.
        // Within window, collect all u values, sort them, slide K.
        // But re-sorting is expensive.
        //
        // ACTUALLY: Let's think differently.
        // Sort seats by u. For each i, consider seats[i..i+K-1] (K consecutive by u).
        // The u-range = seats[i+K-1].u - seats[i].u.
        // The v-range = max(v) - min(v) over seats[i..i+K-1].
        // Chebyshev distance = max(u-range, v-range).
        // We want to minimize this over all i.
        // For v-range over sliding window of K: use monotonic deques.
        // This is O(S log S) total! (sort + linear scan)

        // Sort by u
        sort(seats.begin(),seats.end(),[](const Seat&a,const Seat&b){
            return a.u<b.u||(a.u==b.u&&a.v<b.v);
        });

        // Sliding window of K consecutive (by u), track max/min v with deques
        // Chebyshev dist = max(u[i+K-1]-u[i], maxv-minv)
        // We want min over all windows of size K.
        // BUT: we don't have to pick K consecutive by u! We pick ANY K from the full set.
        // K consecutive by u is not sufficient — we might skip some to get better v-range.
        
        // Hmm wait. If we sort by u, the optimal K seats that minimize max(u-range, v-range)
        // must be consecutive in u? No — we could skip a point with extreme v to reduce v-range
        // even if it slightly increases u-range.
        
        // The standard approach for min Chebyshev diameter of K points from S:
        // Sort by u. For each pair (i, j) with j-i >= K-1, consider picking K from seats[i..j]
        // with u-range = u[j]-u[i] and we want v-range minimized among any K in [i..j].
        // Binary search on answer D. Check: exists K seats with u-range<=D and v-range<=D.
        // Sort by u. Two pointer i,j with u[j]-u[i]<=D. Within window, need K seats with 
        // v-range<=D. Sort the v-values in window, check K consecutive. 
        // With the right data structure this is O(S log S).
        
        // Let's use: sort by u. Two pointer [j..i] with u[i]-u[j]<=D. 
        // Maintain sorted multiset of v-values. Check if any K consecutive have range<=D.
        // Use a Fenwick tree on compressed v to efficiently maintain and query.
        // To check "K consecutive v with range<=D": walk K-apart pointers on v-axis.
        
        // Compress v values
        vector<int> vvals(S);
        for(int i=0;i<S;i++) vvals[i]=seats[i].v;
        {
            vector<int> tmp=vvals;
            sort(tmp.begin(),tmp.end()); tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
            for(int i=0;i<S;i++) vvals[i]=(int)(lower_bound(tmp.begin(),tmp.end(),vvals[i])-tmp.begin());
        }
        // Raw v values for range checks
        vector<int> rawv(S);
        for(int i=0;i<S;i++) rawv[i]=seats[i].v;
        // Sorted unique raw v
        vector<int> uniqv;
        { vector<int> tmp(S); for(int i=0;i<S;i++) tmp[i]=seats[i].v;
          sort(tmp.begin(),tmp.end()); tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
          uniqv=tmp;
        }
        int VN=(int)uniqv.size();
        
        // BIT for count of v-values
        vector<int> bit(VN+2,0);
        auto upd=[&](int p,int val){ for(p++;p<=VN;p+=p&(-p)) bit[p]+=val; };
        auto qry=[&](int p)->int{ int s=0; for(p++;p>0;p-=p&(-p)) s+=bit[p]; return s; };
        // prefix sum [0..p]
        // count in [a,b] = qry(b)-qry(a-1)
        // Find position of k-th element (1-indexed) in BIT
        auto kth=[&](int k)->int{
            int pos=0;
            for(int pw=1<<(__lg(VN)+1);pw;pw>>=1){
                if(pos+pw<=VN && bit[pos+pw]<k){
                    k-=bit[pos+pw]; pos+=pw;
                }
            }
            return pos; // 0-indexed in compressed v
        };
        
        auto feasible=[&](int D)->bool{
            fill(bit.begin(),bit.end(),0);
            int j=0, cnt=0;
            for(int i=0;i<S;i++){
                upd(vvals[i],1); cnt++;
                while(seats[j].u<seats[i].u-D){
                    upd(vvals[j],-1); cnt--; j++;
                }
                if(cnt>=K){
                    // Check if K consecutive v-values in BIT have range <= D
                    // Find the k-th smallest v and the (k+K-1)-th, check range
                    // k=1: v_1 and v_K
                    int lo_v_idx=kth(1);
                    int hi_v_idx=kth(K);
                    if(uniqv[hi_v_idx]-uniqv[lo_v_idx]<=D) return true;
                    // slide: for k=2..cnt-K+1
                    // Actually we need min over all (kth(k+K-1) - kth(k)) for k=1..cnt-K+1
                    // Doing cnt-K+1 kth queries is O(cnt * log VN) — could be slow
                    // Better: walk through compressed v positions
                    // Iterate through non-zero v-positions with two pointers maintaining K elements
                    int total=0, left_ptr=-1, right_ptr=-1;
                    // Find first occupied position
                    for(int p=0;p<VN;p++){
                        int c2=qry(p)-(p>0?qry(p-1):0);
                        if(c2>0 && left_ptr<0) { left_ptr=p; break; }
                    }
                    // This walking is also O(VN) which could be large
                    // Let's just do kth approach — cnt <= S, log VN is small
                    for(int k=1;k+K-1<=cnt;k++){
                        int lv=kth(k), hv=kth(k+K-1);
                        if(uniqv[hv]-uniqv[lv]<=D) return true;
                    }
                }
            }
            return false;
        };
        
        // Hmm, the kth loop is O(cnt * log VN) per window state, and window changes S times.
        // Worst case O(S^2 * log VN). Still too slow.
        
        // CORRECT efficient approach:
        // Sort by u. Two pointer [j..i] with u-range <= D.
        // Maintain BIT on compressed v.
        // Maintain two pointers on the v-axis: lo_ptr and hi_ptr
        // such that there are exactly K elements with v in [uniqv[lo_ptr], uniqv[hi_ptr]].
        // When element added/removed, adjust pointers.
        // Check if uniqv[hi_ptr] - uniqv[lo_ptr] <= D.
        // The trick: maintain lo_ptr as smallest v-index with qry(lo_ptr)>=1,
        // and hi_ptr such that qry(hi_ptr)-qry(lo_ptr-1) >= K and hi_ptr is minimized.
        // When adding an element: if its v < lo_ptr, lo_ptr might decrease.
        // This gets complicated. 
        
        // SIMPLEST CORRECT O(S log S) approach:
        // Observation: sort by u. Slide window [j,i] with u[i]-u[j]<=D.
        // Within window, we want min v-range of K elements.
        // That equals min over k of (kth_smallest_v(k+K-1) - kth_smallest_v(k)).
        // Key insight: as i increases by 1, one element added (and possibly some removed from j).
        // The answer can only change near the inserted/removed elements.
        // But tracking this incrementally is hard.
        //
        // ALTERNATIVE O(S log S) total:
        // Sort by v. For windows of K consecutive by v with v-range <= D,
        // check if there exist K among them whose u-range <= D.
        // K consecutive by v → their u-values may vary.
        // We need K of them with u-range <= D.
        // Within those ≥K points (v-range ≤ D window), find K with min u-range.
        // Sort those by u, pick K consecutive by u with min range.
        // This is a 2D sliding window.
        //
        // Let's do: sort by v. Two pointer l,r with v[r]-v[l] <= D.
        // Maintain multiset of u-values. Check min K-consecutive u-range.
        // Maintain with an ordered set + walking? 
        //
        // Actually for feasibility only, I don't need the minimum K-consecutive u-range,
        // I just need to know if ANY K-consecutive u-range <= D.
        // Maintain a sorted vector of u. On insert/delete, track K-consecutive ranges.
        
        // Let me just use a clean approach with std::set + augmentation.
        // OR: use the "sort by v, ordered set of u, walk two K-apart iterators" approach.
        
        // I'll reset and implement cleanly:
        // 1) Sort by v
        // 2) Two pointer [l,r] with v-range <= D
        // 3) Maintain multiset<int> of u-values
        // 4) On each window, check K-consecutive u min range: 
        //    iterate from begin, keep two iterators K-1 apart, track min diff.
        //    BUT iterating the multiset each time is O(window_size).
        // 5) Optimization: only check near insertion/deletion point.
        //    When inserting u_new: find its position in multiset. 
        //    The only K-consecutive ranges that could improve go through u_new.
        //    Check K-1 ranges around u_new. O(K) per insertion.
        //    When deleting u_old: the ranges that were going through u_old might worsen.
        //    We need to track the global minimum. Deletion is harder.
        //    We'd need to re-check if the old min was using the deleted element.
        
        // This is getting complex. Let me just implement the straightforward 
        // O(S * log(N+M)) approach using sort + two pointer + multiset + 
        // incremental K-consecutive tracking.
        //
        // For S up to 10^6 and binary search log(2000)=11 iterations:
        // Each iteration: sort is done once. Two pointer is O(S).
        // At each step, insert/delete from multiset O(log S).
        // Need to check min K-consecutive u-range in multiset.
        // If we maintain ALL K-consecutive differences in another multiset, 
        // insert costs O(K) to update neighbors. That's O(S*K) worst case per iteration.
        // K can be up to 10^6. Too slow.
        //
        // For FEASIBILITY only: we just need to know if min K-consecutive <= D.
        // We can maintain a count of how many K-consecutive pairs have diff <= D.
        // On insert of element at position p in sorted order:
        //   Old pair (p-1, p) is destroyed, new pairs (p-1, p) and (p, p+1) created.
        //   But K-consecutive means checking u[i+K-1]-u[i], not adjacent pairs!
        //   We'd need the (K-1)-th neighbor difference.
        
        // OK let me think about this more carefully.
        // Sort by v once. Sweep l,r. Maintain multiset<int> us.
        // On each r step, insert seats[r].u. Remove elements while v-range > D.
        // After each change, check: does there exist a subsequence of K elements 
        // in us whose max-min <= D?
        // In a sorted set, that's: min over i of (i+K-1)-th element - i-th element.
        // Maintain us as a vector<int> kept sorted (insort). 
        // For feasibility, after insert at position p, 
        // the only new K-consecutive window that might work is one containing p.
        // Specifically windows [p-K+1..p], [p-K+2..p+1], ..., [p..p+K-1].
        // Check at most K of these. If any has range <= D, feasible.
        // Similarly on delete, we might lose a feasible window.
        // But we only need to return true on FIRST feasible, so we can be lazy:
        // maintain a global min_range variable:
        //   On insert at pos p: check windows containing p. Update min_range if improved.
        //   On delete at pos p: if min_range window overlapped p, recalculate min_range entirely.
        // Recalculation = O(S) which happens rarely (only when deleting from optimal window).
        // This could be O(S^2) worst case but often fast in practice.
        //
        // For competition constraints (S up to 10^6, TL 2s), this should work in C++.
        // Let me implement this clean approach.

        // === RESET: Clean implementation ===
        // Sort by v
        vector<int> order(S);
        iota(order.begin(),order.end(),0);
        sort(order.begin(),order.end(),[&](int a,int b){
            return seats[a].v<seats[b].v||(seats[a].v==seats[b].v&&seats[a].u<seats[b].u);
        });
        
        // For feasibility: sort by v, two-pointer, maintain sorted vector of u
        auto feasible2=[&](int D) -> bool {
            vector<int> us; // sorted u-values in current v-window
            int l=0;
            for(int ri=0;ri<S;ri++){
                int idx=order[ri];
                // insert seats[idx].u into us (sorted)
                int u=seats[idx].u;
                auto it=lower_bound(us.begin(),us.end(),u);
                int p=(int)(it-us.begin());
                us.insert(it,u);
                // remove from left while v-range > D
                while(seats[order[ri]].v - seats[order[l]].v > D){
                    int ru=seats[order[l]].u;
                    auto it2=lower_bound(us.begin(),us.end(),ru);
                    us.erase(it2);
                    l++;
                }
                int sz=(int)us.size();
                if(sz>=K){
                    // check windows of K containing newly inserted position p
                    // p might have shifted due to deletions, find current position
                    // Actually after deletions p is invalid. Let's re-find:
                    // But this is expensive. Let's just check all K-consecutive.
                    // For feasibility with early return:
                    for(int i=0;i<=sz-K;i++){
                        if(us[i+K-1]-us[i]<=D) return true;
                    }
                }
            }
            return false;
        };
        
        // Actually the inner loop checking all K-consecutive is O(sz) per step.
        // Total could be O(S^2). Let me optimize: only check near insertion.
        // After insert at position p (in the sorted us), only check windows 
        // [max(0,p-K+1) .. min(sz-K, p)].
        // That's at most K checks per insertion.
        // But on deletion, the sorted positions shift. 
        // Actually feasibility has early return — once found, stop.
        // And we process in order. Let me just track the minimum K-consecutive 
        // difference incrementally.
        
        // Cleaner approach: 
        // maintain min_diff = min over i of us[i+K-1]-us[i].
        // On insert at pos p:
        //   Remove old window diffs that cross p: window i where i<=p<=i+K-1,
        //   i.e., i in [p-K+1, p]. But we only track the global min.
        //   Just check windows [max(0,p-K+1)..min(sz-K,p)] and update min_diff.
        // On delete at pos p:
        //   If the min_diff window crossed p, recalculate. Otherwise min_diff stays.
        //   Recalc = O(sz).
        // This is fast in practice. Let me implement.
        
        auto feasible3=[&](int D) -> bool {
            vector<int> us;
            int l=0;
            int min_diff=INT_MAX;
            for(int ri=0;ri<S;ri++){
                int u=seats[order[ri]].u;
                auto it=lower_bound(us.begin(),us.end(),u);
                int p=(int)(it-us.begin());
                us.insert(it,u);
                int sz=(int)us.size();
                // update min_diff with windows containing p
                for(int i=max(0,p-K+1);i<=min(sz-K,p);i++){
                    min_diff=min(min_diff, us[i+K-1]-us[i]);
                }
                // remove from left
                while(seats[order[ri]].v-seats[order[l]].v>D){
                    int ru=seats[order[l]].u;
                    auto it2=lower_bound(us.begin(),us.end(),ru);
                    int dp=(int)(it2-us.begin());
                    us.erase(it2);
                    l++;
                    // check if min_diff was affected
                    // conservatively recalculate (only needed if deletion might increase min)
                    // Since we want early return, let's just recalc
                    sz=(int)us.size();
                    if(sz>=K){
                        min_diff=INT_MAX;
                        for(int i=max(0,dp-K);i<=min(sz-K,dp);i++){
                            min_diff=min(min_diff, us[i+K-1]-us[i]);
                        }
                        // But we lost track of the global min from other positions.
                        // Need full recalc if min_diff increased. Let's just do full recalc.
                        min_diff=INT_MAX;
                        for(int i=0;i<=sz-K;i++)
                            min_diff=min(min_diff, us[i+K-1]-us[i]);
                    } else min_diff=INT_MAX;
                }
                if(min_diff<=D) return true;
            }
            return false;
        };
        
        // The full recalc on deletion is O(sz) and could make this O(S^2).
        // Let me skip the incremental tracking and do something smarter.
        
        // FINAL APPROACH — clean O(S log S) per binary search step:
        // Use a balanced BST (std::set with order) isn't easy.
        // Use a BIT + two walking pointers approach.
        
        // Compress u values
        vector<int> uvals(S);
        for(int i=0;i<S;i++) uvals[i]=seats[i].u;
        vector<int> ucomp;
        { auto tmp=uvals; sort(tmp.begin(),tmp.end()); 
          tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
          ucomp=tmp;
          for(int i=0;i<S;i++) uvals[i]=(int)(lower_bound(tmp.begin(),tmp.end(),uvals[i])-tmp.begin());
        }
        int UN=(int)ucomp.size();
        
        vector<int> bit2(UN+2,0);
        auto upd2=[&](int p,int val){ for(p++;p<=UN;p+=p&(-p)) bit2[p]+=val; };
        auto qry2=[&](int p)->int{ int s=0; for(p++;p>0;p-=p&(-p)) s+=bit2[p]; return s; };
        auto kth2=[&](int k)->int{ // 1-indexed k
            int pos=0;
            for(int pw=1<<(__lg(UN+1));pw;pw>>=1){
                if(pos+pw<=UN && bit2[pos+pw]<k){
                    k-=bit2[pos+pw]; pos+=pw;
                }
            }
            return pos;
        };
        
        auto feasible4=[&](int D)->bool{
            fill(bit2.begin(),bit2.end(),0);
            int l=0, cnt2=0;
            for(int ri=0;ri<S;ri++){
                int idx=order[ri];
                upd2(uvals[idx],1); cnt2++;
                while(seats[order[ri]].v-seats[order[l]].v>D){
                    upd2(uvals[order[l]],-1); cnt2--; l++;
                }
                if(cnt2>=K){
                    // Check: kth2(1) and kth2(K) -> ucomp[kth2(K)] - ucomp[kth2(1)] <= D?
                    // But we need min over ALL k of kth2(k+K-1)-kth2(k).
                    // Only check kth2(1) and kth2(K) for the FIRST K elements.
                    // That's just one window. We need all windows.
                    // With walking pointers:
                    // lo_ptr starts at kth2(1), hi_ptr at kth2(K).
                    // Then advance both by 1: kth2(2), kth2(K+1), etc.
                    // Each kth2 call is O(log UN). Total O(cnt2 * log UN) per step.
                    // Total over all steps: O(S * cnt2 * log UN) → O(S^2 log S) worst case. Bad.
                    
                    // Better: just check kth2(1) and kth2(K).
                    // If ucomp[kth2(K)] - ucomp[kth2(1)] <= D, return true.
                    // But this only checks the first K elements by u.
                    // We need min over ALL consecutive K.
                    // Hmm. This is only correct if the minimum gap is at position 1.
                    
                    // We need to check all cnt2-K+1 windows. 
                    // Alternative: maintain two pointers on the BIT that walk together.
                    // lo walks from rank 1 to rank cnt2-K+1.
                    // hi walks from rank K to rank cnt2.
                    // For each, check ucomp[kth2(hi)] - ucomp[kth2(lo)] <= D.
                    // Each kth2 is O(log UN). So O(cnt2 * log UN) per ri.
                    // Total O(S * avg_cnt * log UN). For S=10^6 this is way too slow.
                    
                    // OK, I think for this problem with constraints N,M<=1000 and sum N*M<=10^6,
                    // the number of available seats S is at most 10^6.
                    // But the number of distinct u or v values is at most 2000.
                    // So let's use a different approach: iterate over compressed u values.
                    
                    // Walk compressed u from 0 to UN-1 with two pointers.
                    // Left pointer lp, right pointer rp.
                    // Count elements between lp and rp.
                    // When count >= K and ucomp[rp]-ucomp[lp] <= D, feasible.
                    // Advance lp to reduce range. Advance rp to get more elements.
                    
                    int cnt_inner=0;
                    int lp=0;
                    // find first lp with bit count > 0
                    while(lp<UN && qry2(lp)-(lp>0?qry2(lp-1):0)==0) lp++;
                    if(lp>=UN) continue;
                    int rp=lp;
                    cnt_inner=qry2(rp)-(lp>0?qry2(lp-1):0);
                    while(rp<UN){
                        if(cnt_inner>=K){
                            if(ucomp[rp]-ucomp[lp]<=D) return true;
                            // advance lp
                            cnt_inner-=(qry2(lp)-(lp>0?qry2(lp-1):0));
                            lp++;
                            while(lp<UN && qry2(lp)-(lp>0?qry2(lp-1):0)==0) lp++;
                            if(lp>rp) { rp=lp; if(rp<UN) cnt_inner=qry2(rp)-(lp>0?qry2(lp-1):0); }
                        } else {
                            rp++;
                            if(rp<UN) cnt_inner=qry2(rp)-(lp>0?qry2(lp-1):0);
                        }
                    }
                }
            }
            return false;
        };
        
        // This inner walk is O(UN) per ri step. Total O(S * UN). 
        // S up to 10^6, UN up to 2000 → 2*10^9. Still too slow.
        // But note: we only do the inner walk when cnt2>=K.
        // And the two pointer on v means each element enters/leaves once.
        // The inner walk is done at most S times but UN=2000.
        // 10^6 * 2000 = 2*10^9. Indeed too slow.
        
        // Let me just NOT use BIT. Use the simplest approach that works:
        // Sort by v. Two pointer. Maintain sorted vector of u (insort/erase via lower_bound).
        // After each insertion, ONLY CHECK K windows around insertion point.
        // Don't recalculate on deletion — just maintain a global flag.
        // If deletion might invalidate, do one full scan of O(sz).
        // In practice, deletions from the left of sorted-v don't often kill the 
        // optimal u-window. And we have early return.
        // Let's just try the simple approach — it should work for these constraints.

        // RESET bit2
        fill(bit2.begin(),bit2.end(),0);
        fill(bit.begin(),bit.end(),0);
        
        // Simple clean approach
        int lo2=0, hi2=N+M-2, optD2=hi2;
        while(lo2<=hi2){
            int mid2=(lo2+hi2)/2;
            // Check feasibility with sorted-vector approach
            vector<int> us2;
            int l2=0;
            bool found=false;
            for(int ri=0;ri<S&&!found;ri++){
                int u2=seats[order[ri]].u;
                auto it3=lower_bound(us2.begin(),us2.end(),u2);
                us2.insert(it3,u2);
                while(seats[order[ri]].v-seats[order[l2]].v>mid2){
                    int ru2=seats[order[l2]].u;
                    auto it4=lower_bound(us2.begin(),us2.end(),ru2);
                    us2.erase(it4);
                    l2++;
                }
                int sz2=(int)us2.size();
                if(sz2>=K){
                    for(int i2=0;i2<=sz2-K;i2++){
                        if(us2[i2+K-1]-us2[i2]<=mid2){ found=true; break; }
                    }
                }
            }
            if(found){ optD2=mid2; hi2=mid2-1; } else lo2=mid2+1;
        }
        
        // Now at optD2, find best aura K-subset
        // Same sliding window, but collect ALL feasible K-subsets and pick min aura
        {
            vector<int> us2;
            struct Entry { int u, idx; };
            vector<Entry> elist; // sorted by u
            int l2=0;
            int bestAura=INT_MAX;
            vector<int> bestSet;
            for(int ri=0;ri<S;ri++){
                int idx=order[ri];
                int u2=seats[idx].u;
                auto cmp=[](const Entry&a, const Entry&b){ return a.u<b.u||(a.u==b.u&&a.idx<b.idx); };
                Entry e{u2, idx};
                auto it3=lower_bound(elist.begin(),elist.end(),e,cmp);
                elist.insert(it3,e);
                while(seats[order[ri]].v-seats[order[l2]].v>optD2){
                    int ru2=seats[order[l2]].u;
                    int ridx=order[l2];
                    Entry re{ru2,ridx};
                    auto it4=lower_bound(elist.begin(),elist.end(),re,cmp);
                    while(it4!=elist.end() && it4->idx!=ridx) ++it4;
                    elist.erase(it4);
                    l2++;
                }
                int sz2=(int)elist.size();
                if(sz2>=K){
                    for(int i2=0;i2<=sz2-K;i2++){
                        if(elist[i2+K-1].u-elist[i2].u<=optD2){
                            // find rightmost j2 with u-range <= optD2
                            int j2=i2+K-1;
                            { int a=i2+K-1,b=sz2-1;
                              while(a<=b){ int m=(a+b)/2; if(elist[m].u-elist[i2].u<=optD2){j2=m;a=m+1;}else b=m-1; }
                            }
                            // pick K with smallest aura from elist[i2..j2]
                            int cnt3=j2-i2+1;
                            if(cnt3==K){
                                int s=0; vector<int> ch;
                                for(int q=i2;q<=j2;q++){ s+=seats[elist[q].idx].aura; ch.push_back(elist[q].idx); }
                                if(s<bestAura){ bestAura=s; bestSet=ch; }
                            } else {
                                vector<pair<int,int>> av;
                                for(int q=i2;q<=j2;q++) av.push_back({seats[elist[q].idx].aura, elist[q].idx});
                                sort(av.begin(),av.end());
                                int s=0; vector<int> ch;
                                for(int q=0;q<K;q++){ s+=av[q].first; ch.push_back(av[q].second); }
                                if(s<bestAura){ bestAura=s; bestSet=ch; }
                            }
                        }
                    }
                }
            }
            for(int i:bestSet) cout<<seats[i].r<<" "<<seats[i].c<<"\n";
        }
    }
}
