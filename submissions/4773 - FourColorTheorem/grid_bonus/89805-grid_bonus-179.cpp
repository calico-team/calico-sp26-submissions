
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
using namespace std;


int forest[202005];

int teroids[202005];








int main(){
	int t;
	while(t--){
		int pjt;
		cin>>pjt;
		for(int i=1;i<=pjt;i++) cin>>forest[i];
		pair <int, int> mypair1{0, 0};
		
		
		
		
		
		
		
		
		map <int, int> candies;
		for(int i=1;i<=pjt;i++) candies[forest[i]]++;
		
		
		
		
		
		
		for(auto materator1 : candies){
			if((materator1->second)>mypair1.first){
				mypair1.first=materator1->second;
				mypair1.second=materator1->first;
			}
		}
		for(int i=1;i<=pjt;i++) cout<<mypair1.second<<' ';
		cout<<endl;
	}
}