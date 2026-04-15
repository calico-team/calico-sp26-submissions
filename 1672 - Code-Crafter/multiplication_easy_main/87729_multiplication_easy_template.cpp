#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int R, C, V, W;
};

/*
 * Fill in the original array A (length N, each in [1, 10^9])
 * and discards (at most D distinct 1-indexed cell indices). The
 * discards output line will begin with t, the number of discarded
 * cells, followed by those t indices; t is computed and written
 * for you in main().
 *
 * N: length of the array A
 * M: number of cells
 * D: maximum number of cells you may discard
 * cells: vector of M Cells; for cell k (1-indexed), the product
 *        A[R] * A[C] should be close to the target V, with weight W
 */
void solve(int N, int M, int D, const vector<Cell>& cells,
           vector<int>& A, vector<int>& discards) {
    A.assign(N, 1);
    vector<vector<int>> adj(N);
    for(int i = 0; i < M; ++i) {
        adj[cells[i].R - 1].push_back(i);
        adj[cells[i].C - 1].push_back(i);
    }
    
    for(int i = 0; i < N; ++i) {
        double s = 0;
        int c = 0;
        for(int j : adj[i]) {
            s += sqrt((double)cells[j].V);
            c++;
        }
        if(c > 0) {
            A[i] = max(1, (int)round(s / c));
        }
    }
    
    vector<bool> in_discard(M, false);

    for(int p = 0; p < 3; ++p) {
        int iters = (p == 0 ? 15 : 10);

        for(int it = 0; it < iters; ++it) {
            for(int i = 0; i < N; ++i) {

                struct Point { 
                    double v, w; 
                };

                vector<Point> pts;
                
                for(int k : adj[i]) {
                    if(in_discard[k]) continue;
                    long long other;
                    if (cells[k].R - 1 == i) other = A[cells[k].C - 1];
                    else other = A[cells[k].R - 1];
                    
                    double w = (double)cells[k].W * other / cells[k].V;
                    double v = (double)cells[k].V / other;

                    pts.push_back({v, w});
                }
                if(pts.empty()) 
                    continue;
                
                double tot_w = 0;

                for(const auto& p : pts) 
                    tot_w += p.w;
                sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) { return a.v < b.v; });
                
                double half = tot_w / 2.0;
                double cur_w = 0;
                double best_v = pts.back().v;

                for(const auto& p : pts) {
                    cur_w += p.w;
                    if(cur_w >= half) {
                        best_v = p.v;
                        break;
                    }
                }
                
                long long cands[3] = {max(1LL, (long long)floor(best_v)), max(1LL, (long long)ceil(best_v)), 1LL};

                double best_cost = -1;

                int best_a = A[i];
                for(long long cand : cands) {
                    double cur_cost = 0;
                    for(const auto& q : pts) {
                        cur_cost += q.w * abs(cand - q.v);
                    }
                    if(best_cost < 0 || cur_cost < best_cost) {
                        best_cost = cur_cost;
                        best_a = (int)cand;
                    }
                }
                A[i] = best_a;
            }
        }
        
        if (D > 0 && p < 2) {
            struct ErrorInfo { double err; int k; };
            vector<ErrorInfo> errs;
            errs.reserve(M);
            for(int i = 0; i < M; ++i) {
                double e = (double)cells[i].W * abs((long long)A[cells[i].R - 1] * A[cells[i].C - 1] - cells[i].V) / cells[i].V;
                errs.push_back({e, i});
            }
            sort(errs.begin(), errs.end(), [](const ErrorInfo& a, const ErrorInfo& b) {
                return a.err > b.err;
            });
            in_discard.assign(M, false);
            for(int i = 0; i < D && i < M; ++i) {
                in_discard[errs[i].k] = true;
            }
        }
    }
    
    discards.clear();
    for(int i = 0; i < M; ++i) {
        if(in_discard[i]) discards.push_back(i + 1);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, D;
    cin >> N >> M >> D;
    vector<Cell> cells(M);
    for (int i = 0; i < M; i++) {
        cin >> cells[i].R >> cells[i].C >> cells[i].V >> cells[i].W;
    }

    vector<int> A, discards;
    solve(N, M, D, cells, A, discards);

    for (int i = 0; i < N; i++) {
        if (i > 0) cout << ' ';
        cout << A[i];
    }
    cout << '\n';
    cout << discards.size();
    for (int k : discards) cout << ' ' << k;
    cout << '\n';
    return 0;
}







int better_than_me = 0;
void read_your_input() {}