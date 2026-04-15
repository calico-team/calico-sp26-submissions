#include<bits/stdc++.h>
using namespace std;
string a,b; 
int k;
int idxa,idxb;
int main(){
    cin>>k;
    while(k--){
    	cin>>a>>b;
        idxa=0;
		idxb=0;
		while(idxa < a.length()){
			if(a[idxa]!=b[idxb]){
				a[idxa]='#';
			}else{
				idxb++;
			}idxa++;
		}cout<<a<<endl;
	}
    return 0;
}



