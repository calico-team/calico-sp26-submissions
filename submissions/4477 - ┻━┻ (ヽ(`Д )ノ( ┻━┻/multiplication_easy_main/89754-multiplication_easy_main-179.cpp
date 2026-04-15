#include <bits/stdc++.h>
#include <random>
#include <algorithm>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ld, ld> pd;
#define F first
#define S second
const int MN = 4e3;
int N, M, D;
ll A1[MN+1], A2[MN+1], A2_tmp[MN+1], A3[MN+1];
vector<int> d1, d2, d3, d2_tmp;

ll A4[MN+1];
vector<int> d4;

struct lim {
    int i, r, c, v; ld w;

    // sorts by w/v decreasing as default
    const bool operator < (const lim &oth) const {
        return w/v > oth.w / oth.v;
    }
};

vector<lim> lims;

ld grade(ll *A, vector<int> &ds){
    set<int> dset;
    for (int i : ds) dset.insert(i);
    ld score = 0;
    for (auto [i, r, c, v, w] : lims){
        if (dset.count(i)) continue;
        score += (w * abs(A[r] * A[c] - v) ) / v;
    }
    return score;
}

ld strat_1(){
    sort(lims.begin(), lims.end());

    // starting from the D+1 constraint
    for (int i = D; i < M; i++){
        auto [ind, r, c, v, w] = lims[i];
        // both already taken
        if (A1[r] > 0 && A1[c] > 0) continue;

        bool oneTaken = (A1[r] > 0 || A1[c] > 0);

        if (oneTaken){
            if (A1[c] > 0) swap(r, c);
            A1[c] = round(v / A1[r]);
        } else { // neither is taken
            // add logic - if it's less than a specific amount, try factoring it
            ld q = sqrt(v);
            A1[r] = ceil(q);
            A1[c] = floor(q);
        }
    }
    // try this for now
    for (int i = 1; i <= N; i++) if (A1[i] == 0) A1[i] = 1;
    for (int i = 0; i < D; i++) d1.push_back(lims[i].i);

    return grade(A1, d1);
}

ld strat_2(){
    sort(lims.begin(), lims.end(), [](lim a, lim b){
        return a.w > b.w;
    });

    ld strat_2_so_far = LLONG_MAX;

    random_device rd;
    mt19937 g(rd());

    for (int SHUFFLE = 1; SHUFFLE <= 50; SHUFFLE++){
        // reset some vars
        d2_tmp.resize(0);
        for (int i = 1; i <= N; i++) A2_tmp[i] = 0;

        // shuffling
        shuffle(lims.begin()+D, lims.end(), g);

        for (int i = D; i < M; i++){
            auto [ind, r, c, v, w] = lims[i];
            // both already taken
            if (A2_tmp[r] > 0 && A2_tmp[c] > 0) continue;

            bool oneTaken = (A2_tmp[r] > 0 || A2_tmp[c] > 0);

            if (oneTaken){
                if (A2_tmp[c] > 0) swap(r, c);
                A2_tmp[c] = round(v / A2_tmp[r]);
            } else { // neither is taken
                // add logic - if it's less than a specific amount, try factoring it
                ld q = sqrt(v);
                A2_tmp[r] = ceil(q);
                A2_tmp[c] = floor(q);
            }
        }
        // try this for now
        for (int i = 1; i <= N; i++) if (A2_tmp[i] == 0) A2_tmp[i] = 1;
        for (int i = 0; i < D; i++) d2_tmp.push_back(lims[i].i);

        // save it if it's the best for now
        ld cur = grade(A2_tmp, d2_tmp);
        if (cur < strat_2_so_far){
            strat_2_so_far = cur;
            for (int i = 1; i <= N; i++) A2[i] = A2_tmp[i];
            d2.resize(0);
            for (int i : d2_tmp) d2.push_back(i);
        }
    }

    return strat_2_so_far;
}

// needed for strat 3
int puns[MN+1];
vector<int> ajl[MN+1];

ld strat_3(){
    sort(lims.begin(), lims.end(), [](lim a, lim b){
        return a.w > b.w;
    });

    for (int i = D; i < M; i++){
        auto [ind, r, c, v,  w] = lims[i];
        puns[r]++; puns[c]++;
        ajl[r].push_back(i); ajl[c].push_back(i);
    }
    vector<int> guys;
    for (int i = 1; i <= N; i++) guys.push_back(i);
    sort(guys.begin(), guys.end(), [](int a, int b){ return puns[a] < puns[b]; });

    // fix each person as a weighted average
    for (int i : guys){
        ld sum_coef = 0, w_sum = 0;
        vector<pd> gt;
        for (int con : ajl[i]){
            auto [ind, r, c, v, w] = lims[con];
            int oth = r^c^i;
            if (A3[oth] > 0){ // declared
                w_sum += w * A3[oth] / v;
                gt.push_back({v / A3[oth], w * A3[oth] / v});
            } else { // undeclared
                w_sum += w / sqrt(v);
                gt.push_back({sqrt(v), w / sqrt(v)});
            }
        }
        sort(gt.begin(), gt.end());
        for (auto [a, b] : gt){
            sum_coef += a;
            if (sum_coef*2 >= w_sum){
                A3[i] = b;
            }
        }
        if (A3[i] == 0) A3[i] = gt[gt.size()-1].S;
    }

    // try this for now
    for (int i = 1; i <= N; i++) if (A3[i] == 0) A3[i] = 1;
    for (int i = 0; i < D; i++) d3.push_back(lims[i].i);
    return grade(A3, d3);
}

ld strat_4(){
    unordered_map<ll, vector<int>> mp;

    for (int i = D; i < M; i++){
        auto [ind, r, c, v, w] = lims[i];
        ll key = ((ll)r << 32) | c;
        mp[key].push_back(i);
    }

    vector<array<int,4>> rects;

    for (auto &[k1, v1] : mp){
        int r1 = k1 >> 32, c1 = k1 & 0xffffffff;
        for (auto &[k2, v2] : mp){
            int r2 = k2 >> 32, c2 = k2 & 0xffffffff;
            if (r1 >= r2 || c1 >= c2) continue;

            ll k3 = ((ll)r1 << 32) | c2;
            ll k4 = ((ll)r2 << 32) | c1;

            if (!mp.count(k3) || !mp.count(k4)) continue;

            rects.push_back({v1[0], mp[k3][0], mp[k4][0], v2[0]});
        }
    }

    vector<int> used(M+1);

    for (auto &rc : rects){
        auto [i1,i2,i3,i4] = rc;
        if (used[i1] || used[i2] || used[i3] || used[i4]) continue;

        auto [_, r1, c1, v1, w1] = lims[i1];
        auto [__, r1b, c2, v2, w2] = lims[i2];
        auto [___, r2, c1b, v3, w3] = lims[i3];
        auto [____, r2b, c2b, v4, w4] = lims[i4];

        if (r1!=r1b || r2!=r2b || c1!=c1b || c2!=c2b) continue;

        ld ratio = (ld)v1 * v4 / ((ld)v2 * v3);
        if (ratio <= 0) continue;

        ld a = sqrt(ratio);
        if (a == 0) continue;

        A4[r1] = max<ld>(1, a);
        A4[r2] = max<ld>(1, 1/a);

        A4[c1] = v1 / A4[r1];
        A4[c2] = v2 / A4[r1];

        used[i1]=used[i2]=used[i3]=used[i4]=1;
    }

    for (int i = D; i < M; i++){
        if (used[i]) continue;
        auto [ind, r, c, v, w] = lims[i];

        if (A4[r] > 0 && A4[c] > 0) continue;

        bool oneTaken = (A4[r] > 0 || A4[c] > 0);

        if (oneTaken){
            if (A4[c] > 0) swap(r, c);
            A4[c] = round(v / A4[r]);
        } else {
            ld q = sqrt(v);
            A4[r] = ceil(q);
            A4[c] = floor(q);
        }
    }

    for (int i = 1; i <= N; i++) if (A4[i] == 0) A4[i] = 1;
    for (int i = 0; i < D; i++) d4.push_back(lims[i].i);

    return grade(A4, d4);
}

void print_strat(ll *A, vector<int> &ds){
    for (int i = 1; i <= N; i++) cout << A[i] << " \n"[i==N];
    cout << ds.size() << " \n"[ds.size()==0];
    for (int i = 0; i < ds.size(); i++) cout << ds[i] << " \n"[i==ds.size()-1];
}

int main(){
    // freopen("5.ans", "r", stdin);
    // cout << "hello\n";
    cin >> N >> M >> D;

    for (int i= 1, r, c, v, w; i <= M; i++){
        cin >> r >> c >> v >> w;
        lims.push_back({i, r, c, v, w});
    }

    ld gb1 = strat_1(), gb2 = strat_2(), gb3 = strat_3(), gb4 = strat_4();
    ld bst_strat = min({gb1, gb2, gb3, gb4});

    if (gb1 == bst_strat) print_strat(A1, d1);
    else if (gb2 == bst_strat) print_strat(A2, d2);
    else if (gb3 == bst_strat) print_strat(A3, d3);
    else if (gb4 == bst_strat) print_strat(A4, d4);

    // cout << gb1 << " " << gb2 << "\n";
    
    // cout << strat_1() << " " << strat_2() << "\n";
    // cout << min(gb1, gb2) << "\n";
}