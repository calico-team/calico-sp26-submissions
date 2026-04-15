#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
typedef long long ll;
using namespace std;

/** 
 * Find the index of the first asteroid hit by the laser.
 * 		
 * K: Number of asteroids
 * N, M: Bounds for x- and y-coordinates
 * P, Q: Laser movement (P along y-axis, Q along x-axis)
 * X: List of x-coordinates of asteroids
 * Y: List of y-coordinates of asteroids
 */

const int MAXN = 1e6 + 6;
ll phi[MAXN], faktor[MAXN];

void precompute(){
	phi[1] = 1;
	memset(faktor, -1, sizeof(faktor));
	for(ll i = 2; i < MAXN; i++){
		if(faktor[i] == -1){
			faktor[i] = i;
			for(ll j = i*i; j < MAXN; j += i){
				faktor[j] = i;
			}
		}
	}

	for(ll i = 2; i < MAXN; i++){
		ll j = faktor[i];
		while(i%(j*faktor[i]) == 0){
			j *= faktor[i];
		}
		phi[i] = phi[i/j]*j*(faktor[i] - 1)/faktor[i];
	}
}

ll expo(ll a, ll b, ll md){
	ll ret = 1;
	while(b > 0){
		if(b%2 == 1){
			ret *= a;
			ret %= md;
		}

		a *= a;
		a %= md;
		b /= 2;
	}
	return ret;
}

ll cari(ll n, ll m, ll val){

	ll gd = gcd(n, m);
	if(val % gd != 0){
		return 1e12;
	}
	n /= gd;
	m /= gd;
	val /= gd;

	if(val == 0){
		return n;
	}

	return val*expo(m, (phi[n] - 1 + n)%n, n)%n;
}

ll extgcd(ll a,ll b,ll &x,ll &y){
  if (b == 0) return x=1,y=0,a;
  ll d = extgcd(b,a%b,y,x);
  y -= a/b*x;
  return d;
}

ll crt(ll a, ll m, ll b, ll n) {  
  if (n > m) {swap(a,b); swap(m,n); }
  ll x, y, g = extgcd(m,n,x,y);
  if ((a-b)%g != 0) return -1;
  x = (b-a)%n*x%n/g*m+a;
  return x<0 ? x+m*n/g : x;
}

ll solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
	pair<ll, ll> mn = {(ll)N/gcd(N, Q)*(ll)M/gcd(M, P), 0};
	for(int i = 1; i < K; i++){
		ll butuhX = (X[i] - X[0] + N)%N, butuhY = (Y[i] - Y[0] + M)%M;
		ll stepX = cari(N, Q, butuhX), stepY = cari(M, P, butuhY);
		// cout << stepX << " " << stepY << endl;
		if(stepX == 1e12 || stepY == 1e12){
			continue;
		}

		ll res = crt(stepX, N/gcd(N, Q), stepY, M/gcd(M, P));
		//  cout << i << " " << stepX << " " << N/gcd(N, Q) << " " << stepY << " " << M/gcd(M, P) << " " << res << endl;

		if(res == -1){
			continue;
		}

		mn = min(mn, {res, i});
	}

	return mn.second;
}


int main() {
	int T; cin >> T;
	precompute();
	while (T--) {
		int K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
		vector<int> X(K), Y(K);
		for (int i = 0; i < K; i++) {
			int a, b; cin >> a >> b;
			X[i] = a;
			Y[i] = b;
		}
		cout << solve(K, N, M, P, Q, X, Y) << endl;
	}
	return 0;
}