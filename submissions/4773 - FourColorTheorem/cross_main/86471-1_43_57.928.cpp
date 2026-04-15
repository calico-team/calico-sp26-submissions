
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
using namespace std;


int forest[1005][1005];










int main(){
	int t;
	cin>>t;
	while(t--){
		int pjt;
		int fpl;
		cin>>pjt>>fpl;
		for(int i=1;i<=pjt;i++) for(int j=1;j<=fpl;j++) forest[i][j]=(2*i+j)%5;
		for(int i=1;i<=pjt;i++){
			for(int j=1;j<=fpl;j++) cout<<forest[i][j];
            
            cout<<endl;
		}















	}		  
}