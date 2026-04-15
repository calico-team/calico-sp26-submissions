#include<bits/stdc++.h>
using namespace std;

struct Cell {
    int R, C, V, W;
};

struct DSU {
    vector<int> p, sz;
    DSU() {}
    DSU(int n) { init(n); }
    void init(int n) {
        p.resize(n);
        sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
};

struct Cand {
    double x, w;
};

static bool candCmp(const Cand &a, const Cand &b) {
    return a.x < b.x;
}

struct Fit {
    vector<long double> base;
    vector<vector<int>> nodes,edges;
    vector<int> col;
    vector<unsigned char> bip;
};

struct Solver {
    static constexpr long long LIM = 1000000000LL;

    int N = 0, M = 0, d = 0, maxDeg = 0;
    vector<int> U, V, val, wt, deg, head, adj, ord, idx;
    vector<vector<int>> compNodes, compEdges;
    vector<double> pen;

    Solver(int n, int m, int D, const vector<Cell> &cells) {
        N = n;
        M = m;
        d = min(D, M);
        U.resize(M);
        V.resize(M);
        val.resize(M);
        wt.resize(M);
        deg.assign(N, 0);

        DSU dsu(N);
        for (int e = 0; e < M; e++) {
            int r = cells[e].R - 1;
            int c = cells[e].C - 1;
            U[e] = r;
            V[e] = c;
            val[e] = cells[e].V;
            wt[e] = cells[e].W;
            deg[r]++;
            deg[c]++;
            dsu.unite(r, c);
        }

        for (int x : deg) maxDeg = max(maxDeg, x);

        head.assign(N + 1, 0);
        for (int i = 0; i < N; i++) head[i + 1] = head[i] + deg[i];
        adj.assign(2 * M, 0);
        vector<int> cur = head;
        for (int e = 0; e < M; e++) {
            adj[cur[U[e]]++] = e;
            adj[cur[V[e]]++] = e;
        }

        vector<int> mp(N, -1), cid(N, -1);
        int cc = 0;
        for (int i = 0; i < N; i++) {
            int r = dsu.find(i);
            if (mp[r] == -1) mp[r] = cc++;
            cid[i] = mp[r];
        }

        vector<int> nc(cc, 0), ec(cc, 0);
        for (int i = 0; i < N; i++) nc[cid[i]]++;
        for (int e = 0; e < M; e++) ec[cid[U[e]]]++;

        compNodes.assign(cc, {});
        compEdges.assign(cc, {});
        for (int c = 0; c < cc; c++) {
            compNodes[c].reserve(nc[c]);
            compEdges[c].reserve(ec[c]);
        }
        for (int i = 0; i < N; i++) compNodes[cid[i]].push_back(i);
        for (int e = 0; e < M; e++) compEdges[cid[U[e]]].push_back(e);

        ord.resize(N);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int a, int b) {
            if (deg[a] != deg[b]) return deg[a] > deg[b];
            return a < b;
        });

