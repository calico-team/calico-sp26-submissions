#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);

string A,B, aux;
int casos, perimetro, L,W,E,R, necesito, quiero;
cin>>casos;
for(int i=0;i<casos;i++){
     cin>>L>>W>>E>>R;
    perimetro = 2*(L+W);
    necesito = perimetro * R;
    quiero = E/necesito;
    cout<<quiero<<'\n';
}

return 0;
}
