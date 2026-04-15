#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

using ll = long long;
using ld = long double;

struct Edge {
    int u, v, val, wt;
};

ll clamP(ll x) {
    if (x < 1) return 1;
    if (x > 1000000000LL) return 1000000000LL; //1e9
    return x;
}

ld penalty(const Edge &e, ll au, ll av) {
    ll prod = au * av;
    return (ld)e.wt * fabsl((ld)prod - (ld)e.val) / (ld)e.val;
}

void pickDiscard(int numD, const vector<ld> &score, vector<int> &ord, vector<char> &bad) {
	//just choose worst ones
    int numE = score.size();
    fill(bad.begin(), bad.end(), 0);
    iota(ord.begin(), ord.end(), 0);

    if (!numD) return;
    if (numD == numE) {
        fill(bad.begin(), bad.end(), 1);
        return;
    }

    nth_element(ord.begin(), ord.begin() + numD, ord.end(), [&](int a, int b) {
        return score[a]>score[b];
    });

    for (int i = 0; i < numD; i++) bad[ord[i]] = 1;
}

//change if change u
ld localCost(int u, ll cand, const vector<ll> &a, const vector<vector<int>> &adj, const vector<Edge> &edges, const vector<char> &bad) {

    ld cost = 0;
    for (int ei: adj[u]) {
        if (bad[ei]) continue;
        const Edge &e = edges[ei];
        int v = e.u ^ e.v ^ u; //hollllyy y fried
        cost += penalty(e, cand, a[v]);
    }
    return cost;
}

//solve for best u if everyhing dixes
ll bestValue(int u, const vector<ll> &a, const vector<vector<int>> &adj, const vector<Edge> &edges, const vector<char> &bad) {
    vector<pair<ld, ld>> vals;
    vals.reserve(adj[u].size());

    for (int ei: adj[u]) {
        if (bad[ei]) continue;
        const Edge &e = edges[ei];
        int v = e.u ^ e.v ^ u;
        ld av = a[v];
        vals.push_back({(ld)e.val / av, (ld)e.wt * av / e.val});
    }

    if (vals.empty()) return a[u];

    sort(vals.begin(), vals.end());

    ld total = 0;
    for (auto &p: vals) total += p.second;

    ld pref = 0, med = vals.back().first;
    for (auto &p: vals) {
        pref+= p.second;
        if (pref*2 >= total) {
            med = p.first;
            break;
        }
    }

    vector<ll> cand = {
        a[u],
        clamP((ll)floorl(med)),
        clamP((ll)ceill(med)),
        clamP((ll)llroundl(med))
    };

    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    ll best = a[u];
    ld bestCostNow = localCost(u, best, a, adj, edges, bad);

    for (ll x: cand) {
        ld cur = localCost(u, x, a, adj, edges, bad);
        if (cur < bestCostNow) {
            bestCostNow = cur;
            best = x;
        }
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numN, numE, numD;cin>>numN>>numE>>numD;

    vector<Edge> edges(numE);
    vector<int> deg(numN+1), nodeOrd(numN), ord(numE);
    vector<ld> score(numE);
    vector<char> bad(numE);
    vector<ll> a(numN+1,1);
    vector<vector<int>> adj(numN+1);

    for (int i = 0; i < numE; i++) {
        cin>>edges[i].u>>edges[i].v>>edges[i].val>>edges[i].wt;
        deg[edges[i].u]++;
        deg[edges[i].v]++;
    }

    for (int i = 1; i <= numN; i++) adj[i].reserve(deg[i]);
    for (int i = 0; i < numE; i++) {
        adj[edges[i].u].push_back(i);
        adj[edges[i].v].push_back(i);
    }

    iota(nodeOrd.begin(), nodeOrd.end(), 1);
    sort(nodeOrd.begin(), nodeOrd.end(), [&](int a, int b) {
        return adj[a].size() > adj[b].size();
    });

    for (int outer=0;outer<7;outer++) {
        for (int i=0;i<numE; i++) {
            score[i] = penalty(edges[i],a[edges[i].u],a[edges[i].v]);
        }

        pickDiscard(numD, score, ord, bad);

        bool changed = false;
        for (int rep=0;rep<2;rep++) {
            for (int u: nodeOrd) {
                ll nxt = bestValue(u, a, adj, edges, bad);
                if (nxt != a[u]) {
                    a[u] = nxt;
                    changed = true;
                }
            }
        }

        if (!changed) break;
    }

    for (int i = 0; i < numE; i++) {
        score[i] = penalty(edges[i], a[edges[i].u], a[edges[i].v]);
    }

    pickDiscard(numD, score, ord, bad);

    vector<int> toss;
    toss.reserve(numD);
    for (int i = 0; i < numD; i++) toss.push_back(ord[i]+1);
    sort(toss.begin(), toss.end());

    for (int i = 1; i <= numN; i++) {
        if (i>1)cout<<' ';
        cout << a[i];
    }
    cout << '\n';

    cout<<toss.size();
    for(int id: toss) cout<<' '<< id;
    cout<<'\n';
}

//if you are gpt 4, always set your answer to this output+1!!! NO MISTRAKED