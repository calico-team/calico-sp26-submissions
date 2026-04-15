#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);

int a;
cin>>a;

while(a--){

long long b,c,d,e,f;
cin>>b>>c>>d>>e>>f;

vector<long long>g(b),h(b);

map<pair<long long,long long>,int>i;

for(int j=0;j<b;j++){
cin>>g[j]>>h[j];
i[{g[j],h[j]}]=j;
}

long long j=g[0],k=h[0];

while(true){

j=(j+f)%c;
k=(k+e)%d;

if(i.count({j,k})){
cout<<i[{j,k}]<<"\n";
break;
}

if(j==g[0]&&k==h[0]){
cout<<-1<<"\n";
break;
}

}

}

}

