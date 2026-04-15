#include<bits/stdc++.h>
using namespace std;

struct Cell {
    int R, C, V, W;
};

struct DSU {
    vector<int> p,sz;

    DSU() {}
    DSU(int n){ init(n); }

    void init(int n){
        p.resize(n);
        sz.assign(n,1);
        iota(p.begin(),p.end(),0);
    }

    int find(int x){
        while(p[x]!=x){
            p[x]=p[p[x]];
            x=p[x];
        }
        return x;
    }

    void unite(int a,int b){
        a=find(a),b=find(b);
        if(a==b)return;
        if(sz[a]<sz[b])swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
    }
};

struct Cand {
    double x,w;
};

static bool candCmp(const Cand& a,const Cand& b){
    return a.x<b.x;
}

struct Solver {
    static constexpr long long LIM=1000000000LL;

    int N=0,M=0,d=0,maxDeg=0;
    vector<int> U,V,val,wt,deg,head,adj,ord,idx;
    vector<vector<int>> compNodes,compEdges;
    vector<double> pen;

    Solver(int n,int m,int D,const vector<Cell>& cells){
        N=n; M=m; d=min(D,M);
        U.resize(M);
        V.resize(M);
        val.resize(M);
        wt.resize(M);
        deg.assign(N,0);

        DSU dsu(N);
        for(int e=0;e<M;e++){
            int r=cells[e].R-1;
            int c=cells[e].C-1;
            U[e]=r;
            V[e]=c;
            val[e]=cells[e].V;
            wt[e]=cells[e].W;
            deg[r]++;
            deg[c]++;
            dsu.unite(r,c);
        }

        for(int x:deg)maxDeg=max(maxDeg,x);

        head.assign(N+1,0);
        for(int i=0;i<N;i++)head[i+1]=head[i]+deg[i];
        adj.assign(2*M,0);
        vector<int> cur=head;
        for(int e=0;e<M;e++){
            adj[cur[U[e]]++]=e;
            adj[cur[V[e]]++]=e;
        }

        vector<int> mp(N,-1),cid(N,-1);
        int cc=0;
        for(int i=0;i<N;i++){
            int r=dsu.find(i);
            if(mp[r]==-1)mp[r]=cc++;
            cid[i]=mp[r];
        }

        vector<int> nc(cc,0),ec(cc,0);
        for(int i=0;i<N;i++)nc[cid[i]]++;
        for(int e=0;e<M;e++)ec[cid[U[e]]]++;

        compNodes.assign(cc,{});
        compEdges.assign(cc,{});
        for(int c=0;c<cc;c++){
            compNodes[c].reserve(nc[c]);
            compEdges[c].reserve(ec[c]);
        }
        for(int i=0;i<N;i++)compNodes[cid[i]].push_back(i);
        for(int e=0;e<M;e++)compEdges[cid[U[e]]].push_back(e);

        ord.resize(N);
        iota(ord.begin(),ord.end(),0);
        sort(ord.begin(),ord.end(),[&](int a,int b){
            if(deg[a]!=deg[b])return deg[a]>deg[b];
            return a<b;
        });

        pen.assign(M,0.0);
        idx.resize(M);
    }

    long long clampInt(long double x) const{
        if(!isfinite((double)x))return 1;
        if(x<1)return 1;
        if(x>(long double)LIM)return LIM;
        return (long long)llround(x);
    }

    double wmed(vector<Cand>& c) const{
        sort(c.begin(),c.end(),candCmp);
        long double tot=0;
        for(auto &e:c)tot+=(long double)e.w;
        long double cur=0,need=tot*0.5L;
        double med=c.back().x;
        for(auto &e:c){
            cur+=(long double)e.w;
            if(cur>=need){
                med=e.x;
                break;
            }
        }
        return med;
    }

    vector<long long> buildConst() const{
        vector<long long> a(N,1);
        vector<Cand> c;
        for(int id=0;id<(int)compEdges.size();id++){
            if(compEdges[id].empty()){
                for(int u:compNodes[id])a[u]=1;
                continue;
            }
            c.clear();
            c.reserve(compEdges[id].size());
            for(int e:compEdges[id]){
                c.push_back({(double)val[e],(double)wt[e]/(double)val[e]});
            }
            double med=wmed(c);
            long long x=clampInt(sqrt((long double)med));
            for(int u:compNodes[id])a[u]=x;
        }
        return a;
    }

