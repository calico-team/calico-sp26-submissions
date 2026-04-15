#include<bits/stdc++.h>
using namespace std;
int kk; 
int n,p,tmp,r,k,cnt; 
bool die; 
int main(){
    cin>>kk;
    while(kk--){
    	cin>>n>>p>>r>>k;
    	cnt=0;
    	die=false;
    	for(int i=0;i<n;i++){
    		cin>>tmp;
    		if(die==false)continue; 
    		p-=tmp;
    		if(p<0){
			   cout<<"nah i'd lose"<<endl;
			   die=true; 
			}cnt++;
			if(cnt==k){
				cnt=0;
				p+=r; 
			}
		}if(p>=0&&die==false){
			cout<<"nah i'd win"<<endl; 
		}
	}
    return 0;
}



