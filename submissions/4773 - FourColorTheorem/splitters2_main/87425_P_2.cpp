
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
using namespace std;


int forest[202005];

pair <int, int> mypair1;








int main(){
	int t;
	cin>>t;
	while(t--){
		int pjt, fpl, wdn;
		cin>>pjt>>fpl>>wdn>>mypair1.first;
		mypair1.second=0;
		for(int i=1;i<=pjt;i++) cin>>forest[i];
		for(int i=1;i<=pjt;i++){
			if(forest[i]>fpl) break;

			fpl-=forest[i];
			mypair1.second++;
			if(mypair1.second%mypair1.first==0) fpl+=wdn;
		}
		cout<<(mypair1.second>=pjt?"nah i'd win":"nah i'd lose")<<endl;












	}	
}