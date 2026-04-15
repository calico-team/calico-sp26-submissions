#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < (int)v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

struct fraC {
    int p=0, q=1;

    fraC add(fraC other) {
        return fraC {p * other.q + q * other.p, q * other.q};
    }
    fraC div(int x) {
        return fraC {p, q*x};
    }
};
struct point {
    int r, c;

    point add(point other) {
        return point {r+other.r, c+other.c};
    }
    bool inBounds(int n, int m) {
        return 0 <= r && r < n && 0 <= c && c < m;
    }
};

point getMove(char c) {
    if (c == '^')
        return {-1, 0};
    if (c == '>')
        return {0, 1};
    if (c == '<')
        return {1, 0};
    return {1, 0};
}

bool isArrow(char c) {
    return c == '^' || c == 'v' || c == '>' || c == '<';
}

void solve() {
    int n, m;
    cin >> n >> m;

    vec<string> maxShi (n);
    for (string& s : maxShi) cin >> s;

    vec<vec<fraC>> fractions ( n , vec <    fraC> (m));
    fractions[0][0] = {1, 1};

    vec<point> pointers {{0, 0}};
    fraC totalCollected;
    // int a = 0;
    while ((int)pointers.size() > 0) {
        // if (a++ > 10) break;
        // for (auto x : pointers) cout << "(" << x.r _ x.c << ")" << ln;
        // for (auto& row : fractions) {
        //     for (auto& x : row) {
        //         cout << x.p << "/" << x.q << " ";
        //     }
        //     cout << ln;
        // }
        // cout << endl;

        // move pointers[last]:
        int currI = (int)pointers.size()-1;
        point& curr = pointers[currI];

        // if the char is an arrow, simply move it in the direction
        char c = maxShi[curr.r][curr.c];
        
        if (isArrow(c)) {
            auto next = curr.add(getMove(c));
            if (!next.inBounds(n, m)) {
                totalCollected = totalCollected.add(fractions[curr.r][curr.c]);
                fractions[curr.r][curr.c] = {0, 1};
                pointers.erase(pointers.begin() + currI);
            }
            else {
                fractions[next.r][next.c] = fractions[curr.r][curr.c];
                fractions[curr.r][curr.c] = {0, 1};
                curr = next;
            }
        }
        // if it's a splitter:
        else if (c == 'S') {
            // make a list of neighbors
            vec<point> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (point& ne : neighbors) {ne = ne.add(curr);}
            
            // remove AND COUNT neighbors that are OUT OF BOUNDS
            for (int i = 0; i < (int)neighbors.size(); i++) {
                point& ne = neighbors[i];
                if (!ne.inBounds(n, m)) {
                    totalCollected = totalCollected.add(fractions[ne.r][ne.c]);
                    neighbors.erase(neighbors.begin() + i);
                    i--;
                }
            }

            // remove neighbors that are . and or point to OG spot
            for (int i = 0; i < (int)neighbors.size(); i++) {
                bool remove = false;
                point& ne = neighbors[i];
                char nc = maxShi[ne.r][ne.c];
                point diff = {ne.r - curr.r, ne.c - curr.c};
                if (nc == '.')
                    remove = true;
                else if ((diff.r == 1 && nc == '^') || (diff.r == -1 && nc == 'v') || (diff.c == 1 && nc =='<') || (diff.c == -1 && nc == '>')) {
                    remove = true;
                }

                if (remove) {
                    neighbors.erase(neighbors.begin() + i);
                    i--;
                }
            }
            
            // for each remaining neighbor, create a new pointer there.
            for (int i = 0; i < (int)neighbors.size(); i++) {
                pointers.push_back(neighbors[i]);
                curr = pointers[currI];
                fractions[neighbors[i].r][neighbors[i].c] = fractions[neighbors[i].r][neighbors[i].c].add(fractions[curr.r][curr.c].div((int)neighbors.size()));
            }
            // remove OG pointer
            fractions[curr.r][curr.c] = {0, 1};
            pointers.erase(pointers.begin() + currI);
        }
        // if it's destroy: destroy
        else if (c == 'X') {
            pointers.erase(pointers.begin() + currI);
        }
    }
    int g = std::gcd(totalCollected.p, totalCollected.q);
    cout << totalCollected.p / g _ totalCollected.q / g << ln;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        solve();
    }
}