        pen.assign(M, 0.0);
        idx.resize(M);
    }

    long long clampInt(long double x) const {
        if (!isfinite((double)x)) return 1;
        if (x < 1) return 1;
        if (x > (long double)LIM) return LIM;
        return (long long)llround(x);
    }

    double wmed(vector<Cand> &c) const {
        sort(c.begin(), c.end(), candCmp);
        long double tot = 0;
        for (auto &e : c) tot += (long double)e.w;
        long double cur = 0, need = tot * 0.5L;
        double med = c.back().x;
        for (auto &e : c) {
            cur += (long double)e.w;
            if (cur >= need) {
                med = e.x;
                break;
            }
        }
        return med;
    }

    vector<int> divisors(int x) const {
        vector<int> small, large;
        for (long long d = 1; d * d <= x; d++) {
            if (x % d != 0) continue;
            small.push_back((int)d);
            if (d * d != x) large.push_back(x / (int)d);
        }
        reverse(large.begin(), large.end());
        small.insert(small.end(), large.begin(), large.end());
        return small;
    }

    vector<long long> buildConst() const {
        vector<long long> a(N, 1);
        vector<Cand> c;
        for (int id = 0; id < (int)compEdges.size(); id++) {
            if (compEdges[id].empty()) {
                for (int u : compNodes[id]) a[u] = 1;
                continue;
            }
            c.clear();
            c.reserve(compEdges[id].size());
            for (int e : compEdges[id]) {
                c.push_back({(double)val[e], (double)wt[e] / (double)val[e]});
            }
            double med = wmed(c);
            long long x = clampInt(sqrt((long double)med));
            for (int u : compNodes[id]) a[u] = x;
        }
        return a;
    }

    Fit buildFit(const vector<unsigned char> *act,int iters,bool needMeta) const {
        vector<double> dw(N, 0.0), b(N, 0.0);
        for (int e = 0; e < M; e++) {
            if (act && !(*act)[e]) continue;
            double ww = (double)wt[e];
            double y = log((double)val[e]);
            int u = U[e], v = V[e];
            dw[u] += ww;
            dw[v] += ww;
            b[u] += ww * y;
            b[v] += ww * y;
        }

        auto mulA = [&](const vector<double> &in, vector<double> &out) {
            out.assign(N, 0.0);
            const double lam = 1e-3;
            for (int i = 0; i < N; i++) out[i] = (dw[i] + lam) * in[i];
            for (int e = 0; e < M; e++) {
                if (act && !(*act)[e]) continue;
                double ww = (double)wt[e];
                int u = U[e], v = V[e];
                out[u] += ww * in[v];
                out[v] += ww * in[u];
            }
        };

        vector<double> x(N, 0.0), r = b, z(N, 0.0), p(N, 0.0), Ap(N, 0.0), diag(N, 0.0);
        const double lam = 1e-3;
        for (int i = 0; i < N; i++) diag[i] = dw[i] + lam;

        auto dot = [&](const vector<double> &a, const vector<double> &bb) -> long double {
            long double s = 0;
            for (int i = 0; i < N; i++) s += (long double)a[i] * (long double)bb[i];
            return s;
        };

        for (int i = 0; i < N; i++) {
            z[i] = r[i] / diag[i];
            p[i] = z[i];
        }

        long double rz = dot(r, z), rz0 = rz;
        if (rz0 > 1e-30L) {
            for (int it = 0; it < iters; it++) {
                mulA(p, Ap);
                long double den = dot(p, Ap);
                if (fabsl(den) < 1e-30L) break;

                double alpha = (double)(rz / den);
                for (int i = 0; i < N; i++) {
                    x[i] += alpha * p[i];
                    r[i] -= alpha * Ap[i];
                }

                for (int i = 0; i < N; i++) z[i] = r[i] / diag[i];
                long double rz2 = dot(r, z);
                if (rz2 <= rz0 * 1e-12L) break;

                double beta = (double)(rz2 / rz);
                for (int i = 0; i < N; i++) p[i] = z[i] + beta * p[i];
                rz = rz2;
            }
        }

        Fit fit;
        fit.base.assign(N, 1.0L);
        for (int i = 0; i < N; i++) {
            long double xi = (long double)x[i];
            if (xi < -20) xi = -20;
            if (xi > 20) xi = 20;
            fit.base[i] = expl(xi);
            if (!isfinite((double)fit.base[i])) fit.base[i] = 1.0L;
        }

        DSU dsu(N);
        for (int e = 0; e < M; e++) {
            if (act && !(*act)[e]) continue;
            dsu.unite(U[e], V[e]);
        }

        vector<int> mp(N, -1), cid(N, -1);
        int cc = 0;
        for (int i = 0; i < N; i++) {
            int r0 = dsu.find(i);
            if (mp[r0] == -1) mp[r0] = cc++;
            cid[i] = mp[r0];
        }

        vector<int> nc(cc, 0), ec(cc, 0);
        for (int i = 0; i < N; i++) nc[cid[i]]++;
        for (int e = 0; e < M; e++) if (!act || (*act)[e]) ec[cid[U[e]]]++;

        fit.nodes.assign(cc, {});
        fit.edges.assign(cc, {});
        for (int c = 0; c < cc; c++) {
            fit.nodes[c].reserve(nc[c]);
            fit.edges[c].reserve(ec[c]);
        }
        for (int i = 0; i < N; i++) fit.nodes[cid[i]].push_back(i);
        for (int e = 0; e < M; e++) if (!act || (*act)[e]) fit.edges[cid[U[e]]].push_back(e);

        vector<Cand> c;
        for (int id = 0; id < cc; id++) {
            if (fit.edges[id].empty()) {
                for (int u : fit.nodes[id]) fit.base[u] = 1;
                continue;
            }
            c.clear();
            c.reserve(fit.edges[id].size());
            for (int e : fit.edges[id]) {
                long double prod = fit.base[U[e]] * fit.base[V[e]];
                if (prod < 1e-18L) prod = 1e-18L;
                long double t = (long double)val[e] / prod;
                long double ww = (long double)wt[e] * prod / (long double)val[e];
                if (t > 1e18L) t = 1e18L;
                if (ww > 1e18L) ww = 1e18L;
                c.push_back({(double)t, (double)ww});
            }
            double med = wmed(c);
            long double sc = sqrt(max((long double)med, 1e-18L));
            for (int u : fit.nodes[id]) {
                fit.base[u] *= sc;
                if (!isfinite((double)fit.base[u])) fit.base[u] = 1;
            }
        }

        fit.col.assign(N, -1);
        fit.bip.assign(cc, 1);
        if (needMeta) {
            deque<int> dq;
            for (int id = 0; id < cc; id++) {
                fit.bip[id] = 1;
                for (int s : fit.nodes[id]) {
                    if (fit.col[s] != -1) continue;
                    fit.col[s] = 0;
                    dq.push_back(s);
                    while (!dq.empty()) {
                        int u = dq.front();
                        dq.pop_front();
                        for (int p = head[u]; p < head[u + 1]; p++) {
                            int e = adj[p];
                            if (act && !(*act)[e]) continue;
                            int v = U[e] + V[e] - u;
                            if (cid[v] != id) continue;
                            if (fit.col[v] == -1) {
                                fit.col[v] = fit.col[u] ^ 1;
                                dq.push_back(v);
                            } else if (fit.col[v] == fit.col[u]) {
                                fit.bip[id] = 0;
                            }
                        }
                    }
                }
            }
        }

        return fit;
    }

    long double compPen(const Fit &fit,int cid,long double q,vector<long long> &buf) const {
        for (int u : fit.nodes[cid]) {
            long double x = fit.base[u];
            if (fit.bip[cid]) {
                if (fit.col[u] == 0) x *= q;
                else x /= q;
            }
            buf[u] = clampInt(x);
        }

        long double res = 0;
        for (int e : fit.edges[cid]) {
            long double prod = (long double)buf[U[e]] * (long double)buf[V[e]];
            res += (long double)wt[e] * fabsl(prod - (long double)val[e]) / (long double)val[e];
        }
        return res;
    }

    vector<long long> roundSmart(const Fit &fit) const {
        vector<long long> a(N,1),buf(N,1);
        vector<long double> qq(fit.nodes.size(),1.0L);

        vector<int> reps;
        vector<long double> candQ;
        vector<long long> candK;

        for (int id = 0; id < (int)fit.nodes.size(); id++) {
            if (fit.nodes[id].empty()) continue;

            if (fit.bip[id] && !fit.edges[id].empty() && (int)fit.nodes[id].size() >= 2) {
                reps = fit.nodes[id];
                sort(reps.begin(), reps.end(), [&](int a1, int b1) {
                    if (deg[a1] != deg[b1]) return deg[a1] > deg[b1];
                    return a1 < b1;
                });
                if ((int)reps.size() > 6) reps.resize(6);

                int mn = fit.nodes[id][0], mx = fit.nodes[id][0];
                for (int u : fit.nodes[id]) {
                    if (fit.base[u] < fit.base[mn]) mn = u;
                    if (fit.base[u] > fit.base[mx]) mx = u;
                }
                reps.push_back(mn);
                reps.push_back(mx);
                sort(reps.begin(), reps.end());
                reps.erase(unique(reps.begin(), reps.end()), reps.end());

                candQ.clear();
                candQ.push_back(1.0L);
                static const long double gridVals[] = {
                    0.125L, 0.25L, 0.5L, 0.7071067811865475244L,
                    1.0L,
                    1.4142135623730950488L, 2.0L, 4.0L, 8.0L
                };
                for (long double g : gridVals) candQ.push_back(g);

                for (int u : reps) {
                    candK.clear();
                    for (long long k = 1; k <= 6; k++) candK.push_back(k);
                    candK.push_back(8);
                    candK.push_back(10);
                    long long cur = clampInt(fit.base[u]);
                    for (long long dlt = -1; dlt <= 1; dlt++) {
                        long long k = cur + dlt;
                        if (1 <= k && k <= LIM) candK.push_back(k);
                    }
                    long long fl = (long long)floor((long double)fit.base[u]);
                    long long ce = (long long)ceil((long double)fit.base[u]);
                    if (1 <= fl && fl <= LIM) candK.push_back(fl);
                    if (1 <= ce && ce <= LIM) candK.push_back(ce);
                    sort(candK.begin(), candK.end());
                    candK.erase(unique(candK.begin(), candK.end()), candK.end());

                    for (long long k : candK) {
                        if (fit.base[u] <= 0 || !isfinite((double)fit.base[u])) continue;
                        long double q = (fit.col[u] == 0 ? (long double)k / fit.base[u] : fit.base[u] / (long double)k);
                        if (!isfinite((double)q) || q <= 0) continue;
                        candQ.push_back(q);
                    }
                }

                sort(candQ.begin(), candQ.end());
                vector<long double> uniqQ;
                uniqQ.reserve(candQ.size());
                for (long double q : candQ) {
                    if (!isfinite((double)q) || q <= 0) continue;
                    if (uniqQ.empty()) {
                        uniqQ.push_back(q);
                    } else {
                        long double prev = uniqQ.back();
                        long double ratio = q / prev;
                        if (ratio < 1) ratio = 1 / ratio;
                        if (ratio > 1.0000001L) uniqQ.push_back(q);
                    }
                }
                candQ.swap(uniqQ);

                long double bestQ=1.0L;
                long double bestP=compPen(fit,id,bestQ,buf);
                int checked = 0;
                for (long double q : candQ) {
                    long double curP=compPen(fit,id,q,buf);
                    if (curP < bestP) {
                        bestP = curP;
                        bestQ = q;
                    }
                    checked++;
                    if ((int)fit.edges[id].size() > 250000 && checked >= 24) break;
                }
                qq[id]=bestQ;
            }

            long double q=qq[id];
            for (int u : fit.nodes[id]) {
                long double x = fit.base[u];
                if (fit.bip[id]) {
                    if (fit.col[u] == 0) x *= q;
                    else x /= q;
                }
                a[u] = clampInt(x);
            }
        }

        return a;
    }

    vector<long long> roundPlain(const Fit &fit) const {
        vector<long long> a(N, 1);
        for (int i = 0; i < N; i++) a[i] = clampInt(fit.base[i]);
        return a;
    }

    int sweep(vector<long long> &a, const vector<unsigned char> *act, bool rev) const {
        vector<Cand> c;
        c.reserve(maxDeg);
        int changed = 0;

        auto proc = [&](int u) {
            c.clear();
            for (int p = head[u]; p < head[u + 1]; p++) {
                int e = adj[p];
                if (act && !(*act)[e]) continue;
                int v = U[e] + V[e] - u;
                long long av = a[v];
                double t = (double)val[e] / (double)av;
                double ww = (double)wt[e] * (double)av / (double)val[e];
                c.push_back({t, ww});
            }
            if (c.empty()) return;

            sort(c.begin(), c.end(), candCmp);
            long double tot = 0, cur = 0;
            for (auto &e : c) tot += (long double)e.w;

            double med = c.back().x;
            for (auto &e : c) {
                cur += (long double)e.w;
                if (cur >= tot * 0.5L) {
                    med = e.x;
                    break;
                }
            }

            long long lo = max(1LL, min(LIM, (long long)floor((long double)med)));
            long long hi = lo + 1;
            if (hi > LIM) hi = LIM;
            if (fabsl((long double)med - floor((long double)med)) < 1e-12L) hi = lo;

            long long nv = lo;
            if (hi != lo) {
                long double c1 = 0, c2 = 0;
                for (auto &e : c) {
                    c1 += (long double)e.w * fabsl((long double)lo - (long double)e.x);
                    c2 += (long double)e.w * fabsl((long double)hi - (long double)e.x);
                }
                if (c2 < c1) nv = hi;
            }

            if (nv != a[u]) {
                a[u] = nv;
                changed++;
            }
        };

        if (!rev) {
            for (int u : ord) proc(u);
        } else {
            for (auto it = ord.rbegin(); it != ord.rend(); ++it) proc(*it);
        }

        return changed;
    }

    int sweepLocked(vector<long long> &a, const vector<unsigned char> *act,
                    const vector<unsigned char> *locked, bool rev) const {
        vector<Cand> c;
        c.reserve(maxDeg);
        int changed = 0;

        auto proc = [&](int u) {
            if (locked && (*locked)[u]) return;

            c.clear();
            for (int p = head[u]; p < head[u + 1]; p++) {
                int e = adj[p];
                if (act && !(*act)[e]) continue;
                int v = U[e] + V[e] - u;
                long long av = a[v];
                double t = (double)val[e] / (double)av;
                double ww = (double)wt[e] * (double)av / (double)val[e];
                c.push_back({t, ww});
            }
            if (c.empty()) return;

            sort(c.begin(), c.end(), candCmp);
            long double tot = 0, cur = 0;
            for (auto &e : c) tot += (long double)e.w;

            double med = c.back().x;
            for (auto &e : c) {
                cur += (long double)e.w;
                if (cur >= tot * 0.5L) {
                    med = e.x;
                    break;
                }
            }

            long long lo = max(1LL, min(LIM, (long long)floor((long double)med)));
            long long hi = lo + 1;
            if (hi > LIM) hi = LIM;
            if (fabsl((long double)med - floor((long double)med)) < 1e-12L) hi = lo;

            long long nv = lo;
            if (hi != lo) {
                long double c1 = 0, c2 = 0;
                for (auto &e : c) {
                    c1 += (long double)e.w * fabsl((long double)lo - (long double)e.x);
                    c2 += (long double)e.w * fabsl((long double)hi - (long double)e.x);
                }
                if (c2 < c1) nv = hi;
            }

            if (nv != a[u]) {
                a[u] = nv;
                changed++;
            }
        };

        if (!rev) {
            for (int u : ord) proc(u);
        } else {
            for (auto it = ord.rbegin(); it != ord.rend(); ++it) proc(*it);
        }

        return changed;
    }

    int sweeps(vector<long long> &a, const vector<unsigned char> *act, int passes) const {
        int totalChanged = 0;
        for (int it = 0; it < passes; it++) {
            int ch = sweep(a, act, (it & 1));
            totalChanged += ch;
            if (ch == 0) break;
        }
        return totalChanged;
    }

    int sweepsLocked(vector<long long> &a, const vector<unsigned char> *act,
                     const vector<unsigned char> *locked, int passes) const {
        int totalChanged = 0;
        for (int it = 0; it < passes; it++) {
            int ch = sweepLocked(a, act, locked, (it & 1));
            totalChanged += ch;
            if (ch == 0) break;
        }
        return totalChanged;
    }

    long double edgePen(const vector<long long> &a, int e) const {
        long double prod = (long double)a[U[e]] * (long double)a[V[e]];
        return (long double)wt[e] * fabsl(prod - (long double)val[e]) / (long double)val[e];
    }

    long double eval(const vector<long long> &a, vector<int> *outDisc, vector<unsigned char> *outAct) {
        long double total = 0;
        for (int e = 0; e < M; e++) {
            long double cur = edgePen(a, e);
            pen[e] = (double)cur;
            total += cur;
        }

        if (d == 0) {
            if (outDisc) outDisc->clear();
            if (outAct) {
                if ((int)outAct->size() != M) outAct->assign(M, 1);
                else fill(outAct->begin(), outAct->end(), (unsigned char)1);
            }
            return total;
        }

        iota(idx.begin(), idx.end(), 0);
        nth_element(idx.begin(), idx.begin() + d, idx.end(), [&](int i, int j) {
            return pen[i] > pen[j];
        });

        if (outDisc) outDisc->resize(d);
        if (outAct) {
            if ((int)outAct->size() != M) outAct->assign(M, 1);
            else fill(outAct->begin(), outAct->end(), (unsigned char)1);
        }

        long double rem = 0;
        for (int k = 0; k < d; k++) {
            int e = idx[k];
            rem += edgePen(a, e);
            if (outDisc) (*outDisc)[k] = e + 1;
            if (outAct) (*outAct)[e] = 0;
        }

        return total - rem;
    }

    void upd(const vector<long long> &aa, vector<long long> &bestA, vector<int> &bestDisc,
             vector<int> &tmpDisc, long double &bestObj) {
        long double obj = eval(aa, &tmpDisc, nullptr);
        if (obj < bestObj) {
            bestObj = obj;
            bestA = aa;
            bestDisc = tmpDisc;
        }
    }

    void smallSeedSearch(vector<long long> &bestA, vector<int> &bestDisc,
                         vector<int> &tmpDisc, long double &bestObj) {
        if (N > 18 || M > 1200) return;

        vector<pair<int, long double>> ranked;
        ranked.reserve(M);
        for (int e = 0; e < M; e++) {
            long double score = (long double)wt[e] / (long double)val[e];
            if (!bestA.empty()) {
                score += edgePen(bestA, e);
            }
            ranked.push_back({e, score});
        }

        sort(ranked.begin(), ranked.end(), [&](const auto &a, const auto &b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });

        int edgeBudget = min((int)ranked.size(), 10);
        vector<unsigned char> locked(N, 0), act(M, 1);

        auto relax = [&](const vector<long long> &aa) {
            upd(aa, bestA, bestDisc, tmpDisc, bestObj);
        };

        auto trySeed = [&](const vector<pair<int, long long>> &fixes) {
            vector<long long> cur = bestA;
            if (cur.empty()) cur.assign(N, 1);

            fill(locked.begin(), locked.end(), (unsigned char)0);
            for (auto [u, x] : fixes) {
                cur[u] = x;
                locked[u] = 1;
            }

            for (int it = 0; it < 2; it++) {
                eval(cur, &tmpDisc, &act);
                sweepsLocked(cur, &act, &locked, 2);
                relax(cur);
            }

            for (auto [u, _] : fixes) locked[u] = 0;
            relax(cur);

            eval(cur, &tmpDisc, &act);
            sweeps(cur, &act, 2);
            relax(cur);

            sweeps(cur, nullptr, 3);
            relax(cur);

            eval(cur, &tmpDisc, &act);
            sweeps(cur, &act, 3);
            relax(cur);
        };

        for (int pos = 0; pos < edgeBudget; pos++) {
            int e = ranked[pos].first;
            int u = U[e], v = V[e];
            vector<int> divs = divisors(val[e]);

            if ((int)divs.size() > 256) {
                vector<int> trimmed;
                trimmed.reserve(256);
                int step = max(1, (int)divs.size() / 192);
                for (int i = 0; i < (int)divs.size(); i += step) trimmed.push_back(divs[i]);
                if (trimmed.back() != divs.back()) trimmed.push_back(divs.back());
                sort(trimmed.begin(), trimmed.end());
                trimmed.erase(unique(trimmed.begin(), trimmed.end()), trimmed.end());
                divs.swap(trimmed);
            }

            for (int du : divs) {
                long long dv = val[e] / du;
                for (int orient = 0; orient < 2; orient++) {
                    long long au = (orient == 0 ? du : dv);
                    long long av = (orient == 0 ? dv : du);
                    trySeed({{u, au}, {v, av}});
                }
            }
        }

        for (int i = 0; i < edgeBudget; i++) {
            int e1 = ranked[i].first;
            for (int j = i + 1; j < edgeBudget; j++) {
                int e2 = ranked[j].first;

                int common = -1;
                if (U[e1] == U[e2] || U[e1] == V[e2]) common = U[e1];
                else if (V[e1] == U[e2] || V[e1] == V[e2]) common = V[e1];
                if (common == -1) continue;

                int other1 = U[e1] + V[e1] - common;
                int other2 = U[e2] + V[e2] - common;
                int g = std::gcd(val[e1], val[e2]);
                vector<int> divs = divisors(g);

                if ((int)divs.size() > 128) {
                    vector<int> trimmed;
                    int step = max(1, (int)divs.size() / 96);
                    for (int k = 0; k < (int)divs.size(); k += step) trimmed.push_back(divs[k]);
                    if (trimmed.back() != divs.back()) trimmed.push_back(divs.back());
                    sort(trimmed.begin(), trimmed.end());
                    trimmed.erase(unique(trimmed.begin(), trimmed.end()), trimmed.end());
                    divs.swap(trimmed);
                }

                for (int ax : divs) {
                    long long ao1 = val[e1] / ax;
                    long long ao2 = val[e2] / ax;
                    trySeed({{common, ax}, {other1, ao1}, {other2, ao2}});
                }
            }
        }
    }

    void run(vector<int> &A, vector<int> &discards) {
        if (M == 0 || d == M) {
            A.assign(N, 1);
            discards.clear();
            for (int i = 0; i < d; i++) discards.push_back(i + 1);
            return;
        }

        int pcg = 16;
        if (M <= 1000000) pcg = 22;
        if (M <= 300000) pcg = 28;
        int rounds = (M <= 700000 ? 3 : 2);

        int pcg2 = 12;
        if (M <= 1000000) pcg2 = 16;
        if (M <= 300000) pcg2 = 22;

        int pass = 1;
        if (M <= 1200000) pass = 2;
        if (M <= 400000) pass = 3;

        vector<long long> bestA;
        vector<int> bestDisc, tmpDisc;
        long double bestObj = 1e300L;

        auto relax = [&](const vector<long long> &aa) {
            upd(aa, bestA, bestDisc, tmpDisc, bestObj);
        };

        vector<long long> seed1 = buildConst();
        Fit fit0 = buildFit(nullptr, pcg, false);
        vector<long long> seed2 = roundPlain(fit0);

        relax(seed1);
        relax(seed2);
        long double o1 = eval(seed1, nullptr, nullptr);
        long double o2 = eval(seed2, nullptr, nullptr);

        vector<vector<long long>> starts;
        if (o1 <= o2) {
            starts.push_back(seed1);
            starts.push_back(seed2);
        } else {
            starts.push_back(seed2);
            starts.push_back(seed1);
        }

        vector<unsigned char> act(M, 1);
        for (int s = 0; s < (int)starts.size(); s++) {
            vector<long long> a = starts[s];
            for (int it = 0; it < rounds; it++) {
                relax(a);
                eval(a, &tmpDisc, &act);

                Fit fit = buildFit(&act, pcg, false);
                vector<long long> raw = roundPlain(fit);
                relax(raw);
                long double oraw = eval(raw, nullptr, nullptr);

                vector<long long> ref = raw;
                sweep(ref, &act, (it & 1));
                relax(ref);
                long double oref = eval(ref, nullptr, nullptr);

                a = (oref < oraw ? ref : raw);
            }
            relax(a);
        }

        vector<unsigned char> fixed(M, 1);
        for (int id : bestDisc) fixed[id - 1] = 0;
        vector<long long> pol0 = bestA;
        if (!pol0.empty() && sweep(pol0, d == 0 ? nullptr : &fixed, false) > 0) relax(pol0);

        bool doSmart = (M <= 350000) || (M <= 120LL * max(1, N));
        if (doSmart) {
            Fit fullFit = buildFit(nullptr, pcg2, true);
            vector<long long> s1 = roundSmart(fullFit);
            sweeps(s1, nullptr, pass);
            relax(s1);

            fixed.assign(M, 1);
            for (int id : bestDisc) fixed[id - 1] = 0;
            Fit finFit = buildFit(d == 0 ? nullptr : &fixed, pcg2, true);
            vector<long long> s2 = roundSmart(finFit);
            sweeps(s2, d == 0 ? nullptr : &fixed, pass + 1);
            relax(s2);

            vector<long long> s3 = bestA;
            if (!s3.empty() && sweeps(s3, d == 0 ? nullptr : &fixed, pass + 1) > 0) relax(s3);
        }

        smallSeedSearch(bestA, bestDisc, tmpDisc, bestObj);

        eval(bestA, &bestDisc, nullptr);

        A.resize(N);
        for (int i = 0; i < N; i++) A[i] = (int)bestA[i];
        discards = bestDisc;
    }
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
void solve(int N, int M, int D, const vector<Cell> &cells,
           vector<int> &A, vector<int> &discards) {
    Solver solver(N, M, D, cells);
    solver.run(A, discards);
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
    for (int idx : discards) cout << ' ' << idx;
    cout << '\n';
    return 0;
}
