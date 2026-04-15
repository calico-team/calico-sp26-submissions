#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
typedef long long ll;
using namespace std;

int K, N, M, P, Q;
vector<int> X, Y;

class Laser {
public:
    int x, y;
    
    Laser(int xStart, int yStart) {
        x = xStart;
        y = yStart;
    }
    
    int isCollide() {
        for (int i = 0; i < K; i++) {
            if (x == X[i] && y == Y[i]) {
                return i;
            }
        }
        return -1;
    }
    
    int move(int xStep, int yStep) {
        x += xStep;
        y += yStep;
        
        if (x > N) x -= N;
        if (y > M) y -= M;
        
//        cout << "(" << x << ','<<y<<")" << endl;
        
        int hit = isCollide();
        if (hit != -1) {
            return hit;
        } else {
            return move(xStep, yStep);
        }
    }
};

int solve(int K, int N, int M, int P, int Q) {
    if (K == 0) return -1;
    Laser laser(X[0], Y[0]);
    return laser.move(Q, P);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        cin >> K >> N >> M >> P >> Q;
        
        X.resize(K);
        Y.resize(K);
        
        for (int i = 0; i < K; i++) {
            cin >> X[i] >> Y[i];
        }
        
        cout << solve(K, N, M, P, Q) << endl;
    }
    return 0;
}
