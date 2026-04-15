
#include <iostream>
#include <numeric>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
using namespace std;


int forest[1005][1005];

pair <int, int> mypair1;
                                                                                     







pair <int, int> steroids;



pair <int, int> hit;






int main(){
	int t;
	cin>>t;
	while(t--){
		int pjt, fpl, wdn;
		cin>>pjt>>fpl>>wdn>>mypair1.second>>mypair1.first;
		
		for(int i=0;i<fpl;i++) for(int j=0;j<wdn;j++) forest[i][j]=-1;
		for(int i=0;i<pjt;i++){
			cin>>steroids.first>>steroids.second;
		
			forest[steroids.first][steroids.second]=i;
			if(i==0) hit={steroids.first, steroids.second};
		}          
		for(int i=0;i<=1000005;i++){
			hit.first+=mypair1.first;
			hit.first%=fpl;
			hit.second+=mypair1.second;
			hit.second%=wdn;
			if(forest[hit.first][hit.second]>=0){
				cout<<forest[hit.first][hit.second];
				break;
			}		   	
		}
		cout<<endl;
	}	
}