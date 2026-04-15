#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Edge {
    int u, v;
    ll val, w;
};

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int N, M, D;
vector<Edge> edges;
vector<vector<int>> adj;

vector<ll> bestA;
vector<int> bestDiscard;
ld bestScore = 1e100L;


ld edge_penalty(const Edge& e, ll au, ll av) {

    
    ld prod = (ld)au * (ld)av;
    return (ld)e.w * fabsl(prod - (ld)e.val) / (ld)e.val;
}

vector<ld> compute_penalties(const vector<ll>& a) {
    vector<ld> pen(M);
    for (int i = 0; i < M; i++) {
        pen[i] = edge_penalty(edges[i], a[edges[i].u], a[edges[i].v]);
    }
    return pen;
}

pair<vector<char>, vector<int>> choose_discards(const vector<ll>& a) {
    vector<ld> pen = compute_penalties(a);
    vector<int> ids(M);
    iota(ids.begin(), ids.end(), 0);

    if (D > 0 && D < M) {
        nth_element(ids.begin(), ids.begin() + D, ids.end(), [&](int x, int y) { return pen[x] > pen[y]; });
        ids.resize(D);
    } else if (D == 0) ids.clear();

    vector<char> active(M, 1);
    for (int id : ids) active[id] = 0;

    return {active, ids};
}

ld total_score(const vector<ll>& a, const vector<char>& active) {
    ld score = 0;

    // sum 
    for (int i = 0; i < M; i++) {
        if (active[i]) score += edge_penalty(edges[i], a[edges[i].u], a[edges[i].v]);
    }
    return score;
}

ld coordinate_cost(int ind, ll x, const vector<ll>& a, const vector<char>& active) {
    if (x < 1) return 1e100L;
    ld cost = 0;
    
    for (int eid : adj[ind]) {

        
        if (!active[eid]) continue;
        const Edge& e = edges[eid];


        int other;
        if(e.u == ind) other = e.v;
        else if(e.v == ind) other = e.u;
        
        cost += edge_penalty(e, x, a[other]);
    }
    return cost;
}



ll best_coordinate_value(int ind, const vector<ll>& a, const vector<char>& active) {
    vector<pair<ld, ld>> items;
    

    for (int eid : adj[ind]) {



        if (!active[eid]) continue;
        const Edge& e = edges[eid];
        int other;

        if(e.u == ind) other = e.v;
        else if(e.v == ind) other = e.u;

        ll aj = max<ll>(1, a[other]);
        ld target = (ld)e.val / (ld)aj;
        ld weight = (ld)e.w * (ld)aj / (ld)e.val;
        items.push_back({target, weight});
    }

    if (items.empty()) return a[ind];

    sort(items.begin(), items.end());

    ld totalWeight = 0;
    for (auto& item : items) totalWeight += item.second;

    ld prefix = 0;
    ld median = items.back().first;

    
    for (auto& item : items) {
        prefix += item.second;
        if (prefix * 2 >= totalWeight) {
            median = item.first;
            break;
        }
    }

    ll low = (ll) floor(median);
    ll high = (ll) ceil(median);

    vector<ll> candidates;

    // add the cur val and the median based candidates 
    candidates.push_back(max<ll>(1, a[ind]));
    for (ll d = -2; d <= 2; d++) {
        candidates.push_back(max<ll>(1, low + d));
        candidates.push_back(max<ll>(1, high + d));
    }

    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    ll bestValue = a[ind];
    ld bestCost = coordinate_cost(ind, bestValue, a, active);



    for (ll x : candidates) {
        ld curCost = coordinate_cost(ind, x, a, active);
        if (curCost < bestCost) {
            bestCost = curCost;
            bestValue = x;
        }
    }

    return bestValue;
}


// diff init sols
vector<ll> initial_all_ones() {
    return vector<ll>(N, 1);
}


vector<ll> initial_global_sqrt() {
    ld sumW = 0, sumWV = 0;
    for (const Edge& e : edges) {
        sumW += (ld)e.w;
        sumWV += (ld)e.w * (ld)e.val;
    }

    // global val sqrt of (sum w_i v_i) / (sum w_i)
    ll x = max<ll>(1, (ll)llround(sqrt((double)(sumWV / max<ld>(1, sumW)))));
    return vector<ll>(N, x);
}


