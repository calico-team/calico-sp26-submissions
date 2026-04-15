
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
using namespace std;


int initial[202005];

int trans[202005];








int main(){
	int t;
	cin>>t;
	while(t--){
		int pjt;
		cin>>pjt;
		for(int i=1;i<=pjt;i++){
			cin>>initial[i];
			trans[i]=initial[i];
		}










		sort(trans+1, trans+1+pjt);



		pair <long long, long long> getmost{0, 0};


		
		for(int i=1;i<=pjt;i++){
			if(i<pjt){
				getmost.first+=(long long)(abs(initial[i+1]-initial[i]));
				getmost.second+=(long long)(abs(initial[i+1]-initial[i]));
			}
			getmost.first+=(long long)(abs(initial[i]-trans[pjt/2]));
			getmost.second+=(long long)(abs(initial[i]-trans[pjt/2+1]));
		}
		if(getmost.first<getmost.second) for(int i=1;i<=pjt;i++) cout<<trans[pjt/2]<<' ';
		else for(int i=1;i<=pjt;i++) cout<<trans[pjt/2+1]<<' ';
		cout<<endl;

































	}         
}