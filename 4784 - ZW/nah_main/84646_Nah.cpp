#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);

int kk;
cin>>kk;

while(kk--){

int n,p,r,k;
cin>>n>>p>>r>>k;

int cnt=0;
bool die=false;

for(int i=0;i<n;i++){

int tmp;
cin>>tmp;

if(die) continue;

p-=tmp;

if(p<0){
cout<<"nah i��d lose\n";
die=true;
}

cnt++;

if(cnt==k){
cnt=0;
p+=r;
}

}

if(!die){
cout<<"nah i��d win\n";
}

}

}
