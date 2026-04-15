
#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
using namespace std;


set <int> candies;










int main(){
	int t;
	cin>>t;
	while(t--){
		string jjbit;
		string deciher;
		cin>>jjbit;
		cin>>deciher;

		reverse(deciher.begin(), deciher.end());
		
		candies.clear();
		for(int i=0;i<jjbit.length();i++){
			if(deciher.empty()) break;
			else if(jjbit[i]==deciher.back()){
				candies.insert(i);
				deciher.pop_back();


			}
		}

		for(int i=0;i<jjbit.length();i++) cout<<(candies.count(i)?jjbit[i]:'#');
		cout<<endl;




	}                  
}
