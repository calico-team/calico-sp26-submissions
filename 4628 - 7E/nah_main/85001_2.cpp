#include<bits/stdc++.h>

using namespace std;
int main(){
	
	int t;
	cin>>t; 

int n,p,r,k;
	cin>>n>>p>>r>>k; 
	int e[n];
for(int i=0;i<t;i++){

for(int i=0;i<n;i++){
		cin>>e[i];
	}
	for(int i=1;i<=n;i++){
		if(p>e[i]){
			p=p-e[i];
			if(i==k){
			p+=r;
			}
		}else{
			p=p-e[i];
			break;  
		}
		
	}
    if(p>=0){
    	cout<<"nah i'd win";
	}else{
		cout<<"nah i'd lose";
	
	
	}}
	return 0;
} 
