#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{
	if(b) return gcd(b,a%b);
	else return a;
}
struct ff{
	ll p,q;
	ff(ll p=0,ll q=1):p(p),q(q) {}
};

ff add(ff a,ff b)
{
	if(!a.p) return b;
	if(!b.p) return a;
	ll g=gcd(a.q,b.q);
	ll l=a.q/g*b.q,n=a.p*(b.q/g)+a.q/g*b.p;
	ll g2=gcd(n,l);
	return ff(n/g2,l/g2);
}
ff div(ff a,int k)
{
	if(!a.p) return a;
	ll g=gcd(a.p,k);
	return ff(a.p/g,a.q*(k/g));
}
int n,m;
string g[1015];
ll p[1015][1015],q[1015][1015];
int dr[]={-1,1,0,0},dc[]={0,0,-1,1};
char bd[]="v^><";
ff dfs(int r,int c)
{
	if(r<0 or r>=n or c<0 or c>=m)
		return ff(1,1);
	if(q[r][c]!=-1) return ff(p[r][c],q[r][c]);
	char x=g[r][c];
	ff ret;
	if(x=='X') ret=ff(0,1);
	else if(x=='^') ret=dfs(r-1,c);
    else if(x=='v') ret=dfs(r+1,c);
    else if(x=='<') ret=dfs(r,c-1);
    else if(x=='>') ret=dfs(r,c+1);
    else if(x=='S')
    {
    	int k=0;
    	for(int i=0;i<4;i++)
    	{
    		int nr=r+dr[i],nc=c+dc[i];
    		char nx=g[nr][nc];
    		if(nx!='.' and nx!='S' and nx!=bd[i])
    		{
    			k++;
    			ret=add(ret,dfs(nr,nc));
    		}
    	}
    	ret=div(ret,k);
    }
    p[r][c]=ret.p;
    q[r][c]=ret.q;
    return ret;
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>g[i];
		for(int j=0;j<m;j++)
			q[i][j]=-1;
	}
	ff ans=dfs(0,0);
	cout<<ans.p<<" "<<ans.q<<"\n";
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}