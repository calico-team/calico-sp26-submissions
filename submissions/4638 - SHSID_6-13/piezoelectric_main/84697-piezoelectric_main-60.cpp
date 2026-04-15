#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int T, L, W, E, R, result;
cin>>T;
for(int i=1; i<=T; i++){
	cin>>L>>W>>E>>R;
	if(E%((L+W)*2*R)==0)result=E/((L+W)*2*R);
	else result=E/((L+W)*2*R)+1;
	cout<<result<<endl;
}
return 0;
}
