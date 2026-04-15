#include<bits/stdc++.h>

using namespace std;
using i128 = __int128_t;

static i128 cdiv(i128 a,i128 b){
	return (a+b-1)/b;
}

static i128 fdiv(i128 a,i128 b){
	if(a>=0)return a/b;
	return -(((-a)+b-1)/b);
}

static i128 tri(i128 l,i128 r){
	if(l>r)return 0;
	return (l+r)*(r-l+1)/2;
}

static i128 fs(i128 n,i128 m,i128 a,i128 b){
	i128 ans=0;
	while(1){
		if(a>=m){
			ans+=(n-1)*n*(a/m)/2;
			a%=m;
		}
		if(b>=m){
			ans+=n*(b/m);
			b%=m;
		}
		i128 y=a*n+b;
		if(y<m)break;
		n=y/m;
		b=y%m;
		swap(m,a);
	}
	return ans;
}

static i128 seg(i128 l,i128 r,i128 a,i128 b){
	if(l>r)return 0;
	i128 n=r-l+1;
	i128 s=a*l+b;
	i128 q=fdiv(s,4);
	s-=q*4;
	return n*q+fs(n,4,a,s);
}

static i128 L(i128 d,i128 k){
	i128 p=cdiv(2*d,9),q=cdiv(2*d,5);
	if(k<p)return 0;
	if(k<q)return fdiv(9*k-2*d,4)+1;
	return fdiv(13*k-2*d-4*q,4)+1;
}

static i128 R(i128 d,i128 a,i128 k){
	i128 p=cdiv(2*d,9);
	if(k<p)return 0;
	if(a>=p)return k+L(d,k)-1;
	i128 t=d-2*a;
	i128 u=cdiv(2*t,5),v=cdiv(4*u+2*t,5);
	if(k<u)return fdiv(9*k-2*t,4);
	if(k<v)return fdiv(13*k-2*t-4*u,4);
	return fdiv(17*k-2*t-4*u-4*v,4);
}

static i128 len(i128 d,i128 a,i128 k){
	return 4*k-L(d,k)-R(d,a,k);
}

static i128 pref(i128 n,i128 d,i128 a){
	if(n<=0)return 0;
	i128 p=cdiv(2*d,9),q=cdiv(2*d,5);
	i128 ans=0;

	i128 r=min(n,p-1);
	if(r>=1)ans+=4*tri(1,r);
	if(n<p)return ans;

	if(a>=p){
		i128 l=p;
		r=min(n,q-1);
		if(l<=r){
			i128 cnt=r-l+1;
			ans+=3*tri(l,r)-cnt-2*seg(l,r,9,-2*d);
		}
		l=max(p,q),r=n;
		if(l<=r){
			i128 cnt=r-l+1;
			ans+=3*tri(l,r)-cnt-2*seg(l,r,13,-2*d-4*q);
		}
		return ans;
	}

	i128 t=d-2*a;
	i128 u=cdiv(2*t,5),v=cdiv(4*u+2*t,5);
	vector<i128> cut={p,q,u,v,n+1};
	sort(cut.begin(),cut.end());
	cut.erase(unique(cut.begin(),cut.end()),cut.end());

	i128 cur=p;
	for(i128 nxt:cut){
		if(nxt<=cur)continue;
		i128 l=cur,rr=min(n,nxt-1);
		if(l<=rr){
			i128 a1,b1,a2,b2;
			if(l<q) a1=9,b1=-2*d;
			else a1=13,b1=-2*d-4*q;
			if(l<u) a2=9,b2=-2*t;
			else if(l<v) a2=13,b2=-2*t-4*u;
			else a2=17,b2=-2*t-4*u-4*v;
			i128 cnt=rr-l+1;
			ans+=4*tri(l,rr)-cnt-seg(l,rr,a1,b1)-seg(l,rr,a2,b2);
		}
		cur=nxt;
	}

	return ans;
}

static string cvt(i128 x){
	if(x==0)return "0";
	string s;
	while(x>0){
		s.push_back(char('0'+x%10));
		x/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}

/**
 * Return the total number of tiles mycelium will ever occupy.
 *
 * X_G: x-coordinate of grass starting position
 * Y_G: y-coordinate of grass starting position
 * X_M: x-coordinate of mycelium starting position
 * Y_M: y-coordinate of mycelium starting position
 */
string solve(int X_G, int Y_G, int X_M, int Y_M) {
	i128 dx=llabs(1LL*X_G-X_M);
	i128 dy=llabs(1LL*Y_G-Y_M);
	i128 a=min(dx,dy),b=max(dx,dy),d=a+b;

	i128 lo=0,hi=1;
	while(len(d,a,hi)>0)hi<<=1;
	while(lo<hi){
		i128 mid=(lo+hi+1)>>1;
		if(len(d,a,mid)>0)lo=mid;
		else hi=mid-1;
	}

	return cvt(1+pref(lo,d,a));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int X_G, Y_G, X_M, Y_M;
		cin >> X_G >> Y_G >> X_M >> Y_M;
		cout << solve(X_G, Y_G, X_M, Y_M) << '\n';
	}
}
