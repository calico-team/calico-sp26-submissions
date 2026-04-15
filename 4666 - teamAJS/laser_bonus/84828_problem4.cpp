#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#define int long long
typedef long long ll;
using namespace std;

int extGCD(int a,int b,int &x,int &y){
  if(b==0){x=1;y=0;return a;}
  int x1,y1;
  int d=extGCD(b,a%b,x1,y1);
  x=y1;y=x1-y1*(a/b);
  return d;
}

int inverse(int x,int mod){
  int a,b;
  extGCD(x,mod,a,b);
  return (a%mod+mod)%mod;
}

bool cansolve(int k,int a,int m){
  int tK=k;
  int tM=m;
  while(tM!=0){
    int t=tM;
    tM=tK%tM;
    tK=t;
  }
  return (a%tK==0);
}

int solve(int K,int N,int M,int P,int Q,vector<int> X,vector<int> Y){
  int mk=-1;
  int id=-1;
  int x0=X[0];
  int y0=Y[0];
  for(int i=0;i<K;i++){
    int tx=(X[i]-x0+N)%N;
    int ty=(Y[i]-y0+M)%M;
    if(cansolve(Q,tx,N)&&cansolve(P,ty,M)){
      int tQ=Q,tP=P,tN=N,tM=M;
      while(tN!=0){int t=tN;tN=tQ%tN;tQ=t;}
      int gX=tQ;
      tN=N;tQ=Q;
      while(tM!=0){int t=tM;tM=tP%tM;tP=t;}
      int gY=tP;
      int mX=N/gX,mY=M/gY;
      
      int kx=((tx/gX)*inverse(Q/gX,mX))%mX;
      int ky=((ty/gY)*inverse(P/gY,mY))%mY;
      
      int diff=(kx-ky)%mX;
      if(diff<0)diff+=mX;
      
      int tY=mY,tX=mX;
      while(tX!=0){int t=tX;tX=tY%tX;tY=t;}
      int gXY=tY;
      
      if(diff%gXY==0){
        int mod_j=mX/gXY;
        int j=((diff/gXY)*inverse(mY/gXY,mod_j))%mod_j;
        
        int k=ky+j*mY;
        int lcmXY=mY*mod_j;
        
        if(i==0&&k==0)k+=lcmXY;
        
        if(mk==-1||k<mk){
          mk=k;
          id=i;
        }
      }
    }
  }
  return id;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T;cin>>T;
  while(T--){
    int K,N,M,P,Q;cin>>K>>N>>M>>P>>Q;
    vector<int> X(K),Y(K);
    for(int i=0;i<K;i++){
      int a,b;cin>>a>>b;
      X[i]=a;
      Y[i]=b;
    }
    cout<<solve(K,N,M,P,Q,X,Y)<<"\n";
  }
  return 0;
}