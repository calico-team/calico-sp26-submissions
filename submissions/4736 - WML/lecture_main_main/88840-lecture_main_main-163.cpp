#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Seat{int r,c,u,v,aura;};
bool cmpAura(Seat a,Seat b){return a.aura<b.aura;}

int pref[2005][2005];
vector<Seat> su[2005];
int N,M,K,S;

int query(int u1,int u2,int v1,int v2){
    u1=max(0,u1);v1=max(0,v1);
    u2=min(S-1,u2);v2=min(S-1,v2);
    if(u1>u2||v1>v2)return 0;
    return pref[u2+1][v2+1]-pref[u1][v2+1]-pref[u2+1][v1]+pref[u1][v1];
}

bool check(int D){
    for(int i=0;i<S;i++){
        int u2=min(S-1,i+D);
        for(int j=0;j<S;j++){
            if(query(i,u2,j,min(S-1,j+D))>=K)return true;
        }
    }
    return false;
}

void solve(){
    cin>>N>>M>>K;
    S=N+M-1;
    for(int i=0;i<=S+1;i++){
        su[i].clear();
        for(int j=0;j<=S+1;j++)pref[i][j]=0;
    }
    vector<string> g(N);
    for(int i=0;i<N;i++)cin>>g[i];
    for(int i=0;i<N;i++){
        int tot=0,lft=0;
        for(int j=0;j<M;j++)if(g[i][j]=='#')tot++;
        for(int j=0;j<M;j++){
            if(g[i][j]=='#')lft++;
            else{
                int a=min(lft,tot-lft);
                int u=i+j,v=i-j+M-1;
                su[u].push_back({i,j,u,v,a});
                pref[u+1][v+1]=1;
            }
        }
    }
    for(int i=0;i<S;i++)sort(su[i].begin(),su[i].end(),[](Seat a,Seat b){return a.v<b.v;});
    for(int i=1;i<=S;i++)for(int j=1;j<=S;j++)pref[i][j]+=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
    int low=0,high=N+M,ans=N+M;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(mid)){ans=mid;high=mid-1;}
        else low=mid+1;
    }
    int D=ans;
    int bsum=2e9,bu=-1,bv=-1;
    int freq[505],L[2005],R[2005];
    for(int u1=0;u1<S;u1++){
        int u2=min(S-1,u1+D);
        int vstart=-1,curr=0;
        for(int v1=0;v1<S;v1++){
            int v2=min(S-1,v1+D);
            if(query(u1,u2,v1,v2)>=K){
                if(vstart==-1){
                    curr=0;
                    for(int i=0;i<=500;i++)freq[i]=0;
                    for(int i=u1;i<=u2;i++){
                        int l=0,r=(int)su[i].size()-1,pos=su[i].size();
                        while(l<=r){
                            int m=l+(r-l)/2;
                            if(su[i][m].v>=v1){pos=m;r=m-1;}
                            else l=m+1;
                        }
                        L[i]=R[i]=pos;
                        while(R[i]<(int)su[i].size()&&su[i][R[i]].v<=v2){
                            freq[su[i][R[i]].aura]++;
                            curr++;R[i]++;
                        }
                    }
                    vstart=v1;
                }else{
                    for(int i=u1;i<=u2;i++){
                        while(L[i]<(int)su[i].size()&&su[i][L[i]].v<v1){
                            freq[su[i][L[i]].aura]--;
                            curr--;L[i]++;
                        }
                        while(R[i]<(int)su[i].size()&&su[i][R[i]].v<=v2){
                            freq[su[i][R[i]].aura]++;
                            curr++;R[i]++;
                        }
                    }
                }
                if(curr>=K){
                    int nd=K,sm=0;
                    for(int a=0;a<=500;++a){
                        if(!freq[a])continue;
                        int tk=min(nd,freq[a]);
                        sm+=tk*a;nd-=tk;
                        if(nd==0)break;
                    }
                    if(sm<bsum){bsum=sm;bu=u1;bv=v1;}
                }
            }else vstart=-1;
        }
    }
    vector<Seat> cand;
    for(int i=bu;i<=min(S-1,bu+D);i++){
        for(auto& s:su[i]){
            if(s.v>=bv&&s.v<=min(S-1,bv+D))cand.push_back(s);
        }
    }
    sort(cand.begin(),cand.end(),cmpAura);
    for(int i=0;i<K;i++)cout<<cand[i].r<<" "<<cand[i].c<<"\n";
}

int main(){
    int T;cin>>T;
    while(T--)solve();
    return 0;
}