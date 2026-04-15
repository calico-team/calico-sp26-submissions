#include<bits/stdc++.h>
using namespace std;
const int N=100015,M=300015;
int r[M],c[M],a[M],n,m,d;
double v[M],w[M];
int head[N],nxt[M*2],cid[M*2],ecnt;

void aedge(int u,int ci)
{
	ecnt++;
	cid[ecnt]=ci;
	nxt[ecnt]=head[u];
	head[u]=ecnt;
}
struct err{
	double e;
	int id;
} errs[M];

bool cmp(err a,err b){return a.e>b.e;}

double cdif(int u,int nv)
{
	double dif=0;
	for(int i=head[u];i;i=nxt[i])
	{
		int id=cid[i];
		double op=1.0*a[r[id]]*a[c[id]];
		double oe=w[id]*fabs(op-v[id])/v[id];
		double nr=(r[id]==u?nv:a[r[id]]);
		double nc=(c[id]==u)?nv:a[c[id]];
		double np=nr*nc,ne=w[id]*fabs(np-v[id])/v[id];
		dif+=ne-oe;
	}
	return dif;
}
void sa()
{
	double t1=5000.0;
	double t2=1e-4;
	double dl=0.996;
	while(t1>t2)
	{
		int u=(rand()%n)+1;
		int stp=max(1,(int)t1);
		int dval=(rand()%(2*stp+1))-stp;
		int nv=a[u]+dval;
		if(nv<1) nv=1;
		if(nv!=a[u])
		{
			double dif=cdif(u,nv);
			if(dif<=0 or exp(-dif/t1)>(double)rand()/RAND_MAX)
				a[u]=nv;
		}
		t1*=dl;
	}
	
}
int main()
{
	srand(19890604);
	cin>>n>>m>>d;
	for(int i=1;i<=m;i++)
	{
		cin>>r[i]>>c[i]>>v[i]>>w[i];
		aedge(r[i],i);
		aedge(c[i],i);
	}
	for(int i=1;i<=n;i++)
		a[i]=10;
	int sat=6;
	while(sat--) sa();
	for(int i=1;i<=m;i++)
	{
		errs[i].e=w[i]*fabs(1.0*a[r[i]]*a[c[i]]-v[i])/v[i];
		errs[i].id=i;
	}
	sort(errs+1,errs+m+1,cmp);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	puts(" ");
	d=min(d,m);
	for(int i=1;i<=d;i++)
	{
		if(i==1)
			cout<<errs[i].id;
		else
			cout<<" "<<errs[i].id;
	}
	return 0;
}