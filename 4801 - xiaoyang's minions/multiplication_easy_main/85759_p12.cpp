#include <bits/stdc++.h>
#define ll long long
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
bool P(long long E,long long E_next,double T,mt19937 rng){
    double prob =  exp(-(E_next-E)/T);
    if(prob > 1) return true;
    else{
        bernoulli_distribution d(prob); 
        return d(rng);
    }
}


struct state {
    vector<int> A;
    int max_num;
    state(int n,int mn) {
        max_num = mn;
        for (int i = 0; i < n; i++){
        A.push_back(rand()%max_num + 1);
        }
    }
    state next() {
        vector<int> A_new = A;
        A_new[rand()%A.size()] = rand()%max_num + 1;
        state new_state(A.size(),max_num);
        new_state.A = A_new;
        return new_state;
    }
    double E(const vector<Cell>& cells) {
        double energy = 0;
        for (Cell c:cells){
            energy += c.W*abs(A[c.R-1]*A[c.C-1] - c.V)/c.V;
        }
        return energy;
    };
    vector<pair<double,int>> cell_list(const vector<Cell>& cells){
        vector<pair<double,int>> retval;
        int i = 1;
        for (Cell c:cells){
            double energy = c.W*abs(A[c.R-1]*A[c.C-1] - c.V)/c.V;
            retval.push_back({energy,i});
            i++;
        }
        sort(retval.begin(),retval.end());
        reverse(retval.begin(),retval.end());
        return retval;
    }
};



pair<double, state> simAnneal(int n, const vector<Cell>& cells) {
    int maxv = 0;
    for (Cell c:cells){
        maxv = max(maxv,c.V);
    }
    state s = state(n,maxv);
    state best = s;
    double T = 100000; // Initial temperature
    double u = 0.99; // decay rate
    double E = s.E(cells);
    double E_next;
    double E_best = E;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (T > 1) {
        state next = s.next();
        E_next = next.E(cells);
        if (P(E, E_next, T, rng)) {
            s = next;
            if (E_next < E_best) {
                best = s;
                E_best = E_next;
            }
            E = E_next;
        }
        T *= u;
    }
    return {E_best, best};
}


void solve(int N, int M, int D, const vector<Cell>& cells,
           vector<int>& A, vector<int>& discards) {
    pair<double,state> result = simAnneal(N,cells);
    //cout << "heuristic successful" << endl;
    A = result.second.A;
    vector<pair<double,int>> ls = result.second.cell_list(cells);
    auto it = ls.rbegin();
    for (int i = 0; i < D; i++){
        pair<double,int> a = *it;
        discards.push_back(a.second);
        it++;
        if (it == ls.rend()){break;}
    }
    //cout << "discard successful" << endl;
    return;
}

int main() {
    //freopen("input.txt","r",stdin);
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
