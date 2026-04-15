#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int K;
        ll N,M,P,Q;
        cin>>K>>N>>M>>P>>Q;
        ll ast[100005][2];
        for(int i=0;i<K;i++){
            cin>>ast[i][0]>>ast[i][1];
        }
        ll cx=ast[0][0];
        ll cy=ast[0][1];
        int ans=0;
        while(1){
            cx=(cx+Q)%N;
            cy=(cy+P)%M;
            int f=0;
            for(int i=0;i<K;i++){
                if(cx==ast[i][0]&&cy==ast[i][1]){
                    ans=i;
                    f=1;
                    break;
                }
            }
            if(f){
				break;
			}
        }
        cout<<ans<<endl;
        return 0;
    }
}