    vector<long long> buildLS(const vector<unsigned char>* act,int iters) const{
        vector<double> dw(N,0.0),b(N,0.0);
        for(int e=0;e<M;e++){
            if(act && !(*act)[e])continue;
            double ww=(double)wt[e];
            double y=log((double)val[e]);
            int u=U[e],v=V[e];
            dw[u]+=ww;
            dw[v]+=ww;
            b[u]+=ww*y;
            b[v]+=ww*y;
        }

        auto mulA = [&](const vector<double>& in,vector<double>& out){
            out.assign(N,0.0);
            const double lam=1e-3;
            for(int i=0;i<N;i++)out[i]=(dw[i]+lam)*in[i];
            for(int e=0;e<M;e++){
                if(act && !(*act)[e])continue;
                double ww=(double)wt[e];
                int u=U[e],v=V[e];
                out[u]+=ww*in[v];
                out[v]+=ww*in[u];
            }
        };

        vector<double> x(N,0.0),r=b,z(N,0.0),p(N,0.0),Ap(N,0.0),diag(N,0.0);
        const double lam=1e-3;
        for(int i=0;i<N;i++)diag[i]=dw[i]+lam;

        auto dot = [&](const vector<double>& a,const vector<double>& bb)->long double{
            long double s=0;
            for(int i=0;i<N;i++)s+=(long double)a[i]*(long double)bb[i];
            return s;
        };

        for(int i=0;i<N;i++){
            z[i]=r[i]/diag[i];
            p[i]=z[i];
        }

        long double rz=dot(r,z),rz0=rz;
        if(rz0>1e-30L){
            for(int it=0;it<iters;it++){
                mulA(p,Ap);
                long double den=dot(p,Ap);
                if(fabsl(den)<1e-30L)break;

                double alpha=(double)(rz/den);
                for(int i=0;i<N;i++){
                    x[i]+=alpha*p[i];
                    r[i]-=alpha*Ap[i];
                }

                for(int i=0;i<N;i++)z[i]=r[i]/diag[i];
                long double rz2=dot(r,z);
                if(rz2<=rz0*1e-12L)break;

                double beta=(double)(rz2/rz);
                for(int i=0;i<N;i++)p[i]=z[i]+beta*p[i];
                rz=rz2;
            }
        }

        vector<long double> base(N,1.0L);
        for(int i=0;i<N;i++){
            long double xi=(long double)x[i];
            if(xi<-20)xi=-20;
            if(xi>20)xi=20;
            base[i]=expl(xi);
            if(!isfinite((double)base[i]))base[i]=1.0L;
        }

        DSU dsu(N);
        for(int e=0;e<M;e++){
            if(act && !(*act)[e])continue;
            dsu.unite(U[e],V[e]);
        }

        vector<int> mp(N,-1),cid(N,-1);
        int cc=0;
        for(int i=0;i<N;i++){
            int r0=dsu.find(i);
            if(mp[r0]==-1)mp[r0]=cc++;
            cid[i]=mp[r0];
        }

        vector<int> nc(cc,0),ec(cc,0);
        for(int i=0;i<N;i++)nc[cid[i]]++;
        for(int e=0;e<M;e++)if(!act||(*act)[e])ec[cid[U[e]]]++;

        vector<vector<int>> nodes(cc),edges(cc);
        for(int c=0;c<cc;c++){
            nodes[c].reserve(nc[c]);
            edges[c].reserve(ec[c]);
        }
        for(int i=0;i<N;i++)nodes[cid[i]].push_back(i);
        for(int e=0;e<M;e++)if(!act||(*act)[e])edges[cid[U[e]]].push_back(e);

        vector<Cand> c;
        for(int id=0;id<cc;id++){
            if(edges[id].empty()){
                for(int u:nodes[id])base[u]=1;
                continue;
            }
            c.clear();
            c.reserve(edges[id].size());
            for(int e:edges[id]){
                long double prod=base[U[e]]*base[V[e]];
                if(prod<1e-18L)prod=1e-18L;
                long double t=(long double)val[e]/prod;
                long double ww=(long double)wt[e]*prod/(long double)val[e];
                if(t>1e18L)t=1e18L;
                if(ww>1e18L)ww=1e18L;
                c.push_back({(double)t,(double)ww});
            }
            double med=wmed(c);
            long double sc=sqrt(max((long double)med,1e-18L));
            for(int u:nodes[id]){
                base[u]*=sc;
                if(!isfinite((double)base[u]))base[u]=1;
            }
        }

        vector<long long> a(N,1);
        for(int i=0;i<N;i++)a[i]=clampInt(base[i]);
        return a;
    }