// log vals of neighbors smoothihng 
vector<ll> initial_log_smooth(int rounds = 20) {

    vector<ld> x(N, 0.0L), nx(N, 0.0L);
    for (int it = 0; it < rounds; it++) {
        for (int i = 0; i < N; i++) {
            ld num = 0, den = 0;
            for (int eid : adj[i]) {
                const Edge& e = edges[eid];
                int j = (e.u == i ? e.v : e.u);
                num += (ld)e.w * (log((ld)e.val) - x[j]);
                den += (ld)e.w;


            }

        
            nx[i] = 0.0L;
            if (den > 0) nx[i] = num / den;
        }

        // next round
        x.swap(nx);
    }

    vector<ld> tmp = x;
    nth_element(tmp.begin(), tmp.begin() + N / 2, tmp.end());
    ld med = tmp[N / 2];
    for (ld& y : x) y -= med;

    vector<ll> a(N, 1);
    for (int i = 0; i < N; i++) {
        ld y = expl(x[i]);
        if (!isfinite((double)y)) y = 1.0L;
        y = min<ld>(y, 1e9L);
        a[i] = max<ll>(1, (ll)llround(y));
    }
    return a;
}


// try to find better val with base sol perturbation
vector<ll> perturb(const vector<ll>& base) {
    vector<ll> a = base;
    uniform_int_distribution<int> dist(0, 99);


    for (int i = 0; i < N; i++) {
        int r = dist(rng);
        if (r < 20) a[i] = max<ll>(1, a[i] - 1);
        else if (r < 40) a[i] = a[i] + 1;

        else if (r < 50) a[i] = max<ll>(1, a[i] / 2);
        else if (r < 60) a[i] = min<ll>((ll)1e9, a[i] * 2);
    }


    return a;
}



void try_run(vector<ll> a, int outerIters = 20) {
    vector<char> prevActive;
    bool havePrev = false;

    for (int it = 0; it < outerIters; it++) {
        auto [active, discard] = choose_discards(a);


        vector<int> order(N);

        iota(order.begin(), order.end(), 0);

        bool changed = false;
        for (int ind : order) {
            ll newValue = best_coordinate_value(ind, a, active);
            if (newValue != a[ind]) {
                a[ind] = newValue;
                changed = true;
            }
        }

        auto [newActive, newDiscard] = choose_discards(a);
        ld score = total_score(a, newActive);

        if (score < bestScore) {
            bestScore = score;
            bestA = a;
            bestDiscard.clear();
            for (int i = 0; i < M; i++) if (!newActive[i]) bestDiscard.push_back(i + 1);
            
        }

        if (!changed && havePrev && active == prevActive) break;
        prevActive = active;
        havePrev = true;
    }
}

void solve() {
    adj.assign(N, {});
    for (int i = 0; i < M; i++) {
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }

    vector<vector<ll>> starts;
    starts.push_back(initial_all_ones());
    starts.push_back(initial_global_sqrt());
    starts.push_back(initial_log_smooth());

    starts.push_back(perturb(starts[2]));
    starts.push_back(perturb(starts[1]));
    starts.push_back(perturb(starts[0]));


    // TRY RUNS 
    for (const vector<ll>& start : starts) try_run(start);
    

    if (bestA.empty()) {
        bestA = vector<ll>(N, 1);
        auto [active, discard] = choose_discards(bestA);


        bestDiscard.clear();
        for (int i = 0; i < M; i++){
            if (!active[i]) bestDiscard.push_back(i + 1);
        }
    }

    for (int i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << bestA[i];
    }
    cout << '\n';

    cout << bestDiscard.size();
    for (int id : bestDiscard)  cout << ' ' << id;
    
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> D;
    edges.resize(M); 

    for (int i = 0; i < M; i++) {
        int r, c;
        ll v, w;
        cin >> r >> c >> v >> w;

        r--;
        c--;
        edges[i] = {r, c, v, w};
    }



    solve();
    return 0;
}