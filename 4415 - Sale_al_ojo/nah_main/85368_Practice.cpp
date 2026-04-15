#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);

int casos, N, P, R, K,aux;
vector<int>result;
cin>>casos;
for(int i=0;i<casos;i++){
  int enemigosquevencio = 0;
        result.clear();
    cin>>N>>P>>R>>K;

    for(int k=0;k<N;k++){
        cin>>aux;
        result.push_back(aux);
    }
    for(int h=0;h<N;h++){
        P=P-result[h];
        enemigosquevencio=enemigosquevencio+1;
        if(P<0){
          break;
        }

         if(enemigosquevencio==K){
            P=P+R;
            enemigosquevencio=0;
        }
    }


  if(P>=0){
    cout<<"nah i'd win"<<'\n';
 }else{
    cout<<"nah i'd lose"<<'\n';
 }
}

return 0;
}