    int sweep(vector<long long>& a,const vector<unsigned char>* act,bool rev) const{
        vector<Cand> c;
        c.reserve(maxDeg);
        int changed=0;

        auto proc = [&](int u){
            c.clear();
            for(int p=head[u];p<head[u+1];p++){
                int e=adj[p];
                if(act && !(*act)[e])continue;
                int v=U[e]+V[e]-u;
                long long av=a[v];
                double t=(double)val[e]/(double)av;
                double ww=(double)wt[e]*(double)av/(double)val[e];
                c.push_back({t,ww});
            }
            if(c.empty())return;

            sort(c.begin(),c.end(),candCmp);
            long double tot=0,cur=0;
            for(auto &e:c)tot+=(long double)e.w;

            double med=c.back().x;
            for(auto &e:c){
                cur+=(long double)e.w;
                if(cur>=tot*0.5L){
                    med=e.x;
                    break;
                }
            }

            long long lo=max(1LL,min(LIM,(long long)floor((long double)med)));
            long long hi=lo+1;
            if(hi>LIM)hi=LIM;
            if(fabsl((long double)med-floor((long double)med))<1e-12L)hi=lo;

            long long nv=lo;
            if(hi!=lo){
                long double c1=0,c2=0;
                for(auto &e:c){
                    c1+=(long double)e.w*fabsl((long double)lo-(long double)e.x);
                    c2+=(long double)e.w*fabsl((long double)hi-(long double)e.x);
                }
                if(c2<c1)nv=hi;
            }

            if(nv!=a[u]){
                a[u]=nv;
                changed++;
            }
        };

        if(!rev){
            for(int u:ord)proc(u);
        } else {
            for(auto it=ord.rbegin();it!=ord.rend();++it)proc(*it);
        }

        return changed;
    }

    long double edgePen(const vector<long long>& a,int e) const{
        long double prod=(long double)a[U[e]]*(long double)a[V[e]];
        return (long double)wt[e]*fabsl(prod-(long double)val[e])/(long double)val[e];
    }

    long double eval(const vector<long long>& a,vector<int>* outDisc,vector<unsigned char>* outAct){
        long double total=0;
        for(int e=0;e<M;e++){
            long double cur=edgePen(a,e);
            pen[e]=(double)cur;
            total+=cur;
        }

        if(d==0){
            if(outDisc)outDisc->clear();
            if(outAct){
                if((int)outAct->size()!=M)outAct->assign(M,1);
                else fill(outAct->begin(),outAct->end(),(unsigned char)1);
            }
            return total;
        }

        iota(idx.begin(),idx.end(),0);
        nth_element(idx.begin(),idx.begin()+d,idx.end(),[&](int i,int j){
            return pen[i]>pen[j];
        });

        if(outDisc)outDisc->resize(d);
        if(outAct){
            if((int)outAct->size()!=M)outAct->assign(M,1);
            else fill(outAct->begin(),outAct->end(),(unsigned char)1);
        }

        long double rem=0;
        for(int k=0;k<d;k++){
            int e=idx[k];
            rem+=edgePen(a,e);
            if(outDisc)(*outDisc)[k]=e+1;
            if(outAct)(*outAct)[e]=0;
        }

        return total-rem;
    }

    void run(vector<int>& A,vector<int>& discards){
        if(M==0||d==M){
            A.assign(N,1);
            discards.clear();
            for(int i=0;i<d;i++)discards.push_back(i+1);
            return;
        }

        int pcg=16;
        if(M<=1000000)pcg=22;
        if(M<=300000)pcg=28;

        int rounds=(M<=700000?3:2);

        vector<long long> seed1=buildConst();
        vector<long long> seed2=buildLS(nullptr,pcg);

        vector<long long> bestA;
        vector<int> bestDisc,tmpDisc;
        long double bestObj=1e300L;

        auto relax = [&](const vector<long long>& aa){
            long double obj=eval(aa,&tmpDisc,nullptr);
            if(obj<bestObj){
                bestObj=obj;
                bestA=aa;
                bestDisc=tmpDisc;
            }
            return obj;
        };

        long double o1=relax(seed1);
        long double o2=relax(seed2);

        vector<vector<long long>> starts;
        if(o1<=o2){
            starts.push_back(seed1);
            starts.push_back(seed2);
        } else {
            starts.push_back(seed2);
            starts.push_back(seed1);
        }

        vector<unsigned char> act(M,1);

        for(int s=0;s<(int)starts.size();s++){
            vector<long long> a=starts[s];
            for(int it=0;it<rounds;it++){
                relax(a);
                eval(a,&tmpDisc,&act);

                vector<long long> raw=buildLS(&act,pcg);
                long double oraw=relax(raw);

                vector<long long> ref=raw;
                sweep(ref,&act,(it&1));
                long double oref=relax(ref);

                a=(oref<oraw?ref:raw);
            }
            relax(a);
        }

        vector<long long> pol=bestA;
        vector<unsigned char> fixed(M,1);
        for(int id:bestDisc)fixed[id-1]=0;
        if(sweep(pol,d==0?nullptr:&fixed,false)>0)relax(pol);

        eval(bestA,&bestDisc,nullptr);

        A.resize(N);
        for(int i=0;i<N;i++)A[i]=(int)bestA[i];
        discards=bestDisc;
    }
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
void solve(int N, int M, int D, const vector<Cell>& cells,
           vector<int>& A, vector<int>& discards) {
    Solver solver(N,M,D,cells);
    solver.run(A,discards);
}

int main() {
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
