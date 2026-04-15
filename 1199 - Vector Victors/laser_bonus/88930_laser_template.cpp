#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
typedef long long ll;
using namespace std;

ll find_gcd(ll a, ll b)
{
    while (b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to implement the extended
// euclid algorithm
ll gcd_extend(ll a, ll b,
               ll& x, ll& y)
{
    // Base Case
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    // Recursively find the gcd
    else {
        ll g = gcd_extend(b,
                           a % b, x, y);
        ll x1 = x, y1 = y;
        x = y1;
        y = x1 - (a / b) * y1;
        return g;
    }
}

// Function to prll the solutions of
// the given equations ax + by = c
pair<ll,ll> find_solution(ll a, ll b, ll c)
{
    ll x, y;
    if (a == 0 && b == 0) {

        // Condition for infinite solutions
        if (c == 0) {
            return {-2, -2};
        }

        // Condition for no solutions exist
        else {
            return {-1, -1};
        }
    }
    ll gcd = gcd_extend(a, b, x, y);

    // Condition for no solutions exist
    if (c % gcd != 0) {
        return {-1, -1};
    }
    else {

        // Prll the solution
        return {x * (c / gcd), y * (c / gcd)};
    }
}


/** 
 * Find the index of the first asteroid hit by the laser.
 * 		
 * K: Number of asteroids
 * N, M: Bounds for x- and y-coordinates
 * P, Q: Laser movement (P along y-axis, Q along x-axis)
 * X: List of x-coordinates of asteroids
 * Y: List of y-coordinates of asteroids
 */
ll solve(ll K, ll N, ll M, ll P, ll Q, vector<ll> X, vector<ll> Y) {
	// YOUR CODE HERE
	ll a = X[0];
	ll b = Y[0];
	map<ll, ll> xPosToT;
	for (ll i = 0; i < N; i++) {
		a += Q;
		a %= N;
		if (xPosToT.count(a) == 0) {
			xPosToT[a] = i;
		} else {
			break;
		}
	}
	ll maxTX = xPosToT.size();

	map<ll, ll> yPosToT;
	for (ll i = 0; i < M; i++) {
		b += P;
		b %= M;
		if (yPosToT.count(b) == 0) {
			yPosToT[b] = i;
		} else {
			break;
		}
	}
	ll maxTY = yPosToT.size();
	ll smallestT = -1;
	ll ind = -1;
	for (ll i = 0; i < X.size(); i++) {
		if (xPosToT.count(X[i]) == 0) continue;
		if (yPosToT.count(Y[i]) == 0) continue;
		ll xt = xPosToT[X[i]];
		ll yt = yPosToT[Y[i]];
		ll c = yt-xt;
		ll gcd = find_gcd(maxTY, maxTX);
		if (abs(c) % gcd != 0) continue;

		//cout << " " << xt << " " << yt << "\n";

		pair<ll, ll> sol = find_solution(maxTX, -maxTY, c);
		ll plusY = maxTY/gcd;
		ll plusX = maxTX/gcd;
		ll firstPos = abs(sol.first) / plusY;
		ll secondPos = abs(sol.second) / plusX;
		if (sol.first > 0) firstPos = 0;
		if (sol.second > 0) secondPos = 0;
		//cout << sol.first << " " << sol.second << "\n";
		sol.first += plusY * max(firstPos, secondPos);
		sol.second += plusX * max(firstPos, secondPos);
		if (sol.first < 0 || sol.second < 0) {
			sol.first += plusY;
			sol.second += plusX;
		}
		//cout << sol.first << " " << sol.second << "\n";
		//cout << xt<<" "<<yt<<" "<<maxTX<<" "<<maxTY<<"\n";
		ll t = xt + sol.first * maxTX;
		//cout << t << "\n\n";
		if (t != yt + sol.second*maxTY) {
			//cout << "FATAL ERROR NOT EQUAL\n";
		}
		if (smallestT == -1) {
			smallestT = t;
			ind = i;
		} else if (smallestT > t) {
			smallestT = t;
			ind = i;
		}
	}
	return ind;
}


int main() {
	ll T; cin >> T;
	while (T--) {
		ll K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
		vector<ll> X(K), Y(K);
		for (ll i = 0; i < K; i++) {
			ll a, b; cin >> a >> b;
			X[i] = a;
			Y[i] = b;
		}
		cout << solve(K, N, M, P, Q, X, Y) << endl;
	}
	return 0;
}