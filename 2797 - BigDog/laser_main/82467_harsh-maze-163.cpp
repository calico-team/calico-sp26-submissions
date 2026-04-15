#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll egcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll x1,y1;
	ll g=egcd(b,a%b,x1,y1);
	x=y1;
	y=x1-a/b*y1;
	return g;
}

bool merge(ll a1,ll m1,ll a2,ll m2,ll &a,ll &m){
	if(m1==1){
		a=a2%m2;
		m=m2;
		return true;
	}
	if(m2==1){
		a=a1%m1;
		m=m1;
		return true;
	}
	ll x,y;
	ll g=egcd(m1,m2,x,y);
	ll d=a2-a1;
	if(d%g)return false;
	ll md=m2/g;
	ll k=((d/g)%md+md)%md;
	ll iv=(x%md+md)%md;
	k=k*iv%md;
	m=m1/g*m2;
	a=(a1+m1*k)%m;
	if(a<0)a+=m;
	return true;
}

ll inv_mod(ll a,ll mod){
	if(mod==1)return 0;
	ll x,y;
	egcd(a,mod,x,y);
	x%=mod;
	if(x<0)x+=mod;
	return x;
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
int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
	ll x0=X[0],y0=Y[0];

	ll gx=gcd((ll)Q,(ll)N);
	ll gy=gcd((ll)P,(ll)M);
	ll mx=N/gx,my=M/gy;

	ll iq=inv_mod(Q/gx,mx);
	ll ip=inv_mod(P/gy,my);

	int ans=0;
	ll best=-1;

	for(int i=0;i<K;i++){
		ll dx=(X[i]-x0+N)%N;
		ll dy=(Y[i]-y0+M)%M;

		if(dx%gx||dy%gy)continue;

		ll tx=mx==1?0:(dx/gx)*iq%mx;
		ll ty=my==1?0:(dy/gy)*ip%my;

		ll t,per;
		if(!merge(tx,mx,ty,my,t,per))continue;
		if(t==0)t=per;

		if(best==-1||t<best||(t==best&&i<ans)){
			best=t;
			ans=i;
		}
	}

	return ans;
}


int main() {
	int T; cin >> T;
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
